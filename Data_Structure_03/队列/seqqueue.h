#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

#define MAX 1024

typedef void * SeqQueue;

// ��ʼ������

SeqQueue init_SeqQueue();

// ���

void push_SeqQueue(SeqQueue pQueue, void * data);

// ����

void pop_SeqQueue(SeqQueue pQueue);

// ���ض�ͷԪ��

void * front__SeqQueue(SeqQueue pQueue);

// ���ض�βԪ��

void * back__SeqQueue(SeqQueue pQueue);

// ���ض���Ĵ�С

int size_SeqQueue(SeqQueue pQueue);

// ���ٶ���

void destory_SeqQueue(SeqQueue * pQueue);
