#include <bits/stdc++.h>
using namespace std;
int main() {
string a, b;
getline(cin, a);
getline(cin, b);
sort(a.begin(), a.end());
int z = 0;
int idx = 0;
for (int i = 0; i < a.size(); i++) {
if (a[i] == '0')
z++;
else {
idx = i;
break;
}
}
string res;
if (idx != 0) {
res.push_back(a[idx]);
idx++;
}
for (int i = 0; i < z; i++) {
res.push_back('0');
}
for (int i = idx; i < a.size(); i++) res.push_back(a[i]);
if (res == b)
cout << "OK" << endl;
else
cout << "WRONG_ANSWER" << endl;
return 0;
}
