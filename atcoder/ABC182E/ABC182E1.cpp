#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int height, width, bulbs, blocks;

	cin >> height >> width >> bulbs >> blocks;
	
	short x,y;

	vector<short> bulbsX[height+1];  // 1-index
	vector<short> bulbsY[width+1];

	for (short i = 0; i < bulbs; i++) {
		cin >> x >> y;
		bulbsX[x].push_back(y);
		bulbsY[y].push_back(x);
	}

	vector<short> blocksX[height];
	vector<short> blocksY[height];
	for (short i = 0; i < bulbs; i++) {
		cin >> x >> y;
		blocksX[x].push_back(y);
		blocksY[y].push_back(x);
	}

	cout << "starting search\n";

	for (short x = 1; x < height+1; x++) {  // each column

		vector<short> vec = bulbsX[x];
		sort(vec.begin(), vec.end());
		cout << "sorted " << x << '\n';
		for (short i = 0; i < vec.size(); i++) {  // each column's lights
			short before = i-1, after = i+1;
			cout << "checking sanity\n";
			if (before < 0) {
				before = 0;
			}
			else {
				before = vec.at(before);
			}
			if (after == vec.size()) {
				after = height+1;
			}
			else {
				after = vec.at(after);
			}
			
			for (short b : blocksX[x]) {
				if (b < vec.at(i) && b > before)
					before = b;
				else if (b > vec.at(i) && b < after)
					after = b;
			}
			rowRanges.push_back(pair<short,short>(before,after));  // duplicates/overlap should be indistinct

		// cout << '(' << x << ", " << i << ')' << ' ' << '[' << before << " - " << after << ']' << '\t';

		}
                unique(rowRanges.begin(), rowRanges.end());
		for (auto s : rowRanges) {
			cout << '[' << s.first << " - " << s.second << ']' << '\t';
		}
		cout << '\n';
	}

        // do it again with rows


	return 0;
}
