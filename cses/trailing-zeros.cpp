#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int a = 0;
	for (int i = 5; i <= n; i*=5) {
		a += n / i;
	}
	cout << a;
	return 0;
}
