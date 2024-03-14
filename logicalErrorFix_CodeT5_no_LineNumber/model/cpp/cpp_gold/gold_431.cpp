#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int p[maxn];
int main() {
int T;
scanf("%d", &T);
while (T--) {
int n, h;
scanf("%d%d", &h, &n);
int ans = 0;
int len = 1;
scanf("%d", p + 1);
for (int i = 2; i <= n; ++i) {
scanf("%d", p + i);
}
for (int i = 2; i <= n; ++i) {
if (p[i] - p[i - 1] == -1 || len == 0)
++len;
else {
if (len % 2 == 0) ++ans;
++ans;
len = 1;
--i;
p[i] = p[i + 1] + 1;
}
}
}
if (len % 2 == 0 && p[n] != 1) ++ans;
printf("%d\n", ans);
}
}
