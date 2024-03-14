#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long powmod(long long a, long long b) {
long long res = 1;
if (a >= mod) a %= mod;
for (; b; b >>= 1) {
if (b & 1) res = res * a;
if (res >= mod) res %= mod;
a = a * a;
if (a >= mod) a %= mod;
}
return res;
}
int a[100];
int main() {
ios_base::sync_with_stdio(false);
;
cin.tie(0);
cout.tie(0);
int n;
cin >> n;
for (long long i = (long long)(1); i <= (long long)(n); i++) {
cin >> a[i];
}
bool flag = false;
for (long long i = (long long)(1); i <= (long long)(n); i++) {
int temp = a[i] - a[i - 1];
if (temp > 15) {
flag = true;
cout << a[i - 1] + 15;
}
}
if (!flag) {
int temp = 90 - a[n];
if (temp > 15)
cout << (a[n] + 15);
else
cout << "90";
}
return 0;
}
