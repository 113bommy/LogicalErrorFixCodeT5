#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
void read(T &x) {
char ch;
x = 0;
int f = 1;
while (isspace(ch = getchar_unlocked()))
;
if (ch == '-') ch = getchar_unlocked(), f = -1;
do x = x * 10 + (ch - '0');
while (isdigit(ch = getchar_unlocked()));
x *= f;
}
template <class T, class... A>
void read(T &x, A &...args) {
read(x);
read(args...);
}
const int N = 2005;
const int M = 1000000007;
char s[N], t[N];
int way[N][N * 2], sum[N][N * 2];
void inc(int &x, ll y) {
if ((x += y) >= M) x -= M;
}
int main() {
int T;
read(T);
while (T--) {
int n;
read(n);
memset(way, 0, (n + 1) * sizeof(way[0]));
memset(sum, 0, (n + 1) * sizeof(sum[0]));
scanf("%s%s", s, t);
for (int i = 1; i < n; i += 2) {
if (s[i] != '?') s[i] ^= 1;
if (t[i] != '?') t[i] ^= 1;
}
way[0][N] = 1;
for (int i = 0; i < n; ++i) {
vector<int> cs, ct;
if (s[i] == '0')
cs = {0};
else if (s[i] == '1')
cs = {1};
else
cs = {0, 1};
if (t[i] == '0')
ct = {0};
else if (t[i] == '1')
ct = {-1};
else
ct = {0, -1};
for (int x : cs)
for (int y : ct)
for (int j = N - i; j <= N + i; ++j) {
inc(way[i + 1][j + x + y], way[i][j]);
sum[i + 1][j + x + y] = (sum[i + 1][j + x + y] + sum[i][j] +
(ll)abs(j - N + x + y) * way[i][j]);
}
}
printf("%d\n", sum[n][N]);
}
return 0;
}
