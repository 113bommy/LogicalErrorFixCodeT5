#include <bits/stdc++.h>
using namespace std;
bool occured[2001];
bool occupied[2001];
long long int f[2001];
long long int invf[2001];
int a[2001];
long long int power(long long int b, long long int e) {
if (e == 0) {
return 1LL;
} else if (e == 1) {
return b;
} else {
long long int p = power(b, e / 2);
if (e % 2 == 0) {
return (p * p) % 1000000007;
} else {
p = (p * p) % 1000000007;
p = (p * b) % 1000000007;
return p;
}
}
}
void calc() {
f[0] = 1LL;
for (int i = 1; i <= 2000; i++) {
f[i] = (f[i - 1] * i) % 1000000007;
}
invf[2000] = power(f[2000], 1000000007 - 2);
for (int i = 1999; i >= 0; i--) {
invf[i] = (invf[i + 1] * (i + 1)) % 1000000007;
}
}
long long int nCr(long long int n, long long int r) {
if (r > n) {
return 0;
} else {
long long int temp = f[n];
temp = (temp * invf[n - r]) % 1000000007;
temp = (temp * invf[r]) % 1000000007;
return temp;
}
}
int main() {
calc();
int n;
scanf("%d", &n);
for (int i = 1; i <= n; i++) {
int temp;
scanf("%d", &temp);
a[i] = temp;
}
for (int i = 1; i <= n; i++) {
occupied[i] = true;
}
for (int i = 1; i <= n; i++) {
if (a[i] != -1) {
occured[a[i]] = true;
} else if (a[i] == -1) {
occupied[i] = false;
}
}
int proper = 0;
int positions = 0;
for (int i = 1; i <= n; i++) {
if (!occured[i] && !occupied[i]) {
proper++;
}
}
for (int i = 1; i <= n; i++) {
if (!occupied[i]) {
positions++;
}
}
long long int answer1 = 0;
for (int i = 0; i <= proper; i++) {
if (i % 2 == 0) {
answer1 = (answer1 + nCr(proper, i) * f[positions - i]) % 1000000007;
} else {
answer1 = ((answer1 - nCr(positions, i) * f[positions - i]) % 1000000007 +
1000000007) %
1000000007;
}
}
printf("%lld\n", answer1);
return 0;
}
