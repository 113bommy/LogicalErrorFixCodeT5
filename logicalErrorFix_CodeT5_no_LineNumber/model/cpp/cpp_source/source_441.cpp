#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double SQRT2 = 1.41421356237;
const double EPS = 1e-9;
const float SQRT2F = (float)SQRT2;
const int INF = 1e9;
const long long INF64 = 1e18;
template <class T>
T sqr(const T &x) {
return x * x;
}
template <class T>
T min(const T &a, const T &b, const T &c) {
return min(min(a, b), c);
}
template <class T>
T max(const T &a, const T &b, const T &c) {
return max(max(a, b), c);
}
inline void yesno(bool y) { cout << (y ? "YES\n" : "NO\n"); }
inline void yes_stop(bool y) {
if (y) {
yesno(1);
exit(0);
}
}
inline void no_stop(bool y) {
if (!y) {
yesno(0);
exit(0);
}
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int sgn(int x) { return (x > 0) - (x < 0); }
class IManip {
public:
virtual void write(ostream &os) const {}
};
template <class It>
class ManipRangePrinter : public IManip {
private:
const It b, e;

public:
ManipRangePrinter(It _b, It _e) : b(_b), e(_e) {}
void write(ostream &os) const {
It g = b;
if (g != e) os << *g;
for (++g; g != e; ++g) {
os << " " << *g;
}
}
It begin() { return b; }
It end() { return e; }
};
ostream &operator<<(ostream &os, const IManip &man) {
man.write(os);
return os;
}
template <class It>
ManipRangePrinter<It> range(It b, It e) {
return ManipRangePrinter<It>(b, e);
}
struct Edge {
int to, w;
bool operator<(const Edge &x) const {
if (to == x.to) return w < x.w;
return to < x.to;
}
};
void pref_func(const char *s, int *a) {
a[0] = 0;
for (int i = 1; s[i]; ++i) {
int j = a[i - 1];
while (j > 0 && s[i] != s[j]) j = a[j - 1];
a[i] = j + (s[i] == s[j]);
}
}
char s[(int)1e7];
int p[(int)1e7];
int main() {
ios_base::sync_with_stdio(0);
gets(s);
pref_func(s, p);
int n = strlen(s);
if (p[n - 1]) {
int sv = p[n - 1];
deque<int> v;
while (sv > 0) {
v.push_back(sv);
sv = p[sv - 1];
}
while (v.size()) {
int sv = v.back();
v.pop_back();
for (int i = 0; i < n - 1; ++i) {
if (p[i] == sv) {
for (int j = 0; j < p[i]; ++j) {
cout << s[j];
}
cout << "\n";
return 0;
}
}
}
}
cout << "Just a legend\n";
return 0;
}
