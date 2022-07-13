#include <iostream>
#include <vector>
using namespace std;

int traverse(short x, short y, short delX, short delY, short *grid[], short h, short w) {
	int count = 0;
	x += delX;
	y += delY;
	if (x > h || y > w || x < 1 || y < 1 || grid[x][y] < 0)
		return 0;	
	else if (grid[x][y] == 0) {
		grid[x][y] = 2;
		count++;
	} else {count += traverse(x,y, delX,delY, grid, h,w);}
	return count;
}


int main(void) {
	int height, width, bulbs, blocks;

	cin >> height >> width >> bulbs >> blocks;

	short * grid[height+1];
	for (int i = 1; i < height+1; i++)
		grid[i] = new short[width]();  // 1 indexing
	
	pair<short,short> xy;
	
	pair<short,short> b[bulbs];
	vector<short> bx[height];
	vector<short> by[width];
	for (int i = 0; i < bulbs; i++) {
		cin >> xy.first >> xy.second;
		grid[xy.first][xy.second] = 1;
		bx[xy.first].push_back(xy.second);
		by[xy.second].push_back(xy.first);
		
		b[i] = xy;
	}
	cout << "scanned bublbs";

	vector<short> blx[height];
	vector<short> bly[width];
	for (int i = 0; i < blocks; i++) {
		cin >> xy.first >> xy.second;
		blx[xy.first].push_back(xy.second);
		bly[xy.second].push_back(xy.first);
	}
	cout << "scanned blocs";

	unsigned int count = bulbs;
	short greater, lesser, x,y;
	for (short i = 0; i < height; i++) {
		x = i+1;
		for (auto i : bx[i])
			cout << i << ' ';

		xy = b[i];
		greater = height+1; lesser = 0;
		// cout << "starting with " << xy.first << ", "<< xy.second << '\n';
		for (auto i : blx[xy.first]) {
			if (i < xy.first && i > lesser)
				lesser = i;
			else if (i > xy.first && i < greater)
				greater = i;
		}
		for (auto i : blx[xy.first]) {
			if (i < xy.first && i > lesser)
				lesser = i;
			else if (i > xy.first && i < greater)
				greater = i;
		}
		
		cout << "lesser, greater\t" << lesser << ", " << greater << '\n';




		//count +=  + traverse(xy.first,xy.second,0,-1,grid,height,width) + traverse(xy.first,xy.second,1,0,grid,height,width) + traverse(xy.first,xy.second,-1,0,grid,height,width);  // down
	}

	cout << count;

	return 0;
}
