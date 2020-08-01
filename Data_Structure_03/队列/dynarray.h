#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dynamicArray
{
	void ** pAddr;		// ά���ڶ�������ʵ����ָ��

	int m_Capacity;		// ��������

	int m_Size;			// �����С
};

typedef void * DynArray;

// ��ʼ������

DynArray init_DynamicArray(int capacity);

// ���빦��

int insert_DynamicArray(DynArray pArray, int pos, void * data);

// �鿴����

void * view_DynamicArray(DynArray pArray, int pos);

// ��������

void foreach_DynamicArray(DynArray pArray, void(*ptr)(void *));

// ɾ������--��λ��

void delete_pos_DynamicArray(DynArray pArray, int pos);

// ɾ������--��ֵ

void delete_val_DynamicArray(DynArray pArray, void * data, int (*compare_Element)(void *, void *));

// Ԫ�ظ���

int getSize_DynamicArray(DynArray pArray);

// ��������

void destory_DynamicArray(DynArray * pArray);
