#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Process
{ 
	int Pid;
	int BurstTime;
	//int arrTime;
	
 }p[100],q[100];
  
int counter, qt = 2,time=0,front=0,rear=0;


int check()
{	int flag = 0;
	for(int i=0; i< counter ; i++)
	{
		if(p[i].BurstTime > 0 )
		{
			flag= 1;
			break;
		}
		else 
			flag =0; 
			
		
	}
	return flag;
}


void push(Process p)
{
	queue[fornt] = p;
	front++;
}
void pop()
{
	rear>fornt?cout<<"\nqueue is empty\n":rear++;
}



int main(){
	int TotalProcess,sec=0;
	cout<<"\n Enter total process : ";
	cin>>TotalProcess;
	for(int i = 0; i<TotalProcess ; i++)
	{
		cout<<"\nEnter Burst time : ";
		cin>>p[i].BurstTime;
		p[i]=i;
	}
	while(check())
	{
		if(sec<TotalProcess)
		{
			push(p[sec]);
			sec++;
		}
		for(int i=0;i<qt;i++)
		{
			if(sec<TotalProcess)
			{
				q[sec]
			}
		}
	}
	return 0;
}
