#include <stdio.h>
#include <stdlib.h>

struct Arr{
	int len;
	int cnt;
	int *pBase;
};

void init_arr(struct Arr * pArr, int lenth);
bool is_full(struct Arr * pArr);
bool is_empty(struct Arr * pArr);
void append_arr(struct Arr * pArr, int val);
void show(struct Arr * pArr);
bool insert_arr(struct Arr * pArr,int pos,int val);
bool delete_arr(struct Arr * pArr,int pos,int *pVal);
void inversion_arr(struct Arr * pArr);
void bubble_sort(struct Arr * pArr);

int main()
{
	struct Arr arr;
	int val;
	
	init_arr(&arr,6);
	append_arr(&arr, 6);
	append_arr(&arr, 1);
	append_arr(&arr, 4);
	append_arr(&arr, 2);
	insert_arr(&arr,2,5);

	if ( delete_arr(&arr, 1, &val) )
	{
		printf("删除成功!\n");
		printf("您删除的元素是: %d\n", val);
	}
	else
	{
		printf("删除失败!\n");
	}
	inversion_arr(&arr);
	show(&arr);
	bubble_sort(&arr);
	show(&arr);
} 

void init_arr(struct Arr * pArr,int lenth)
{
	pArr->pBase = (int *) malloc (sizeof (int) * lenth);
	//待改进，判断是否分配成功 
	if (pArr->pBase == NULL)
	{
		printf("it is failed");
		exit(-1);
	}
	else
	{
		pArr->len = lenth;
		pArr->cnt = 0;
	}

}

bool is_full(struct Arr * pArr)
{
	if (pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

bool is_empty(struct Arr * pArr)
{
	if ( pArr->cnt == 0 )
		return true;
	else
		return false;
}

void append_arr(struct Arr * pArr, int val)
{
	if (is_full(pArr))
		printf("it is full\n");
	else {
	
		pArr->pBase[pArr->cnt] = val;
		(pArr->cnt)++;
	}
	
}

void show(struct Arr * pArr)
{
	if (is_empty(pArr))
		printf("it is empty");
	else
		for (int i = 0; i<pArr->cnt;i++)
		{
			printf("%d ",pArr->pBase[i]);
			
		}
		printf("\n");
}

bool insert_arr(struct Arr * pArr,int pos,int val)
{
	if (is_full(pArr))
		return false;
	if (pos<1 || pos > pArr->cnt+1)
		return false;
	
	for (int i=pArr->cnt-1;i>=pos-1;--i)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	
	pArr->pBase[pos - 1] = val;
	pArr->cnt++;
	
	return true;
	
}

bool delete_arr(struct Arr * pArr,int pos,int *pVal)
{
	int i;
	
	if (is_empty(pArr))
		return false;
	if (pos<1 || pos>pArr->cnt)
		return false;
	
	*pVal = pArr->pBase[pos - 1];
	
	for (i=pos;i<pArr->cnt;i++)
	{
		pArr->pBase[i-1] =  pArr->pBase[i];
	}
	pArr->cnt--;
	return true;
}

void inversion_arr(struct Arr * pArr)
{
	int i = 0;
	int j = pArr->cnt-1;
	int temp;
	
	while (i<j)
	{
		temp = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = temp;
		i++;
		--j;
	}
	
	return;
}

void bubble_sort(struct Arr * pArr)
{
	int i,j;
	int temp;
	for (i = 0;i<pArr->cnt;i++)
	{
		for (j = i+1;j < pArr->cnt;j++)
		{
			if (pArr->pBase[i]>pArr->pBase[j])
			{
				temp = pArr->pBase[j];
                pArr->pBase[j] = pArr->pBase[i];
                pArr->pBase[i] = temp;
			}
		}
	}
}



