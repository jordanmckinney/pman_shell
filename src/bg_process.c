#include <unistd.h>
#include <readline/readline.h>
#include <stdlib.h>
#include "../include/helpers.h"

void bg_process(proc **root_ptr, char * arg1, char ** argarray){
	if(arg1==NULL){
		fprintf(stderr,"Error: arguments required\n");
		return;
	}

	pid_t pid=fork();
	if(pid<0){
		fprintf(stderr,"Unable to fork\n");
		return;
	}
	if(pid==0){
		if (execvp(arg1, (char*const*)(argarray+1)) < 0){
			fprintf(stderr,"Error executing command: %s\n", arg1);
			exit(-1);
		}
	}
	
	// alloc process struct for list
	proc *procsumm = (proc*)malloc(sizeof(proc));
	strcpy(procsumm->cmd,arg1);
	procsumm->pid=pid;
	procsumm->isStop=0;
	procsumm->next=NULL;
	
	// add process to list
	if(*root_ptr==NULL)
		*root_ptr = procsumm;
	else{
		proc *curr;
		for(curr=*root_ptr; curr->next!=NULL; curr=curr->next);
		curr->next=procsumm;
	}
	printf("Process %d has started\n", pid);
}
	



