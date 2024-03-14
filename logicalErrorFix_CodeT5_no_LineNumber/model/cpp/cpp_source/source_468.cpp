#include <bits/stdc++.h>
using namespace std;
int main() {
long long t;
cin >> t;
while (t--) {
long long n;
cin >> n;
long long a[n];
for (long long i = 0; i < n; i++) cin >> a[i];
long long pre[n];
long long prem[n];
long long suf[n];
long long sufm[n];
multiset<long long> m;
multiset<long long, greater<long long> > mm;
m.insert(a[0]);
mm.insert(a[0]);
pre[0] = LONG_LONG_MIN;
prem[0] = LONG_LONG_MAX;
for (long long i = 1; i < n; i++) {
pre[i] = max((*m.begin()) * a[i], (*mm.begin()) * a[i]);
prem[i] = min((*mm.begin()) * a[i], (*m.begin()) * a[i]);
pre[i] = max(pre[i], pre[i - 1]);
prem[i] = min(prem[i], prem[i - 1]);
m.insert(a[i]);
mm.insert(a[i]);
}
m.clear();
mm.clear();
m.insert(a[n - 1]);
mm.insert(a[n - 1]);
suf[n - 1] = LONG_LONG_MIN;
sufm[n - 1] = LONG_LONG_MAX;
for (long long i = n - 2; i >= 0; i--) {
suf[i] = max((*m.begin()) * a[i], (*mm.begin()) * a[i]);
sufm[i] = min((*mm.begin()) * a[i], (*m.begin()) * a[i]);
suf[i] = max(suf[i], suf[i + 1]);
sufm[i] = min(sufm[i], sufm[i + 1]);
m.insert(a[i]);
mm.insert(a[i]);
}
long long ans = -100000000000000000LL;
for (long long i = 2; i < n - 2; i++) {
ans = max(ans, pre[i - 1] * a[i] * suf[i + 1]);
ans = max(ans, pre[i - 1] * a[i] * sufm[i + 1]);
ans = max(ans, prem[i - 1] * a[i] * suf[i + 1]);
ans = max(ans, prem[i - 1] * a[i] * sufm[i + 1]);
}
cout << ans << "\n";
}
}
