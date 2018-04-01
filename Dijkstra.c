#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXINT 10000

void Dijkstra(int n, int v, int dist[], int prev[], int c[5][5]) {
	//��Ԫ���·�������dijkstra�㷨

	bool s[5];//�Ƿ��㼯
	for (int i = 0; i < n; i++) {//��ʼ����㼯
		dist[i] = c[v][i];//ˢ��dist�е�·������
		s[i] = false;
		if (dist[i] == MAXINT)//ˢ��ǰ���ڵ�
			prev[i] = 0;
		else
			prev[i] = v;
	}
	for (int j = 0; j < 5; j++)
	{
		printf("%d ", dist[j]);
	}

	dist[v] = 0;
	s[v] = true;

	for (int i = 0; i < n; i++) {//Ѱ�Һ��
		int temp = MAXINT;
		int u = v;
		for (int j = 0; j < n; j++) { //�ҵ���������Ҫ�����ĵ�
			if ((s[j] == false) && (dist[j] < temp)) {
				u = j;
				temp = dist[j];
			}
		}

			s[u] = true;
			printf("%d ", u);

			for (int j = 0; j < n; j++) {//ˢ��dist���������
				if ((!s[j]) && (c[u][j] < MAXINT)) {
					int newdist = dist[u] + c[u][j];
					if (newdist < dist[j]) {
						dist[j] = newdist;
						prev[j] = u;
					}
				}
			}
			
			for (int j = 0; j < 5; j++)
			{
				printf("%d ", dist[j]);
			}
			printf("\n");
	}
}

void printOut(int c[5][5]) {//������飬��λ����ָ����Ϊ��������
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			printf("%d ",*(*(c+i)+j));
		}
		printf("\n");
	}
}

int main(void) {
	int c[5][5] = { 
	{0,10,MAXINT,30,100},
	{MAXINT,0,50,MAXINT,MAXINT},
	{MAXINT,MAXINT,0,MAXINT,10},
	{MAXINT,MAXINT,20,0,60},
	MAXINT,MAXINT,MAXINT,MAXINT,0};//�����Ȩͼ�����Ӿ���
	int prev[5];
	int dist[5];
	
	//printOut(c);
	Dijkstra(5, 1, dist, prev, c);
	printf("\n ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", dist[i]);
	}
	system("pause");

}