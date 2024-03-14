#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 100;
long long sum;
long long sumLeft[MAX];
pair<int, int> arr[MAX];
int main() {
int n, d;
scanf("%d %d", &n, &d);
for (int i = 1; i <= n; i++) {
scanf("%d %d", &arr[i].first, &arr[i].second);
}
arr[n + 1].first = INT_MAX;
sort(arr, arr + n + 1);
for (int i = 1; i <= n; i++) sumLeft[i] = sumLeft[i - 1] + arr[i].second;
sum = sumLeft[n];
long long ans = 0;
for (int i = 1; i <= n; i++) {
int index = distance(
arr,
upper_bound(arr, arr + n + 1, make_pair(arr[i].first + d, INT_MAX)));
ans = max(ans, sumLeft[index - 1] - sumLeft[i - 1]);
}
cout << ans << endl;
}
