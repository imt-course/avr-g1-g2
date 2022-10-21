/*
 * Scheduler.h
 *
 *  Created on: Oct 21, 2022
 *      Author: ahmad
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#define SCHEDULER_MAX_TASKS 3

typedef enum
{
    SCHEDULER_TASK_SUSPENDED,
    SCHEDULER_TASK_RESUMED
} Scheduler_TaskStateType;


/************************************************************************************
Name:           Scheduler_Init 
Description:    Initialize the Scheduler.
Parameters In:  None.
Parameters Out: None.
Return Value:   None.
*/
void Scheduler_Init(void);

/************************************************************************************
Name:           Scheduler_CreateTask 
Description:    Creates new task at first empty location of tasks array.
Parameters In:  - funcPtr: Pointer of the task function.
                - delay: First delay before task executes.
                - preodicity: Time between every execution of the task.
                              If 0, the task is one shot (executed once).
Parameters Out: - None.
Return Value:   - Index of the task if there is empty slot in the tasks array.
                - SCHEDULER_MAX_TASKS if the tasks array is full, task is not created.
*/
u8 Scheduler_CreateTask(void (*funcPtr) (void), u16 delay, u16 preodicity);

/************************************************************************************
Name:           Scheduler_DeleteTask
Description:    Deletes the task at this index from tasks array.
Parameters In:  - taskIndex: Index of task to be deleted.
Parameters Out: None.
Return Value:   None.
*/
void Scheduler_DeleteTask(u8 taskIndex);

/************************************************************************************
Name:           Scheduler_ResumeTask
Description:    Resumes the task at this index from tasks array if it was suspended.
Parameters In:  - taskIndex: Index of task to be resumed.
Parameters Out: None.
Return Value:   None.
*/
void Scheduler_ResumeTask(u8 taskIndex);

/************************************************************************************
Name:           Scheduler_SuspendTask
Description:    Suspends the task at this index from tasks array if it was resumed.
Parameters In:  - taskIndex: Index of task to be suspended.
Parameters Out: None.
Return Value:   None.
*/
void Scheduler_SuspendTask(u8 taskIndex);

/************************************************************************************
Name:           Scheduler_GetTaskState
Description:    Get task state, suspended or resumed.
Parameters In:  - taskIndex: Index of task.
Parameters Out: None.
Return Value:   State of Task:
                - SCHEDULER_TASK_RESUMED
                - SCHEDULER_TASK_SUSPENDED
*/
Scheduler_TaskStateType Scheduler_GetTaskState(u8 taskIndex);

/************************************************************************************
Name:           Scheduler_Start
Description:    Starts the timer used by scheduler.
                This function may be modified if using any Microcontroller.
                This should initialize the timer with system tick
                and set its ISR with updateTasks function.
Parameters In:  None.
Parameters Out: None.
Return Value:   None.
*/
void Scheduler_Start(void);

/************************************************************************************
Name:           Scheduler_Dispatch
Description:    Executes the Scheduler alogrithms to call tasks
Parameters In:  None.
Parameters Out: None.
Return Value:   None.
*/
void Scheduler_Dispatch(void);

#endif /* INC_SCHEDULER_H_ */
