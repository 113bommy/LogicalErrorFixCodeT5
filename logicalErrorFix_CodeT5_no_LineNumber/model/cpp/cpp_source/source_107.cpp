#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
template <typename first, typename second>
ostream &operator<<(ostream &os, const pair<first, second> &p) {
return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
os << "{";
for (auto it = v.begin(); it != v.end(); ++it) {
if (it != v.begin()) os << ", ";
os << *it;
}
return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
os << "[";
for (auto it = v.begin(); it != v.end(); ++it) {
if (it != v.begin()) os << ", ";
os << *it;
}
return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
os << "[";
for (auto it = v.begin(); it != v.end(); ++it) {
if (it != v.begin()) os << ", ";
os << *it;
}
return os << "]";
}
template <typename first, typename second>
ostream &operator<<(ostream &os, const map<first, second> &v) {
os << "[";
for (auto it = v.begin(); it != v.end(); ++it) {
if (it != v.begin()) os << ", ";
os << it->first << " = " << it->second;
}
return os << "]";
}
void faltu() { cerr << '\n'; }
template <typename T>
void faltu(T a[], int n) {
for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
cerr << '\n';
}
template <typename T, typename... hello>
void faltu(T arg, const hello &...rest) {
cerr << arg << ' ';
faltu(rest...);
}
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
;
int a, count = 0, store = 0;
cin >> a;
int arr[a];
for (int i = 0; i < a; i++) {
cin >> arr[i];
}
int max = arr[0];
int min = arr[0];
for (int i = 0; i < a; i++) {
if (arr[i] > max) {
max = arr[i];
count++;
}
if (arr[i] > min) {
min = arr[i];
count++;
}
}
cout << count;
return 0;
}
