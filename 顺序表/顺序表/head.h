#ifndef  _SEQLIST_H_
#define _SEQLIST_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#define N 100
typedef int DataType;
typedef struct SeqListD
{
	DataType* array; 
	size_t size;
	size_t capacity;
}SeqListD,*PSeqListD;

void InitSeqListD(PSeqListD pSeq)//��ʼ��
{
	pSeq->array = (DataType*)malloc(sizeof(DataType)*N);
	if (NULL == pSeq->array)
		exit(-1);
	pSeq->capacity = N;
	pSeq->size = 0;
}
void CheckCapacity(PSeqListD pSeq)//�������
{
	if (pSeq->size == pSeq->capacity)
	{
		DataType* tmp = (DataType*)realloc(pSeq->array, (pSeq->capacity*2) * sizeof(DataType));
		if (NULL == tmp)
			exit(-1);
		pSeq->array = tmp;
		pSeq->capacity *= 2;
	}
}
void PushBack(PSeqListD pSeq, DataType data)//β��
{
	CheckCapacity(pSeq);
	pSeq->array[pSeq->size] = data;
	pSeq->size += 1;
}
void PopBack(PSeqListD pSeq)//βɾ
{
	if (pSeq->size > 0)
	{
		pSeq->size -= 1;
	}
}
void PopFront(PSeqListD pSeq)//ͷɾ
{
	size_t i = 0;
	for (i = 0; i < pSeq->size - 1; ++i)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size -= 1;
}
void PushFront(PSeqListD pSeq, DataType data)//ͷ��
{
	size_t i = 0;
	CheckCapacity(pSeq);//�������
	for (i = pSeq->size; i > 0; --i)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	pSeq->array[i] = data;
	pSeq->size += 1;
}
void PrintSeqlist(PSeqListD pSeq)//��ӡ
{
	size_t i = 0;
	for (; i < pSeq->size; ++i)
	{
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}

void Erase(PSeqListD pSeq, size_t pos)
{
	size_t i = 0;
	for (i = pos; i < pSeq->size - 1; ++i)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size -= 1;
}
int Find(PSeqListD pSeq, DataType data)//����ֵΪdata��Ԫ��
{
	size_t i = 0;
	for (; i < pSeq->size; ++i)
	{
		if (pSeq->array[i] == data)
			return i;
	}
	return -1;
}

void RemoveAll(PSeqListD pSeq, DataType data)//�Ƴ�����ֵ��ȵ�Ԫ��
{
	size_t i = 0, count = 0;
	for (; i < pSeq->size; ++i)
	{
		if (pSeq->array[i] == data)
		{
			++count;
		}
		else
		{
			pSeq->array[i - count] = pSeq->array[i];
		}
	}
	pSeq->size -= count;
}
void Destroy(PSeqListD pSeqList)//����
{
	if (NULL != pSeqList)
	{
		free(pSeqList->array);
		pSeqList->array = NULL;
		pSeqList->capacity = 0;
		pSeqList->size = 0;
	}
}
void Insert(PSeqListD pSeq, size_t pos, DataType data)//����λ�ò���
{
	size_t i = 0;
	for (i = pSeq->size; i > pos; --i)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	pSeq->array[i] = data;
	pSeq->size += 1;
}

void BubbleSort(PSeqListD pSeq)//ð������
{
	size_t i, j, tmp;
	for (i = 0; i < pSeq->size - 1; ++i)
	{
		for (j = pSeq->size - 1; j > i; --j)
		{
			if (pSeq->array[i] > pSeq->array[j])
			{
				tmp = pSeq->array[i];
				pSeq->array[i] = pSeq->array[j];
				pSeq->array[j] = tmp;
			}
		}
	}
}
void SelectSort(PSeqListD pSeq)//ѡ������
{
	size_t min_num = 0;
	size_t i, j, tmp;
	for (i = 0; i < pSeq->size - 1; ++i)
	{
		min_num = i;
		for (j = i + 1; j < pSeq->size; j++)
		{
			if (pSeq->array[j] < pSeq->array[min_num])
			{
				min_num = j;
			}
		}
		if (min_num != i)
		{
			tmp = pSeq->array[i];
			pSeq->array[i] = pSeq->array[min_num];
			pSeq->array[min_num] = tmp;
		}
	}
}
int BinarySearch(PSeqListD pSeq, DataType data)
{
	size_t left = 0;
	size_t right = pSeq->size - 1;
	size_t mid = 0;
	while (left <= right)
	{
		mid = left + ((right - left) >> 1);
		if (pSeq->array[mid] == data)
		{
			return mid;
		}
		else if (pSeq->array[mid] > data)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return mid;
}

void InsertSearch(PSeqListD pSeq)//��������
{
	
	int target = 0;
	size_t i, j;
	for (i = 1; i < pSeq->size; ++i)
	{
		target = pSeq->array[i];//������
		j = i;
		while (j > 0 && pSeq->array[j - 1] > target)//����
		{
			pSeq->array[j] = pSeq->array[j - 1];
			j--;
		}
		pSeq->array[j] = target;//����
	}
}
#endif
