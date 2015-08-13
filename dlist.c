/*************************************************************************
	> File Name: dlist.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月13日 星期四 16时08分03秒
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

#include<stdlib.h>
#include"dlist.h"

//创建链表，返回头节点
DListNode* dlist_create(void) {
	DListNode *ret = (DListNode*) malloc (sizeof(DListNode));
	ret->data = 0;	//头结点的data值存放链表长度
	ret -> next = (void*)0;
	return ret;
}

//在头结点后插入节点
Ret dlist_prepend(DListNode *thiz, void *data) {
	Ret ret = RET_ERR;
	if(thiz != (void*)0) {
		DListNode *p = (DListNode*) malloc(sizeof(DListNode));
		p -> data = (Type)data;
		p -> next = thiz -> next;
		thiz -> next = p;
		thiz -> data ++;
		ret = RET_OK;
	}
	return ret;
}

//在尾节点后追加节点
Ret dlist_append(DListNode *thiz, void *data) {
	Ret ret = RET_ERR;
	if(thiz != (void*)0) {
		DListNode *p = thiz;
		for(p = thiz; p -> next != (void*)0; p = p->next) ;
		
		DListNode *new_node = (DListNode*) malloc (sizeof(DListNode));
		new_node -> data = (Type)data;
		new_node -> next = (void*)0;

		p -> next = new_node;
		thiz -> data ++;
		ret = RET_OK;
	}
	return ret;
}

//在第index个节点前插入节点
Ret dlist_insert(DListNode *thiz, size_t index, void *data) {
	Ret ret = RET_ERR;
	if(thiz != (void*)0 && thiz->data >= index) {
		DListNode *new_node = (DListNode*) malloc (sizeof(DListNode));
		new_node -> data = (Type)data;
		
		DListNode *p = thiz;	//指向new_node前一个节点
		int i = 0;
		for(i = 0; i < index; ++i) {
			p = p -> next;
		}

		new_node -> next = p -> next;	//insert
		p -> next = new_node;

		thiz -> data ++;
		ret = RET_OK;
	}
	return ret;
}

//删除索引为index的节点
Ret dlist_delete(DListNode *thiz, size_t index) {
	Ret ret = RET_ERR;
	if(thiz != (void*)0 && index < thiz->data) {
		DListNode *p = thiz;	//指向删除节点的前一个节点
		int i = 0;
		for(i = 0; i < index; ++i) {
			p = p -> next;
		}

		DListNode *node_to_delete = p -> next;	//delete
		p -> next = node_to_delete -> next;
		free(node_to_delete);

		thiz->data --;
		ret = RET_OK;
	}
	return ret;
}

//返回第index个元素的值
Ret dlist_get_by_index(DListNode *thiz, size_t index, void **data) {
	Ret ret = RET_ERR;
	if(thiz != (void*)0 && index < thiz->data) {
		Type *value = (Type*)data;		//返回值
		DListNode *p = thiz -> next;
		int i = 0;
		for(i = 0; i < index; ++i) {
			p = p -> next;
		}

		*value = p -> data;
		ret = RET_OK;
	}
	return ret;
}

//设置第index个元素的值
Ret dlist_set_by_index(DListNode *thiz, size_t index, void *data) {
	Ret ret = RET_ERR;
	if(thiz != (void*)0 && index < thiz->data) {
		DListNode *p = thiz -> next;
		int i = 0;
		for(i = 0; i < index; ++i) {
			p = p -> next;
		}
		
		p -> data = (Type)data;
		ret = RET_OK;
	}
	return ret;
}

//遍历整个链表
Ret dlist_foreach(DListNode *thiz, DataVisitFunc visit, void *ctx) {
	Ret ret = RET_ERR;
	if(thiz != (void*)0) {
		DListNode *p = thiz;
		for(p = thiz -> next; p != (void*)0 ; p = p -> next) {
			ret = visit((void*)p->data, ctx);

			if(ret != RET_OK) break;
		}
	}
	return ret;
}

//返回链表长度
size_t dlist_length(DListNode *thiz) {
	return thiz->data;
}

//销毁链表
void dlist_destory(DListNode *thiz) {
	DListNode *p = thiz -> next;
	DListNode *node_to_delete = thiz;
	for(p = thiz -> next; p != (void*)0 ; p = p -> next) {
		free(node_to_delete);
		node_to_delete = p;
	}
	free(node_to_delete);
	thiz = (void*)0;
}
