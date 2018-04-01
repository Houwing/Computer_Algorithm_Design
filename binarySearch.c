#include <stdio.h>
#include <stdlib.h>

int BinarySearch(char array[], const char target, int n) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (array[middle] == target) {
			return middle;
		}
		else if (array[middle] > target) {
			right = middle - 1;
		}
		else {
			left = middle +1;
		}
	}
	return -1;
}

int main(void) {
	char array[4] = { 'a','b','g','w' };//ÔÚarrayÀïÃæÕÒ¡®h¡¯
	char target = 'a';
	int num = 4;
	int t = BinarySearch(array,target,num);
	
	
	if (t==-1) {
		printf("-1");
	}
	else
	{
		printf("%c", array[t]);
	}
	system("pause");

}