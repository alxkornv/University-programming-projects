#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
void sig_proc(int);
unsigned int sig_count=0;
int main()
{
	int stat;
	struct sigaction n;
    sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask,SIGINT);
	n.sa_mask = mask;
	n.sa_handler = sig_proc;
	sigaction(SIGINT,&n,0);


	dup2(1,4);
	close(1);
	creat("fnames.txt",0660);
	system("cd /media/alex/LINUXFILES/my_spool && ls -1");
	close(1);
	dup2(4,1);
	close(4);
	printf("В очереди на печать находятся следующие файлы:\n");
	system("cat fnames.txt");

	if(fork()==0)
	{
		FILE *fp;
		char temp[] = "cd /media/alex/LINUXFILES/my_spool && cat ";
		fp = fopen("fnames.txt","r");
		char *str = NULL;
		size_t len;

		while(getline(&str,&len,fp)>0)
		{
			char *cmd = (char*)malloc(strlen(temp)+strlen(str));
			strcat(cmd,temp);
			strcat(cmd, str);
			printf("Содержимое файла %s",str);
			system(cmd);
			printf("\n");
			free(cmd);
		}
		free(str);
		fclose(fp);
		exit(0);
	}
	else
	{
		wait(&stat);
		sleep(15);
		sleep(15);
		sleep(15);
		sleep(15);
	}
	
	return 0;
}

void sig_proc(int signum)
{
	sig_count++;
	if(sig_count==3)
	{
		printf("\nКоличество файлов в очереди на печать: ");
		fflush(stdout);
		system("cd /media/alex/LINUXFILES/my_spool && ls | wc -l");
		printf("\n");
	}

}



