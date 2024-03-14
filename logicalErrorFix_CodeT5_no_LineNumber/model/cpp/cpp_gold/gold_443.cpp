#include <bits/stdc++.h>
using namespace std;
int z[1000100];
string s;
void Z_function_wrong(string st) {
memset(z, 0, sizeof(z));
int i = 0, l = 0, r = 0, d = s.length();
while (i < d) {
if (i > r) {
while (st[z[i]] == st[i + z[i]] && i + z[i] < d) z[i]++;
r = i + z[i] - 1;
l = i;
} else
z[i] = min(z[i - l], r - i + 1);
i++;
}
}
void Z_function1(string st) {
memset(z, 0, sizeof(z));
int i = 0, l = 0, r = 0, d = st.length();
while (i < d) {
if (i <= r) z[i] = min(z[i - l], r - i + 1);
while (st[z[i]] == st[i + z[i]] && i + z[i] < d) z[i]++;
if (i + z[i] - 1 > r) {
r = i + z[i] - 1;
l = i;
}
i++;
}
}
int main() {
cin >> s;
int t = s.length(), ind = 0, maxz = 0;
Z_function(s);
for (int i = 1; i < t; i++) {
if (z[i] == t - i && maxz >= t - i) {
ind = i;
break;
}
maxz = max(maxz, z[i]);
}
if (ind != 0)
for (int i = ind; i < t; i++) cout << s[i];
else
cout << "Just a legend";
return 0;
}
