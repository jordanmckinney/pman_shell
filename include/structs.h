#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_CMD_LEN 20

typedef struct proc{
    pid_t pid;
    char cmd[MAX_CMD_LEN];
    int isStop;
    struct proc *next;
} proc;

#endif