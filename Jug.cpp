/******************************************************************
*	Program		: Jugg.cpp
*	Author		: Krish Godiawala & Shivkumar Dudhani
*	Version		: 1.0
*	Description : Jug-Problem
*******************************************************************/
#include<iostream>
#include"Configuration.h"
#include"Puzzle.h"
#include"Water.h"

using namespace std;

int main(int argc, char* argv[])
{
	/*
	Generics to vector of int for the jug problem
	*/
	Puzzle<vector<int>, vector<int>>  puzzle(argc, argv);
	puzzle.BFS();
	cin.get();
	return 0;
}