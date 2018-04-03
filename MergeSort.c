#include <stdio.h>
#include <stdlib.h>


void Merge(int a[], int left, int middle, int right, int temp[]) {
	//合并a[l:m] & a[m+1:r]to temp[l:r]
	int i = left, j = middle + 1, k = left;
	while ((i <= middle) && (j <= right)) {
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	if (i > middle)//左边结束
		for (int q = j; q <= right; q++)
			temp[k++] = a[q];
	else//右边结束
		for (int q = i; q <= middle; q++)
			temp[k++] = a[q];
	
}
void Copy(int a[], int temp[], int left, int right) {
	for (int i = left; i <= right ; i++) {
		a[i] = temp[i];
	}
}
void MergeSort(int a[], int left, int right,int temp[]) {
	
	if (left < right) {
		//保证至少有个元素
		int middle = (left + right) / 2;//取中点
		MergeSort(a, left, middle,temp);
		MergeSort(a, middle + 1, right,temp);
		Merge(a, left, middle, right,temp);
		Copy(a,temp,left,right);
	}
}




void Print(int a[],int len)
{
	for (int i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(void) {
	int array[10] = {5,74,24,71,13,2,1,63 };
	//int array[10] = { 1, 24, 55,66, 2,23,45,78 };
	int temp[10];
	Print(array, 8);
	MergeSort(array, 0, 7,temp);
	Print(array, 8);
	system("pause");
}