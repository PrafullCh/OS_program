#include<iostream>
using namespace std;


struct Process{
	int procNo;
	int burstTime;
	int arrTime;
	int compTime;
}q[100];

int front=0,rear=0,qt=2;
int totalProcess;
struct Process p[100];
int check()
{	int flag = 0;
	for(int i=0; i< totalProcess ; i++)
	{
		if(p[i].burstTime > 0 )
		{
			flag= 1;
			break;
		}
		else 
			flag =0; 
			
		
	}
	return flag;
}


int main()
{
	
		cout<<"Enter total number of proceess ";
		cin>>totalProcess;
		
	for(int i=0;i<totalProcess;i++)
			{
				p[i].procNo=i+1;
				cout<<"\nProcess P-"<<(i+1)<<" : ";
				cin>>p[i].burstTime;
				p[i].arrTime=i==0?0:p[i-1].arrTime+p[i-1].burstTime;
			}
	int sec =0;
	//struct Process p2[totalProcess];
	int i=1;
	while(check())
	{
		if(sec<totalProcess)//new process in queue
		{
			q[front] = p[sec];
			
			front++;
		}
		
			if(i<=qt)//main excution
			{
				q[rear].burstTime-=1;
				cout<<"P "<<q[rear].procNo<<"\t";
				i++;
			}	
			else if(i>qt)
			{
				 if(q[rear].burstTime>0 ) //if burst time is reamaining to be executed then got to front
				 {
				 	q[front++] =q[rear++];
				 	
				 } 
				 
				i=1;
			}
			if(q[rear].burstTime==0 )//if burst time become 0  then q
			{
				 	q[rear].compTime =sec;
				 	rear++;
			}
		
		sec++;
	}
	for(int i=0;i<totalProcess;i++)
		cout<<" P-"<<p[i].procNo<<"\t"<<p[i].burstTime<<"\t  "<<p[i].arrTime<<"\t "<<p[i].compTime<<endl;
	return 0;
}
