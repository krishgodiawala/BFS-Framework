/******************************************************************
*	Program		: Clock.cpp
*	Author		: Krish Godiawala & Shivkumar Dudhani
*	Version		: 1.0
*	Description : Hold the main operations required to solve puzzle
*				  Stack,Queue
*******************************************************************/
#include<iostream>
#include"Configuration.h"
#include"Puzzle.h"
#include"Clock.h"

using namespace std;

int main(int argc, char* argv[])
{
	/*
	Define the class generics to int for the clock puzzle
	*/
		Puzzle<int, int>  puzzle(argc, argv);
		puzzle.BFS();		

		cin.get();
	return 0;
}