#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
using namespace std;

struct cell
{
	int row, col;
	float h,g,f;
	int time;
};
class Maze
{
private:
	
	int currRow=0;
	
	
	


public:
	string startRow, startCol, goalRow, goalCol, totalCols;
	int quadSize = 20;
	
	
	int max_row;
	string map[40][40];

	void readFile(std::ifstream& input);
	void printMaze();
	void paint();
	void makeQuad(int vert_x, int vert_y,int r,int g,int b);
	void printMessage();
	void changeMapState(int mouseX, int mouseY, int key);
	

};
