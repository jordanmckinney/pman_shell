#### Course: CSC 360

### Overview

This project consists of a simple shell capable of starting and managing background processes. 

### Compilation/Execution

To compile the program type `make`

The program can be run with `./pman`

### Functions

Pman support the following functions:

`bg <filename> <argument1> <argument2> ...`
	
Executes given file with arguments and runs process in background.

`bglist`

Lists all processes currently active that belong to pman. Stopped processes will not appear.

`bgkill <pid>`

Kills process with given PID.

`bgstop <pid>`

Stops process with given PID. Process can be resumed with 'bgstart'

`bgstart <pid>`

Resumes stopped process with given PID.

`pstat <pid>`

Prints data about given PID. Prints comm, state, utime, stime, rss, voluntary context switches and involuntary context switches.

### Sources

Program skeleton based on A1-hint-official.c
