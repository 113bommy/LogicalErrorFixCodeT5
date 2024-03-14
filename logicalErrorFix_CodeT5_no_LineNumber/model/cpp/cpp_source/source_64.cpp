#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 100;
int n, a[N], b[N];
int p(int k) { return (1 << k); }
bool solve(int k) {
sort(b + 1, b + n + 1);
int cnt = 0;
for (int i = 1; i <= n; i++) {
int l1 = i, r1 = n + 1;
while (r1 - l1 > 1) {
int m1 = (l1 + r1) >> 1;
if (b[i] + b[m1] < p(k))
l1 = m1;
else
r1 = m1;
}
int l2 = i, r2 = n + 1;
while (r2 - l2 > 1) {
int m2 = (l2 + r2) >> 1;
if (b[i] + b[m2] < p(k + 1))
l2 = m2;
else
r2 = m2;
}
if (r1 != n + 1) cnt += l2 - r1 + 1;
int l3 = i, r3 = n + 1;
while (r3 - l3 > 1) {
int m3 = (l3 + r3) >> 1;
if (b[i] + b[m3] < p(k + 1) + p(k))
l3 = m3;
else
r3 = m3;
}
int l4 = r3, r4 = n + 1;
while (r4 - l4 > 1) {
int m4 = (l4 + r4) >> 1;
if (b[i] + b[m4] <= p(k + 2) - 2)
l4 = m4;
else
r4 = m4;
}
if (r3 != n + 1) cnt += l4 - r3 + 1;
}
return (cnt & 1);
}
int main() {
ios_base::sync_with_stdio(false);
cin >> n;
for (int i = 1; i <= n; i++) {
cin >> a[i];
}
int ans = 0;
for (int i = 0; i < 3; i++) {
for (int j = 1; j <= n; j++) b[j] = a[j] % p(i + 1);
if (solve(i)) ans += (1 << i);
}
cout << ans;
}
