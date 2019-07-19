#include<stdio.h>
#include"head.h"
int main()
{
	SeqListD p;
	InitSeqListD(&p);

	PushBack(&p, 1);



	PushBack(&p, 2);
	PushBack(&p, 3);
	PushBack(&p, 4);
	PrintSeqlist(&p);

	PopBack(&p);
	PrintSeqlist(&p);

	PushFront(&p, 4);
	PushFront(&p, 5);
	PrintSeqlist(&p);

	PopFront(&p);
	PrintSeqlist(&p);

	Insert(&p, 2, 6);
	PrintSeqlist(&p);

	Erase(&p, 2);
	PrintSeqlist(&p);

	BinarySearch(&p, 3);
	system("pause");
	return 0;
}