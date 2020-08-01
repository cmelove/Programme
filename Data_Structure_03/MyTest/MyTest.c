#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct LeafNode
{
	char ch;

	struct LeafNode * lChild;
	struct LeafNode * rChild;
};

void foreach(struct LeafNode * root)
{
	if (NULL == root)
	{
		return;
	}

	printf("%c ", root->ch);

	foreach(root->lChild);
	foreach(root->rChild);

	return;
}

void countLeaves(struct LeafNode * root, int * num)
{
	if (NULL == root)
	{
		return;
	}
	if (NULL == root->lChild&&NULL == root->rChild)
	{
		(*num)++;
	}
	countLeaves(root->lChild, num);
	countLeaves(root->rChild, num);
	return;
}

int  counHeight(struct LeafNode * root)
{
	if (NULL == root)
	{
		return 0;
	}

	int lHeight = counHeight(root->lChild);
	int rHeight = counHeight(root->rChild);

	return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
}

struct LeafNode * copyLeaves(struct LeafNode * root)
{
	if (NULL == root)
	{
		return NULL;
	}

	struct LeafNode * lChild = copyLeaves(root->lChild);
	struct LeafNode * rChild = copyLeaves(root->rChild);

	struct LeafNode * newLeaf = (struct LeafNode *)malloc(sizeof(struct LeafNode));

	if (NULL == newLeaf)
	{
		return NULL;
	}

	newLeaf->ch = root->ch;
	newLeaf->lChild = lChild;
	newLeaf->rChild = rChild;

	return newLeaf;
}

void freeLeaves(struct LeafNode * root)
{
	if (NULL == root)
	{
		return;
	}

	freeLeaves(root->lChild);
	freeLeaves(root->rChild);

	free(root);	
	root = NULL;
}

void test01()
{
	struct LeafNode nodeA = { .ch = 'A',.lChild = NULL,.rChild = NULL };
	struct LeafNode nodeB = { .ch = 'B' ,.lChild = NULL,.rChild = NULL };
	struct LeafNode nodeC = { .ch = 'C',.lChild = NULL,.rChild = NULL };
	struct LeafNode nodeD = { .ch = 'D',.lChild = NULL,.rChild = NULL };
	struct LeafNode nodeE = { .ch = 'E' ,.lChild = NULL,.rChild = NULL };
	struct LeafNode nodeF = { .ch = 'F',.lChild = NULL,.rChild = NULL };
	struct LeafNode nodeG = { .ch = 'G',.lChild = NULL,.rChild = NULL };
	struct LeafNode nodeH = { .ch = 'H',.lChild = NULL,.rChild = NULL };

	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	foreach(&nodeA);

	puts("");

	int num = 0;

	countLeaves(&nodeA, &num);

	printf("num = %d\n", num);

	int height = counHeight(&nodeA);

	printf("height = %d\n", height);

	struct LeafNode * newRoot = copyLeaves(&nodeA);

	foreach(newRoot);

	puts("");

	freeLeaves(newRoot);

}

int main(void)
{
	test01();

	system("pause");

	return 0;
}