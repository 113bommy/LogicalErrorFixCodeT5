#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int q;
int h, n;
int p[N];
int main() {
std::ios::sync_with_stdio(0);
std::cin.tie(0);
while (cin >> q) {
while (q--) {
cin >> h >> n;
for (int i = (1); i < (n + 1); i++) cin >> p[i];
int ans = 0;
int cnt = 1;
n++;
p[n] = 0;
for (int i = (2); i < (n + 1); i++) {
if (p[i] == p[i - 1] - 1)
cnt++;
else {
if (cnt & 1)
;
else {
ans++;
cnt = 2;
}
}
}
cout << ans << '\n';
}
}
return 0;
}
