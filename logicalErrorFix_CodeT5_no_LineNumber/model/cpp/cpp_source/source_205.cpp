#include <bits/stdc++.h>
using namespace std;
int main() {
long int k, l, d, i, n, j = 1, m, c, b;
cin >> n >> k >> d;
for (i = 0; i < d; i++) {
j *= k;
if (j > n) break;
}
if (i == d && j < n) {
cout << "-1";
return 0;
}
int a[1000][1000] = {0};
b = n / k;
for (m = 0; m < d && b > 0; m++) {
for (i = 0; i < n; i++) a[m][i] = (i / b) % k;
b /= k;
}
for (j = 0; j < d; j++) {
for (i = 0; i < n; i++) cout << a[j][i] + 1 << ' ';
cout << '\n';
}
return 0;
}
