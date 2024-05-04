/**
*
* @Name : Differential_Calculator/main.hpp
* @Version : 1.0
* @Programmer : Harshpreet Kaur Kathuria
* @Date : 2024-04-121
* @Released under :
* @Repository :
*
**/
#ifndef MAIN_HPP_
	#define MAIN_HPP_

	#include <iostream>
	#include <cmath>
	#include <inttypes.h>
	#include <sstream>
	#include <bits/stdc++.h>
	#include <algorithm>
	#include <vector>
	using namespace std;

	void 	help();
	void 	error();

	void	Algorithm_Solver();
	bool	arebracketsbalanced(string equation);
	int 	Bracket_Counter (string equation);

	float 	Equaltion_Breaker(string equation);
	string Space_Remover (string equation);
	float Bracket_Breaker (string equation);
	//string Bracket_Breaker (string equation);

#endif
