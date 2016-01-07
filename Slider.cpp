/******************************************************************
*	Program		: Slider.cpp
*	Author		: Krish Godiawala & Shivkumar Dudhani
*	Version		: 1.0
*	Description : Solve Sam Loyds Sliding Problem
*******************************************************************/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"Configuration.h"
#include"Puzzle.h"
#include"Slider.h"

using namespace std;

int main(int argc, char* argv[])
{
	Puzzle<vector<vector<char>>, vector<vector<char>>>  puzzle(argc, argv);
	puzzle.BFS();
	cin.get();
	return 0;
}