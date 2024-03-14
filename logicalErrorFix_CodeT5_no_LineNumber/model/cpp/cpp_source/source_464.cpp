#include <bits/stdc++.h>
using namespace std;
const double h = 1e-6;
const int MAX_ = 200005;
inline long long int mul(long long int a, long long int b) {
return (a * 1ll * b) % 1000000007;
}
inline long long int sub(long long int a, long long int b) {
long long int c = a - b;
if (c < 0) c += 1000000007;
return c;
}
inline long long int add(long long int a, long long int b) {
long long int c = a + b;
if (c > 1000000007) c -= 1000000007;
return c;
}
long long int sqr(long long int x) { return x * x; }
int main() {
long long int t;
cin >> t;
while (t--) {
long long int n;
cin >> n;
int a[n];
for (int i = 0; i < n; i++) {
cin >> a[i];
}
sort(a, a + n);
long long int t1 = a[0] * a[1] * a[n - 1] * a[n - 2] * a[n - 3];
long long int t2 = a[0] * a[1] * a[2] * a[3] * a[n - 1];
long long int t3 = a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5];
cout << max({t1, t2, t3}) << endl;
}
return 0;
}
