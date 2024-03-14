#include <bits/stdc++.h>
using namespace std;
const int maxn = 102000;
int n, m, color[maxn], isBipartite = true;
int dfn[maxn], dfs_clock, rt;
long long black, white, ans[maxn], c[maxn];
pair<int, int> fa[maxn];
vector<pair<int, int> > G[maxn];
vector<int> oddCycle;
void dfs0(int u, int col, pair<int, int> faEdge) {
color[u] = col, dfn[u] = ++dfs_clock;
if (col == 2)
black += c[u];
else
white += c[u];
fa[u] = faEdge;
for (auto [v, id] : G[u])
if (v != faEdge.first) {
if (dfn[v]) {
if (dfn[v] < dfn[u] && color[v] == color[u] && isBipartite) {
isBipartite = false;
rt = u;
int p = u;
while (p != v) {
oddCycle.push_back(fa[p].second);
p = fa[p].first;
}
oddCycle.push_back(id);
}
} else
dfs0(v, col ^ 1, {u, id});
}
}
void dfs(int u, int fath) {
dfn[u] = ++dfs_clock;
for (auto [v, id] : G[u])
if (v != fath && !dfn[v]) {
dfs(v, u);
if (c[v]) {
long long d = c[v];
c[u] -= d, c[v] -= d, ans[id] += d;
}
}
}
int main() {
scanf("%d%d", &n, &m);
for (int i = 1; i <= n; ++i) scanf("%lld", &c[i]);
for (int i = 1; i <= m; ++i) {
int u, v;
scanf("%d%d", &u, &v);
G[u].emplace_back(v, i);
G[v].emplace_back(u, i);
}
dfs0(1, 2, {-1, -1});
memset(dfn, 0, sizeof dfn);
dfs_clock = 0;
if (isBipartite) {
if (black != white) {
puts("NO");
return 0;
} else
dfs(1, -1);
} else {
dfs(rt, -1);
assert(c[rt] % 2 == 0);
long long d = c[rt] / 2, sz = (long long)oddCycle.size();
for (int i = 0; i < sz; ++i) ans[oddCycle[i]] += d * (i & 1 ? -1 : 1);
}
puts("YES");
for (int i = 1; i <= m; ++i) printf("%lld\n", ans[i]);
return 0;
}
