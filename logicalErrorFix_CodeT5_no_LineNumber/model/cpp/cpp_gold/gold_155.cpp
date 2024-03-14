#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
const long double eps = 1e-07;
int n;
int a[200000];
int d[200000];
int main() {
scanf("%d", &n);
for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
d[0] = -inf;
for (int i = 1; i <= n; ++i) d[i] = inf;
for (int i = 0; i < n; i++) {
int l = 0;
int r = n;
while (r - l > 2) {
int m = (l + r) / 2;
if (d[m] < a[i]) {
l = m;
} else
r = m;
}
for (int j = r; j >= l; --j)
if (d[j] < a[i]) {
d[j + 1] = a[i];
break;
}
int ans = -inf;
for (int i = 1; i <= n; ++i)
if (d[i] != inf) ans = max(ans, i);
cout << ans << endl;
return 0;
}
