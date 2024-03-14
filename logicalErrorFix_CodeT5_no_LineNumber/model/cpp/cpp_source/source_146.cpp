#include <bits/stdc++.h>
using namespace std;
int in() {
int tmp;
scanf("%d", &tmp);
return tmp;
}
int &in(int &x) { return x = in(); }
template <typename T, typename... Args>
void in(T &x, Args &...args) {
in(x);
if (sizeof...(args)) in(args...);
}
template <class T, class L>
T &smax(T &x, L y) {
if (y > x) x = y;
return x;
}
template <class T, class L>
T &smin(T &x, L y) {
if (y < x) x = y;
return x;
}
namespace std {
template <>
struct hash<pair<int, int> > {
size_t operator()(pair<int, int> const &x) const {
return hash<long long>()(((long long)x.first << 32) ^ x.second);
}
};
} // namespace std
const int maxn = 5e3 + 17;
int x, y, a, b, c, m, ans, xs[] = {-1, 1, 0, 0}, ys[] = {0, 0, -1, 1};
int mp(int x) { return x < 0 ? -2 * x : 2 * x + 1; }
int ant[maxn][maxn];
queue<pair<int, int> > q;
int main() {
in(ant[mp(0)][mp(0)]);
q.push({0, 0});
while (!q.empty()) {
int x = q.front().first, y = q.front().second;
q.pop();
if (ant[mp(x)][mp(y)] < 4) continue;
for (int i = 0; i < 4; i++) {
ant[mp(x + xs[i])][mp(y + ys[i])] += ant[mp(x)][mp(y)] / 4;
if (ant[mp(x + xs[i])][mp(y + ys[i])] > 4) q.push({x + xs[i], y + ys[i]});
}
ant[mp(x)][mp(y)] %= 4;
}
int t = in();
while (t--) {
int x = in(), y = in();
if (mp(x) >= maxn || mp(y) >= maxn)
printf("0\n");
else
printf("%d\n", ant[mp(x)][mp(y)]);
}
return 0;
}
