#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin >> n;
vector<int> v(n);
for (int i = 0; i < n; i++) {
cin >> v[i];
}
bool ok = 1;
vector<int> srt;
while (v.size() != 0 && ok) {
int maxi = *max_element(v.begin(), v.end());
for (int i = 0; i < v.size() && ok; i++) {
if (v[i] == maxi) {
if (i > 0 && v[i - 1] < v[i] - 1) ok = 0;
if (i < v.size() - 1 && v[i + 1] < v[i] - 1) ok = 0;
if (ok) {
if (ok) {
v.erase(v.begin() + i);
break;
}
}
}
if (ok)
cout << "YES" << endl;
else
cout << "NO" << endl;
}
