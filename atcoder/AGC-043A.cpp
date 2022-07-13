// #include <bits/stdc++.h> turns out atcoder doesnt provide bits
#include <iostream>
#include <climits>
using namespace std;

int traverse(const int x, const int y, int * mem[], const int maxX, const int maxY, bool * map[]) {
        if (x == maxX-1 && y == maxY-1)  // base case, at the end corner
                return map[x][y];  // returns 1 if black (needs a change)
        if (mem[x][y] == -1) {  // no cache hit
                int right = INT_MAX, down = INT_MAX;  // dummy values as null case
                if (x < maxX-1) {  // can go right
                        right = traverse(x+1, y, mem, maxX, maxY, map);
                        if (map[x+1][y] != map[x][y] && map[x][y])  // we are black, next space is white, add an operation
                                right++;
                }
                if (y < maxY-1) {  // can go left
                        down = traverse(x, y+1, mem, maxX, maxY, map);
                        if (map[x][y+1] != map[x][y] && map[x][y])  // we are black, next space is white, add an operation
                                down++;
                }

                mem[x][y] = min(right, down);
        }


        return mem[x][y];
}

int main(void) {
        int x, y;
        scanf("%d %d", &x, &y);
        bool **map = new bool*[x];
        int **mem = new int*[x];

        char buf;
        for (int i = 0; i < x; i++) {
                buf = getchar();
                mem[i] = new int[y];
                map[i] = new bool[y];
                for (int j = 0; j < y; j++) {
                        cin >> buf;
                        map[i][j] = (buf == '#');  // true is black, false is white
                        mem[i][j] = -1;
                }
        }
        cout << traverse(0,0, mem, x,y, map);

        return 0;
}