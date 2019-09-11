interface Threads
{
	int SIZE=5;
}
class ProCon extends Thread implements Threads{
	int s = 1;
	int emptySlot=SIZE;
	int fullSlot =0;
	int num;
	ProCon(int num)
	{
		this.num=num;
	}
	synchronized void table(int n)
	{
		for(int i=1;i<=10;i++)
			System.out.println(i*n);
	}
	void wait(int num)
	{
		while(num==0);
		num--;
	}
	void signal(int num)
	{
		while(num>0);
		num++;
	}
	public static void main(String[] args) {
		Thread t1 = new ProCon(4);
		Thread t2 = new ProCon(5);
	}
}