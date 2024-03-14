#include <bits/stdc++.h>
using namespace std;
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
int T;
cin >> T;
while (T--) {
int N;
cin >> N;
vector<int> A(N);
for (auto &x : A) cin >> x;
int ganar = 0;
int perder = 0;
for (int i = 30; i >= 0; i--) {
int unos = 0;
int ceros = 0;
for (auto &x : A) {
if (x & (1 << i))
unos++;
else
ceros++;
}
if (unos % 2 == 0) continue;
if ((unos % 4 == 3) && (ceros % 2 == 0)) {
perder = 1;
break;
ganar = 1;
break;
}
if (ganar) {
cout << "WIN\n";
;
continue;
}
if (perder) {
cout << "LOSE\n";
;
continue;
}
cout << "DRAW\n";
;
}
return 0;
}
