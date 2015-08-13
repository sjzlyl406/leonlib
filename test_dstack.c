/*************************************************************************
	> File Name: test_dstack.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月13日 星期四 20时16分04秒
 ************************************************************************/

#include<stdio.h>
#include"dstack.h"

int main(void) {
	DStack *pstack = dstack_create();
	dstack_push(pstack, (void*)20);
	dstack_push(pstack, (void*)10);
	dstack_push(pstack, (void*)22);
	printf("the size of stack is :%d\n", dstack_length(pstack));

	int num;
	dstack_top(pstack, (void*)&num);
	printf("top:%d\n", num);
	printf("the size of stack is :%d\n", dstack_length(pstack));

	dstack_pop(pstack);
	dstack_top(pstack, (void*)&num);
	printf("top:%d\n", num);
	printf("the size of stack is :%d\n", dstack_length(pstack));

	dstack_pop(pstack);
	dstack_top(pstack, (void*)&num);
	printf("top:%d\n", num);
	printf("the size of stack is :%d\n", dstack_length(pstack));

	dstack_destory(pstack);
	return 0;
}
