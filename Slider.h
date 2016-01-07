/******************************************************************
*	Program		: Slider.h
*	Author		: Krish Godiawala & Shivkumar Dudhani
*	Version		: 1.0
*	Description : Hold the main operations required to solve 
*				  Sam Loyd's Sliding Problem
*******************************************************************/

template <class K, class T>
class Slider : public Configuration<K, T>{
	/*
	Class to hold the x ,y coordinate
	*/
	class position
	{
	public: int x, y;
			position()
			{
				x = 0;
				y = 0;
			}
	};

	string file;
	string fileop;

	/*
	State of puzzle to be stored as a vector of vector
	*/
	int height;
	int width;

public:
	/*
	Check Goal
	*/
	bool checkGoal(T node){
		if (finalmove == node)
			return true;
		else
			return false;
	}

	/*
	Constructor
	Parameters :
	argc : number of command line arguments
	argv : pointer to array containing the command line arguments
	*/
	Slider<K, T>(int argc, char* argv[]){		
		load = true;
		/*
		Input File
		*/
		if (argv[1][0] == '-')
		{
			//User Input
			loadpuzzle();
		}
		else
		{	// Input from file
			this->file = argv[1];
			loadFile();
		}

		/*
		Output File
		*/
		if (argv[2][0] == '-')
		{
			opfile = false;
		}
		else
		{
			opfile = true;
			fileop = argv[2];
		}
	}

	/*
	Load the File
	*/
	bool loadFile()
	{
		string line;
		ifstream filep(this->file);
		if (filep.is_open())
		{
			if (getline(filep, line))
			{
				cout << "File determined the dimensions of the puzzle" << endl;
				/*	Get Width and Height */
				istringstream read(line);

				if (!(read >> width >> height))
				{
					cout << "Unable to read dimensions for matix" << endl;
					return false;
				}
			}
			else
			{
				cout << "Unable to read first line for dimensions" << endl;
				return false;
			}

			if (!(width > 0 && height > 0))
			{
				cout << "No puzzle " << endl;
				return false;
			}
			else
			{
				/*
				********************************************
				Read the initial configuration
				********************************************
				*/

				for (int i = 0; i < height; i++)
				{
					if (getline(filep, line))
					{
						/*
						Check the line length to verify the number of blocks /width
						*/
						if (line.length() != width)
						{
							cout << "Unable to read initial configuration" << endl;
							return false;
						}
						else
						{
							vector<char> row;
							row.clear();
							for (int j = 0; j < width; j++)
							{
								row.push_back(line[j]);
							}
							initial.push_back(row);
						}
					}
					else
					{
						cout << "Unable to read configuration" << endl;
						return false;

					}
				}
				/*
				********************************************
				Read the Blank Line
				********************************************
				*/
				if (getline(filep, line))
				{
					if (!line.empty())
					{
						cout << "No spaceer line : invalid format" << endl;
						return false;
					}
				}
				else
				{
					cout << "No spaceer line : invalid format" << endl;
					return false;
				}

				/*
				********************************************
				Read the final configuration
				********************************************
				*/
				for (int i = 0; i < height; i++)
				{
					if (getline(filep, line))
					{
						/*
						Check the line length to verify the number of blocks /width
						*/
						if (line.length() != width)
						{
							cout << "Unable to read initial configuration" << endl;
							return false;
						}
						else
						{
							vector<char> row;
							row.clear();
							for (int j = 0; j < width; j++)
							{
								row.push_back(line[j]);
							}
							finalmove.push_back(row);
						}
					}
					else
					{
						cout << "Unable to read configuration" << endl;
						return false;

					}
				}
			}
			/*
			Read the initial configuration for the puzzle
			1>Read the number of lines => height
			2>Number of chars =>width
			*/


		}
		else
		{
			cout << "Unable to open File" << endl;
			filep.close();
			return false;
		}
		filep.close();
		return true;

	}

	/*
	Determine the next move
	*/
	vector<T> nextMove(T Move){
		T currentmove;
		T newPos;
		vector<T> newmoves;
		position blank_pos;
		/*
		Move Top
		Move Left
		Move BOttom
		Move Right
		*/
		//Find the . in the vector			
		blank_pos = findpos(Move);

		newPos = swaptop(Move, blank_pos);
		if (!newPos.empty())
			newmoves.push_back(newPos);
		newPos.clear();

		newPos = swapleft(Move, blank_pos);
		if (!newPos.empty())
			newmoves.push_back(newPos);
		newPos.clear();

		newPos = swapbottom(Move, blank_pos);
		if (!newPos.empty())
			newmoves.push_back(newPos);
		newPos.clear();

		newPos = swapright(Move, blank_pos);
		if (!newPos.empty())
			newmoves.push_back(newPos);
		newPos.clear();


		return newmoves;
	}
	/*
	Swap the blank with top block
	*/
	T swaptop(T Move, position blank)
	{
		T newpos;
		if (blank.x + 1 < height)
		{
			newpos = Move;
			char temp;
			temp = newpos[blank.x][blank.y];
			newpos[blank.x][blank.y] = newpos[blank.x + 1][blank.y];
			newpos[blank.x + 1][blank.y] = temp;
		}
		return newpos;
	}

