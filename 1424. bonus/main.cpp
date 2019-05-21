#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[10005];
int indegree[10005] = { 0 };
int bonus[10005] = { 0 };

bool topoSort(int n) {
	for (int i = 0; i < n; i++) {
		for(auto j : graph[i]) {
				indegree[j]++;
		}
	}

	queue<int> q;
	int temp;

	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			bonus[i] = 100;
		}
	}

	while (!q.empty()) {
		temp = q.front();
		q.pop();
		for (auto j : graph[temp]) {
			indegree[j]--;
			if (indegree[j] == 0) {
				q.push(j);
				bonus[j] = bonus[temp] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (indegree[i] != 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (a == b) {
			cout << "Poor Xed" << endl;
			return 0;
		}
		graph[b - 1].push_back(a - 1);
	}
	if (!topoSort(n))
		cout << "Poor Xed" << endl;
	else {
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += bonus[i];
		cout << sum << endl;
	}
	return 0;
}