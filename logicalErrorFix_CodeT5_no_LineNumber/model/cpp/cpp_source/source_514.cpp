#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int size(const T& c) {
return c.size();
}
using namespace std;
const int maxn = 300 + 10;
const int oo = 1000000000;
int a[maxn], b[maxn];
int d[maxn][maxn], u, v, top, n, e;
struct ketqua {
int i;
int j;
int d;
} res[maxn * maxn * 3];
void add(int i, int j, int d) {
a[i] -= d;
a[j] += d;
res[++top].i = i;
res[top].j = j;
res[top].d = d;
}
void go(int s, int e, int c) {
if (d[s][e] == 1) {
add(s, e, c);
return;
}
for (int i = (1), _b = (n); i <= _b; i++) {
if (i != s && i != e && d[i][e] == 1 && d[s][e] == d[s][i] + d[i][e]) {
if (a[i] >= c) {
add(i, e, c);
go(s, i, c);
return;
} else {
int rem = c - a[i];
add(i, e, a[i]);
go(s, i, c);
add(i, e, rem);
}
}
}
}
int main() {
cin >> n >> v >> e;
for (int i = (1), _b = (n); i <= _b; i++) cin >> a[i];
for (int i = (1), _b = (n); i <= _b; i++) cin >> b[i];
for (int i = (1), _b = (n); i <= _b; i++) {
for (int j = (1), _b = (n); j <= _b; j++) d[i][j] = oo;
d[i][i] = 0;
}
for (int i = (1), _b = (e); i <= _b; i++) {
cin >> u >> v;
d[u][v] = 1;
d[v][u] = 1;
}
for (int k = (1), _b = (n); k <= _b; k++)
for (int i = (1), _b = (n); i <= _b; i++)
for (int j = (1), _b = (n); j <= _b; j++)
d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
for (int k = (1), _b = (n * 5); k <= _b; k++) {
for (int i = (1), _b = (n); i <= _b; i++)
for (int j = (1), _b = (n); j <= _b; j++) {
if (i == j) continue;
if (a[i] < b[i] && a[j] > b[j]) {
int c = min(b[i] - a[i], a[j] - b[j]);
go(j, i, c);
}
}
}
for (int i = (1), _b = (n); i <= _b; i++)
if (a[i] != b[i]) {
cout << "NO";
return 0;
}
cout << top << endl;
for (int i = (1), _b = (top); i <= _b; i++)
cout << res[i].i << ' ' << res[i].j << ' ' << res[i].d << endl;
fclose(stdin);
fclose(stdout);
return 0;
}
