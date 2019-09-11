#include<iostream>
using namespace std;

class Calculate
{
	private:
		float totalProcess;
		float proNo[100];
		float compTime[100];
		float arrTime[100];
		float priority[100];
		float avgWaitingTime;
		float avgTurnAroundTime;
		float turnAroundTime[100];
		float waitingTime[100];
		float burstTime[100];
	public:
		Calculate()
		{
			cout<<"Enter Total no of processes : ";
			cin>>totalProcess;
			cout<<"Enter Burst Time for processes : ";
			for(int i=0;i<totalProcess;i++)
			{
				proNo[i]=i;
				cout<<"\nProcess P"<<(i+1)<<" : ";
				cin>>burstTime[i];
				cout<<"\nEnter priority : ";
				cin>>priority[i];
			}
			for(int i=0;i<totalProcess;i++)
			{
							
				for(int j=0;j<totalProcess;j++)
				{
					if(priority[j]==(i+1))
					{
						if(j==0)
						{
							arrTime[j]=0;
							compTime[j]=burstTime[j];
						}
						else
						{
							arrTime[j]=arrTime[j-1]+burstTime[j-1];
							compTime[j]=arrTime[j]+burstTime[j];
						}
						turnAroundTime[j]=compTime[j]-arrTime[j];
						waitingTime[j]=turnAroundTime[j]-burstTime[j];
					}
				}
			}
		}
		void calAvgWaitingTime()
		{
			float sum = 0;
			for(int i=0;i<totalProcess;i++)
			sum+=waitingTime[i];
			avgWaitingTime = sum/totalProcess;
			cout<<"\nTotal waiting time : "<<sum;
			cout<<"\nAverage waiting time is "<<avgWaitingTime;
		}
		void calculateTAT()
		{
			float sum = 0;
			for(int i=0;i<totalProcess;i++)
			sum+=turnAroundTime[i];
			avgTurnAroundTime = sum/totalProcess;
			cout<<"\nTotal TAT : "<<sum;
			cout<<"\nAverage TAT is "<<avgTurnAroundTime;
		}
		void printInfo()
		{
			cout<<"\n\n\n\t\tBurst \tArrival\tCompl\tTAT\tWaiting Time\n";
		
		
				for(int i=0;i<totalProcess;i++)
				{
					for(int j=0;j<totalProcess;j++)
					{
						if((i+1)==(priority[j]))
						{
							cout<<"priority"<<priority[i]<<"\t"<<burstTime[j]<<"\t  "<<arrTime[j]<<"\t "<<compTime[j]<<"\t"<<turnAroundTime[j]<<"\t"<<waitingTime[j]<<endl;
						}
					}
				}
			
			
		}
};

int main()
{
	Calculate obj;
	obj.printInfo();
	obj.calAvgWaitingTime();
	obj.calculateTAT();
	return 0;
}

