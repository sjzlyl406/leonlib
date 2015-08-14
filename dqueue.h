/*************************************************************************
	> File Name: dqueue.h
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月14日 星期五 09时46分44秒
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

#ifndef _DQUEUE_H_
#define _DQUEUE_H_

#include "darray.h"
#include "dlist.h"

#define RET_OK			0		//正确
#define RET_ERR			-1		//返回错误
#define RET_ERR_ARG		-2		//参数错误
#define MALL_ERR		-3		//分配空间错误
//#define NOT_FOUND		1		//没有查找结果

//#define INITSPACE		5		//初始大小

typedef int Type;				//类型
typedef int Ret;				//返回结果
typedef unsigned int size_t;	//下标类型

typedef DListNode Container;		//容器


struct _DQueue {
	Container *cc;
};
typedef struct _DQueue DQueue;

DQueue* dqueue_create();
Ret dqueue_push(DQueue *thiz, void *data);
Ret dqueue_pop(DQueue *thiz);
Ret dqueue_top(DQueue *thiz, void **data);
Ret dqueue_is_empty(DQueue *thiz);
size_t dqueue_length(DQueue *thiz);
void dqueue_destory(DQueue *thiz);



#endif
