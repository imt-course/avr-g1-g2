/*
 * Application.c
 *
 *  Created on: Oct 21, 2022
 *      Author: ahmad
 */
#include <std_types.h>
#include <Dio.h>
#include <Gie.h>
#include <Scheduler.h>

#define APP_PIN_LED1 DIO_PORTA,DIO_PIN0
#define APP_PIN_LED2 DIO_PORTA,DIO_PIN1

static void Task_Led1 (void);
static void Task_Led2 (void);
static void Application_Init(void);

void Application_Main(void) {
    Application_Init();
    Gie_Enable();
    Scheduler_Init();
    Scheduler_CreateTask(Task_Led1, 0, 1000);
    Scheduler_CreateTask(Task_Led2, 1000, 1000);
    Scheduler_Start();
    Scheduler_Dispatch();
}

static void Application_Init(void) {
    Dio_SetPinMode(APP_PIN_LED1, DIO_PIN_OUTPUT);
    Dio_SetPinMode(APP_PIN_LED2, DIO_PIN_OUTPUT);
}

static void Task_Led1 (void) {
    Dio_FlipPinLevel(APP_PIN_LED1);
}
static void Task_Led2 (void) {
    Dio_FlipPinLevel(APP_PIN_LED2);
}
