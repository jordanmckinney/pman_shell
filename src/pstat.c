#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include <stdlib.h>

#include "../include/structs.h"
#include "../include/helpers.h"

void pstat(proc *root, char *arg1){
	if(arg1==NULL){
		fprintf(stderr,"Error: PID required\n");
		return;
	}

	// check that pid belongs to pman
	if(check_pid(root,atoi(arg1))){
		fprintf(stderr, "Invalid PID: %s\n", arg1);
		return;
	}

	char path[64];
	snprintf(path, sizeof(path), "/proc/%s/stat",arg1);
    FILE *fp = fopen(path, "r");
  
  	// read from stat
    if(fp){
    	char comm[32];
  		int rss; 
  		unsigned long int utime, stime;
  		char state;
  		
  		// most fields are skipped with %*s
		fscanf(fp,  "%*s %s %c "
					"%*s %*s %*s %*s %*s "
					"%*s %*s %*s %*s %*s "
					"%lu %lu "
					"%*s %*s %*s %*s %*s "
					"%*s %*s %*s "
					"%d",
					comm, &state,  
					&utime, &stime, 
					&rss);
  	
		printf("comm: %s\n", comm);
		printf("state: %c\n", state);
		printf("rss: %d\n", rss);
		printf("utime: %f\n", (float)utime/sysconf(_SC_CLK_TCK));
		printf("stime: %f\n", (float)stime/sysconf(_SC_CLK_TCK));
		fclose(fp);
    }

	char buffer[256];
	snprintf(path, sizeof(path), "/proc/%s/status",arg1);
    fp = fopen(path, "r");

	// read from status
	if(fp){
		int currline=0;
		while(fgets(buffer,sizeof(buffer),fp)!=NULL){
			if(currline>38){
				printf("%s", buffer);
			}
			currline++;
		}
    	fclose(fp);
    }
}
