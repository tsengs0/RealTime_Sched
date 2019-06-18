#ifndef __TASK_H
#define __TASK_H

#include <vector>
using std::vector;

enum {
	ON  = 0,
	OFF = 1
};

// Task Controll Block
typedef struct TCB_t {
	int tsk_id;
	double phase; // the arrival time of its first instance
	double period; // periodic interval of task's arrival
	double abs_dline; // absolute deadline
	double rel_dline; // relative deadline
	float wcet; // worst-case execution time 
	float rem_exe; // worst-case remaining time
	char ready;
	char flag;
} TCB;


double calc_lcm(vector<TCB> tasks, int limit); // to calculate the hyperperiod of given task set by least-common multiple of all tasks' period parameters
bool dline_cmp(TCB tsk1, TCB tsk2); // check the smaller absolute deadline
bool period_cmp(TCB tsk1, TCB tsk2); // check the shorter period


#endif // __TASK_H
