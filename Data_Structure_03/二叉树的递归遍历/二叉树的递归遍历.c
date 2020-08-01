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

void recursion(struct BinaryNode * root)
{
	if (NULL == root)
	{
		return;
	}

	// 先序遍历	-- 根 左 右

	recursion(root->lChild);

	recursion(root->rChild);

	printf("%c ", root->ch);
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

	// 递归遍历

	recursion(&nodeA);

	puts("");
}


int main(void)
{
	test01();

	system("pause");

	return 0;
}