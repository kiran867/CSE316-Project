#include<stdio.h>

main()
{
        int i=0, j, a, number[30];

        for (i = 0; i < 3; ++i)
        {
            printf("Enter the priority of the queue %d\n",i+1);
            scanf("%d", &number[i]);

        }


        for (i = 0; i < 3; ++i)
        {

            for (j = i + 1; j < 3; ++j)
            {

                if (number[i] > number[j])
                {

                    a =  number[i];
                    number[i] = number[j];
                    number[j] = a;

                }

            }

        }

        printf("The Queues arranged in ascending order of priority\n");
        for (i = 0; i < 3; ++i)
            printf("%d\n", number[i]);

        int high= 0;
            high= number[0];
        if(high>0)
        {
            Queue1();
        }
        int mid= 0;
            mid = number[1];
        if(mid>0)
        {
            Queue2();
        }
        int low= 0;
            low=number[2];
        if(low>0)
        {
            queue3();
        }


}

      void Queue1()  //round robins
         {
            printf("\nRound Robin\n");
         	int a,i,j,n,m,g=0,r=0;
            int b[10],rq[10],id[10],wt[10],tt[10],at[10],bt[10],TimeQuantum=4;

            printf("enter number of processes ");
            scanf("%d",&n);

            int temp=n;

            for(i=0;i<n;i++)
            {
                id[i]=i;
                printf("Enter Arrival time for process P%d ",i+1);
                scanf("%d",&at[i]);
                printf("\nEnter Burst time for process P%d ",i+1);
                scanf("%d",&bt[i]);
            }

            for(i=0;i<n;i++)
            {
                b[i]=bt[i];
            }

            int k=0;
            while(1)
            {
                int d=1;
                for(i=0;i<n;i++)
                {
                    if(b[i]>0)
                    {
                        d=0;
                        if(b[i]>TimeQuantum)
                        {
                            k=k+TimeQuantum;
                            b[i]=b[i]-TimeQuantum;
                        }
                        else
                        {
                            k=k+b[i];
                            wt[i]=k-b[i];
                            b[i]=0;
                        }
                    }
                }
                if(d==1)
                {
                    break;
                }
            }

            for(i=0;i<n;i++)
            {
                if(wt[i]==0)
                {
                    rq[i]=id[i];
                }
            }

            printf("Waiting time\n");

            for(i=0;i<n;i++)
            {
                printf("P%d ",i+1);
                printf("%d\n",wt[i]);
            }

            for(i=0;i<n;i++)
            {
                tt[i]=bt[i]+wt[i];
            }

            printf("Turnaround Time\n");

            for(i=0;i<n;i++)
            {
                printf("P%d ",i+1);
                printf("%d\n",tt[i]);
            }

            for(i=0;i<n;i++)
            {
                r=r+wt[i];
                g=g+tt[i];
            }

            printf("Average Waiting Time\n");
            printf("%f",(float)r/(float)n);
            printf("\nAverage Turnaround Time\n");
            printf("%f",(float)g/(float)n);
}



    void Queue2()  // priority
    {
        printf("\nPriority Scheduling\n");
        int i,j,n,pos,temp,avg_wt,avg_tt;
        int total=0,bt[20],p[20],wt[20],tt[20],pr[20];

        printf("Enter Total Number of Process:");
        scanf("%d",&n);

        printf("\nEnter Burst Time and Priority\n");
        for(i=0;i<n;i++)
        {
            printf("\nP[%d]\n",i+1);
            printf("Burst Time:");
            scanf("%d",&bt[i]);
            printf("Priority:");
            scanf("%d",&pr[i]);
            p[i]=i+1;           //contains process number
        }

        //sorting burst time, priority and process number in ascending order using selection sort
        for(i=0;i<n;i++)
        {
            pos=i;
            for(j=i+1;j<n;j++)
            {
                if(pr[j]<pr[pos])
                    pos=j;
            }

            temp=pr[i];
            pr[i]=pr[pos];
            pr[pos]=temp;

            temp=bt[i];
            bt[i]=bt[pos];
            bt[pos]=temp;

            temp=p[i];
            p[i]=p[pos];
            p[pos]=temp;
        }

        wt[0]=0;	//waiting time for first process is zero

        //calculate waiting time
        for(i=1;i<n;i++)
        {
            wt[i]=0;
            for(j=0;j<i;j++)
                wt[i]+=bt[j];

            total+=wt[i];
        }

        avg_wt=total/n;      //average waiting time
        total=0;

        printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
        for(i=0;i<n;i++)
        {
            tt[i]=bt[i]+wt[i];     //calculate turnaround time
            total+=tt[i];
            printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tt[i]);
        }

        avg_tt=total/n;     //average turnaround time
        printf("\n\nAverage Waiting Time=%d",avg_wt);
        printf("\nAverage Turnaround Time=%d\n",avg_tt);
    }

    void queue3()    //first come first serve
    {
        printf("\nFirst come First Serve\n");

        int n,bt[20],wt[20],tt[20],avg_wt=0,avg_tt=0,i,j;

        printf("Enter total number of processes(maximum 20):");
        scanf("%d",&n);

        printf("\nEnter Process Burst Time\n");
        for(i=0;i<n;i++)
        {
            printf("P[%d]:",i+1);
            scanf("%d",&bt[i]);
        }

        wt[0]=0;    //waiting time for first process is 0

        //calculating waiting time
        for(i=1;i<n;i++)
        {
            wt[i]=0;
            for(j=0;j<i;j++)
                wt[i]+=bt[j];
        }

        printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

        //calculating turnaround time
        for(i=0;i<n;i++)
        {
            tt[i]=bt[i]+wt[i];
            avg_wt+=wt[i];
            avg_tt+=tt[i];
            printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tt[i]);
        }

        avg_wt/=i;
        printf("\n\nAverage Waiting Time:%d",avg_wt);

        avg_tt/=i;
        printf("\nAverage Turnaround Time:%d",avg_tt);
    }


