#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

#define MAX 1024

typedef void * SeqQueue;

// 初始化队列

SeqQueue init_SeqQueue();

// 入队

void push_SeqQueue(SeqQueue pQueue, void * data);

// 出队

void pop_SeqQueue(SeqQueue pQueue);

// 返回队头元素

void * front__SeqQueue(SeqQueue pQueue);

// 返回队尾元素

void * back__SeqQueue(SeqQueue pQueue);

// 返回队伍的大小

int size_SeqQueue(SeqQueue pQueue);

// 销毁队列

void destory_SeqQueue(SeqQueue * pQueue);
