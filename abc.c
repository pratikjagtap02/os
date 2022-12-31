#include<stdio.h>
#include<sys/types.h>
#define MAX 50

void bsort(int arr[MAX], int size)
{
    int temp;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        printf("\t-->%d",arr[i]);
    }
}

void insert(int arr[MAX], int size)
{
    int temp=0;
    for(int i=0;i<size;i++)
    {
        int j=i-1;
        while(j>=0)
        {
            if(arr[j+1]<arr[j])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
            j--;
        }
    }
    for(int i=0;i<size;i++)
    {
        printf("\t-->%d",arr[i]);
    }
}

int main()
{
    int pid;
    int n,arr[MAX];

    printf("enter the no. of element:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\t-->");
        scanf("%d",&arr[i]);
    }
    pid=fork();
    if(pid==0)
    {
        printf("\nparent(bubble)");
        bsort(arr,n);

    }
    else
    {
        printf("child(insertion)");
        insert(arr,n);
    }
}

/*#include <stdio.h>
#include <sys/types.h>
#define MAX 50

void bsort(int arr[MAX], int size)
{
    int temp;

    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j + 1] < arr[j]) // 3 2 1  //2 3
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {

        printf("\t->%d", arr[i]);
    }
}

void insert(int arr[MAX], int size)
{

    int temp = 0;

    for(int i=1; i < size; i++)
    {
        int j=i-1;
        while (j >= 0)
        {
            if(arr[j+1]<arr[j])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
            j--;
        }
    }

    for (int i = 0; i < size; i++)
    {

        printf("\t->%d", arr[i]);
    }


}

int main()
{

    int pid;
    int n;
    int arr[MAX];

    printf("\nEnter no of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        printf("--> ");
        scanf("%d", &arr[i]);
    }

    pid = fork();

    if (pid == 0)
    {
        printf("\nChild (insertion)\n");
        insert(arr, n);
    }
    else
    {
        printf("Parent (Bubble)\n");
        bsort(arr, n);
    }

    return 0;
}
*/