	/*
	Swap the blank with bottom block
	*/
	T swapbottom(T Move, position blank)
	{
		T newpos;
		if (blank.x - 1 >= 0)
		{
			newpos = Move;
			char temp;
			temp = newpos[blank.x][blank.y];
			newpos[blank.x][blank.y] = newpos[blank.x - 1][blank.y];
			newpos[blank.x - 1][blank.y] = temp;
		}
		return newpos;
	}


	/*
	Swap the blank with left block
	*/
	T swapleft(T Move, position blank)
	{
		T newpos;
		if (blank.y - 1 >= 0)
		{
			newpos = Move;
			char temp;
			temp = newpos[blank.x][blank.y];
			newpos[blank.x][blank.y] = newpos[blank.x][blank.y - 1];
			newpos[blank.x][blank.y - 1] = temp;
		}
		return newpos;
	}
	/*
	Swap the blank with right block
	*/
	T swapright(T Move, position blank)
	{
		T newpos;
		if (blank.y + 1 < width)
		{
			newpos = Move;
			char temp;
			temp = newpos[blank.x][blank.y];
			newpos[blank.x][blank.y] = newpos[blank.x][blank.y + 1];
			newpos[blank.x][blank.y + 1] = temp;
		}
		return newpos;
	}
	/*
	Assumption : there is always a blank in the puzzle
	*/
	position findpos(T Move)
	{
		position pos;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (Move[i][j] == '.')
				{
					pos.x = i;
					pos.y = j;
					return pos;
				}
			}
		}
		return pos;
	}

	/*
	Display the Puzzle Set
	*/
	void display(T Move)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << " " << Move[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}


	/*
	Init write to file
	*/
	virtual void writetofile()
	{
		T node;
		ofstream file(fileop);
		if (file.is_open())
		{
			while (!_stack.empty())
			{
				node = _stack.top();
				_stack.pop();
				for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < width; j++)
					{
						file << " " << node[i][j] << " ";
					}
					file << endl;
				}
				file << endl;
			}
			file.close();
			cout << "Solution written to file " << fileop << endl;
		}
		else
		{
			cout << "Unable to write to a file " << fileop << endl;
			opfile = false;
		}
	}

	/*
	Load the puzzle
	using user input
	*/
	void loadpuzzle()
	{
		/*
		Get the the height and width of the puzzle
		*/
		cout << "Enter puzzle height(greater than zero) " << endl;
		cin >> height;
		cout << "Enter puzzle width(greater than zero) " << endl;
		cin >> width;
		
		if (!(width > 0 && height > 0))
		{
			cout << "No puzzle " << endl;
			load = false;
			return;			
		}
		char block;
		int blank = 0;
		/*
		Get the Initial User Puzzle
		*/
		cout << "Enter Initial Puzzle Configuration with \".\" for a blank" << endl;
		for (int i = 0; i < height; i++)
		{
					vector<char> row;
					row.clear();
					for (int j = 0; j < width; j++)
					{
						cout << "Enter block [" << i << "][" << j << "]";
						cin >> block;
						if (block == '.')
							blank++;

						row.push_back(block);
					}
					initial.push_back(row);
		}
		if (blank != 1)
		{
			cout << "No or more Blank specified for the puzzle";
			load = false;
			return;
		}
		/*
		Get the Final User Puzzle
		*/
		blank = 0;
		cout << "Enter Final Puzzle Configuration with \".\" for a blank" << endl;
		for (int i = 0; i < height; i++)
		{
			vector<char> row;
			row.clear();
			for (int j = 0; j < width; j++)
			{
				cout << "Enter block [" << i << "][" << j << "]";
				cin >> block;
				if (block == '.')
					blank++;
				row.push_back(block);
			}
			finalmove.push_back(row);
		}
		if (blank != 1)
		{
			cout << "No or more Blank specified for the puzzle";
			load = false;
			return;
		}
	}
};