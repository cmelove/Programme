#include "seqqueue.h"

SeqQueue init_SeqQueue()
{
	return init_DynamicArray(MAX);
}

void push_SeqQueue(SeqQueue pQueue, void * data)
{
	if (NULL == pQueue)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	insert_DynamicArray((DynArray)pQueue, -1, data);

	return;
}

void pop_SeqQueue(SeqQueue pQueue)
{
	if (NULL == pQueue)
	{
		return;
	}

	delete_pos_DynamicArray((DynArray)pQueue, 0);

	return;
}

void * front__SeqQueue(SeqQueue pQueue)
{
	if (NULL == pQueue)
	{
		return NULL;
	}

	return view_DynamicArray((DynArray)pQueue, 0);

}

void * back__SeqQueue(SeqQueue pQueue)
{
	if (NULL == pQueue)
	{
		return NULL;
	}

	int size = getSize_DynamicArray((DynArray)pQueue);

	return view_DynamicArray((DynArray)pQueue, size - 1);
}

int size_SeqQueue(SeqQueue pQueue)
{
	if (NULL == pQueue)
	{
		return -1;
	}

	return getSize_DynamicArray((DynArray)pQueue);
}

void destory_SeqQueue(SeqQueue * pQueue)
{
	destory_DynamicArray((DynArray *)pQueue);
}
