#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct BinaryNode
{
	char ch;		// ������

	struct BinaryNode * lChild;			// ���ӽڵ�
	struct BinaryNode * rChild;			// ���ӽڵ�
};

void calcLeaves(struct BinaryNode * root, int * num)
{
	// �ݹ�Ľ�������

	if (NULL == root)
	{
		return;
	}

	if (NULL == root->lChild&&NULL == root->rChild)
	{
		(*num)++;
	}
	calcLeaves(root->lChild, num);
	calcLeaves(root->rChild, num);

	return;
}

int getTreeHeight(struct BinaryNode * root)
{
	if (NULL == root)
	{
		return 0;
	}

	// ����� �������߶�

	int lHeight = getTreeHeight(root->lChild);
	int rHeight = getTreeHeight(root->rChild);

	// ȡ�� �������� ���ֵ + 1

	int height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;

	return height;
}

struct BinaryNode * copyBinaryNode(struct BinaryNode * root)
{
	if (NULL == root)
	{
		return NULL;
	}

	// �ȿ���������

	struct BinaryNode * lChild = copyBinaryNode(root->lChild);

	// �ٿ���������

	struct BinaryNode * rChild = copyBinaryNode(root->rChild);

	// �ٴ����½ڵ�

	struct BinaryNode * newNode = (struct BinaryNode *)malloc(sizeof(struct BinaryNode));

	if (NULL == newNode)
	{
		return NULL;
	}

	newNode->lChild = lChild;
	newNode->rChild = rChild;

	newNode->ch = root->ch;

	// ���ظ��û�

	return newNode;
}

void showBinaryNode(struct BinaryNode * root)
{
	if (NULL == root)
	{
		return;
	}

	printf("%c ", root->ch);

	showBinaryNode(root->lChild);
	showBinaryNode(root->rChild);

}

void test01()
{
	struct BinaryNode nodeA = { .ch = 'A',.lChild = NULL,.rChild = NULL };
	struct BinaryNode nodeB = { .ch = 'B',.lChild = NULL,.rChild = NULL };
	struct BinaryNode nodeC = { .ch = 'C',.lChild = NULL,.rChild = NULL };
	struct BinaryNode nodeD = { .ch = 'D',.lChild = NULL,.rChild = NULL };
	struct BinaryNode nodeE = { .ch = 'E',.lChild = NULL,.rChild = NULL };
	struct BinaryNode nodeF = { .ch = 'F',.lChild = NULL,.rChild = NULL };
	struct BinaryNode nodeG = { .ch = 'G',.lChild = NULL,.rChild = NULL };
	struct BinaryNode nodeH = { .ch = 'H',.lChild = NULL,.rChild = NULL };

	// �����ڵ�֮��Ĺ�ϵ

	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	// 1. �����е�Ҷ������

	int num = 0;

	calcLeaves(&nodeA, &num);

	printf("Leaves = %d\n", num);

	// 2. �����ĸ߶�

	int height = getTreeHeight(&nodeA);

	printf("Height = %d\n", height);

	// 3. ����������

	struct BinaryNode * newTree = copyBinaryNode(&nodeA);

	showBinaryNode(newTree);

	puts("");
}

int main(void)
{
	test01();


	system("pause");

	return 0;
}