/*************************************************************************
	> File Name: dstack.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月13日 星期四 19时45分57秒
 ************************************************************************/

/*******************************************************************
 * 栈：
 * 功能：
 *		DStack* dstack_create();
 *
 *		Ret dstack_push(DStack *thiz, void* data);
 *		Ret dstack_pop(DStack *thiz);
 *		Ret dstack_top(DStack *thiz, void **data);
 *		Ret dstack_is_empty(DStack *thiz);
 *		size_t dstack_length(DStack *thiz);
 *
 *		void dstack_destory(DStack *thiz);
 * ****************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"dstack.h"

typedef Container* (*container_create) (void);	
typedef Ret (*container_append) (Container *thiz, void *data);
typedef Ret (*container_insert) (Container *thiz, size_t index, void *data);
typedef Ret (*container_delete) (Container *thiz, size_t index);
typedef size_t (*container_length) (Container *thiz);
typedef void (*container_destory) (Container *thiz);
typedef Ret (*container_get_by_index) (Container *thiz, size_t index, void **data);


static container_create cc_create = darray_create;
static container_append cc_append = darray_append;
static container_insert cc_insert = darray_insert;
static container_delete cc_delete = darray_delete;
static container_length cc_length = darray_length;
static container_destory cc_destory = darray_destroy;
static container_get_by_index cc_get_by_index = darray_get_by_index;

/*
static int init_container_func() {
	static container_create cc_create = darray_create;
	static container_append cc_append = darray_append;
	static container_insert cc_insert = darray_insert;
	static container_delete cc_delete = darray_delete ;
	static container_length cc_length = darray_length ;
	static container_destory cc_destory = darray_destroy ;
	static container_get_by_index cc_get_by_index = darray_get_by_index;
	return 0;
}
//force to load those funcitons
static int do_init_func = init_container_func();
*/

//创建栈
DStack* dstack_create() {
	DStack *ret = (DStack*) malloc (sizeof(DStack));
	ret->cc = cc_create();
	return ret;
}

//压入栈
Ret dstack_push(DStack *thiz, void* data) {
	Ret ret = RET_ERR;
	if(thiz != (void*)0) {
		ret = cc_append(thiz->cc, data);
	}
	return ret;
}

//弹出栈
Ret dstack_pop(DStack *thiz) {
	Ret ret = RET_ERR;
	if(thiz != (void*)0 && dstack_is_empty(thiz) != RET_OK) {
		size_t length = dstack_length(thiz);
		ret = cc_delete(thiz->cc, length-1);
	}
	return ret;
}

//返回栈顶元素
Ret dstack_top(DStack *thiz, void **data) {
	Ret ret = RET_ERR;
	if(thiz != (void*)0 && dstack_is_empty(thiz) != RET_OK) {
		size_t length = dstack_length(thiz);
		ret = cc_get_by_index(thiz->cc, length-1, data);
	}
	return ret;
}

//栈为空
Ret dstack_is_empty(DStack *thiz) {
	Ret ret = RET_ERR;
	size_t length = dstack_length(thiz);
	if(length == 0)
		ret = RET_OK;
	return ret;
}

//返回栈的长度
size_t dstack_length(DStack *thiz) {
	return cc_length(thiz->cc);
}

//销毁栈的空间
void dstack_destory(DStack *thiz) {
	cc_destory(thiz->cc);
}


