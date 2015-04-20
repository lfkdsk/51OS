//系统任务程序
#include "OS_task.h"
#include "89c51.h"
#include "main.h"
#include "task_switch.h"
#include <reg52.h>
//程序控制块
idata volatile PCB OS_PBC[MAX_TASK];

//当前运行任务的ID号
volatile unsigned char OS_TASK_ID;

//声明堆栈
unsigned char idata OS_Stack[MAX_TASK][SRACK_DEPTH];

//任务装载函数
void task_load(unsigned char PRI,unsigned int FN,unsigned char T_ID)
{
	OS_PCB[T_ID].Priority=PRI;
	OS_PCB[T_ID].Task_SP=OS_Stack[T_ID]+1;
	OS_Stack[T_ID][0] = (unsigned int)FN & 0xff; 
	OS_Stack[T_ID][1] = (unsigned int)FN << 8; 
}

//任务运行函数
void OS_Start(T_ID)
{
	OS_TASK_ID=T_ID;
	SP=OS_PCB[OS_TASK_ID].Task_SP;	
	while(1);//卡着吧
}
