.phony all:
all: pman

pman: src/pman.c src/update_bg_process.c src/check_pid.c src/bg_kill.c
	gcc src/pman.c src/update_bg_process.c src/check_pid.c \
	src/change_state.c src/bg_kill.c src/bg_process.c \
	src/bg_list.c src/pstat.c \
	-lreadline -lhistory -o pman

.PHONY clean:
clean:
	-rm -rf *.o *.exe
