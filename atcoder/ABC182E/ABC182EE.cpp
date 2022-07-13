#include <iostream>
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
	} 
	else  // this was all the optimization needed :sob:
		{count += traverse(x,y, delX,delY, grid, h,w);}
	return count;
}


int main(void) {
	int height, width, bulbs, blocks;

	cin >> height >> width >> bulbs >> blocks;

	short * grid[height+1];
	for (int i = 1; i < height+1; i++)
		grid[i] = new short[width]();  // 1 indexing
	pair<short,short> b[bulbs];
	
	pair<short,short> xy;
	for (int i = 0; i < bulbs; i++) {
		cin >> xy.first >> xy.second;
		grid[xy.first][xy.second] = 1;
		
		b[i] = xy;
	}
	for (int i = 0; i < blocks; i++) {
		cin >> xy.first >> xy.second;
		grid[xy.first][xy.second] = -1;
	}

	unsigned int count = bulbs;
	for (short i = 0; i < bulbs; i++) {
		xy = b[i];
		// cout << "starting with " << xy.first << ", "<< xy.second << '\n';
		count += traverse(xy.first,xy.second,0,1,grid,height,width) + traverse(xy.first,xy.second,0,-1,grid,height,width) + traverse(xy.first,xy.second,1,0,grid,height,width) + traverse(xy.first,xy.second,-1,0,grid,height,width);  // down
	}

	cout << count;

	return 0;
}
