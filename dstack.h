/*************************************************************************
	> File Name: dstack.h
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月13日 星期四 15时44分25秒
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
#include"darray.h"
#include"dlist.h"

#ifndef _DSTACK_H_
#define _DSTACK_H_

#define RET_OK			0		//正确
#define RET_ERR			-1		//返回错误
#define RET_ERR_ARG		-2		//参数错误
#define MALL_ERR		-3		//分配空间错误
#define NOT_FOUND		1		//没有查找结果

#define INITSPACE		5		//初始大小

typedef int Type;				//类型
typedef int Ret;				//返回结果
typedef unsigned int size_t;

typedef DArray Container;		//容器


struct _DStack {
	Container *cc;
};
typedef struct _DStack DStack;


DStack* dstack_create();
Ret dstack_push(DStack *thiz, void* data);
Ret dstack_pop(DStack *thiz);
Ret dstack_top(DStack *thiz, void **data);
Ret dstack_is_empty(DStack *thiz);
size_t dstack_length(DStack *thiz);
void dstack_destory(DStack *thiz);



#endif

