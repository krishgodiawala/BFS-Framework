/******************************************************************
*	Program		: Clock.h
*	Author		: Krish Godiawala & Shivkumar Dudhani
*	Version		: 1.0
*	Description : Contains the elements specific to Clock puzzle
*******************************************************************/

/*
Class to check solve the Clock problen
K N/A
T - > int (time in clock)
*/
template < class K, class T >
class Clock : public Configuration<K, T>{
	T mod;
public :
	/*
	Constructor
	1> Mod
	2>Current Time in clock
	3>Final Time in clock
	*/
	Clock(int mod, int current, int final)
	{
		load = true;
		initial = current;
		finalmove = final;
		this->mod = mod;
	}


	/*
	Check the Move and determine the next possible moves and then add them to the queue
	For a clock the next possible move is -1 or +1 of the current time
				currentTime
	currentTime -1			currentTime + 1
	*/
	vector<T> nextMove(T Move){
		T currentmove;
		vector<T> newmoves;

		/*currentTime -1*/
		currentmove = (Move - 1) % mod;
		if (currentmove == 0)
			currentmove = mod;
		newmoves.push_back(currentmove);		
		
		/*currentTime +1*/
		currentmove = (Move + 1) % mod;
		if (currentmove == 0)
			currentmove = mod;
		newmoves.push_back(currentmove);

		return newmoves;
	}
	/*
	Check Goal
	If current time is equal to final time
	*/
	bool checkGoal(T node){
		return (finalmove == node) ? true : false;
	}

	/*
	Display the Puzzle Set
	*/
	void display(T Move)
	{
		cout << endl << Move;
	}
};