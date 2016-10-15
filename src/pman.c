#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include <stdlib.h>

#include "../include/structs.h"
#include "../include/helpers.h"

int main(int argc, char const *argv[]){
	proc *root=NULL; 
	proc **root_ptr=&root; 
	char *prompt = "Pman: >";
	char *input = NULL;

	while(input=readline(prompt)){

		update_bg_process(root_ptr);
		if(strlen(input)==0) continue;

		char *cmd = NULL;
		char *arg1 = NULL;
		char ** argarray = NULL;
		int num_args=0;

		// tokenize input
		char * token = strtok(input, " ");
		while(token){
			argarray=realloc(argarray, sizeof(char*)* ++num_args);
			if (argarray==NULL) exit(-1); 
			
			argarray[num_args-1]=token;
			token=strtok(NULL, " ");
		}
		// add on null
		argarray=realloc(argarray,sizeof(char*)*(num_args+1));
		argarray[num_args]=NULL;
		
		cmd=argarray[0];
		if(num_args>1) arg1=argarray[1];

		// 'quit' command with no args will exit pman
		if(strcmp(cmd,"quit")==0 && arg1==NULL)
			exit(0);

		// 'bglist' lists all current processes belonging to pman
		else if(strcmp(cmd,"bglist")==0)
			bg_list(root_ptr,arg1);
		
		// 'bgkill', 'bgstart', 'bgstop' kill, start or stop processes
		// belonging to pman
		else if(strcmp(cmd,"bgkill")==0||strcmp(cmd,"bgstart")==0||
			strcmp(cmd,"bgstop")==0)
			bg_kill(*root_ptr,cmd,arg1);		
		
		// command starting with 'bg' will start background process
		else if(strcmp(cmd,"bg")==0)
			bg_process(root_ptr,arg1,argarray);
		
		// list information about specific process 
		else if(strcmp(cmd,"pstat")==0)
			pstat(*root_ptr,arg1);
		
		else
			fprintf(stderr, "Command not found: %s\n", cmd);	
		free(argarray);

	}
	return 0;
}
