#include <readline/readline.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "../include/structs.h"
#include "../include/helpers.h"

void bg_kill(proc *root, char * cmd, char * arg1){
	if(arg1==NULL){
		fprintf(stderr,"Error: PID required\n");
		return;
	}
	int pid = atoi(arg1);
	if(pid==0){
		fprintf(stderr, "Error: invalid PID %s\n", arg1);
		return;
	}
	if(check_pid(root,pid)){
		fprintf(stderr, "Error: Invalid PID %s\n", arg1);
		return;
	}
	if(strcmp(cmd,"bgkill")==0){
		if(kill(pid,SIGKILL)<0){
			fprintf(stderr,"Error killing process %d, check PID\n",pid);
			return;
		}
		printf("Process %d killed\n", pid);
		return;
	}
	else if(strcmp(cmd,"bgstart")==0){
		if(kill(pid,SIGCONT)<0){
			fprintf(stderr,"Error starting process %d, check PID\n",pid);
			return;
		}	
		change_state(root,pid,0);
		return;
	}
	else if(strcmp(cmd,"bgstop")==0){
		if(kill(pid,SIGSTOP)<0){
			fprintf(stderr,"Error killing process %d, check PID\n",pid);
			return;
		}
		change_state(root,pid,1);
		return;
	}
}
