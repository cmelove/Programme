#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void * SeqStack;


// 初始化栈

SeqStack init_SeqStack();

// 入栈

void push_SeqStack(SeqStack pStack, void * data);

// 出栈

void pop_SeqStack(SeqStack pStack);

// 获取栈顶元素

void * top_SeqStack(SeqStack pStack);

// 获取栈的大小

int getSize_SeqStack(SeqStack pStack);

// 判断是否为空

int isEmpty_SeqStack(SeqStack pStack);

// 销毁栈

void destory_SeqStack(SeqStack * pStack);
