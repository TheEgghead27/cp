#include <stdio.h>

int main(void) {
	char str[101], c;
	int R, B, Y, G, n[100], i = 0, j = 0;
	bool cool = true;
	while (cool) {
		c = getchar(str);
		switch(c) {
			case 'R':
				R++;
				break;
			case 'B':
				B++;
				break;
			case 'Y':
				Y++;
				break;
			case 'G':
				G++;
				break;
			case '!':
				n[j];
				j++;
				break;
			default:
				cool = false;
				c = '\0';
		}
		str[i] = c;
		i++;
	}
	i -= 2;
	int target = i / 4;
	R = target - R;
	B = target - B;
	Y = target - Y;
	G = target - G;
	for (int k = 0; k < j; k++) {
		if (n[k] < target * 4)
			continue;
		n[k]

	}


	return 0;
}
