#ifndef __OS_TASK_H__
#define __OS_TASK_H__
//任务功能
	//最大任务数
#define MAX_TASK 5
	//堆栈深度
#define SRACK_DEPTH 20
	//保存切换任务时软件压栈字节数
#define Num_PUSH_bytes 13
	//程序控制块结构
typedef struct 
{
	 unsigned char Task_SP;       //任务堆栈指针
	 unsigned char Priority;      //优先级，值越小，优先级越高

}PCB;

extern idata volatile PCB OS_PCB[MAX_TASK];//定义堆栈
extern volatile unsigned char OS_TASK_ID;//定义任务ID
void task_load(unsigned char PRI,unsigned int FN,unsigned char T_ID);
void OS_Start(T_ID);













#endif