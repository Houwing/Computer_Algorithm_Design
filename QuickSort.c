#include <stdio.h>

int patition(int arry[], int L, int R){
	int j = L;
	int key = arry[R];//֧��λ�����������һ��
	for (int i = 0; i < R; i++) {
		if (arry[i] < key) {//���arr[i]��֧��С���ͽ����ŵ�֧���������飬��������һ��Ԫ��
			int temp = arry[i];
			arry[i] = arry[j];
			arry[j] = temp;
			j++;
		}
	}
	//֧�����ڱ�j�������̶�֧��λ��
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