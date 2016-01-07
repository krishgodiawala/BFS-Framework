/******************************************************************
*	Program		: Puzzle.h
*	Author		: Krish Godiawala & Shivkumar Dudhani
*	Version		: 1.0
*	Description : Contains the Bread First Search Algortihm which
*				  that runs all the puzzle
*******************************************************************/
template <class K, class T>
class Puzzle : public Configuration<K, T>{
	Configuration *puzzle;

public:
	/*
	Constructor
	Instantiates the Clock class and casts to the puzzle class
	Parameters :
	argc : number of command line arguments
	argv : pointer to array containing the command line arguments
	*/
	Puzzle(int argc, char* argv[])
	{
		if (argc == 4)
		{
			puzzle = new water<vector<int>, vector<int>>(argv, argc);
		}
		else
		{
			cout << "Insuffiecient Parameters " << endl;
		}
	}
	/*
	Breadth First search
	*/
	bool BFS() {
		if (puzzle == NULL)
			return false;
		if (puzzle->load == false)
			return false;

		T currentnode;
		vector<T> move;
		vector<T> nextmoves;
		/*
		Check if the first move is the solution to the puzzle
		*/
		if (puzzle->firstmove(puzzle->initial))
		{
			/*
			Solution found in the first move
			*/
			currentnode = puzzle->initial;
			cout << "Yayyee!!Solution Found" << endl;
			cout << "Puzzle already solved" << endl;
			return true;
		}
		else
		{
			/*
			Add the initial state of puzzle to the queue and map
			*/
			puzzle->enque(puzzle->initial);
			puzzle->insert(puzzle->initial, puzzle->initial);
		}
		/*
		Process till queue is not empty
		*/
		while (!puzzle->isEmpty())
		{
			/*
			Get the front of queue
			*/
			move = puzzle->deque();
			currentnode = move.front();
			/*
			Check Goal if the current state is the goal of the solution
			*/
			if (puzzle->checkGoal(currentnode))
			{
				break;
			}
			nextmoves.clear();
			nextmoves = puzzle->nextMove(currentnode);
			/*
			for the current state of puzzle determine the possible moves
			Vector is returned which contains the possible moves
			the Map will hold <current state >,<parent state>
			*/
			for (T move : nextmoves)
			{
				if (puzzle->insert(move, currentnode))
					puzzle->enque(move);
			}
		}

		/*
		If ,after all possible moves there is not element in the queue
		then no solution found
		*/
		if (puzzle->isEmpty())
		{
			cout << ":( !!Solution not Found" << endl;
			return false;
		}
		else
		{
			/*
			If,the queue contains element in queue,the solution is found for the puzzle
			*/
			cout << "Yayyee!!Solution Found" << endl;
			/*
			Back track from the current state till the initial state by
			check the map for the parent state for the current state
			and add them to the stack
			*/
			puzzle->solutionMoves(currentnode);
			/*
			IF the o/p is to be written to the file
			Initialize the file pointer to write
			*/
			if (puzzle->opfile == true)
			{
				puzzle->writetofile();
			}
			if (puzzle->opfile == false)
			{				/*
							Write to system console
							*/
				/*
				Pop the elements from the stack
				*/
				while (!puzzle->_stack.empty())
				{
					puzzle->display(puzzle->_stack.top());
					puzzle->_stack.pop();
				}
			}
			return true;
		}
	};
};