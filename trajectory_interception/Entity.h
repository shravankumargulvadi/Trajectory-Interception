#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "fssimplewindow.h"
#include "Maze.h"
#include <chrono>
#include <algorithm>
#include "yssimplesound.h"
#include <queue>
#include<windows.h>
#include <map>



using namespace std;
class compare
{
public:
	bool operator () (cell Node1, cell Node2)
	{
		return Node1.f > Node2.f;
	}
};

class Entity
{

	public:
	int trajTime;
	map<int,cell> trajMap;
	vector<cell> optimalPath;
	vector<cell> expectedTrajectory;
	int entity_row, entity_col;
	Maze *myMaze=nullptr;
	void setMaze(Maze& aMaze);
	void move( int direction);
	void paint();
	bool reset(); // places entity at maze start 
	bool reachedGoal();
	bool isNavigable(int row, int col);
	void celebrate();
	void drawEntity(int vert_x, int vert_y,int inflation, int r, int g, int b);
	void killEntity();
	void erase();
	void findShortestPath();
	vector<cell> getSuccessors(cell currCell, bool visited[][40]);
	void  selfPlay();
	void  selfPlay(Entity* target);
	void drawCrumbs();
	void setTraj(vector<cell> trajectory);
	void Astar3D();
	void getHeuristic(cell* current, cell* target);
	void makeTrajDict(Entity* target);


};
