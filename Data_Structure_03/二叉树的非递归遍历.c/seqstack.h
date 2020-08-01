#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void * SeqStack;


// ��ʼ��ջ

SeqStack init_SeqStack();

// ��ջ

void push_SeqStack(SeqStack pStack, void * data);

// ��ջ

void pop_SeqStack(SeqStack pStack);

// ��ȡջ��Ԫ��

void * top_SeqStack(SeqStack pStack);

// ��ȡջ�Ĵ�С

int getSize_SeqStack(SeqStack pStack);

// �ж��Ƿ�Ϊ��

int isEmpty_SeqStack(SeqStack pStack);

// ����ջ

void destory_SeqStack(SeqStack * pStack);
