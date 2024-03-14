#include <bits/stdc++.h>
using namespace std;
string s[100];
int cost[100];
int n, m, k, togo[100], fruits[100];
int main(void) {
cin >> n >> m;
for (int i = 0; i < n; i++) scanf("%d", &cost[i]);
sort(cost, cost + n);
scanf("\n");
k = 0;
for (int i = 0; i < m; i++) {
getline(cin, s[i]);
togo[i] = k;
for (int j = 0; j < i; j++)
if (s[i] == s[j]) {
togo[i] = togo[j];
fruits[togo[j]]++;
}
if (togo[i] == k) fruits[k] = 1, k++;
}
sort(fruits, fruits + k);
int ans1 = 0, ans2 = 0;
for (int i = 0; i < k; i++) {
ans1 += cost[i] * fruits[k - i - 1];
ans2 += cost[n - i - 1] * fruits[k - i - 1];
}
cout << ans1 << ' ' << ans2 << endl;
}
