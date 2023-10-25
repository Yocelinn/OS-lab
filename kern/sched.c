#include <env.h>
#include <pmap.h>
#include <printk.h>

/* Overview:
 *   Implement a round-robin scheduling to select a runnable env and schedule it using 'env_run'.
 *
 * Post-Condition:
 *   If 'yield' is set (non-zero), 'curenv' should not be scheduled again unless it is the only
 *   runnable env.
 *
 * Hints:
 *   1. The variable 'count' used for counting slices should be defined as 'static'.
 *   2. Use variable 'env_sched_list', which contains and only contains all runnable envs.
 *   3. You shouldn't use any 'return' statement because this function is 'noreturn'.
 */
void schedule(int yield) {
	static int count = 0; // remaining time slices of current env
	struct Env *e = curenv;
	static int user_time[5];//创建一个用户累计运行时间片数数组
	struct Env *each;

	int user_runnable[5] = {0};//用于记录可执行进程的用户号
	TAILQ_FOREACH(each, &env_sched_list, env_sched_link) {
		if(each->env_status == ENV_RUNNABLE){
			user_runnable[each->env_user] = 1;
		}
	}
	
	/* We always decrease the 'count' by 1.
	 *
	 * If 'yield' is set, or 'count' has been decreased to 0, or 'e' (previous 'curenv') is
	 * 'NULL', or 'e' is not runnable, then we pick up a new env from 'env_sched_list' (list of
	 * all runnable envs), set 'count' to its priority, and schedule it with 'env_run'. **Panic
	 * if that list is empty**.
	 *
	 * (Note that if 'e' is still a runnable env, we should move it to the tail of
	 * 'env_sched_list' before picking up another env from its head, or we will schedule the
	 * head env repeatedly.)
	 *
	 * Otherwise, we simply schedule 'e' again.
	 *
	 * You may want to use macros below:
	 *   'TAILQ_FIRST', 'TAILQ_REMOVE', 'TAILQ_INSERT_TAIL'
	 */
	/* Exercise 3.12: Your code here. */

	
	if(yield != 0 || count == 0 || e == NULL || e->env_status != ENV_RUNNABLE){
		if(e != NULL && e->env_status == ENV_RUNNABLE){
			TAILQ_REMOVE(&env_sched_list, e, env_sched_link);
		
			if(e->env_status == ENV_RUNNABLE){		//将当前进程移至链表尾,如果说只有e一个runnable，那么移动后它仍是头
				TAILQ_INSERT_TAIL(&env_sched_list, e, env_sched_link);
			}
			user_time[e->env_user] += e->env_pri;	//用户累计运行时间片数+=pri
		}
//		e = TAILQ_FIRST(&env_sched_list);
//		if(e != NULL){	
//			count = e->env_pri;
//		}else { 	//说明调度链表为空
		if(TAILQ_EMPTY(&env_sched_list)){		
			panic ("schedule: no runnable envs");
		}
		u_int u = 0;
		u_int i;
		for(i = 0;i < 5;i++){
			if(user_runnable[i] != 0) {
				u = i;
				break;
			}
		}
		for(i = 0;i < 5;i++) {
			if(user_runnable[i] != 0){
				if(user_time[i] < user_time[u]){	//累计运行时间数更少
					u = i;
				} else if(user_time[i] == user_time[u] && i < u){
					//累计时间一样多，选择编号小的
					u = i;
				}
			}
		}
		TAILQ_FOREACH(each, &env_sched_list, env_sched_link) {
			if(each->env_user == u) {
				e = each;
				break;
			}
		}
		if(e != NULL){
			count = e->env_pri;
		}else {
			panic("finding error");
		}
	}
	count --;
	env_run(e);
}
