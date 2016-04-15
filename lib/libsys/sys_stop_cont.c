// crossy sends kernel call that is handled with do_stop_cont()

#include "syslib.h"

int sys_stop_cont(endpoint_t proc_ep, int signr){
	message m;
	m.SIG_ENDPT = proc_ep;
	m.SIG_NUMBER = signr;
	return(_kernel_call(SYS_STOP_CONT, &m));
}
