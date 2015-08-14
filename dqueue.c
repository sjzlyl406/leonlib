/*************************************************************************
	> File Name: dqueue.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月14日 星期五 10时00分20秒
 ************************************************************************/

/*************************************************************************
 * 队列：
 * 功能：
 *			DQueue* dqueue_create();
 *
 *			Ret dqueue_push(DQueue *thiz, void *data);
 *			Ret dqueue_pop(DQueue *thiz);
 *			Ret dqueue_top(DQueue *thiz, void **data);
 *			Ret dqueue_is_empty(DQueue *thiz);
 *			size_t dqueue_length(DQueue *thiz);
 *
 *			void dqueue_destory(DQueue *thiz);
 *
 * *********************************************************************/

#include<stdlib.h>
#include"dqueue.h"

typedef Container* (*container_create) (void);
typedef Ret (*container_append) (Container *thiz, void *data);
typedef Ret (*container_insert) (Container *thiz, size_t index, void *data);
typedef Ret (*container_delete) (Container *thiz, size_t index);
typedef size_t (*container_length) (Container *thiz);
typedef void (*container_destory) (Container *thiz);
typedef Ret (*container_get_by_index) (Container *thiz, size_t index, void **data);


static container_create cc_create = dlist_create;
static container_append cc_append = dlist_append;
static container_insert cc_insert = dlist_insert;
static container_delete cc_delete = dlist_delete;
static container_length cc_length = dlist_length;
static container_destory cc_destory = dlist_destory;
static container_get_by_index cc_get_by_index = dlist_get_by_index;

/*
static int init_container_func() {
	static container_create cc_create = dlist_create;
	static container_append cc_append = dlist_append;
	static container_insert cc_insert = dlist_insert;
	static container_delete cc_delete = dlist_delete ;
	static container_length cc_length = dlist_length ;
	static container_destory cc_destory = dlist_destroy ;
	static container_get_by_index cc_get_by_index = dlist_get_by_index;
	return 0;
}
//force to load those funcitons
static int do_init_func = init_container_func();
*/


//创建队列
DQueue* dqueue_create() {
	DQueue *ret = (DQueue*) malloc (sizeof(DQueue));
	ret -> cc = cc_create();
	return ret;
}

//压入队列
Ret dqueue_push(DQueue *thiz, void *data) {
	Ret ret = RET_ERR;
	if(thiz != (void*)0 ) {
		ret = cc_append(thiz->cc, data);
	}
	return ret;
}

//弹出首位元素
Ret dqueue_pop(DQueue *thiz) {
	Ret ret = RET_ERR;
	if(thiz != (void*)0 && dqueue_is_empty(thiz) != RET_OK) {
		ret = cc_delete(thiz->cc, 0);
	}
	return ret;
}

//返回队列元素
Ret dqueue_top(DQueue *thiz, void **data) {
	Ret ret = RET_ERR;
	if(thiz != (void*)0 && dqueue_is_empty(thiz) != RET_OK) {
		ret = cc_get_by_index(thiz->cc, 0, data);
	}
	return ret;
}

//队列为空
Ret dqueue_is_empty(DQueue *thiz) {
	Ret ret = RET_ERR;
	size_t length = dqueue_length(thiz);
	if(length == 0) 
		ret = RET_OK;
	return ret;
}

//返回队列长度
size_t dqueue_length(DQueue *thiz) {
	return cc_length(thiz->cc);
}

//销毁队列
void dqueue_destory(DQueue *thiz) {
	cc_destory(thiz->cc);
}

