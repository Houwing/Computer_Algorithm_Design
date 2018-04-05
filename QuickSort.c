#include <stdio.h>

int patition(int arry[], int L, int R){
	int j = L;
	int key = arry[R];//支点位置是数组最后一个
	for (int i = 0; i < R; i++) {
		if (arry[i] < key) {//如果arr[i]比支点小，就交换放到支点的左侧数组，否则检查下一个元素
			int temp = arry[i];
			arry[i] = arry[j];
			arry[j] = temp;
			j++;
		}
	}
	//支点与哨兵j交换，固定支点位置
	int temp = arry[j];
	arry[j] = arry[R];
	arry[R] = temp;
	return j;
}
void quickSort(int arry[], int L,int R){
	
	if (L < R) {
		int M = patition(arry, L, R);
		quickSort(arry, L, M - 1);
		quickSort(arry, M + 1, R);
	}
	
}
int main(void) {
	int arry[] = { 3,8,1,2,5,4 };
	patition(arry, 0, 5);
	quickSort(arry, 0, 5);

	for (int i = 0; i < 6; i++) {
		printf("%d ", arry[i]);
	}

	system("pause");
}