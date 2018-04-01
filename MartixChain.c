#include <stdio.h>
#include <stdlib.h>

void MartixChain(int *p, int n, int m[5][5], int s[5][5]) {
	//p是一个以为数组，用于存储每个矩阵的列数
	//n用于存储多少个矩阵
	//m是一个二位数组，用于存储从i*j的最少计算次数
	//s是一个二位数组，用于存储最佳断开位置

	for (int i = 1; i<= n; i++)//对角线赋值
		m[i][i] = 0;
	for (int r = 2; r <= n; r++) {
		//设置链长k,从链长k=2开始
		for (int i = 1; i <= n - r + 1; i++) {
			//设置起点
			int j = i + r - 1;
			m[i][j] = m[i+1][j]+p[i-1] * p[i] * p[j];//默认从第一个断
			s[i][i] = i;
			for (int k = i + 1;k < j; k++) {
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[j] * p[k];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}

int main(void) {
	int p[5] = { 3,5,8,4,2 };
	int n = 4;
	int m[5][5] = { 0 };
	int s[5][5] = { 0 };
	MartixChain(p, n, m, s);
	for (int i = 0; i <=n; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%d         ", m[i][j]);
		}
		printf("\n");
	}
	system("pause");
}