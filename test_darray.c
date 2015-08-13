/*************************************************************************
	> File Name: test132.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月13日 星期四 09时31分13秒
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include"darray.h"

Ret cmp(void *arg1, void *ctx);
Ret visit(void *arg1, void *ctx);
Ret print_data(void *data, void *ctx);

int main(void) {
	DArray darray;
	int array[] = {1,2,3};
	darray_create(&darray, (void*)array, 3);
	
	int i = 0;
	printf("insert 4 at index 2:\n");
	darray_insert(&darray, 2, (void*)4);
	darray_foreach(&darray, print_data, (void*)0);
	printf("\n\n");

	printf("prepend 5 \n");
	darray_prepend(&darray, (void*)5);
	darray_foreach(&darray, print_data, (void*)0);
	printf("\n\n");
	
	printf("append 5 \n");
	darray_append(&darray, (void*)5);
	darray_foreach(&darray, print_data, (void*)0);
	printf("\n\n");
	
	printf("delete element at index 2 \n");
	darray_delete(&darray, 2);
	darray_foreach(&darray, print_data, (void*)0);
	printf("\n\n");
	
	printf("set 34 by index 4 \n");
	darray_set_by_index(&darray, 4, (void*)34);
	darray_foreach(&darray, print_data, (void*)0);
	printf("\n\n");
	
	printf("get by index 4\n");
	darray_get_by_index(&darray, 4, (void*)&i);
	printf("is : %d\n\n", i);

	clock_t cloc = clock();
	int j = 3;
	while(j--){
		for(i = 0; i < 10000; ++i) {
			darray_append(&darray, (void*)4 );
		}
		for( ; i >= 0; --i) {
			darray_delete(&darray, 3);
		}
	}
	clock_t cloc2 = clock();
	clock_t total_t = (cloc2-cloc) ;
	printf("用时：%f\n", (double)total_t);

	darray_destroy(&darray);

	return 0;
}

Ret cmp(void *arg1, void *ctx) {
	Ret ret = RET_OK;
	if((Type)arg1 > (Type)ctx) {
		ret = RET_OK;
	}
	else {
		ret = NOT_FOUND;
	}
	return ret;
}
Ret visit(void *arg1, void *ctx) {
	long long *sum = ctx;
	*sum += (Type)arg1;
	return RET_OK;
}

Ret print_data(void *data, void *ctx) {
	printf("%d\t", (Type)data);
	return RET_OK;
}
