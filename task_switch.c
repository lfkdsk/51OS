//任务交换程序
#include "OS_task.h"
#include "89c51.h"
#include "main.h"
#include "task_switch.h"
#include <reg52.h>
//任务调度函数
void task_switch(){
	static int i;
	unsigned char j,MAX; 
	OS_PCB[OS_TASK_ID].Task_SP = SP; 
	for(i=0;i<MAX_TASK;i++)
	{
		MAX=j;
		if(OS_PCB[j].Priority<OS_PCB[i].Priority||j!=OS_TASK_ID)   //如果优先级高，则切换之
        {
         	j=i;
		}
	}
	OS_TASK_ID=j;
	SP = OS_PCB[OS_TASK_ID].Task_SP; 
} 


