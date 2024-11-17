#include<stdio.h>
#define max 25
void main()
{
    int frag[max],block_size[max],file_size[max],i,j,no_blocks,no_files,diff,lowest=9999;
    static int bf[max],block_no[max];
    printf("\n\t Memory Management schme-BestFit");
    printf("\n Enter the number of blocks:");
    scanf("%d",&no_files);
    printf("\n Enter the size of blocks:\n");
    for(i=1;i<=no_blocks;i++)
    {
        printf("Block:%d",i);
        scanf("%d",&block_size[i]);
    }
    for(i=1;i<=no_files;i++)
    {
        for(j=1;j<=no_blocks;j++)
        {
            if(bf[j]!=1)
            {
                diff=block_size[j]-file_size[i];
                if(lowest>diff && diff>=0)
                {
                    block_no[i]=j;
                    lowest=diff;
                }
            }
        }
        frag[i]=lowest;
        bf[block_no[i]]=1;
        lowest=9999;
    }
    printf("\n File-No:\t File-Size:\t Block-No:\t Block-Size:\tFragment");
    for(i=1;i<=no_files;i++)
    printf("\n %d\t\t%d\t\t%d\t\t%d\t\t%d",i,file_size[i],block_no[i],block_size[block_size[block_no[i]],frag[i]]);
}