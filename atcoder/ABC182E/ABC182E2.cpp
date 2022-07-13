#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

pair<short,short> processPointLine(short x, short y, short n1y, short n2y, vector<short> blocksX[]) {
        bool n1t = false, n2t = false;
        // look for blocks in vicinity (capped off at neighboring bulbs)
        for (auto block : blocksX[x]) {
                if (block < n1y) {
                        n1y = block;
                        n1t = true;
                }
                else if (block > n2y) {
                        n2y = block;
                        n2t = true;
                }
        }

        // place virtual blocks around neighboring bulbs to block double-counting
        if (!n1t) {  // we bounded at a light to our left, block it off
                blocksX[x].push_back(n1y+1);
        }
        if (!n2t) {  // we bounded at a light to our right, block it off
                blocksX[x].push_back(n2y-1);
        }

        cout << "got range from (" << x << ", " << y << "); [" << n1y << " to " << n2y << "]\n";

        return pair<short,short>(n1y, n2y); // note down glowable ranges
}


int main(void) {
        // read in data
        int height, width, bulbs, blocks;
        cin >> height >> width >> bulbs >> blocks;

        short x, y;  // buffer vars

        // read in bulbs
        vector<short> bulbsX[height];
        vector<short> bulbsY[width];
        for (short i = 0; i < bulbs; i++) {
                cin >> x >> y;
                x--;
                y--;
                bulbsX[x].push_back(y);
                bulbsY[y].push_back(x);
        }

        // read in blocks
        vector<short> blocksX[height + 1];
        vector<short> blocksY[width + 1];
        for (short i = 0; i < bulbs; i++) {
                cin >> x >> y;
                x--;
                y--;
                blocksX[x].push_back(y);
                blocksY[y].push_back(x);
        }

        // fill out edges with virtual blocks
        for (int i = 0; i < width + 1; i++) {
                blocksX[height].push_back(i);
        }
        for (int i = 0; i < height + 1; i++) {
                blocksY[width].push_back(i);
        }


        for (short x = 0; x < height; x++) {  // sort each column
                sort(bulbsX[x].begin(), bulbsX[x].end());
        }
        for (short y = 0; y < width; y++) {  // and sort each row
                sort(bulbsY[y].begin(), bulbsY[y].end());
        }

        for (short x = 0; x < height; x++) {  // for each column's
                processPointLine(x, bulbsX[x][0], -1, bulbsX[x][x + 1], blocksX);
                for (short i = 1; i < bulbsX[x].size() - 1; i++) {  // bulbs (and in turn, every bulb)
                        processPointLine(x, bulbsX[x][bulbsX[x].size() - 1], bulbsX[x][x - 1], bulbsX[x][x + 1],
                                         blocksX);
                }
                cout << "moving on\n";
                processPointLine(x, bulbsX[x][bulbsX[x].size() - 1], bulbsX[x][x - 1], height + 1, blocksX);
        }
}