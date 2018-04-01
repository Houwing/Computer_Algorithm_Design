#include <stdio.h>
#include <stdlib.h>

void MartixChain(int *p, int n, int m[5][5], int s[5][5]) {
	//p��һ����Ϊ���飬���ڴ洢ÿ�����������
	//n���ڴ洢���ٸ�����
	//m��һ����λ���飬���ڴ洢��i*j�����ټ������
	//s��һ����λ���飬���ڴ洢��ѶϿ�λ��

	for (int i = 1; i<= n; i++)//�Խ��߸�ֵ
		m[i][i] = 0;
	for (int r = 2; r <= n; r++) {
		//��������k,������k=2��ʼ
		for (int i = 1; i <= n - r + 1; i++) {
			//�������
			int j = i + r - 1;
			m[i][j] = m[i+1][j]+p[i-1] * p[i] * p[j];//Ĭ�ϴӵ�һ����
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