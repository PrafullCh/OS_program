#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Process
{ 
	int Pid;
	int BurstTime;
	
 }p[100];
  
int counter, qt = 4,time=0;

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

int main(){
	
	cout<<"Enter the  total no. of process :";
	cin>>counter;
	int i = 0;
	for ( int j = 0 ; j< counter ; j++)
	{
		p[j].Pid = j+1; 
		cout<<"Enter the  Burst time :";
		cin >> p[j].BurstTime ;
	}
	
	
	

	while(check())
	{
		if(p[i].BurstTime > 0)
		{
			p[i].BurstTime -= qt ;
			
			cout<<"  P "<<p[i].Pid;
			p[i].BurstTime = p[i].BurstTime == 0 ? 0 : p[i].BurstTime ;
			
		}
		i++;
		i = (i==counter)?0:i;	
	}
	
	return 0;
}
