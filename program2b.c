#include<stdio.h>

int main()
{
    int n,at[10],bt[10],wt[10],ta[10],status[10],min,gc=0,i,j,process,choice;
    int rm[10],p[10],count=0,slice;

    printf("Enter number of processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Arrival and Burst time for process %d\n",i);
        scanf("%d  %d",&at[i],&bt[i]);
        status[i]=1;
    }
    printf("Enter your choice\n");
    printf("1.Round Robin Scheduling\t2.Priority Scheduling\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
                printf("Enter the Time slice\n");
                scanf("%d",&slice);
                for(i=0;i<n;i++)
                {
                    rm[i]=bt[i];
                }
                while(count<n)
                {
                    for(i-0;i<n;i++)
                    {
                        if(gc<at[i] || rm[i]==0)
                            continue;
                        else
                        {
                            if(rm[i]<=slice)
                            {
                                gc=gc+rm[i];
                                rm[i]=0;
                                wt[i]=gc-at[i]-bt[i];
                                ta[i]=gc-at[i];
                                count++;
                            }
                            else
                            {
                                rm[i]=rm[i]-slice;
                                gc=gc+slice;
                            }
                        }
                    }

                }
        break;
        case 2:
                for(i=0;i<n;i++)
                {
                    printf("Enter Priority of process %d\n",i);
                    scanf("%d",&p[i]);
                }
                for(i=0;i<n;i++)
                {
                    min=99;
                    for(j=0;j<n;j++)
                    {
                        if(p[j]<min && status[j]==1 && at[j]<=gc)
                        {
                            min=p[j];
                            process=j;
                        }
                    }
                    wt[process]=gc-at[process];
                    gc=gc+bt[process];
                    ta[process]=gc-at[process];
                    status[process]=0;
                }
        break;
        default:
                printf("Invalid choice\n:");
        break;
    }
    printf("Process\tAT\tBT\tWT\tTA\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",i,at[i],bt[i],wt[i],ta[i]);
    }
    return 0;
}