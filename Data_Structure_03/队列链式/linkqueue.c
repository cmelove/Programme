#include "linkqueue.h"

struct QueueNode
{
	struct QueueNode * next;
};

struct LQueue
{
	struct QueueNode pHead;

	int m_Size;

	struct QueueNode *pTail;
};

LinkQueue init_LinkQueue()
{
	struct LQueue * pQueue = (struct LQueue *)malloc(sizeof(struct LQueue));

	if (NULL == pQueue)
	{
		return NULL;
	}

	pQueue->pHead.next = NULL;
	pQueue->pTail = &pQueue->pHead;
	pQueue->m_Size = 0;

	return pQueue;
}

void  push_LinkQueue(LinkQueue pQueue, void * data)
{
	if (NULL == pQueue)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	struct LQueue * queue = (struct LQueue *)pQueue;

	struct QueueNode * newNode = (struct QueueNode *)data;

	newNode->next = NULL;

	queue->pTail->next = newNode;

	queue->pTail = newNode;

	queue->m_Size++;

	return;
}

void  pop_LinkQueue(LinkQueue pQueue)
{
	if (NULL == pQueue)
	{
		return;
	}

	struct LQueue * queue = (struct LQueue *)pQueue;

	if (0 == queue->m_Size)
	{
		return NULL;
	}
	
	struct QueueNode * pCurrent = &queue->pHead;

	struct QueueNode * pDelete = pCurrent->next;

	pCurrent->next = pDelete->next;

	queue->m_Size--;
	
	if (0 == queue->m_Size)
	{
		queue->pHead.next = NULL;		
		queue->pTail = &queue->pHead;
	}
}

void * front_LinkQueue(LinkQueue pQueue)
{
	if (NULL == pQueue)
	{
		return NULL;
	}

	struct LQueue * queue = (struct LQueue *)pQueue;

	if (0 == queue->m_Size)
	{
		return NULL;
	}
	
	return queue->pHead.next;
}


void * back_LinkQueue(LinkQueue pQueue)
{
	if (NULL == pQueue)
	{
		return NULL;
	}

	struct LQueue * queue = (struct LQueue *)pQueue;

	if (0 == queue->m_Size)
	{
		return NULL;
	}

	return queue->pTail;
}

int getSize_LinkQueue(LinkQueue pQueue)
{
	if (NULL == pQueue)
	{
		return -1;
	}

	struct LQueue * queue = (struct LQueue *)pQueue;

	return queue->m_Size;
}

void destory_LinkQueue(LinkQueue * pQueue)
{
	if (NULL == pQueue)
	{
		return;
	}

	if (NULL == *pQueue)
	{
		return;
	}

	free(*pQueue);
	*pQueue = NULL;
}