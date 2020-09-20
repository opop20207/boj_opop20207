#include <stdio.h>
#include <math.h>

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return a < b ? b : a;
}

int main(void)
{
	int T;
	double x1, y1, r1, x2, y2, r2;
	scanf("%d", &T);
	while (T--) {
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
		double temp;
		int res;
		temp = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		if (temp + (double)min(r1, r2) < max(r1, r2)) {
			printf("0\n");
			continue;
		}
		if (temp + (double)min(r1, r2) == max(r1, r2)) {
			if (x1 == x2 && y1 == y2 && r1 == r2) {
				printf("-1\n");
				continue;
			}
			else if (x1 == x2 && y1 == y2 && r1!=r2) {
				printf("0\n");
				continue;
			}
			else {
				printf("1\n");
				continue;
			}
		}
		if (temp + (double)min(r1, r2) > max(r1, r2)) {
			if (temp == r1 + r2) {
				printf("1\n");
				continue;
			}
			if (temp > r1 + r2) {
				printf("0\n");
				continue;
			}
			if (temp < r1 + r2) {
				printf("2\n");
				continue;
			}
		}
	}
}