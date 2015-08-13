/*************************************************************************
	> File Name: darray.h
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月13日 星期四 14时05分13秒
 ************************************************************************/


/******************************************************************
 * 动态数组 
 * 功能：
 *		 DArray *darray_create(void*);
 *		 Ret darray_create_by_array(DArray *thiz, void **array, size_t lenth);
 *		 Ret darray_insert(DArray *thiz, size_t index, void* data);
 *		 Ret darray_prepend(DArray *thiz, void *data);
 *		 Ret darray_append(DArray *thiz, void *data);
 *		 Ret darray_delete(DArray *thiz, size_t index);
 *		 Ret darray_get_by_index(DArray *thiz, size_t index, void **data);
 *		 Ret darray_set_by_index(DArray *thiz, size_t index, void *data);
 *		 Ret darray_find(DArray *thiz, DataCompareFunc cmp, void* ctx);
 *		 Ret darray_foreach(DArray *thiz, DataVisitFunc visit, void *ctx);
 *		 size_t darray_length(DArray *thiz);
 *		 void darray_destroy(DArray *thiz);
 * ***************************************************************/

#ifndef _DARRAY_H_
#define _DARRAY_H_

#define RET_OK 0		//正确
#define RET_ERR	-1		//返回错误
#define RET_ERR_ARG	-2	//参数错误
#define MALL_ERR -3		//分配空间错误
#define NOT_FOUND 1		//没有查找结果

#define INITSPACE 5		//初始大小

typedef int Type;	//类型
typedef int Ret;	//返回结果

struct _DArray {
	Type *data;
	size_t length;
	size_t capacity;
};
typedef struct _DArray DArray;

typedef unsigned int size_t;

typedef Ret (*DataCompareFunc) (void *, void *);
typedef Ret (*DataVisitFunc) (void *, void *);

DArray *darray_create(void);
Ret darray_create_by_array(DArray *thiz, void **array, size_t length);
Ret darray_insert(DArray *thiz, size_t index, void* data);
Ret darray_prepend(DArray *thiz, void *data);
Ret darray_append(DArray *thiz, void *data);
Ret darray_delete(DArray *thiz, size_t index);
Ret darray_get_by_index(DArray *thiz, size_t index, void **data);
Ret darray_set_by_index(DArray *thiz, size_t index, void *data);
Ret darray_find(DArray *thiz, DataCompareFunc cmp, void* ctx);
Ret darray_foreach(DArray *thiz, DataVisitFunc visit, void *ctx);
size_t darray_length(DArray *thiz);
void darray_destroy(DArray *thiz);

#endif
