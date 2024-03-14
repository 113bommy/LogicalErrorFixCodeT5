#include <bits/stdc++.h>
using namespace std;
void _fill_int(int* p, int val, int rep) {
int i;
for (i = 0; i < rep; i++) p[i] = val;
}
signed long long GETi() {
signed long long i;
scanf("%lld", &i);
return i;
}
int N;
int S[101];
vector<int> V;
void solve() {
int f, i, j, k, l, x, y;
int sa = 0, sb = 0;
cin >> N;
for (i = 0; i < N; i++) {
cin >> S[i];
for (j = 0; j < S[i]; j++) {
cin >> x;
if (j < S[i] / 2)
if (S[i] % 2 && j == S[i] / 2)
V.push_back(x);
else
sb += x;
}
}
sort(V.begin(), V.end());
reverse(V.begin(), V.end());
for (i = 0; i < V.size(); i++) {
if (i % 2)
sb += V[i];
else
sa += V[i];
}
(void)printf("%d %d\n", sa, sb);
}
int main(int argc, char** argv) {
string s;
if (argc == 1) ios::sync_with_stdio(false);
for (int i = 1; i < argc; i++) s += argv[i], s += '\n';
for (int i = s.size() - 1; i >= 0; i--) ungetc(s[i], stdin);
solve();
return 0;
}
