#include "OS_task.h"
#include "89c51.h"
#include "main.h"
#include "task_switch.h"
#include <reg52.h>
sbit K1=P0^0;
void del10ms()
{
	unsigned char a,b,c;
	for (c=1;c>0;c--)
        for(b=0;b<38;b++)
           for(a=0;a<130;a++);
}
void task_1()
{
	while(1)
	{
		if(K1==0)
	  	  del10ms();
		  if(K1==0)
			{
				task_switch();	
			}
	}
}

void task_2()
{
	while(1)
	{
		if(K1==0)
	  	  del10ms();
		  if(K1==0)
			{
				task_switch();	
			}
	}
}

void task_3()
{

	while(1)
	{
		if(K1==0)
	  	  del10ms();
		  if(K1==0)
			{
				task_switch();	
			}
	}
}

void task_4()
{
	while(1)
	{
		if(K1==0)
	  	  del10ms();
		  if(K1==0)
			{
				task_switch();	
			}
	}
}

void task_5()
{
	while(1)
	{
		if(K1==0)
	  	  del10ms();
		  if(K1==0)
			{
				task_switch();	
			}
	}
}
void main(void)
{
//	载入函数 优先级 任务名 任务ID
	task_load(2,task_1, 0);
	task_load(3,task_2, 1);
	task_load(4,task_3, 2);
	task_load(5,task_4, 3);
	task_load(6,task_4, 4);
	OS_Start(0);
}