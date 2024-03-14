#include <bits/stdc++.h>
using namespace std;
long long int arr[200005], l[200005], r[200005];
vector<long long int> vec;
map<char, int> mp;
vector<char> st;
long long int n, m;
string s, s1, s2;
int main() {
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
long long int i, j, k, c = INT_MAX, ans = 0, t, z, x, y, curr = -1;
cin >> n;
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
l[n - 1] = 1;
for (i = n - 2; i >= 0; i--) {
if (arr[i] < arr[i + 1])
l[i] = l[i + 1] + 1;
else
l[i] = 1;
}
r[0] = 1;
for (i = 1; i < n; i++) {
if (arr[i] < arr[i - 1])
r[i] = r[i - 1] + 1;
else
r[i] = 1;
}
int lf = 0, rt = n - 1;
if (arr[lf] < arr[rt]) {
curr = arr[lf];
st.push_back('L');
lf++;
} else if (arr[rt] < arr[lf]) {
curr = arr[rt];
st.push_back('R');
rt--;
} else {
curr = -2;
if (l[lf] > r[rt]) {
for (i = 0; i < l[lf]; i++) st.push_back('L');
} else {
for (i = 0; i < r[rt]; i++) st.push_back('R');
}
}
if (curr == -2) {
cout << st.size() << endl;
for (int i = 0; i < st.size(); i++) cout << st[i];
cout << st[i];
return 0;
}
}
while (lf <= rt) {
if (arr[lf] < arr[rt]) {
if (arr[lf] > curr) {
curr = arr[lf];
st.push_back('L');
lf++;
} else if (arr[rt] > curr) {
curr = arr[rt];
st.push_back('R');
rt--;
} else
break;
} else if (arr[rt] < arr[lf]) {
if (arr[rt] > curr) {
curr = arr[rt];
st.push_back('R');
rt--;
} else if (arr[lf] > curr) {
curr = arr[lf];
st.push_back('L');
lf++;
} else
break;
} else if (lf != rt && arr[lf] == arr[rt] && curr < arr[lf]) {
if (l[lf] > r[rt]) {
for (i = 0; i < l[lf]; i++) st.push_back('L');
break;
} else {
for (i = 0; i < r[rt]; i++) st.push_back('R');
break;
}
} else if (lf == rt) {
if (arr[lf] > curr) {
lf++;
st.push_back('L');
break;
} else
break;
} else
break;
}
cout << st.size() << endl;
for (int i = 0; i < st.size(); i++) {
cout << st[i];
}
}
