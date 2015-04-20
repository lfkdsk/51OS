//ϵͳ�������
#include "OS_task.h"
#include "89c51.h"
#include "main.h"
#include "task_switch.h"
#include <reg52.h>
//������ƿ�
idata volatile PCB OS_PBC[MAX_TASK];

//��ǰ���������ID��
volatile unsigned char OS_TASK_ID;

//������ջ
unsigned char idata OS_Stack[MAX_TASK][SRACK_DEPTH];

//����װ�غ���
void task_load(unsigned char PRI,unsigned int FN,unsigned char T_ID)
{
	OS_PCB[T_ID].Priority=PRI;
	OS_PCB[T_ID].Task_SP=OS_Stack[T_ID]+1;
	OS_Stack[T_ID][0] = (unsigned int)FN & 0xff; 
	OS_Stack[T_ID][1] = (unsigned int)FN << 8; 
}

//�������к���
void OS_Start(T_ID)
{
	OS_TASK_ID=T_ID;
	SP=OS_PCB[OS_TASK_ID].Task_SP;	
	while(1);//���Ű�
}
