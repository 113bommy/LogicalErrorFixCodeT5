#include <bits/stdc++.h>
using namespace std;
int main() {
std::ios::sync_with_stdio(false);
int n, m;
scanf("%d%d", &n, &m);
set<int> s;
int k, x;
bool v1[10002], v2[10002];
for (int i = 0; i < m; i++) {
scanf("%d", &k);
memset(v1, 0, sizeof(v1));
memset(v2, 0, sizeof(v2));
bool f = 1;
for (int j = 0; j < k; j++) {
scanf("%d", &x);
if ((x > 0 && v2[x]) || (x < 0 && v1[-x])) {
f = 0;
break;
} else {
if (x > 0)
v1[x] = 1;
else
v2[-x] = 1;
}
}
if (f) {
puts("YES");
return 0;
}
}
puts("NO");
return 0;
}
