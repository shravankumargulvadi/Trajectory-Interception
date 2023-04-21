#include "Maze.h"
#include "Entity.h"




int Menu(string &customFileName)
{//ask user to choose level and return it
	string userAns;
	int level;
	cout << "Do you want to load a custom level? Y/N :";
	cin >> userAns;
	if (userAns == "N" || userAns == "n") //Load standard levels if not custom levels
	{
		cout << "Choose level to play: " << endl << "Press '1' for level-1" << endl;
		cout << "Press '2' for level-2" << endl << "Press '3' for level-3" << endl << "Level: ";
		cin >> level;
		return level;
	}
	else if (userAns == "Y" || userAns == "y")//if user chooses custom level take filename
	{
		cout << "Enter the file name : ";
		cin >> customFileName;
		std::ifstream inFile4(customFileName);

		cout << endl << "chosen file name is" <<" "<< customFileName<<endl;
		level = -1;
		return level;
	}
	else//wrong key typed
	{
		cout << "Invalid input" << endl;
		Menu(customFileName);
	}
}

std::ostream& operator<<(std::ostream& os, const Maze& aMaze)
{//overload '<<' for osstream
	os << "Start: " << aMaze.startRow << " " << aMaze.startCol << endl;
	os << "End: " << aMaze.goalRow << " " << aMaze.goalCol << endl;
	os << "Map Begin: " << aMaze.totalCols << endl;
	for (int i = 0; i <= aMaze.max_row; i++) {
		for (int j = 0; j <= stoi(aMaze.totalCols); j++)
			os << aMaze.map[i][j] << " ";
		os << endl;
	}
	os << "Map End: " << endl;
	return os;
}

void saveFile(Maze& theMaze)
{// function to savefile,
	string fileToSave;
	cout << "Enter the name of the file to save >> ";
	cin >> fileToSave;
	if (fileToSave.length() > 0)
	{
		ofstream outfile(fileToSave);
		if (outfile.is_open())
		{
			outfile << theMaze;//using overloaded '<<' operator
			outfile.close();
		}
		else {
			cout << "could not open the file";
		}
	}
}


