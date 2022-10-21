/*
 * Scheduler.c
 *
 *  Created on: Oct 21, 2022
 *      Author: ahmad
 */
#include <std_types.h>
#include <Gpt.h>
#include <Scheduler.h>

typedef enum
{
    SCHEDULER_FALSE,
    SCHEDULER_TRUE
} Scheduler_BooleanType;

typedef struct
{
    Scheduler_TaskStateType state;
    Scheduler_BooleanType runFlag;
    u16 delay;
    u16 periodicity;
    void (*funcPtr)(void);
} Scheduler_TaskType;

static void updateTasks(void);
static Scheduler_TaskType tasks[SCHEDULER_MAX_TASKS];

void Scheduler_Init(void)
{
    u8 i;
    for (i = 0; i < SCHEDULER_MAX_TASKS; i++)
    {
        Scheduler_DeleteTask(i);
    }
}

u8 Scheduler_CreateTask(void (*funcPtr)(void), u16 delay, u16 periodicity)
{
    u8 i;
    for (i = 0; i < SCHEDULER_MAX_TASKS; i++)
    {
        if (tasks[i].funcPtr == NULL_PTR)
        {
            tasks[i].state = SCHEDULER_TASK_RESUMED;
            tasks[i].runFlag = SCHEDULER_FALSE;
            tasks[i].delay = delay;
            tasks[i].periodicity = periodicity;
            tasks[i].funcPtr = funcPtr;
            break;
        }
    }
    return i;
}
void Scheduler_DeleteTask(u8 taskIndex)
{
    tasks[taskIndex].state = SCHEDULER_TASK_SUSPENDED;
    tasks[taskIndex].runFlag = SCHEDULER_FALSE;
    tasks[taskIndex].delay = 0;
    tasks[taskIndex].periodicity = 0;
    tasks[taskIndex].funcPtr = NULL_PTR;
}

void Scheduler_SuspendTask(u8 taskIndex)
{
    tasks[taskIndex].state = SCHEDULER_TASK_SUSPENDED;
}
void Scheduler_ResumeTask(u8 taskIndex)
{
    tasks[taskIndex].state = SCHEDULER_TASK_RESUMED;
}
Scheduler_TaskStateType Scheduler_GetTaskState(u8 taskIndex)
{
    return tasks[taskIndex].state;
}
void Scheduler_Start(void)
{
    /* Initialze Timer with Prescaler = 64 and F_CPU = 8MHz */
    Gpt_Init();
    /* Set Compare Value = 125, means System Tick = 1ms */
    Gpt_ResetAndStart(GPT_CHANNEL_TIM0, 125);
    /* Enable Timer Interrupt Notification */
    Gpt_EnableNotification(GPT_INT_SOURCE_TIM0_COMP, updateTasks);
}
void Scheduler_Dispatch(void)
{
    u8 i;
    while (1)
    {
        for (i = 0; i < SCHEDULER_MAX_TASKS; i++)
        {
            if ((tasks[i].runFlag == SCHEDULER_TRUE) && (tasks[i].state == SCHEDULER_TASK_RESUMED))
            {
                tasks[i].runFlag = SCHEDULER_FALSE;
                tasks[i].funcPtr();
                if (tasks[i].periodicity == 0)
                {
                    /*One Shot Task*/
                    Scheduler_DeleteTask(i);
                }
            }
        }
    }
    
}

static void updateTasks(void)
{
    u8 i;
    for (i = 0; i < SCHEDULER_MAX_TASKS; i++)
    {
        if (tasks[i].funcPtr != NULL_PTR)
        {
            if (tasks[i].delay == 0)
            {
                tasks[i].runFlag = SCHEDULER_TRUE;
                tasks[i].delay = tasks[i].periodicity;
            }
            tasks[i].delay -= 1;
        }
    }
}
