#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const double eps = 1e-8;
const int maxn = 30000;
int ans[100][100];
int n, q;
void dfs(int x, int y) {
if (x > 20 || y > 20 || x < 0 || y < 0) return;
int add = 0;
if (ans[x][y] >= 4) {
add = ans[x][y] / 4;
ans[x][y] = ans[x][y] % 4;
} else {
return;
}
ans[x + 1][y] += add;
if (x > 0) ans[x - 1][y] += add;
ans[x][y + 1] += add;
if (y > 0) ans[x][y - 1] += add;
dfs(x + 1, y);
dfs(x - 1, y);
dfs(x, y + 1);
dfs(x, y - 1);
}
int main() {
while (cin >> n >> q) {
memset(ans, 0, sizeof(ans));
int cmp = ceil(0.5 * log2(n));
ans[10][10] = n;
dfs(10, 10);
for (int i = (1); i <= (q); ++i) {
int a, b;
scanf("%d%d", &a, &b);
if (abs(a) > cmp || abs(b) > cmp) {
cout << 0 << endl;
continue;
}
cout << ans[a + 10][b + 10] << endl;
}
}
return 0;
}
