/*************************************************************************
	> File Name: dlist.h
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月13日 星期四 15时50分54秒
 ************************************************************************/

/********************************************************************
 * 链表：
 * 功能：
 *		DListNode* dlist_create(void);
 *
 *		Ret dlist_prepend(DListNode *thiz, void *data);
 *		Ret dlist_append(DListNode *thiz, void *data);
 *		Ret dlist_insert(DListNode *thiz, size_t index, void *data);
 *		Ret dlist_delete(DListNode *thiz, size_t index);
 *		Ret dlist_get_by_index(DListNode *thiz, size_t index, void **data);
 *		Ret dlist_set_by_index(DListNode *thiz, size_t index, void *data);
 *		Ret dlist_foreach(DListNode *thiz, DataVisitFunc visit, void *ctx);
 *
 *		size_t dlist_length(DListNode *thiz);
 *		void dlist_destory(DListNode *thiz);
 * *****************************************************************/

#ifndef _DLIST_H_
#define _DLIST_H_

#define RET_OK			0		//ok
#define RET_ERR			-1		//返回错误
#define RET_ERR_ARGa	-2		//参数错误
#define MALL_ERR		-3		//分配空间错误
//#define NOT_FOUND		1		//没有查找结果

//#define INITSPACE

typedef int Type;
typedef int Ret;

struct _DListNode {
	Type data;
	struct _DListNode *next;
};
typedef struct _DListNode DListNode;

typedef unsigned int size_t;

typedef Ret (*DataVisitFunc) (void *, void *);

DListNode* dlist_create(void);
Ret dlist_prepend(DListNode *thiz, void *data);
Ret dlist_append(DListNode *thiz, void *data);
Ret dlist_insert(DListNode *thiz, size_t index, void *data);
Ret dlist_delete(DListNode *thiz, size_t index);
Ret dlist_get_by_index(DListNode *thiz, size_t index, void **data);
Ret dlist_set_by_index(DListNode *thiz, size_t index, void *data);
Ret dlist_foreach(DListNode *thiz, DataVisitFunc visit, void *ctx);
size_t dlist_length(DListNode *thiz);
void dlist_destory(DListNode *thiz);

#endif
