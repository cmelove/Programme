#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "linkqueue.h"

struct Codec
{
	struct Codec * addr;

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

	LinkQueue pQueue=  init_LinkQueue();

	if (NULL == pQueue)
	{
		printf("init_LinkQueue Failed\n");
		return -1;
	}
	
	push_LinkQueue(pQueue, (void *)&(struct Codec) {NULL, 10, "Monday" });
	push_LinkQueue(pQueue,(void *)&(struct Codec) { NULL,20, "Tuesday" });
	push_LinkQueue(pQueue, (void *)&(struct Codec) {NULL, 30, "Wednesday" });
	push_LinkQueue(pQueue, (void *)&(struct Codec) {NULL, 40, "Thursday" });
	push_LinkQueue(pQueue, (void *)&(struct Codec) {NULL, 50, "Friday" });

	int size = getSize_LinkQueue(pQueue);

	printf("Size = %d\n", size);

	show_Element(front_LinkQueue(pQueue));
	show_Element(back_LinkQueue(pQueue));

	pop_LinkQueue(pQueue);
	pop_LinkQueue(pQueue);

	push_LinkQueue(pQueue, (void *)&(struct Codec) { NULL, 60, "Saturday" });
	push_LinkQueue(pQueue, (void *)&(struct Codec) { NULL, 70, "Sunday" });


	printf("===================\n");

	size = getSize_LinkQueue(pQueue);

	printf("Size = %d\n", size);

	show_Element(front_LinkQueue(pQueue));
	show_Element(back_LinkQueue(pQueue));

	destory_LinkQueue(&pQueue);

	printf("addr = %x\n", pQueue);

	system("pause");

	return 0;
}