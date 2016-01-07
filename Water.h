/******************************************************************
*	Program		: Water.h
*	Author		: Krish Godiawala & Shivkumar Dudhani
*	Version		: 1.0
*	Description : Hold the functionality for water puzzle
*******************************************************************/

template <class K, class T>
class water : public Configuration<K, T>{
		int length;
		int goal;
		vector<int> _capacityvector;

public:
	/*
	Constructor
	Instantiates the Water class and casts to the puzzle class
	Parameters :
	argc : number of command line arguments
	argv : pointer to array containing the command line arguments
	*/
	water(char *arguments[], int len)
		{
			load = true;
			length = len;
			goal = atoi(arguments[1]);
			for (int i = 2; i < length; i++)
			{
				_capacityvector.push_back(atoi(arguments[i]));
				initial.push_back(0);
			}
		}

	/*
	Determine the next possible moves for the current state
	Case 1: Emptying the jugs
	Case 2: Fill the jugs to the full capacity
	Case 3: Fill the water from each objects
	*/
	vector<T> nextMove(T Move){

			vector<T> newmoves;
			/*
			Check the next moves for all the jugs in the current state
			*/
			for (unsigned int i = 0; i < Move.size(); i++)
			{
				/*
				Emptying the jugs
				*/
				if (Move[i] != 0)
				{
					T empty_jugs;
					empty_jugs = Move;
					empty_jugs[i] = 0;
					newmoves.push_back(empty_jugs);
				}

				/*
				Filling the jugs
				*/
				if (Move[i] != _capacityvector[i])
				{
					T full_jugs;
					full_jugs = Move;
					full_jugs[i] = _capacityvector[i];
					newmoves.push_back(full_jugs);
				}

				/*
				Transferring the content between the Jugs
				*/
				for (unsigned int j = 0; j < Move.size(); j++)
				{
					T transfer_jugs = Move;
					if (i != j)
					{
						if (Move[i] + Move[j] <= _capacityvector[j])
						{
							transfer_jugs[j] = transfer_jugs[i] + transfer_jugs[j];
							transfer_jugs[i] = 0;
							newmoves.push_back(transfer_jugs);
						}
						else
						{
							transfer_jugs[j] = _capacityvector[j];
							transfer_jugs[i] = transfer_jugs[i] - (_capacityvector[j] - Move[j]);
							newmoves.push_back(transfer_jugs);
						}
					}
				}
			}
			return newmoves;
		}

		/*
		Check the goal ,if the current move is final solution
		*/
		bool checkGoal(T node)
		{
			for (unsigned int i = 0; i < node.size(); i++)
			{
				if (node[i] == goal)
				{
					return true;
				}
			}
			return false;
		}

		/*
		Display the moves for the soultion
		*/
		void solutionMoves(T Move)
		{
		map<vector<int>, vector<int>>::iterator itr;
		_stack.push(Move);
		do
		{

			itr = _map.find(Move);
			if (itr != _map.end())
			{
				_stack.push(itr->second);
			}
			Move = itr->second;
		} while (itr->second != initial);

		}
		/*
		Display the jug configuration
		*/
		void display(T Move)
		{
			for (unsigned int i = 0; i<Move.size(); i++)
				cout << Move[i] << " ";
			cout << endl;
		}
	};