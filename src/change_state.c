#include <stdlib.h>
#include "../include/structs.h"

void change_state(proc *root, int pid, int state){
	proc *curr;
	for(curr=root; curr!=NULL; curr=curr->next){
		if(curr->pid==pid){
			curr->isStop=state;	
			return;
		} 
	}
}