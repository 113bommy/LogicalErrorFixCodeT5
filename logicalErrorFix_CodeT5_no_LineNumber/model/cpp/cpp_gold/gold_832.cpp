#include <bits/stdc++.h>
using namespace std;
struct Node {
vector<int> v;
};
vector<Node> tree(4 * 1e6 + 5);
vector<int> arr(1e6 + 5);
vector<int> merge(vector<int> v1, vector<int> v2) {
int i1 = 0, i2 = 0;
vector<int> ans;
while (i1 < v1.size() and i2 < v2.size()) {
if (v1[i1] <= v2[i2])
ans.push_back(v1[i1++]);
else
ans.push_back(v2[i2++]);
}
while (i1 < v1.size()) ans.push_back(v1[i1++]);
while (i2 < v2.size()) ans.push_back(v2[i2++]);
return ans;
}
void build(int ss, int se, int idx) {
if (ss == se) {
tree[idx].v.push_back(arr[ss]);
return;
}
int mid = (ss + se) / 2;
build(ss, mid, 2 * idx);
build(mid + 1, se, 2 * idx + 1);
tree[idx].v = merge(tree[2 * idx].v, tree[2 * idx + 1].v);
}
int query(int ss, int se, int idx, int l, int r, int k) {
if (l > se or r < ss) return 0;
if (l <= ss and r >= se)
return (lower_bound(tree[idx].v.begin(), tree[idx].v.end(), k) -
tree[idx].v.begin());
int mid = (ss + se) / 2;
int x = query(ss, mid, 2 * idx, l, r, k);
int y = query(mid + 1, se, 2 * idx + 1, l, r, k);
return x + y;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
;
int n;
cin >> n;
vector<int> a(n);
unordered_map<int, int> f, m;
for (int i = (0); i <= (n - 1); i += (1)) cin >> a[i];
for (int i = (n - 1); i >= (0); i -= (1)) {
f[a[i]]++;
arr[i] = f[a[i]];
}
build(0, n - 1, 1);
long long int ans = 0;
for (int i = (0); i <= (n - 1); i += (1)) {
m[a[i]]++;
ans += query(0, n - 1, 1, i + 1, n - 1, m[a[i]]);
}
cout << ans << endl;
return 0;
}
