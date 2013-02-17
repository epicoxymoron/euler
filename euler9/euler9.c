#include <stdio.h>

int main(int argc, char **argv) {
	int a, b, c;
	int d = 1000;

	for (c = d - 2; c > 1; c--) {
		if (c % 25 == 0)
		printf("%d\n", c);
		for (b = c-1; b > 1; b--) {
			for (a = b-1; a > 1; a--) {
				if (a*a + b*b == c*c) {
					if (a+b+c == d) {
						printf("%d^2 * %d^2 = %d^2\n", a, b, c);
						printf("%d * %d = %d\n", a*a, b*b, c*c);
						printf("%d + %d + %d = %d\n", a, b, c, d);
						return 0;
					}
				}
				else if (a*a + b*b < c*c) {
					break;
				}
			}
		}
	}
	printf("Couldn't find a, b, and c\n");
	return 1;
}
