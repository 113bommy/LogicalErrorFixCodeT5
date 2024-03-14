#include <bits/stdc++.h>
using namespace std;
long long p2[30];
int dp[30][30];
int full[30][30];
int main() {
int k;
cin >> k;
p2[0] = 1;
int lgk;
for (int i = 1; i < 30; i++) p2[i] = (p2[i - 1] * 2);
for (int i = 0; i < 30; i++)
if ((k & p2[i]) && k - p2[i] < p2[i]) lgk = i + 1;
full[0][0] = 1;
for (int i = 1; i <= lgk; i++)
for (int j = 0; j <= i; j++) {
if (j == 0)
full[i][j] = (full[i - 1][j] * 2) % 1000000007;
else
full[i][j] = (((full[i - 1][j] * 2) % 1000000007) +
((full[i - 1][j - 1] * p2[i - j]) % 1000000007)) %
1000000007;
}
dp[0][0] = 1;
for (int i = 1; i < lgk; i++)
for (int j = 0; j <= i; j++) {
if (j == 0) {
if ((k & p2[i - 1]) == 0)
dp[i][j] = dp[i - 1][j];
else
dp[i][j] = (full[i - 1][j] + dp[i - 1][j]) % 1000000007;
} else if ((k & p2[i - 1]) == 0)
dp[i][j] = dp[i - 1][j];
else
dp[i][j] = (((full[i - 1][j] + dp[i - 1][j]) % 1000000007) +
((dp[i - 1][j - 1] * p2[i - j]) % 1000000007)) %
1000000007;
}
int ans = 0;
for (int j = 1; j <= lgk; j++) {
ans = (ans + dp[lgk - 1][j - 1]) % 1000000007;
}
for (int i = 1; i < lgk; i++)
for (int j = 1; j <= i; j++) {
ans = (ans + full[i - 1][j - 1]) % 1000000007;
}
cout << ans + 1 << endl;
}
