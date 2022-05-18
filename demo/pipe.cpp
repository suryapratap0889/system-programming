//program to demonstrate an IPC using PIPE
#include <iostream>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#define MAX 256
using namespace std;
char msg1[] = "Hello World #1";
char msg2[] = "Hello World #2";
char msg3[] = "Hello World #3";
int prnerr(int ret, const char msg[]){
	if (ret < 0) {
		perror(msg);
		exit(EXIT_FAILURE);
	}
	return 0;
}
int main() {
	char buff[MAX];
	int pipefd[2],i,ret,le;

	ret = pipe(pipefd);
	len = strlen(msg1);
	prnerr(ret,"Error Creating Pipe");
	ret = write(pipefd[1],msg1,strlen(msg1));
	prnerr(ret,"Unable to write Message to Pipe");
	ret = write(pipefd[1],msg2,strlen(msg2));
	prnerr(ret,"Unable to write Message to Pipe");
	ret = write(pipefd[1],msg3,strlen(msg3));
	prnerr(ret,"Unable to write Message to Pipe");

	child_pid = fork();
	if (child_pid == 0) {
		close(0);
		dup(pipefd[0]);
		close(pipefd[0]);
		close(pipefd[0]);
		execlp("tr","tr","a-z","A-Z",0);
	}

	/*	for (i = 0; i < 3; i++) {
		ret = read(pipefd[0],buff,MAX);
		prnerr(ret,"Error Reading the Pipe");
		cout << buff << endl;
	} */
	close(pipefd[0]);
	close(pipefd[0]);
	wait(&status)
	return 0;
}
