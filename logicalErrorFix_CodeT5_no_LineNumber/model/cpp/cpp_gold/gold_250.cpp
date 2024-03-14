#include <bits/stdc++.h>
using namespace std;
int main() {
int x, n, m = 0, b = 0, v, arr[100000];
cin >> x;
for (int i = 0; i < x; i++) {
cin >> arr[i];
}
for (int i = 0; i < x; i++) {
if (i == x - 1)
break;
else if (arr[i] < arr[i + 1] - 15) {
b++;
m = arr[i];
n = arr[i + 1];
break;
v = arr[i + 1];
}
if (arr[0] > 15)
cout << 15;
else if (x == 1 && arr[0] <= 15)
cout << arr[0] + 15;
else if (b == 0) {
if (v + 15 > 90)
cout << 90;
else
cout << v + 15;
} else if (b > 0)
cout << m + 15;
return 0;
}
