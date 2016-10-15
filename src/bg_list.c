#include <readline/history.h>
#include "../include/helpers.h"

void bg_list(proc **root_ptr,char *arg1){
	// arguments were given 
	if(arg1!=NULL){
		fprintf(stderr,"bglist takes no arguments\n");
		return;
	}
	int count=0;
	proc *curr;
	printf("------------------------\n");
	for(curr=*root_ptr; curr!=NULL; curr=curr->next){
		if(curr->isStop) 
		    printf("%d: %s ***stopped***\n", curr->pid,curr->cmd);
        else
		    printf("%d: %s\n", curr->pid,curr->cmd);
		count++;
	}
	printf("Total background jobs: %d\n", count);
	printf("------------------------\n");
}
