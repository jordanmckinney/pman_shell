#include <readline/history.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "../include/structs.h"

void update_bg_process(proc **root_ptr) {
    int id=0;
    int status=0;
    while(1) {
        id = waitpid(-1, &status, WNOHANG | WUNTRACED | WCONTINUED); 
       
        // no children changed state, no update needed 
        if(id == 0) return;
       
        // no more updates, return
        else if(id < 0) return;
       
        // process updated, remove from list 
        else if(id > 0) {
        	if(WIFSIGNALED(status)){
                 
                    proc *curr;
                    proc *prev=NULL;
                    for(curr=*root_ptr; curr!=NULL; curr=curr->next){
                        if(curr->pid==id){
                            if(curr==*root_ptr) *root_ptr=curr->next;
                            else prev->next=curr->next;
                            printf("Process: %d killed\n",id);
                            free(curr);
                            break;
                        }
                        prev=curr;
                    }
            }else if(WIFSTOPPED(status)){
                    printf("Process: %d stopped\n", id);
            }else if(WIFCONTINUED(status)){
                    printf("Process: %d continued\n", id);
            }

        }     
    }
    return;
}
