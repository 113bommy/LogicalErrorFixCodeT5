#include <bits/stdc++.h>
using namespace std;
int main() {
int t;
cin >> t;
while (t--) {
string order;
cin >> order;
string s;
cin >> s;
map<char, int> m;
int c = 1;
for (auto i : order) {
m[i] = c;
c++;
}
long long ans = 0;
for (int i = 1; i < s.length(); i++) {
ans += (m[s[i]] - m[s[i - 1]]);
}
std::cout << ans << std::endl;
}
return 0;
}
