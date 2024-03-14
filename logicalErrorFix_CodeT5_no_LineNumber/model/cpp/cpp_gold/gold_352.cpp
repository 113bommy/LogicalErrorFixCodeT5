#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll X[ac];
ll Y[ac];
ll A[ac], B[ac];
ll UF[ac];
ll f(ll a) {
if (UF[a] == a) return a;
return UF[a] = f(UF[a]);
}
void u(ll a, ll b) { UF[f(a)] = UF[f(b)]; }
bool cmp1(ll a, ll b) { return X[a] <= X[b]; }
bool cmp2(ll a, ll b) { return Y[a] <= Y[b]; }
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
int n;
cin >> n;
for (int i = 0; i < n; i++) {
cin >> X[i] >> Y[i];
}
for (int i = 0; i < n; i++) A[i] = B[i] = UF[i] = i;
sort(A, A + n, cmp1);
sort(B, B + n, cmp2);
vector<array<ll, 3>> V;
for (int i = 0; i < n - 1; i++) {
V.push_back({X[A[i + 1]] - X[A[i]], A[i], A[i + 1]});
V.push_back({Y[B[i + 1]] - Y[B[i]], B[i], B[i + 1]});
}
sort(V.begin(), V.end());
ll s = 0;
for (auto x : V) {
if (f(x[1]) != f(x[2])) {
s += x[0];
u(x[1], x[2]);
}
}
cout << s << '\n';
}
