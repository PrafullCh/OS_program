#include<iostream>
using namespace std;

class pr
{
	public:
		float totalProcess;
		float totalBurstTime=0;
		float proNo[100];
		float compTime[100];
		float arrTime[100];
		float burstTime[100];
		
		pr()
		{
			cout<<"Enter Total no of processes : ";
			cin>>totalProcess;
			cout<<"Enter Burst Time for processes : ";
			for(int i=0;i<totalProcess;i++)
			{
				proNo[i]=i;
				cout<<"\nProcess P"<<(i+1)<<" : ";
				cin>>burstTime[i];
				totalBurstTime += burstTime[i];  
				
			
			}
			
		}
		
		void print()
		{
			for(int i=0 ; i<=totalBurstTime ; i++ )
			{
				
				cout<<"Process : "<<proNo[j];

			}
		}
	
};

int main()
{
	pr work;

	work.print();
	return 0;
}
