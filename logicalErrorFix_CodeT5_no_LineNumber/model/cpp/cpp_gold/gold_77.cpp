#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 45;
int n, a[N];
void solve() {
cin >> n;
vector<int> cnt(30);
for (int i = 1; i <= n; i++) {
cin >> a[i];
for (int j = 29; j >= 0; j--) {
if (a[i] & (1 << j)) {
cnt[j]++;
}
}
}
for (int j = 29; j >= 0; j--) {
if (cnt[j] % 2 == 0) continue;
if (cnt[j] % 4 == 1) {
cout << "WIN" << endl;
return;
} else {
cout << ((n - cnt[j]) & 1 ? "WIN" : "LOSE") << endl;
return;
}
cout << "DRAW" << endl;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
int t;
cin >> t;
while (t--) {
solve();
}
}
