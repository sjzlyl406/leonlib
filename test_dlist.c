/*************************************************************************
	> File Name: test_dlist.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月13日 星期四 18时38分54秒
 ************************************************************************/

#include<stdio.h>
#include"dlist.h"

Ret print_list(void *data, void *ctx);

int main(void) {
	DListNode *pHead = dlist_create();
	dlist_prepend(pHead, (void*)20);
	dlist_foreach(pHead, print_list, (void*)0);
	printf("prepend 20;");
	printf("\n\n");

	dlist_append(pHead, (void*)30);
	dlist_foreach(pHead, print_list, (void*)0);
	printf("append 30");
	printf("\n\n");

	dlist_insert(pHead, 2, (void*)30);
	dlist_foreach(pHead, print_list, (void*)0);
	printf("insert 30 at index 2;");
	printf("\n\n");

	dlist_delete(pHead, 2);
	dlist_foreach(pHead, print_list, (void*)0);
	printf("delete element at index 2");
	printf("\n\n");

	int num = 0;
	dlist_get_by_index(pHead, 1, (void*)&num);
	dlist_foreach(pHead, print_list, (void*)0);
	printf("第2位上元素为：%d\n\n", num);

	dlist_set_by_index(pHead, 1, (void*)10);
	dlist_foreach(pHead, print_list, (void*)0);
	printf("set 10 by index 2;");
	printf("\n\n");

	dlist_destory(pHead);
}

Ret print_list(void *data, void *ctx) {
	Ret ret = RET_ERR;
	printf("%d\t", (Type)data);
	ret = RET_OK;
	return ret;
}
