#include <bits/stdc++.h>
int main() {
int bx, by, n, m, X = 0, Y = 0;
scanf("%d%d", &n, &bx);
int x[n];
for (int i = 0; i < n; i++) scanf("%d", &x[i]);
scanf("%d%d", &m, &by);
int y[m];
for (int i = 0; i < m; i++) scanf("%d", &y[i]);
for (int i = 1; i <= n; i++) {
X += pow(bx, n - i) * x[i - 1];
}
for (int i = 1; i <= m; i++) {
Y += pow(by, m - i) * y[i - 1];
}
if (X == Y)
printf("=");
else if (X < Y)
printf("<");
else
printf(">");
}
