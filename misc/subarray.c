#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int argc;
	scanf("%d", &argc);
	int *argv = malloc(sizeof(int) * argc);
	for (int i = 0; i < argc; i++)
		scanf("%d", argv+i);

	int sum = 0, max = 0;
	int start = 0, fin = 0;
	for (int i = 0; i < argc; i++) {
		if ((sum + argv[i]) <= 0) {
			sum = 0;
			start = i + 1;
		}
		else
			sum += argv[i];
		if (max < sum) {
			max = sum;
			fin = i;
		}
	}
	printf("%d\n", max);
	printf("[");
	for (int i = start; i <= fin; i++)
		printf("%d, ", argv[i]);
	printf("]");

	return 0;
}
