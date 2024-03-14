#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const double pi = acos(-1);
void print() { cout << '\n'; }
template <typename T, typename... Params>
void print(const T& var1, const Params&... var2) {
cout << var1 << ' ';
print(var2...);
}
template <typename T>
void pr(const T& v) {
for (auto c : v) cout << c << ' ';
cout << '\n';
}
long long int power(long long int a, long long int b, long long int p) {
if (b == 0) return 1;
long long int c = power(a, b / 2, p);
if (b % 2 == 0)
return (c * c) % p;
else
return (((c * c) % p) * a) % p;
}
long long int invmod(long long int n, long long int p) {
return power(n, p - 2, p);
}
bool isPrime(long long int n) {
if (n <= 1) return false;
if (n <= 3) return true;
if (n % 2 == 0 || n % 3 == 0) return false;
for (long long int i = 5; i * i <= n; i = i + 6)
if (n % i == 0 || n % (i + 2) == 0) return false;
return true;
}
const int maxn = 1e6 + 6;
int tree[maxn];
int read(int idx) {
int sum = 0;
while (idx > 0) {
sum += tree[idx];
idx -= (idx & -idx);
}
return sum;
}
void update(int MaxIdx, int idx, int val) {
while (idx <= MaxIdx) {
tree[idx] += val;
idx += (idx & -idx);
}
}
int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int n;
cin >> n;
int a[n], f[n];
map<int, int> mm, mmap;
for (long long int i = 0; i < n; i++) {
cin >> a[i];
mm[a[i]]++;
f[i] = mm[a[i]];
}
long long int ans = 0;
for (long long int i = n - 1; i >= 0; i--) {
ans += read(f[i] - 1);
mmap[a[i]]++;
update(n, mmap[a[i]], 1);
}
print(ans);
return 0;
}
