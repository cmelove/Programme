#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



typedef void * LinkQueue;

// ��ʼ��

LinkQueue init_LinkQueue();

// ���

void  push_LinkQueue(LinkQueue pQueue,void * data);

// ����

void  pop_LinkQueue(LinkQueue pQueue);

// ���ض�ͷ

void * front_LinkQueue(LinkQueue pQueue);

// ���ض�β

void * back_LinkQueue(LinkQueue pQueue);

// ��������

int getSize_LinkQueue(LinkQueue pQueue);

// ���ٶ���

void destory_LinkQueue(LinkQueue * pQueue);