#include <string>
#include <bit>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

/*
*	Common code for slicer files
*
*	System: Linux Mint 21.1 x86_64
*	Author: Zain Ali
*	IDE: terminal, nano, gcc 11.3.0
*
*/

#ifndef ASSERT_MSG
	#define ASSERT_MSG(val, msg) if(!val) { throw runtime_error(string("\x1b[1;31m") + msg + string("\033[0m")); }
#endif

#ifndef COORDS
#define COORDS

	struct coords {

		vector<float> 

	};

#endif

#ifndef FACET
#define FACET
	struct facet {

		vector<float> normal = vector<float>(3, -1);
		vector<vector<float>> points = vector<vector<float>>(3, vector<float>(3, -1));

	};
#endif

#ifndef SLICE
#define SLICE

	struct slice {

		vector<>

	};

#endif
