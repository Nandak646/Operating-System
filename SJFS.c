#include<stdio.h>
int main()
{
        int n;
        printf("Enter the number of processes:");
        scanf("%d",&n);
        int p[n],bt[n],wt[n],tat[n];
        printf("Enter thr burst time for %d processes\n",n);
        for(int i=1;i<=n;i++)
        {
		p[i]=i;
	        scanf("%d",&bt[i]);
        }
	//sorting
	int temp;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(bt[i]>bt[j])
			{
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
                                                  temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
        //calculate the waiting time
        wt[1]=0;
        for(int i=2;i<=n;i++)
        {
                wt[i]=wt[i-1]+bt[i-1];
        }
        //calculate the turn around time
        for(int i=1;i<=n;i++)
        {
                tat[i]=bt[i]+wt[i];
        }
        //printing
        for(int i=1;i<=n;i++)
        {
                printf("\nProcess%d     %d      %d      %d\n",p[i],bt[i],wt[i],tat[i]);
        }
}
