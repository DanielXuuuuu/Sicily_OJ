//Dijkstra算法, 给定起点求到终点的最短路径（利用优先队列实现）
//利用优先队列，只是简单的每次把可以走的push进去，但是优先队列保证了每次取最小的
//Dijkstra的每次新加入一个结点就更新有关结点到集合的距离：优先队列中同一点可能会push进好几次，但总是距离小的在前，相当于更新了

#include <iostream>
#include <queue>
using namespace std;

int grid[105][105] = { 0 };
int row, column;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int visited[105][105] = { 0 };

struct point {
	int x;
	int y;
	int cost;
	point(int a = 0, int b = 0, int c = 0) {
		x = a;
		y = b;
		cost = c;
	}
    //优先队列默认最大堆
	friend bool operator<(point p1, point p2) { //必须重载小于号,使优先队列为最小堆
		return p1.cost > p2.cost; //对于结点按照cost排序
	}
};

bool canGo(int x, int y) {
	return x >= 1 && x <= row && y >= 1 && y <= column && !visited[x][y];
}

int main() {
	int caseNum;
	cin >> caseNum;
	point start, end;

	while (caseNum--) {
		cin >> row >> column;
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= column; j++) {
				cin >> grid[i][j];
				visited[i][j] = 0;
			}

		cin >> start.x >> start.y >> end.x >> end.y;

		priority_queue<point> q;
		start.cost = grid[start.x][start.y];
		q.push(start);

		while (!(q.top().x == end.x && q.top().y == end.y)) {
			point temp = q.top();
			q.pop();
			visited[temp.x][temp.y] = 1;

			for (int i = 0; i < 4; i++) {
				int x = temp.x + dir[i][0];
				int y = temp.y + dir[i][1];
				if (canGo(x, y)) {
					q.push(point(x, y, temp.cost + grid[x][y]));
				}
			}
			while (visited[q.top().x][q.top().y]) //会有重复，删去已经访问过的
				q.pop();
		}
		cout << q.top().cost << endl;
	}

	return 0;
}