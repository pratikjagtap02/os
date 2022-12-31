#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



make_tokens(char *buff, char *args[]) {
  char *p;
  int pos = 0;
  p = strtok(buff, " ");

  while (p != NULL) {
    args[pos++] = p;
    p = strtok(NULL, " ");
  }
  args[pos] = NULL;
}

void search(char *op, char *fname, char *needle)
{
    
    char buff[30],c;
    
    FILE *fh;
    fh = fopen(fname,"r");
    if(!fh)
    {
        printf("\nFILE NOT FOUND");
        return;
    }
    int ln=0;
    
    if(strcmp(op,"f")==0)
    {
        while(!feof(fh))
        {
            fgets(buff,29,fh);
            ln++;
            if(strstr(buff, needle))
            {
                printf("NEEDLE FOUND AT LINE: %d", ln);
                break;
            }
            
        }
    }
    else if(strcmp(op, "a")==0)
    {
        int ln=0;
        while(!feof(fh))
        {
            fgets(buff,29,fh);
            ln++;

            if(strstr(buff,needle))
            {
                printf("NEEDLE FOUND AT LINE: %d\n", ln);
            }
        }
    }
        
    

}

int main() {


  char buff[20];
  char *args[20];
  int pid;


  while (1) {

    printf("\nmyshell$ ");
    fgets(buff, 20, stdin);

    buff[strlen(buff) - 1] = '\0';
    make_tokens(buff, args);

    if (strcmp(args[0], "search") == 0) {
      search(args[1], args[2], args[3]);
    } else {
      pid = fork();
      if (pid == 0) {
        if (execvp(args[0], args) == -1) 
        {
          //printf("\nWrong command");
        }
      } else {
        wait();
      }
    }
  }

//  return 0;
}

/*#include<stdio.h>
#include<sys/types.h>

void main()
{
    pid_t pid;
    pid=fork();

    if(pid == 0)
    {
        sleep(5);
        printf("\nIn child process..\n");
        printf("\nchild process id:%d\n",getpid());
        printf("\nparent id from child:%d",getppid());
        
    }

    else
    {
        printf("In parent process...\n");
        printf("\nparent process id: %d\n",getpid());
    }
}*/