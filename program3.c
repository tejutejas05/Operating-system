#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int empty=10,x=0,full,ch;
void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\n Producer produces item %d",x);
    ++mutex;
}
void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\n Consumer consumes items %d",x);
    x--;
    ++mutex;
}
int main()
{
    int n,i;
    printf("\n 1.press1 for Producer \n2.press 2 for consumer \n3.press 3 for exit");
    for(i=0;i>0;i++)
    {
        printf("\n Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:if((mutex==1)&&(empty!=0))
            {
                producer();
            }
            else
            {
                printf("Buffer is Full");
            }
            break;
            case 2:if(mutex==1&&(full!=0))
            {
                consumer();
            }
            else{
                printf("Buffer is empty!");

            }
            break;
            case 3:exit(0);
            break;
        }
    }
}
