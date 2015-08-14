/*************************************************************************
	> File Name: test_dqueue.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月14日 星期五 10时15分37秒
 ************************************************************************/

#include<stdio.h>
#include"dqueue.h"

int main(void) {
	DQueue *pstack = dqueue_create();
	dqueue_push(pstack, (void*)20);
	dqueue_push(pstack, (void*)10);
	dqueue_push(pstack, (void*)22);
	printf("the size of stack is :%d\n", dqueue_length(pstack));

	int num;
	dqueue_top(pstack, (void*)&num);
	printf("top:%d\n", num);
	printf("the size of stack is :%d\n", dqueue_length(pstack));

	dqueue_pop(pstack);
	dqueue_top(pstack, (void*)&num);
	printf("top:%d\n", num);
	printf("the size of stack is :%d\n", dqueue_length(pstack));

	dqueue_pop(pstack);
	dqueue_top(pstack, (void*)&num);
	printf("top:%d\n", num);
	printf("the size of stack is :%d\n", dqueue_length(pstack));

	dqueue_destory(pstack);
	return 0;
}
