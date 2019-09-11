#include<iostream>
using namespace std;


struct Process{
	int procNo;
	int burstTime;
};


int main()
{
	int totalProcess;
		cout<<"Enter total number of proceess ";
		cin>>totalProcess;
		struct Process p[totalProcess];
	for(int i=0;i<totalProcess;i++)
			{
				p[i].procNo=i;
				cout<<"\nProcess P-"<<(i+1)<<" : ";
				cin>>p[i].burstTime;
			}
	int sec =0;
	struct Process p2[totalProcess];
	int i=0;
	while(1)
	{
		if(p[sec].procNo)
		{
			p2[i]=p[sec];
			cout<<sec<<"  P"<<p2[i].procNo<<endl;
			p[sec].burstTime--;
			sec++;
			i++;
		}
		else
		{
			struct Process temp;
			for(int ii = 0; ii<i;ii++)
			{
				for(int iii = 0;iii<i-1;iii++)
				{
					if(p2[iii].burstTime>0)
					p2[iii].burstTime--;
				}	
			}	
		}
	}
	return 0;
}
