/******************************************************************
*	Program		: Configuration.h
*	Author		: Krish Godiawala & Shivkumar Dudhani
*	Version		: 1.0
*	Description : Hold the main operations required to solve puzzle
*				  Stack,Queue
*******************************************************************/

#include<stack>
#include<queue>
#include<map>

using namespace std;
/*
1>Class to contain the BFS structure
2>Queue
3>Map
*/
template <class K, class T>
class Configuration{
public:
	T initial;			// Holds the initial state of puzzle
	T finalmove;		// Holds the final state of puzzle
	queue<T> _queue;
	map<T, K>  _map;
	stack<T> _stack;
	int noMoves = 0;	// Number of moves
	bool opfile = false;
	bool load = false;
	/*
	Constructor
	*/
	Configuration()
	{
	}

	/*
	Check Goal
	return bool true of goal is found
	*/
	virtual bool checkGoal(T node){
		return true;
	}

	/*
	*********************************************
	Queue Operations
	*********************************************
	*/

	/*
	Add to Queue
	parameters :
	T node The element to be added to queue
	*/
	virtual bool enque(T node){
		_queue.push(node);

		return true;
	}
	/*
	if the queue is not Empty
	Pop node from the Queue
	return : array of vectors
	*/
	virtual vector<T> deque() {
		vector<T> ret;
		if (!isEmpty())
		{
			ret.push_back(_queue.front());
			_queue.pop();
			return ret;
		}
		else
			return ret;
	}
	/*
	Check if the queue is empty
	return bool
	*/
	bool isEmpty()
	{
		return _queue.empty();
	}
	/*
	*********************************************
	Map Operations
	*********************************************
	*/
	/*
	If the time(key) has already been traversed before then it will be present in the map
	hence insert will return false if not will add to the map
	parameteters
	Key Key for map
	Value Value for map
	return bool true,if succesfully added to the map
	false,if entry for the key already exists
	*/
	virtual bool insert(K key, T value){
		if (_map.find(key) == _map.end())
		{
			_map.insert(pair<K, T>(key, value));
			return true;
		}
		else
			return false;

	}

	/*
	*********************************************
	BFS
	*********************************************
	*/
	/*
	Get the moves from the array of Moves
	It would internally call the queue and access the current head of the queue
	and appropriately get the next possible moves for the curret node
	parameter : T Move Current Move
	return	  : Vector of next possible moves
	*/
	virtual vector<T> nextMove(T Move){
		vector<T> test;
		return test;
	}

	/*
	Check if the first move is the solution
	parameter : T move Current Move
	return bool :
	*/
	virtual bool firstmove(T move)
	{
		/*
		Check the initial move
		*/
		return checkGoal(move) ? true : false;
	}


	/*
	Solution to the moves
	*/
	void solutionMoves(T Move)
	{
		/*
		Back track from the final time to previous state using _map key -> value
		*/
		/*
		Search from final puzzle
		in the Map using Key Value
		where	Key = current puzzle set
		Value = parent puzzle set
		keep back tracking will Key = Initial
		Add the moves to the stack
		*/
		T step = Move;
		map<T, T>::iterator it;

		cout << "Back tracking the solution to determine the moves" << endl;

		do		{
			/*
			Add the values to the stack
			*/
			_stack.push(step);
			it = _map.find(step);
			if (it != _map.end())
				step = it->second;
		} while (step != initial);
		/*
		Add the Initial Configuration
		*/
		_stack.push(initial);
	}
	/*
	Display the Puzzle Set
	*/
	virtual void display(T Move)
	{
	}
	/*
	Write the puzzle to the file
	*/
	virtual void writetofile()
	{
	}

};