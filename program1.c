#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    int status;
    int n=20;
    pid=fork();
    if(pid==-1)
    {
        return(1);
    }
    printf("\n Fork Successful !\n");
    if(pid==0)
    {
        n=n*10;
        printf("Child:I'm the child,my process ID is:%d\n",getpid());
        execl("/bin/ls","-l","/home/student/4al23cd049",(char*)0);
        printf("Child:My Parent process ID is:%d\n",getppid());
        printf("Chid:Value of n=%d\n",n);
        return(0);
    }
    else if(pid>0)
    {
        printf("Parent:I'mthe Parent,My pracess ID is:%d\n",getpid());
        printf("Parent:My Parent is %d\n",getppid());
        n=n*2;
        printf("Parent:value of n=%d\n",n);
        pid=wait(&status);
        printf("Parent:My child process with ID %d terminated\n",pid);
        if(WIFEXITED(status))
        {
            printf("Parent:child process exited with %d\n",WEXITSTATUS(status));
        }
    }
    return(0);
}