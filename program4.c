#include<stdio.h>

int main()
{
    int t[20],d[20],h,i,j,n,temp,k,atr[20],tot,p,sum=0;
    printf("enter the number of tracks to be travesed");
    scanf("%d",&n);
    printf("enter thr position of heads");
    scanf("%d",&h);
    t[0]=0;t[1]=h;
    printf("enter the trackers");
    for(i=2;i<n+2;i++)
    scanf("%d",&t[i]);
    for(i=0;i<n+2;i++)
    {
        for(j=0;j<(n+2)-i-1;j++)
        {
            if(t[j]>t[j+1])
            {
                temp=t[j];
                t[j]=t[j+1];
                t[j+1]=temp;
            }

        }
    }
    int m;
    for(i=0;i<n+2;i++)
        if(t[i]==h)
            k=i;
    for(m=k;m>0;m--)
    {
        sum=sum+(t[m]-t[m-1]);
        printf("\n %d----->%d\n",t[m],t[m+1]);
    }
    sum=sum+t[k+1];
    printf("\n 0---->%d\n",t[k+1]);
    for(m=k+2;m<n+2;m++)
    {
        sum=sum+t[m]-t[m-1];
        printf("\n%d--->%d\n",t[m-1],t[m]);
    }
    printf("total head movements are: %d",sum);
    
}