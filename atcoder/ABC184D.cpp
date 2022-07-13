#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

#define TARGET 100

double mem[TARGET + 1][TARGET + 1][TARGET + 1];

double recurse(int a, int b, int c) {
	if (mem[a][b][c]) {return mem[a][b][c];}
	if (a == TARGET || b == TARGET || c == TARGET) {
		return 0;
	}
	
	double res = 0;
	res += ((recurse(a+1,b,c)+1) * a / (a+b+c));
	res += ((recurse(a,b+1,c)+1) * b / (a+b+c));
	res += ((recurse(a,b,c+1)+1) * c / (a+b+c));
	mem[a][b][c] = res;

	return res;
}


int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	
	/*
	for (int i = 1; i < TARGET + 1; i++) {
		for (int j = 1; j < TARGET + 1; j++) {
			for (int k = 1; k < TARGET + 1; k++) {
				mem[i][j][k] = 0;
			}
		}
	}
	*/

	printf("%.7f",recurse(a,b,c));

	return 0;
}
