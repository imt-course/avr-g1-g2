/*
 * main.c
 *
 *  Created on: Oct 21, 2022
 *      Author: ahmad
 */
#include "FreeRTOS/FreeRTOS.h"
#include "FreeRTOS/task.h"
#include "FreeRTOS/semphr.h"
#include <std_types.h>
#include <Dio.h>
#include <Usart.h>
#include <Gie.h>

#define APP_EXAMPLE 1

/*****************************************************************************/
#if APP_EXAMPLE == 1
/*****************************************************************************/

#define APP_PIN_LED1 DIO_PORTA, DIO_PIN0
#define APP_PIN_LED2 DIO_PORTA, DIO_PIN1

void Task_Led1(void *pvParameters);
void Task_Led2(void *pvParameters);

int main(void)
{
    xTaskCreate(Task_Led1, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(Task_Led2, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    vTaskStartScheduler();
}

void Task_Led1(void *pvParameters)
{
    Dio_SetPinMode(APP_PIN_LED1, DIO_PIN_OUTPUT);
    while (1)
    {
        Dio_FlipPinLevel(APP_PIN_LED1);
        vTaskDelay(1000);
    }
}

void Task_Led2(void *pvParameters)
{
    vTaskDelay(1000);
    Dio_SetPinMode(APP_PIN_LED2, DIO_PIN_OUTPUT);
    while (1)
    {
        Dio_FlipPinLevel(APP_PIN_LED2);
        vTaskDelay(1000);
    }
}

/*****************************************************************************/
#elif APP_EXAMPLE == 2
/*****************************************************************************/

void Task1(void *pvParameters);
void Task2(void *pvParameters);

int main(void)
{
    Usart_Init();
    xTaskCreate(Task1, NULL, 250, NULL, 1, NULL);
    xTaskCreate(Task2, NULL, 250, NULL, 1, NULL);
    vTaskStartScheduler();
}

void Task1(void *pvParameters)
{
    while (1)
    {
        Usart_Print("IAMTASK1 ");
        vTaskDelay(2000);
    }
}

void Task2(void *pvParameters)
{
    vTaskDelay(1000);
    while (1)
    {
        Usart_Print("IAMTASK2 ");
        vTaskDelay(2000);
    }
}

/*****************************************************************************/
#elif APP_EXAMPLE == 3
/*****************************************************************************/

void Task1(void *pvParameters);
void Task2(void *pvParameters);

xSemaphoreHandle UartSem;

int main(void)
{
    Usart_Init();
    xTaskCreate(Task1, NULL, 250, NULL, 1, NULL);
    xTaskCreate(Task2, NULL, 250, NULL, 1, NULL);
    UartSem = xSemaphoreCreateCounting(1, 1);
    vTaskStartScheduler();
}

void Task1(void *pvParameters)
{
    while (1)
    {
        xSemaphoreTake(UartSem, portMAX_DELAY);
        Usart_Print("IAMTASK1 ");
        xSemaphoreGive(UartSem);
        vTaskDelay(1000);
    }
}

void Task2(void *pvParameters)
{
    while (1)
    {
        xSemaphoreTake(UartSem, portMAX_DELAY);
        Usart_Print("IAMTASK2 ");
        xSemaphoreGive(UartSem);
        vTaskDelay(1000);
    }
}

/*****************************************************************************/
#elif APP_EXAMPLE == 4
/*****************************************************************************/

void ReceiveTask(void *pvParameters);
void ReceiveISR(u8 data);
volatile char receivedMessage;
xSemaphoreHandle ReceiveSem;

int main(void)
{
    xTaskCreate(ReceiveTask, NULL, 250, NULL, 1, NULL);
    ReceiveSem = xSemaphoreCreateCounting(1, 0);
    vTaskStartScheduler();
}

void ReceiveTask(void *pvParameters)
{
    Usart_Init();
    Usart_EnableReceiveNotification(ReceiveISR);
    while (1)
    {
        xSemaphoreTake(ReceiveSem, portMAX_DELAY);
        Usart_Print("%c", receivedMessage);
        vTaskDelay(100);
    }
}

void ReceiveISR(u8 data)
{
    receivedMessage = data;
    xSemaphoreGiveFromISR(ReceiveSem, NULL);
}

/*****************************************************************************/
#elif APP_EXAMPLE == 5
/*****************************************************************************/

#define MAX_RECEIVE_CHAR 100
void ReceiveTask(void *pvParameters);
void ReceiveISR(u8 data);
char receivedMessage[MAX_RECEIVE_CHAR];
xSemaphoreHandle ReceiveSem;

int main(void)
{
    xTaskCreate(ReceiveTask, NULL, 250, NULL, 1, NULL);
    ReceiveSem = xSemaphoreCreateCounting(MAX_RECEIVE_CHAR, 0);
    vTaskStartScheduler();
}

void ReceiveTask(void *pvParameters)
{
    u8 counter = 0;
    Usart_Init();
    Usart_EnableReceiveNotification(ReceiveISR);
    while (1)
    {
        xSemaphoreTake(ReceiveSem, portMAX_DELAY);
        Usart_Print("%c", receivedMessage[counter]);
        counter++;
        vTaskDelay(2000);
    }
}

void ReceiveISR(u8 data)
{
    static u8 counter = 0;
    receivedMessage[counter++] = data;
    xSemaphoreGive(ReceiveSem);
}

/*****************************************************************************/
#elif APP_EXAMPLE == 6
/*****************************************************************************/

#define MAX_RECEIVE_CHAR 2
void ReceiveTask(void *pvParameters);
void ReceiveISR(u8 data);
xQueueHandle buffer;

int main(void)
{
    xTaskCreate(ReceiveTask, NULL, 250, NULL, 1, NULL);
    buffer = xQueueCreate(MAX_RECEIVE_CHAR, sizeof(char));
    vTaskStartScheduler();
}

void ReceiveTask(void *pvParameters)
{
    u8 message;
    Usart_Init();
    Usart_EnableReceiveNotification(ReceiveISR);
    while (1)
    {
        xQueueReceive(buffer, &message, portMAX_DELAY);
        Usart_Print("%c", message);
        vTaskDelay(1000);
    }
}

void ReceiveISR(u8 data)
{
    xQueueSend(buffer, &data, portMAX_DELAY);
}

#endif
