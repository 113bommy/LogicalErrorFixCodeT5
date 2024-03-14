#include <bits/stdc++.h>
using namespace std;
struct person {
int height;
int width;
int diff;
};
struct person people[1005];
int cmp(const struct person &a, const struct person &b) {
return (a.diff) > (b.diff);
}
int main() {
int n;
long long ans = 1000000000;
scanf("%d", &n);
for (int i = 1; i <= n; i++) {
scanf("%d %d", &people[i].width, &people[i].height);
people[i].diff = people[i].width - people[i].height;
}
sort(people + 1, people + n + 1, cmp);
long long H, W;
for (int i = 2; i <= 2 * n + 1; i++) {
H = ((i % 2 == 0) ? (people[(i >> 1)].height) : (people[(i >> 1)].width));
W = ((i % 2 == 0) ? (people[(i >> 1)].width) : (people[(i >> 1)].height));
int left = (n >> 1) - (i % 2);
int k = (i >> 1);
for (int j = 1; j <= n; j++) {
if (k != j) {
if ((people[j].height > H && people[j].width > H))
goto next;
else if (people[j].height > H) {
left--;
W += people[j].height;
}
}
}
if (left < 0) goto next;
for (int j = 1; j <= n; j++) {
if (k != j && people[j].height <= H) {
if (people[j].width <= H && people[j].diff > 0 && left > 0) {
left--;
W += people[j].height;
} else
W += people[j].width;
}
}
ans = ans < W * H ? ans : W * H;
next:;
}
printf("%I64d\n", ans);
}
