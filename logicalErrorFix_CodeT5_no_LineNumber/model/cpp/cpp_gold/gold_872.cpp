#include <bits/stdc++.h>
using namespace std;
double prob[20], ans[20];
double p[(1 << 20)];
int indexOf[20];
int main() {
int n, k;
scanf("%d%d", &n, &k);
int initN = n;
for (int i = 0, tot = 0; i < n; ++i, ++tot) {
cin >> prob[i];
if (prob[i] < 1e-9)
indexOf[i] = tot;
}
const int n2 = (1 << n);
k = min(k, n);
p[0] = 1;
for (int i = 0; i < n2; ++i) {
if (__builtin_popcount(i) == k) {
for (int j = 0; j < n; ++j)
if ((i >> j) & 1) ans[indexOf[j]] += p[i];
continue;
}
double den = 0;
for (int j = 0; j < n; ++j)
if (((i >> j) & 1) == 0) den += prob[j];
for (int j = 0; j < n; ++j)
if (((i >> j) & 1) == 0) {
p[i | (1 << j)] += p[i] * prob[j] / den;
}
}
fixed(cout);
cout.precision(10);
for (int i = 0; i < initN; ++i) cout << ans[i] << " ";
cout << endl;
return 0;
}
