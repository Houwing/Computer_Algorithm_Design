#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXINT 10000

void Dijkstra(int n, int v, int dist[], int prev[], int c[5][5]) {
	//单元最短路径问题的dijkstra算法

	bool s[5];//是否红点集
	for (int i = 0; i < n; i++) {//初始化红点集
		dist[i] = c[v][i];//刷新dist中的路径长度
		s[i] = false;
		if (dist[i] == MAXINT)//刷新前驱节点
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

	for (int i = 0; i < n; i++) {//寻找红点
		int temp = MAXINT;
		int u = v;
		for (int j = 0; j < n; j++) { //找到接下来需要操作的点
			if ((s[j] == false) && (dist[j] < temp)) {
				u = j;
				temp = dist[j];
			}
		}

			s[u] = true;
			printf("%d ", u);

			for (int j = 0; j < n; j++) {//刷新dist里面的数据
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

void printOut(int c[5][5]) {//输出数组，二位数组指针作为参数传递
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
	MAXINT,MAXINT,MAXINT,MAXINT,0};//有向带权图的连接矩阵
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