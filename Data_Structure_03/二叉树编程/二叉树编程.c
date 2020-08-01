#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct BinaryNode
{
	char ch;		// 数据域

	struct BinaryNode * lChild;			// 左子节点
	struct BinaryNode * rChild;			// 右子节点
};

void calcLeaves(struct BinaryNode * root, int * num)
{
	// 递归的结束条件

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

	// 求出左 右子树高度

	int lHeight = getTreeHeight(root->lChild);
	int rHeight = getTreeHeight(root->rChild);

	// 取左 右子树中 最大值 + 1

	int height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;

	return height;
}

struct BinaryNode * copyBinaryNode(struct BinaryNode * root)
{
	if (NULL == root)
	{
		return NULL;
	}

	// 先拷贝左子树

	struct BinaryNode * lChild = copyBinaryNode(root->lChild);

	// 再拷贝右子树

	struct BinaryNode * rChild = copyBinaryNode(root->rChild);

	// 再创建新节点

	struct BinaryNode * newNode = (struct BinaryNode *)malloc(sizeof(struct BinaryNode));

	if (NULL == newNode)
	{
		return NULL;
	}

	newNode->lChild = lChild;
	newNode->rChild = rChild;

	newNode->ch = root->ch;

	// 返回给用户

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

	// 建立节点之间的关系

	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	// 1. 求书中的叶子数量

	int num = 0;

	calcLeaves(&nodeA, &num);

	printf("Leaves = %d\n", num);

	// 2. 求数的高度

	int height = getTreeHeight(&nodeA);

	printf("Height = %d\n", height);

	// 3. 拷贝二叉树

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