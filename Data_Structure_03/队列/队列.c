#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "seqqueue.h"

struct Codec
{
	int length;

	char buf[32];
};

void show_Element(void * data)
{
	if (NULL == data)
	{
		return;
	}

	struct Codec * code = (struct Codec *)data;

	printf("%d\t%s\n", code->length, code->buf);
}

int main(void)
{
	SeqQueue pQueue = init_SeqQueue();

	if (NULL == pQueue)
	{
		printf("init_SeqQueue Failed\n");

		return -1;
	}
	
	push_SeqQueue(pQueue, (void *)&(struct Codec) {10, "Monday"	});
	push_SeqQueue(pQueue, (void *)&(struct Codec) { 20, "Tuesday" });
	push_SeqQueue(pQueue, (void *)&(struct Codec) { 30, "Wednesday" });
	push_SeqQueue(pQueue, (void *)&(struct Codec) { 40, "Thursday" });
	push_SeqQueue(pQueue, (void *)&(struct Codec) { 50, "Friday" });
	
	printf("Size = %d\n", size_SeqQueue(pQueue));

	show_Element(front__SeqQueue(pQueue));

	show_Element(back__SeqQueue(pQueue));

	printf("===========================\n");

	pop_SeqQueue(pQueue);

	printf("Size = %d\n", size_SeqQueue(pQueue));

	show_Element(front__SeqQueue(pQueue));

	show_Element(back__SeqQueue(pQueue));

	destory_SeqQueue(&pQueue);

	system("pause");

	return 0;
}