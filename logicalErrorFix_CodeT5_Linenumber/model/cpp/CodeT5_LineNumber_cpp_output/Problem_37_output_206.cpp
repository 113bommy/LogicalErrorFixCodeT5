#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
int t;
cin >> t;
while (t--) {
long long n, m;
cin >> n >> m;
for (int i = 1; i <= n; i++) a[i] = 1;
while (m--) {
int v, s, temp;
cin >> v >> s >> temp;
a[temp] = 0;
}
for (int i = 1; i <= 100010; i++) {
if (a[i]) {
for (int j = 1; j <= n; j++) {
if (i != j) cout << i << " " << j << endl;
}
break;
}
}
}
}