#include <bits/stdc++.h>
using namespace std;
const int N = 2555;
int sum[N][N];
long long ans;
int n, m, K;
int p1[10], p2[10];
char str[N];
int count_ones(int x1, int x2, int y1, int y2) {
return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}
void dfs(int x1, int x2, int y1, int y2) {
if (x1 == x2 && y1 == y2) {
if (count_ones(x1, x2, y1, y2) == K) ans++;
return;
}
if (x2 - x1 > y2 - y1) {
int m = (x1 + x2) / 2;
dfs(x1, m, y1, y2);
dfs(m + 1, x2, y1, y2);
for (int i = y1; i <= y2; i++) {
for (int j = 0; j <= K; j++) p1[j] = x1, p2[j] = x2;
for (int j = i; j <= y2; j++) {
for (int k = 0; k <= K; k++) {
while (count_ones(p1[k], m, i, j) > k) p1[k]++;
while (count_ones(m + 1, p2[k], i, j) > k) p2[k]--;
}
for (int k = 1; k < K; k++) {
ans += (p1[k - 1] - p1[k]) * (p2[K - k] - p2[K - k - 1]);
}
if (!K)
ans += (m - p1[0] + 1) * (p2[0] - m);
else
ans += (m - p1[0] + 1) * (p2[K] - p2[K - 1]) +
(p1[K - 1] - p1[K]) * (p2[0] - m);
}
}
} else {
int m = (y1 + y2) / 2;
dfs(x1, x2, y1, m);
dfs(x1, x2, m + 1, y2);
for (int i = x1; i <= x2; i++) {
for (int j = 0; j <= K; j++) p1[j] = y1, p2[j] = y2;
for (int j = i; j <= x2; j++) {
for (int k = 0; k <= K; k++) {
while (count_ones(i, j, p1[k], m) > k) p1[k]++;
while (count_ones(i, j, m + 1, p2[k]) > k) p2[k]--;
}
for (int k = 1; k < K; k++) {
for (int k = 1; k < K; k++) {
ans += (p1[k - 1] - p1[k]) * (p2[K - k] - p2[K - k - 1]);
}
if (!K)
ans += (m - p1[0] + 1) * (p2[0] - m);
else
ans += (m - p1[0] + 1) * (p2[K] - p2[K - 1]) +
(p1[K - 1] - p1[K]) * (p2[0] - m);
}
}
}
int main() {
scanf("%d%d%d", &n, &m, &K);
for (int i = 1; i <= n; i++) {
scanf("%s", str + 1);
for (int j = 1; j <= m; j++) {
sum[i][j] =
sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (str[j] == '1');
}
}
ans = 0;
dfs(1, n, 1, m);
cout << ans << endl;
return 0;
}
