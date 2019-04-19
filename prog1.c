#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
#include<stdbool.h>
#include<semaphore.h>
//#include<cursors.h>
bool flag[2];
int turn;
void p0()
{
while(true)
{
	flag[0]=true;
	while(flag[1])
	{
	if(turn==1)
	{
	flag[0]=false;
	while(turn==1)
	flag[0]=true;
	}
	}
	turn=1;
	flag[0]=false;
}
}
void p1()
{
while(true)
{
	flag[1]=true;
	while(flag[0])
	{
	if(turn==1)
	{
	flag[1]=false;
	while(turn==0)
	flag[1]=true;
	}
	}
	turn=0;
	flag[1]=false;
}
}
void main()
{
flag[0]=false;
flag[1]=false;
turn=1;
parbegin(p0,p1);
}
