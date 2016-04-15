// crossy

#include <lib.h>
#include <unistd.h>
#include <minix/callnr.h>

int get_stopped_procs(pid_t * buf){
	message m;
	m.SI_WHERE = buf;
	int result = _syscall(PM_PROC_NR, GET_STOPPED_PROCS, &m);
	if (result == 0) {
		int length;
		for (length = 0 ; buf[length] != 0; length++) {}
		return length;
	}
   errno = EINVAL;
   return -1;
}
