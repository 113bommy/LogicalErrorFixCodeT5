#include <bits/stdc++.h>
using namespace std;
long long i, j, n, m, k, x, y, l, r;
long long res, ans, cur;
string s, q, s1, s2;
char ch1, ch2, ch3;
long long a[500000], b[500000];
bool f11[500000], f12[500000];
bool fix[500000];
vector<long long> g[500000], c[500000];
long long X(long long A, long long B, long long P) {
if (!B) return 1;
if (B == 1) return (A % P);
long long C = X(A, B / 2, P);
C *= C;
C %= P;
if (B % 2) C *= A;
return C % P;
}
long long UG(long long A, long long B) {
if (A > B) return UG(B, A);
if (A == 0) return B;
if (A == 1) return 1;
return UG(B % A, A);
}
long long UJ(long long A, long long B) {
long long C = UG(A, B);
A /= C;
A *= B;
return A;
}
long long d[5000000];
int main() {
cin >> n;
for (i = 1; i <= n; i++) cin >> a[i];
d[0] = -10;
d[1] = a[1];
for (i = 2; i <= n; i++) d[i] = 1000000000;
for (i = 2; i <= n; i++) {
l = 0;
r = (i - 1);
while (l + 1 < r) {
m = (l + r) / 2;
if (d[m] < a[i])
l = m;
else
r = m - 1;
}
if (d[r] < a[i]) d[r + 1] = min(d[r + 1], a[i]);
if (d[l] < a[i]) d[l + 1] = min(d[l + 1], a[i]);
}
for (i = n; i >= 1; i--)
if (d[i] != 1000000000) break;
cout << i << endl;
}
