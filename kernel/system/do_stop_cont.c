// crossy

#include "kernel/system.h"
#include <minix/endpoint.h>

/*========================================================*
 *                  do_stop_cont    					  *
 *	sets or unsets flags								                      *
 *========================================================*/

// just like do_kill method
int do_stop_cont(struct proc *caller_ptr, message *m_ptr) {
	proc_nr_t proc_nr, proc_nr_e;
	int sig_nr = m_ptr->SIG_NUMBER;

	proc_nr_e = (proc_nr_t) m_ptr->SIG_ENDPT;

	if (!isokendpt(proc_nr_e, &proc_nr)) return(EINVAL);
	if (sig_nr >= _NSIG) return(EINVAL);
	if (iskerneln(proc_nr)) return(EPERM);	

	if (sig_nr == SIGCONT){
		if (RTS_ISSET(proc_addr(proc_nr), RTS_STOP_CONT))
			RTS_UNSET(proc_addr(proc_nr), RTS_STOP_CONT);
	}

	else if (sig_nr == SIGSTOP){
		RTS_SET(proc_addr(proc_nr), RTS_STOP_CONT);
	}

	return(OK);
}
