#include"SeqList.h"
void SeqListInit(SL* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType)*4);
	if (ps->a == NULL)
	{
		printf("ÄÚ´æÉêÇëÊ§°Ü\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d",ps->a[i]);
	}
	printf("\n");
}
void SeqListCheckCapacity(SL* ps)
{
	SLDataType* b;
	assert(ps);
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		b = (SLDataType*)realloc(ps->a,sizeof(SLDataType) * (ps->capacity));
	
		if (b == NULL)
		{
			printf("À©ÈÝÊ§°Ü");
			exit(-1);
		}
		else
			ps->a = b;
	}
}


//Î²²åÎ²É¾
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;

}
void SeqListPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}

//Í·²åÍ·É¾
void SeqListPushFront(SL* ps, SLDataType x)
{
	int end = ps->size-1;
	assert(ps);
	SeqListCheckCapacity(ps);

	while (end>=0)
	{
		ps->a[end+1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
	
}
void SeqListPopFront(SL* ps)
{
	assert(ps);
	SeqListCheckCapacity(ps);

	int start = 0;
	ps->size--;
	while (start<=ps->size-1)
	{
		ps->a[start] = ps->a[start+1];
		start++;
	}


}
//Ä³Î»ÖÃ²åÉ¾
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos<ps->size);
	SeqListCheckCapacity(ps);
	int ret = ps->size-1;
	while(ret >= pos)
	{
		ps->a[ret + 1] = ps->a[ret];
		ret--;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos < ps->size&& pos >= 0);
	int start = pos;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start+1];
		start++;
	}
	ps->size--;
}
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	while (i < ps->size)
	{
		if (ps->a[i] == x)
			return i;
		i++;
	}
	return -1;
}


