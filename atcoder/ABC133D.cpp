// based on editorial
// moral of the story: try to do math outside of the problem itself, and solve for x and stuff i guess lol

#include <iostream>
using namespace std;

int main(void) {
	unsigned short n;
	cin >> n;
	unsigned long long s = 0, t = 0;
	unsigned int a[n], mountain;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	// mfw giving up and reading the editorial still takes a good minute to understand
		s += a[i];
		if ((i % 2))
			t += a[i];
	}
	mountain = s - (2 * t);  // mfw you in fact did not understand
				 // (its a bunch of algebra you did not see coming)
	cout << /*s << ' ' << t << ' ' <<*/ mountain;

	for (int i = 0; i < n-1; i++) {
		mountain = (2 * a[i]) - (mountain);
		cout << ' ' << mountain;
	}



	





	return 0;
}
