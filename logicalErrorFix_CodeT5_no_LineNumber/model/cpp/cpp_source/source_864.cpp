#include <bits/stdc++.h>
const int OO = 1e9;
using namespace std;
int main() {
ios_base::sync_with_stdio(false);
int n, m;
cin >> n >> m;
set<int> s1, s2;
for (int i = (0); i < (int)(m); ++i) {
int t1, t2;
cin >> t1 >> t2;
s1.insert(min(t1, t2));
s2.insert(max(t1, t2));
if (*s1.end() >= *s2.begin()) {
cout << 0;
return 0;
}
}
if (!s1.size() && !s2.size()) {
cout << n - 1;
return 0;
}
cout << *s2.begin() - *s1.end();
return 0;
}
