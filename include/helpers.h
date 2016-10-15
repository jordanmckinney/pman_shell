#ifndef HELPERS
#define HELPERS

#include "structs.h"

// uses waitpid to check for processes that have changed state
// if process has been killed, remove from list
void update_bg_process(proc **root_ptr);

// simply check if pid currently belongs to pman
int check_pid(proc *root, int pid);

// change the active/stopped state of process
int change_state(proc *root, int pid, int state);

// kill, start, or stop process
void bg_kill(proc *root, char * cmd, char * arg1);

// starts background process
void bg_process(proc **root_ptr, char * arg1, char ** argarray);

// prints out all active processes owned by pman
void bg_list(proc **root_ptr,char *arg1);

// prints info about specific process owned by pman
void pstat(proc *root, char *arg1);

#endif