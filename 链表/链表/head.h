
#ifndef _SLIST_H_
#define _SLIST_H_

typedef int DataType;

typedef struct SListNode {
	DataType data;
	struct SListNode* next;
}SListNode;

void SListInit(SListNode** pphead);
void SListDestory(SListNode** pphead);

SListNode* BuySListNode(DataType x);
void SListPushFront(SListNode** pphead, DataType x);
void SListPopFront(SListNode** pphead);
void SListInsertAfter(SListNode* pos,DataType x);
void SListEraseAfter(SListNode* pos);
SListNode* SListFind(SListNode* phead, DataType x);
void SListRemove(SListNode** pphead, DataType x);
void SListPrint(SListNode* phead);
void SListReverse(SListNode **pphead);
void SListReverse2(SListNode **pphead);
#endif 
