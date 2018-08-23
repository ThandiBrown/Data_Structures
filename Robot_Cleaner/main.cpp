


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {

	srand(time(0));

	int robot_row, robot_col;	// the row and column position of the robot respectively
	int room_length;
	int num_of_moves;
	int next_move;
	bool clean = true;
	bool restart;

	do
	{
		restart = false;

		cout << "Enter the location (x,y); room dimensions (x,y); and number of moves." << endl;
		
		try 
		{
			cin.exceptions(istream::failbit);
			cin >> robot_row >> robot_col >> room_length >> num_of_moves;
		}
		catch(const ios::failure& e)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "Only use integers as inputs. Please try again.\n";
			restart = true;
			system("pause");
			continue;
		}
		

		if (robot_col == 0)
		{
			robot_col = 0;
		}
		else if (robot_row == 0)
		{
			robot_row = 0;
		}
		else if ((robot_col >= room_length + 1) || robot_col <= 0 || (robot_row >= room_length + 1) || robot_row <= 0)
		{
			restart = true;
			cout << "The coordinates you have entered are off the grid. Please try again.\n";
		}
		else
		{
			robot_col--;
			robot_row--;
		}

	} 
	while (restart);

	/* allocate space for a 2d array */
	int ** room_tiles = new int*[room_length];	
	for (int i = 0; i < room_length; i++)
		room_tiles[i] = new int[room_length];
	
	/* initializes elements in the array and sets them equal to zero */
	for (int i = 0; i < room_length; i++)		
		for (int j = 0; j < room_length; j++)
			room_tiles[i][j] = 0;


	cout << robot_row << " " << robot_col << " \n";
	room_tiles[robot_row][robot_col] = 1;


	/* making moves */
	for (int i = 0; i < num_of_moves; i++)
	{
		next_move = (rand() % 4) + 1;		// generate number b/w 1 and 4
		cout << next_move;

		switch (next_move)
		{
		case 1:
			robot_row--;
			if (robot_row < 0)
				robot_row = 0;

			cout << " Coordinates:" << robot_row << " " << robot_col << " " << endl;
			room_tiles[robot_row][robot_col] = 1;
			break;

		case 2:
			robot_row++;
			if (robot_row >= room_length)
				robot_row = room_length - 1;

			cout << " Coordinates:" << robot_row << " " << robot_col << " " << endl;
			room_tiles[robot_row][robot_col] = 1;
			break;

		case 3:
			robot_col--;
			if (robot_col < 0)
				robot_col = 0;

			cout << " Coordinates:" << robot_row << " " << robot_col << " " << endl;
			room_tiles[robot_row][robot_col] = 1;
			break;

		case 4:
			robot_col++;
			if (robot_col >= room_length)
				robot_col = room_length - 1;

			cout << " Coordinates:" << robot_row << " " << robot_col << " " << endl;
			room_tiles[robot_row][robot_col] = 1;
			break;

		default:
			cout << "Your random numbers are off: " << next_move << endl;
			break;

		}
	}
	
	/* checks if room is clean */
	for (int i = 0; i < room_length; i++)
	{		
		for (int j = 0; j < room_length; j++)
		{
			if (room_tiles[i][j] == 0)
			{
				clean = false;
			}
			cout << room_tiles[i][j] << " ";
		}

		cout << "\n";
	}
			
	if (clean)
	{
		cout << "The room is clean." << endl;
	}
	else
	{
		cout << "The room is dirty" << endl;
	}

	system("pause");
}