#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	long long x;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		
		while (!(x % 2)) {
			x /= 2;
		} 
		
		if (x == 1)
			printf("NO\n");
		else
			printf("YES\n");
	}


	return 0;
}
