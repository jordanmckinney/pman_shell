#include <stdlib.h>
#include "../include/structs.h"

int check_pid(proc *root, int pid){
	proc *curr;
	for(curr=root; curr!=NULL; curr=curr->next){
		if(curr->pid==pid) return 0;
	}
	return 1;
}