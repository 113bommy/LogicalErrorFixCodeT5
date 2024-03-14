#include <bits/stdc++.h>
using namespace std;

void func(long long cur, int use, long long &counter) {
if (cur > N) return;
if (use = 0b111) counter++;
func(cur * 10 + 7, use | 0b001, counter);
func(cur * 10 + 5, use | 0b010, counter);
func(cur *
+ 3, use | 0b100, counter); 10 }
int main() {
cin >> N;
long long res = 0;
func(0, 0, res);
cout << res << endl;
}
