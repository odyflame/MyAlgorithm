/*
*2015112119 by ������
*/
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>


using namespace std;
int dp[501][501];
int cost[501];
int sum[501];
int t, k, i;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &k);
		for (i = 1; i <= k; ++i) {
			scanf("%d", &cost[i]);
			sum[i] = sum[i - 1] + cost[i];
		}

		for (int d = 1; d < k; ++d) {
			for (int tx = 1; tx + d <= k; ++tx) {
				int ty = tx + d;
				dp[tx][ty] = INT_MAX;

				for (int mid = tx; mid < ty; ++mid)
					dp[tx][ty] =
					min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
			}
		}

		printf("%d\n", dp[1][k]);
	}
	return 0;
}