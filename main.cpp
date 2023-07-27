#include <string>
#include <bit>
#include <vector>
#include <iostream>
#include <fstream>
#include "fileParser.h"
#include "common.h"

using namespace std;

#define DEFAULT_FILE_PATH "./cat.stl"

/*
*	Takes a STL file and spits out GCode
*
*	System: Linux Mint 21.1 x86_64
*	Author: Zain Ali
*	IDE: terminal, nano, gcc 11.3.0
*
*	The pseudo to vibe wit it
*
*	STL FILE
*	   vv     File Parser  takes STL and extracts useful information
*	vector<facet>
*	   vv     superImposer  superImposes the triangles onto Slices on calculated Z-steps
*	vector<slice>
*	   vv     WallGenerator  generates GCode for Walls at this point
*	vector<slice>
*	   vv     InfillGenerator  lays an infill pattern
*	GCodeString
*	   vv
*	Printer
*
*/

/*
*	TODO:
*		I have a FileParser but we need to rebuild the struct of facet
*		should be split into class Coord, class Facet, class Slice
*
*/

int main (int argc, char *argv[]) {

	string filePath = argc > 1 ? argv[1] : DEFAULT_FILE_PATH;
	cout << "FILEPATH: " << filePath << endl;

	vector<facet> facets = parseFile(filePath);

	return 0;
}

