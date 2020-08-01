#include "DynArray.h"

DynArray init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}

	struct dynamicArray * pArray = NULL;

	pArray = (struct dynamicArray *)malloc(sizeof(struct dynamicArray));

	if (NULL == pArray)
	{
		printf("Allocate Array Failed\n");
		return NULL;
	}

	pArray->pAddr = (void **)malloc(sizeof(void *)*capacity);

	memset(pArray->pAddr, 0, sizeof(void *)*capacity);

	pArray->m_Capacity = capacity;

	pArray->m_Size = 0;

	return pArray;
}

int insert_DynamicArray(DynArray pArray, int pos, void * data)
{
	if (NULL == pArray)
	{
		return -1;
	}

	struct dynamicArray * array = (struct dynamicArray *)pArray;

	if (pos < 0 || pos>array->m_Size)
	{
		// 无效的位置 进行尾插

		pos = array->m_Size;
	}

	if (NULL == data)
	{
		return -1;
	}

	if (array->m_Size >= array->m_Capacity)
	{
		void ** pTemp = (void **)malloc(sizeof(void *)*(array->m_Capacity + 10));

		if (NULL == pTemp)
		{
			printf("Allocate Mem Failed\n");
			return -1;
		}

		memset(pTemp, 0, sizeof(void *)*(array->m_Capacity + 10));

		memcpy(pTemp, array->pAddr, sizeof(void *)*array->m_Capacity);

		free(array->pAddr);

		array->pAddr = pTemp;

		pTemp = NULL;

		array->m_Capacity += 10;

	}

	for (int i = array->m_Size;i > pos;--i)
	{
		array->pAddr[i] = array->pAddr[i - 1];
	}

	array->pAddr[pos] = data;

	array->m_Size++;

	return 0;
}

void * view_DynamicArray(DynArray pArray, int pos)
{
	if (NULL == pArray)
	{
		return NULL;
	}

	struct dynamicArray * array = (struct dynamicArray *)pArray;

	if (pos < 0 || pos>array->m_Size - 1)
	{
		// 无效的位置 进行查看

		return NULL;
	}

	return array->pAddr[pos];
}

void foreach_DynamicArray(DynArray pArray, void(*ptr)(void *))
{
	if (NULL == pArray)
	{
		return;
	}

	if (NULL == ptr)
	{
		return;
	}

	struct dynamicArray * array = (struct dynamicArray *)pArray;

	for (int i = 0;i < array->m_Size;++i)
	{
		ptr(array->pAddr[i]);
	}

}

void delete_pos_DynamicArray(DynArray pArray, int pos)
{
	if (NULL == pArray)
	{
		return;
	}

	struct dynamicArray * array = (struct dynamicArray *)pArray;

	if (pos<0 || pos>array->m_Size - 1)
	{
		// 无效的位置 直接return
		return;
	}

	for (int i = pos;i < array->m_Size - 1;++i)
	{
		array->pAddr[i] = array->pAddr[i + 1];
	}
	array->m_Size--;

	return;
}

void delete_val_DynamicArray(DynArray pArray, void * data, int(*compare_Element)(void *, void *))
{
	if (NULL == pArray)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	struct dynamicArray * array = (struct dynamicArray *)pArray;

	int pos;

	for (pos = 0;pos < array->m_Size;++pos)
	{
		if (compare_Element(array->pAddr[pos], data))
		{
			delete_pos_DynamicArray(array, pos);
			break;
		}
	}
	return;
}

int getSize_DynamicArray(DynArray pArray)
{
	if (NULL == pArray)
	{
		return;
	}

	struct dynamicArray * array = (struct dynamicArray *)pArray;

	return array->m_Size;
}

void destory_DynamicArray(DynArray * pArray)
{
	if (NULL == pArray)
	{
		return;
	}

	if (NULL == *pArray)
	{
		return;
	}

	free(*pArray);

	*pArray = NULL;

}