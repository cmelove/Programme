#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dynamicArray
{
	void ** pAddr;		// 维护在堆区的真实数组指针

	int m_Capacity;		// 数组容量

	int m_Size;			// 数组大小
};

typedef void * DynArray;

// 初始化数组

DynArray init_DynamicArray(int capacity);

// 插入功能

int insert_DynamicArray(DynArray pArray, int pos, void * data);

// 查看功能

void * view_DynamicArray(DynArray pArray, int pos);

// 遍历功能

void foreach_DynamicArray(DynArray pArray, void(*ptr)(void *));

// 删除功能--按位置

void delete_pos_DynamicArray(DynArray pArray, int pos);

// 删除功能--按值

void delete_val_DynamicArray(DynArray pArray, void * data, int (*compare_Element)(void *, void *));

// 元素个数

int getSize_DynamicArray(DynArray pArray);

// 销毁数组

void destory_DynamicArray(DynArray * pArray);