int main()
{
	
	int key;
	int mouseEvent, leftButton, middleButton, rightButton, locX, locY;
	Entity entity, target;
	string customFileName;
	int level = Menu(customFileName); //display menu and read level
	
	
	FsOpenWindow(5, 5, 800, 800, 0, "Maze Game");

	while (level != 0)
	{
		
		
		Maze aMaze;
		
		entity.setMaze(aMaze);// let entity know the maze
		target.setMaze(aMaze);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		

		//read the maps as per the level variable
		if (level == 1)
		{
			std::ifstream inFile1("mazeA_10x10.map");
			aMaze.readFile(inFile1);
			
			
		}
		else if (level == 2)
		{
			std::ifstream inFile2("mazeB_25x25.map");
			aMaze.readFile(inFile2);
			/*vector<cell> trajectory = { {6,10},{5,10},{4,10},{4,9},{4,8},{3,8},{3,7},{2,7},{1,7},{0,7},{0,6},{0,5},{1,5},{2,5},{3,5},
										{3,4},{4,4},{4,3},{4,2},{5,2},{6,2},{6,3},{7,3},{8,3},{8,4},{9,4},{10,4},{11,4},{11,3},{11,2},
										{10,2},{10,1},{10,0},{11,0},{12,0},{13,0},{13,1},{13,2},{13,3},{13,4},{13,5},{13,6},{14,6},{15,6},
										{15,7},{15,8},{14,8},{13,8},{12,8},{12,9},{11,9},{10,9},{10,10},{9,10},{8,10},{8,11},{8,12},{7,12},
										{6,12},{5,12},{4,12},{3,12},{3,13},{2,13},{1,13},{1,14},{1,15},{0,15},{0,16},{0,17},{1,17},{2,17},
										{3,17},{3,18},{3,19},{2,19},{2,20},{2,21},{1,21},{0,21},{0,22},{0,23},{1,23},{1,24},{2,24},{3,24},
										{4,24},{4,23},{4,22},{4,21},{5,21},{6,21},{6,20},{6,19},{6,18},{6,17},{6,16},{7,16},{8,16},{9,16},
										{9,17},{9,18},{9,19},{8,19},{8,20},{8,21},{8,22},{9,22},{9,23},{9,24},{10,24},{11,24},{12,24},{12,23},
										{12,22},{11,22},{11,21},{11,20},{12,20},{13,20},{14,20},{15,20},{16,20},{16,19},{16,18},{16,17},{16,16},
										{17,16},{18,16},{19,16},{20,16},{21,16},{21,15},{22,15},{22,14},{22,13},{22,12},{23,12},{24,12},{24,13},
										{24,14},{24,15},{24,16},{24,17},{23,17},{23,18},{22,18},{21,18},{20,18},{19,18},{19,19},{19,20},{19,21},
										{19,22},{19,23},{19,24},{20,24},{21,24} };*/

			vector<cell> trajectory = { {12,11},{12,12},{12,13},{12,14},{12,15},{12,16},{12,16},{12,16},{11,16},{10,16},{9,16},{9,17},{9,18},{9,19},{8,19},{8,20},{8,21},{8,22},{9,22},{9,23},{9,24},{10,24},{11,24},{12,24},{12,23},
										{12,22},{11,22},{11,22},{11,21},{11,20},{12,20},{13,20},{13,20},{13,20},{13,20},{13,20},{14,20},{15,20},{16,20},{16,19},{16,18},{16,17},{16,16},
										{17,16},{18,16},{19,16},{20,16},{20,16},{20,16},{20,16},{20,16},{20,16},{20,16},{20,16},{20,16},{20,16},{20,16},{20,16},{21,16},{21,15},{21,15},{21,15},{21,15},{21,15},{21,15},{21,15},{21,15},{21,15},{21,15},{21,15},{21,15},{22,15},{22,14},{22,13},{22,12},{23,12},{24,12},{24,13},
										{24,14},{24,15},{24,16},{24,17},{23,17},{23,18},{22,18},{21,18},{20,18},{19,18},{19,19},{19,20},{19,21},
										{19,22},{19,23},{19,23},{19,23},{19,23},{19,23},{19,23},{19,23},{19,23},{19,23},{19,23},{19,23},{19,24},{20,24},{21,24} };
		
			reverse(trajectory.begin(), trajectory.end()); //reverse it to maintain homogeneity in selfPlay()
			target.setTraj(trajectory);
			
		}
		else if (level==3)
		{
			std::ifstream inFile3("mazeC_40x20.map");
			aMaze.readFile(inFile3);
			
		}
		else if(level==-1) //if level is custom
		{
			std::ifstream inFile4(customFileName);
			
			//try {
				aMaze.readFile(inFile4);
			//	throw(customFileName);
			//}
			//this part doesnt seem to be giving an error while reading invalid file names
			//catch (string customFileName)
			//{
			//	cout << "Entered file name is invalid" << endl;
			//	main();
			//}

		}
		aMaze.paint();
		entity.entity_row = stoi(aMaze.startRow);
		entity.entity_col = stoi(aMaze.startCol);
		target.entity_row = stoi(aMaze.goalRow);
		target.entity_col = stoi(aMaze.goalCol);
		aMaze.printMaze();

		

		while (FSKEY_NULL == FsInkey())
		{
			//paint maze and entity
			
			aMaze.paint();
			entity.drawEntity(20 * (entity.entity_col - 1), 20 * (entity.entity_row - 1), 1, 0, 0, 125);
			target.drawEntity(20 * (target.entity_col - 1), 20 * (target.entity_row - 1), 1, 0, 0, 125);
			glFlush();
			FsPollDevice();
			key = FsInkey();
			mouseEvent = FsGetMouseEvent(leftButton, middleButton,rightButton, locX,locY);
			
			
			if (mouseEvent == FSMOUSEEVENT_LBUTTONDOWN )
			{// if left mouse button down the we change the map state
				
				aMaze.changeMapState(locX, locY, mouseEvent);
				aMaze.printMaze();
				aMaze.paint();
			}
			if (key == FSKEY_E || key == FSKEY_S)
			{// if 'E' or 'S' is pressed change map state 
				aMaze.changeMapState(locX, locY, key);
				aMaze.printMaze();
				aMaze.paint();
			}
			if (entity.reachedGoal())
			{//if goal is reached kill the bug and celebrate
				entity.killEntity(); //makes kill animation
				glFlush();
				entity.celebrate(); //Plays music
				if (level <= 2)
				{
					level += 1;
					break;
				}
				else
				{
					cout << "You Win!!!!"<<endl;
					break;
				}
			}
			// take keyboard input and call move function
			if (key == FSKEY_ESC)
			{
				return 0;
			
			}
			else if (key == FSKEY_W) //press 'w' to save file
			{
				saveFile(aMaze);
			}
			else if (key == FSKEY_G) //press 'G' for selfplay
			{
				 //find shortest path using depth first search
				if (level == 2)
				{
					entity.makeTrajDict(&target);
					entity.Astar3D();
					entity.selfPlay(&target);
				}
				else
				{
					entity.findShortestPath();
					entity.selfPlay(); //execute the found path
				}
			}
			else
			{
				entity.move(key); 
			}
			
		}
	}
}