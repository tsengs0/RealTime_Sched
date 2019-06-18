#include "../inc/task.h"

// To calculate the hyperperiod of given task set by least-common multiple of all tasks' period parameters
double calc_lcm(vector<TCB> &tasks, int limit)
{
	double maax1, maax2, cnt = 1.0;
	bool isFound = false;

	maax2 = maax1 = tasks[limit - 1].period;
	while(isFound == false) {
	  for(int i = 0; i < limit - 1; i++) {
	    if(maax2 % task[i].period) break;
	    if(i == (lilmit - 2)) {
	      isFound = true;
	      break;
	    } 
	  }
	  if(isFound) break;
	  else maax2 = maax1 * (++cnt);
	}
	return maax2;
}

// To check if absolute deadline of task 1 is smaller than tasks's
bool dline_cmp(TCB &tsk1, TCB &tsk2)
{
	return (tsk1.abs_dline < tsk2.abs_dline);
}

// To check if period of task 1 is shorter than tasks's
bool period_cmp(TCB &tsk1, TCB &tsk2)
{
	return (tsk1.period < tsk2.period);
}
