#include<stdio.h>
#include<sys/types.h>

int main()
{
  int pid, retnice;
  pid=fork();
  
  for(int i=0; i<10;i++)
    {
    if(pid== 0)
    {
      retnice= nice(-5);
      printf("Child gets higher CPU priority than                parent%d\n", retnice);
      sleep(1);
      
    }
    else
    {
      retnice =nice (4);
       printf("parent gets lower CPU priority than                child%d\n", retnice);
      sleep(1);
      
    }
    }
}