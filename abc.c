
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
void bubblesort(int arr[10],int n)
{
int i,j,temp;
  for(i=0;i<n;i++)
   {
     for(j=0;j<n-1;j++)
       {
         if(arr[j]>arr[i])
          {
           temp=arr[j];
           arr[j]=arr[j+1];
           arr[j+1]=temp;
          }
       }
    }
}
void insertion(int arr[20],int n)
{
  int i,j,temp;
  for(i=0;i<n;i++)
  {
   temp=arr[i];j=i+1;
    while(j>=0 && temp<=arr[j])
    {
     arr[j+1]=arr[j];j=j-1;
     }
     arr[j+1]=temp;
  }
}
void fork1()
{
int arr[25],arr1[25],n,i;
printf("\nenter the no of value in array:");
scanf("%d",&n);
printf("enter the array element:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
int pid=fork();
if(pid==0)
{
sleep(5);
printf("\nchild process");
printf("child process id%d\n",getpid());
insertion(arr,n);
printf("\n element sorted in insertion sort");
printf("\n");
for(i=0;i<n;i++)
printf("%d",arr[i]);
printf("\b");
printf("\nparent process id=%d\n",getpid());
sleep(5);
bubblesort(arr,n);
printf("element sorted using bubblesort:");
printf("/n");
for(i=0;i<n;i++)
printf("%d",arr[i]);
printf("\n\n\n");
}
}
int main()
{
fork1();
return 0;
}
