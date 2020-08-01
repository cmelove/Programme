#include "seqstack.h"

#define MAX 1024


struct SStack
{
	void * data[MAX];

	int m_Size;
};



SeqStack init_SeqStack()
{
	struct SStack * pStack = (struct SStack *)malloc(sizeof(struct SStack));

	if (NULL == pStack)
	{
		return NULL;
	}


	memset(pStack, 0, sizeof(struct SStack));

	return pStack;
}

void push_SeqStack(SeqStack pStack, void * data)
{
	if (NULL == pStack)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	struct SStack * stack = (struct SStack *)pStack;

	if (stack->m_Size == MAX)
	{
		return;
	}

	stack->data[stack->m_Size] = data;

	stack->m_Size++;
}

void pop_SeqStack(SeqStack pStack)
{
	if (NULL == pStack)
	{
		return;
	}

	struct SStack * stack = (struct SStack *)pStack;

	if (0 == stack->m_Size)
	{
		return;
	}

	stack->data[stack->m_Size - 1] = NULL;

	stack->m_Size--;

	return;
}

int getSize_SeqStack(SeqStack pStack)
{
	if (NULL == pStack)
	{
		return -1;
	}

	struct SStack * stack = (struct SStack *)pStack;

	return stack->m_Size;
}

int isEmpty_SeqStack(SeqStack pStack)
{
	if (NULL == pStack)
	{
		return -1;
	}

	struct SStack * stack = (struct SStack *)pStack;

	return stack->m_Size > 0;
}

void destory_SeqStack(SeqStack * pStack)
{
	if (NULL == pStack)
	{
		return;
	}

	if (NULL == *pStack)
	{
		return;
	}

	free(*pStack);

	*pStack = NULL;

	return;
}

void * top_SeqStack(SeqStack pStack)
{
	if (NULL == pStack)
	{
		return NULL;
	}

	struct SStack * stack = (struct SStack *)pStack;

	if (0 == stack->m_Size)
	{
		return NULL;
	}

	return stack->data[--stack->m_Size];
}