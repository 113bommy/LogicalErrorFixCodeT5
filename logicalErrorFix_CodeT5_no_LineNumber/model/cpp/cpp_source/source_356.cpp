#include <bits/stdc++.h>
using namespace std;
int w, h;
vector<string> feeld;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 1};
int add, id;
void rec(int x, int y) {
if (feeld[y][x] == 'B') {
id |= 1;
return;
}
if (feeld[y][x] == 'W') {
id |= 2;
return;
}
feeld[y][x] = '-';
add++;
for (int i = 0; i < 4; i++) {
int nx = x + dx[i], ny = y + dy[i];
if (!(0 <= nx && nx < w && 0 <= ny && ny < h)) continue;
if (feeld[ny][nx] == '-') continue;
rec(nx, ny);
}
}
void solve() {
int ansb = 0, answ = 0;
for (int i = 0; i < h; i++) {
for (int j = 0; j < w; j++) {
if (feeld[i][j] == '.') {
add = 0;
id = 0;
rec(j, i);
if (id == 1) ansb += add;
if (id == 2) answ += add;
}
}
}
cout << ansb << " " << answ << endl;
}
int main() {
while (1) {
cin >> w >> h;
if (w == 0 && h == 0) break;
feeld.assign(h, "");
for (int i = 0; i < h; i++) cin >> feeld[i];
solve();
}
return 0;
}
