#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <class T>
bool uin(T& a, const T& b) {
return a > b ? a = b, true : false;
}
template <class T>
bool uax(T& a, const T& b) {
return a < b ? a = b, true : false;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr int inf = 1e9;
void solve() {
int n;
cin >> n;
vector<int> p(n);
for (auto& x : p) cin >> x;
p.insert(begin(p), -inf);
vector<array<int, 2>> dp(n + 1);
vector<array<bool, 2>> par(n + 1);
fill(begin(dp[0]), end(dp[0]), -inf);
for (int i = 1; i <= n; ++i) {
auto& nxt = dp[i];
auto& pre = dp[i - 1];
fill(begin(nxt), end(nxt), inf);
for (int x = -p[i], j = 0; j < 2; ++j, x = -x) {
if (x > -p[i - 1] && uin(nxt[j], pre[0])) par[i][j] = 0;
if (x > pre[0] && uin(nxt[j], -p[i - 1])) par[i][j] = 0;
if (x > +p[i - 1] && uin(nxt[j], pre[1])) par[i][j] = 1;
if (x > pre[1] && uin(nxt[j], +p[i - 1])) par[i][j] = 1;
}
}
if (min(dp[n][0], dp[n][1]) > n) {
cout << "NO\n";
return;
}
cout << "YES\n";
vector<int> res;
for (int i = n, state = dp[n][0] <= n ? 0 : 1; i > 0; --i) {
if (state)
res.push_back(+p[i]);
else
res.push_back(-p[i]);
state = par[i][state];
}
reverse(begin(res), end(res));
for (auto x : res) cout << x << ' ';
cout << '\n';
}
signed main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
int t;
cin >> t;
while (t--) solve();
}
