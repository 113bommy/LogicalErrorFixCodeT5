#include <bits/stdc++.h>
using namespace std;
long long read() {
long long x = 0, f = 1;
char c = getchar();
while (c > '9' || c < '0') {
if (c == '-') f = -1;
c = getchar();
}
while (c >= '0' && c <= '9') {
x = x * 10 + c - '0';
c = getchar();
}
return f * x;
}
int n, op, a[51];
long long dp[51][51][51], pw[51], ans;
int main() {
n = read(), op = read();
pw[0] = 1;
for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * 2 % 1000000007;
for (int i = 1; i <= n; ++i) a[i] = read();
dp[0][0][0] = 1;
for (int i = 1; i <= n; ++i)
for (int ow = 0; ow <= i; ++ow)
for (int ob = 0; ow + ob <= i; ++ob) {
if (a[i] == 1 || a[i] == -1) {
long long s = 0;
if (ow) {
s = dp[i - 1][ow - 1][ob];
if (ob) s = s * pw[ob - 1] % 1000000007;
}
if (ob + ow < i && ob) {
s = (s + dp[i - 1][ow][ob] * pw[ob - 1] % 1000000007) % 1000000007;
}
s = s * pw[i - ob - 1] % 1000000007;
dp[i][ow][ob] = s;
}
if (a[i] == 0 || a[i] == -1) {
long long s = 0;
if (ob) {
s = dp[i - 1][ow][ob - 1];
if (ow) s = s * pw[ow - 1] % 1000000007;
}
if (ow + ob < i && ow) {
s = (s + dp[i - 1][ow][ob] * pw[ow - 1] % 1000000007) % 1000000007;
}
s = s * pw[i - ow - 1] % 1000000007;
dp[i][ow][ob] = (dp[i][ow][ob] + s) % 1000000007;
}
}
for (int ow = 0; ow <= n; ++ow)
for (int ob = 0; ob + ow <= n; ++ob)
if ((ow + ob) % 2 == op) ans = (ans + dp[n][ow][ob]) % 1000000007;
cout << ans << '\n';
return 0;
}
