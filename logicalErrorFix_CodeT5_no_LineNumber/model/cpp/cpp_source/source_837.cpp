#include <bits/stdc++.h>
using namespace std;
int cnt[100000], dp[30005][500];
int main() {
int n, x, d;
cin >> n >> d;
int mi = d, mx = d, pi = d, px = d;
for (long long i = 0; i < n; i++) {
scanf("%d", &x);
cnt[x]++;
}
int an = 0, i = d, k = max(0, d - 245);
for (int i = 30000; i >= d; i--) {
for (long long j = k + 1; j < d + 245; j++) {
if (i + j > 30001) continue;
if (j > 1)
dp[i][j - k] =
max(max(dp[i + j - 1][j - k - 1], dp[i + j + 1][j - k + 1]),
dp[i + j][j - k]);
else
dp[i][j - k] = max(dp[i + j][j - k], dp[i + j + 1][j - k + 1]);
dp[i][j - k] += cnt[i];
if (an < dp[i][j - k]) an = dp[i][j - k];
}
}
cout << dp[d][d - k] << endl;
}
