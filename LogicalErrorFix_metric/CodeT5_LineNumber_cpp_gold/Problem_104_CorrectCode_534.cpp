#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 1000010;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
pair<int, int> a[N], c[N];
void solve() {
int n, m;
cin >> n >> m;
long long suma = 0, sumb = 0;
long long l = 0, r = 0;
for (int i = 1; i <= n; i++) {
cin >> a[i].first >> a[i].second;
int first = min(m, a[i].first), second = min(m, a[i].second);
suma += a[i].first, sumb += a[i].second;
l += -2 * first + m, r += 2 * second - m;
}
if (suma + l <= sumb && suma + r >= sumb) {
long long cx = sumb - suma - l;
vector<pair<int, int> > res;
for (int i = 1; i <= n; i++) {
int first = min(m, a[i].first), second = min(m, a[i].second);
int le = m - second, ri = first;
while (le < ri) {
int mid = le + ri >> 1;
if ((first - mid) * 2 <= cx)
ri = mid;
else
le = mid + 1;
}
cx -= (first - le) * 2;
res.push_back({le, m - le});
}
cout << cx << '\n';
for (int i = 0; i < n; i++)
cout << res[i].first << ' ' << res[i].second << '\n';
} else if (suma + l > sumb) {
cout << suma + l - sumb << '\n';
for (int i = 1; i <= n; i++) {
int first = min(m, a[i].first);
cout << first << ' ' << m - first << '\n';
}
} else {
cout << sumb - suma - r << '\n';
for (int i = 1; i <= n; i++) {
int second = min(m, a[i].second);
cout << m - second << ' ' << second << '\n';
}
}
}
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr), cout.tie(nullptr);
cout << fixed << setprecision(10);
int T(1);
cin >> T;
for (int o = 1; o <= T; o++) {
solve();
}
return 0;
}