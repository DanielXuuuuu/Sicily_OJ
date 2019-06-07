#include <iostream>
#include <cmath>
#include <memory.h>
using namespace std;

#define N 10005

bool isPrime[N];
bool used[1005];
int seq[1005];

void init() {
	for (int i = 2; i < N; i++) {
		isPrime[i] = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				isPrime[i] = false;
				break;
			}
		}
	}
}

bool exam(int num, int d, int pos ) {
	for (int i = pos - 1; i >= pos - d + 1 && i >= 1; i--) {
		num += seq[i];
		if (isPrime[num]) {
			return false;
		}
	}
	return true;
}

bool dfs(int n, int m, int d, int pos) {
	if (pos > m - n + 1)
		return true;
	for (int i = n; i <= m; i++) {
		if (!used[i]) {
			if (exam(i, d, pos)) {
				seq[pos] = i;
				used[i] = true;
				if (dfs(n, m, d, pos + 1))
					return true;
				used[i] = false;
			}
		}
	}
	return false;
}

int main() {
	int n, m, d;
	init();

	while (cin >> n >> m >> d) {
		if (n == 0 && m == 0 && d == 0)  break;
		memset(used, 0, sizeof(used));

		if (!dfs(n, m, d, 1))
			cout << "No anti-prime sequence exists.";
		else {
			int i;
			for (i = 1; i < m - n + 1; i++)
				cout << seq[i] << ",";
			cout << seq[i];
		}
		cout << endl;
	}
	return 0;
}