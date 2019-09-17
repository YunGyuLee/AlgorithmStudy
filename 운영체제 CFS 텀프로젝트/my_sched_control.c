#include <linux/syscalls.h>
int fast_PID = -1;
int slow_PID = -1;
EXPORT_SYMBOL(fast_PID);
EXPORT_SYMBOL(slow_PID); 

asmlinkage void sys_sched_faster(int n) {//function to deliver PID to schedular for fast scheduling
	fast_PID = n;
	printk("fast PID: %d\n",fast_PID);
	return;
}

asmlinkage void sys_sched_slower(int n) {//function to deliver PID to schedular for slow scheduling
	slow_PID = n;
	printk("slow PID: %d\n",slow_PID);
	return;
}
