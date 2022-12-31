#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

void make_tok(char *s, char *tok[])
{
	int i=0;
	char * p;
	p=strtok(s, " ");
	while(p!=NULL)
	{
		tok[i++]=p;
		p= strtok(NULL," ");

	}
	tok[i]=NULL;
}

void l_DIR(char * dir_name, char*op)
{
	int count=0;
	struct dirent*dir;
	DIR *d;
	d=opendir(dir_name);
	
	if(d)
	{
		if(*op=='f')
		{
			while((dir=readdir(d))!=NULL)
			{
				printf("%s\n",dir->d_name);
			}
		}
		else if(*op=='n')
		{
			while((dir=readdir(d))!=NULL)
			{
				count++;
			}
			printf("no of entries is:%d",count-2);
		}
		else if(*op=='i')
		{
			while((dir=readdir(d))!=NULL)
			{
				printf("%s %d\n",dir->d_ino,dir->d_name);
			}
		}
	}
	closedir(d);
}
 
 int main()
 {
	int pid;
	char buff[80];
	char *args[10];
	while(1)
	{
		printf("\nmyshell$\n");
		fflush(stdin);
		fgets(buff,80,stdin);
		buff[strlen(buff) -1]='\0';
		make_tok(buff, args);

		if(strcmp(args[0],"list")==0)
		l_DIR(args[2],args[1]);

		else
		{
			pid=fork();
			if(pid>0)
			wait();
			else
			{
				if(execvp(args[0],args)==-1)
				printf("\n bad command..\n");
			}
		}
	}
 }



/*#include<stdio.h>
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
      printf("Child gets higher CPU priority than parent%d\n", retnice);
      sleep(1);
      
    }
    else
    {
      retnice =nice (4);
       printf("parent gets lower CPU priority than child%d\n", retnice);
      sleep(1);
      
    }
    }
}
////////////////////////////

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void make_toks(char *s, char *tok[])
{
	int i = 0;
	char *p;
	p = strtok(s, " ");
	while (p != NULL)
	{
		tok[i++] = p;
		p = strtok(NULL, " ");
	}
	tok[i] = NULL;
}
void count(char *fn, char op)
{
	int fh, cc = 0, wc = 0, lc = 0;
	char c;
	fh = open(fn, O_RDONLY);
	if (fh == -1)
	{
		printf("file %s not found.\n", fn);
		return;
	}
	while (read(fh, &c, 1) > 0)
	{
		if (c == ' ')
			wc++;
		else if (c == '\n')
		{
			wc++;
			lc++;
		}
		cc++;
	}
	close(fh);
	switch (op)
	{
	case 'c':
		printf("No. of charecters:%d\n", cc );
		break;
	case 'w':
		printf("No. of words:%d\n", wc);
		break;
	case 'l':
		printf("No. of lines:%d\n", lc + 1);
		break;
	default:
		printf("Wrong command\n");
	}
}
int main()
{
	char buff[80], *args[10];
	int pid;
	while (1)
	{
		printf("myshell$");
		fflush(stdin);
		fgets(buff, 80, stdin);
		buff[strlen(buff) - 1] = '\0';
		make_toks(buff, args);
		
		if (strcmp(args[0], "count") == 0)
			count(args[2], args[1][0]);

		else
		{
			pid = fork();
			if (pid > 0)
				wait();
			else
			{
				if (execvp(args[0], args) == -1)
					printf("Wrong command.\n");
			}
		}
	}
	return 0;
}
*/