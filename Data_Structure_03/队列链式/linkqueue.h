#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



typedef void * LinkQueue;

// 初始化

LinkQueue init_LinkQueue();

// 入队

void  push_LinkQueue(LinkQueue pQueue,void * data);

// 出队

void  pop_LinkQueue(LinkQueue pQueue);

// 返回队头

void * front_LinkQueue(LinkQueue pQueue);

// 返回队尾

void * back_LinkQueue(LinkQueue pQueue);

// 返回数量

int getSize_LinkQueue(LinkQueue pQueue);

// 销毁队列

void destory_LinkQueue(LinkQueue * pQueue);