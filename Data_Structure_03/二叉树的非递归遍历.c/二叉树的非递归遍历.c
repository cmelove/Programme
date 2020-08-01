#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "seqstack.h"

struct BinaryNode
{
	char ch;		// ������

	struct BinaryNode * lChild;			// ���ӽڵ�
	struct BinaryNode * rChild;			// ���ӽڵ�

	int flag;			// ��ʶ
};

void nonRecursion(struct BinaryNode * root)
{
	// ��ʼ��ջ

	SeqStack pStack = init_SeqStack();

	if (NULL == pStack)
	{
		printf("init_SeqStack Failed\n");
		return;
	}

	push_SeqStack(pStack, root);

	while (getSize_SeqStack(pStack) > 0)
	{
		struct BinaryNode * node = (struct BinaryNode *)top_SeqStack(pStack);

		if (1 == node->flag)
		{
			printf("%c ", node->ch);
			continue;
		}
		else
		{
			node->flag = 1;

			if (node->rChild)
				push_SeqStack(pStack, node->rChild);

			if (node->lChild)
				push_SeqStack(pStack, node->lChild);

			push_SeqStack(pStack, node);
		}
	}

	puts("");

	// ����ջ

	destory_SeqStack(&pStack);
}

void test01()
{
	struct BinaryNode nodeA = { .ch = 'A',.lChild = NULL,.rChild = NULL,.flag = 0 };
	struct BinaryNode nodeB = { .ch = 'B',.lChild = NULL,.rChild = NULL ,.flag = 0 };
	struct BinaryNode nodeC = { .ch = 'C',.lChild = NULL,.rChild = NULL,.flag = 0 };
	struct BinaryNode nodeD = { .ch = 'D',.lChild = NULL,.rChild = NULL,.flag = 0 };
	struct BinaryNode nodeE = { .ch = 'E',.lChild = NULL,.rChild = NULL ,.flag = 0 };
	struct BinaryNode nodeF = { .ch = 'F',.lChild = NULL,.rChild = NULL ,.flag = 0 };
	struct BinaryNode nodeG = { .ch = 'G',.lChild = NULL,.rChild = NULL,.flag = 0 };
	struct BinaryNode nodeH = { .ch = 'H',.lChild = NULL,.rChild = NULL,.flag = 0 };

	// �����ڵ�֮��Ĺ�ϵ

	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	// ִ�зǵݹ�ı���

	nonRecursion(&nodeA);
}

int main(void)
{
	test01();

	system("pause");

	return 0;
}