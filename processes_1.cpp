#include<iostream>
using namespace std;

class Process{
		
		float proNo;
		float compTime;
		float arrTime;
		float priority;
		float turnAroundTime;
		float waitingTime;
		//float burstTime;
	public:
		float burstTime;
		static float totalProcess;
		static float avgWaitingTime;
		static float avgTurnAroundTime;
		Process(){
			cout<<"For process no : "<<totalProcess+1<<endl;
			cout<<"Enter Burst Time : ";
			cin>>burstTime;
			cout<<"Enter Priority :";
			cin>>priority;
			totalProcess++;
			proNo=totalProcess;
		}
		void calculate(){
						if(proNo==0)
						{
							arrTime=0;
							compTime=burstTime;
						}
						else
						{
							arrTime=obj.compTime;
							compTime=arrTime+burstTime;
						}
						turnAroundTime=compTime-arrTime;
						waitingTime=turnAroundTime-burstTime;
		} 		
		friend void calAvgWaitingTime();
		friend void calculateTAT();
};		
float Process::totalProcess=0;
float Process::avgWaitingTime=0;
float Process::avgTurnAroundTime=0;
		void calAvgWaitingTime(Process obj)
		{
			static float sum = 0;
			for(int i=0;i<Process::totalProcess;i++)
			sum+=obj.waitingTime;
			Process::avgWaitingTime = sum/Process::totalProcess;
			
		}
		void calculateTAT(Process obj)
		{
			static float sum = 0;
			for(int i=0;i<Process::totalProcess;i++)
			sum+=obj.turnAroundTime;
			Process::avgTurnAroundTime = sum/Process::totalProcess;
			
		}
	int main(){
		int totalProcess;
		cout<<"Enter total number of proceess ";
		cin>>totalProcess;
		Process p[totalProcess];
		
		
		for(int i=0;i<totalProcess;i++)
		{
			for(int j=0;j<totalProcess-1-i;j++)
			{
				if(p[j].burstTime>p[j+1].burstTime)
				{
					Process obj = p[j];
					p[j] = p[j+1];
					p[j+1] = obj;
				}
			}
		}
		for(int i=0;i<totalProcess;i++)
		p[i].calculate()
		return 0; 
	}
