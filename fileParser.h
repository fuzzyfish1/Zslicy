#include <string>
#include <bit>
#include <vector>
#include <iostream>
#include <fstream>
#include "common.h"

using namespace std;

/*
*	STL fileParser takes an stl spits out facet list
*
*	System: Linux Mint 21.1 x86_64
*	Author: Zain Ali
*	IDE: terminal, nano, gcc 11.3.0
*
*	STL fileforeach triangle is binary file
*		Uint8[80] header               // header is always 80 chars, leftover chars are filled with spaces
*		uint32 numTriangles
*
*		foreach triangle
*			REAL32[3] – Normal vector	// float
*			REAL32[3] – Vertex 1
*			REAL32[3] – Vertex 2
*			REAL32[3] – Vertex 3
*			UINT16 – Attribute byte count // unsigned short
*/


#ifndef FILEPARSER
#define FILEPARSER

/* reads the next 3 ie 1 point */
istream& operator >> (istream&is, vector<float>& v) {

	float f;

	v = vector<float>(3 , -1);
	for (int i = 0; i < 3; i++) {

		is.read((char*)&f, 4);
		v.at(i) = f;
	}

	return is;
}

/* reads the next 12 float32 as a facet*/
istream& operator >> (istream& is, facet& f) {

	is >> f.normal;

	for(int i = 0; i < 3; i++) {
		is >> f.points.at(i);
	}

	return is;

}

vector<facet> parseFile(string filePath) {

	ifstream inFile(filePath.c_str(), ios::in | ios::binary);

	ASSERT_MSG(inFile, "fucky filePath");

	// getting Header
	char header[81] = ""; // 80 char from file + 1 string terminatory byte
	inFile.read(header, 80 * sizeof(char));
	header[80] = '\0';
	cout << "HEADER: " << header << endl;

	// getting numberFacets
	unsigned int numFacets = 0;
	inFile.read((char*)&numFacets, sizeof(unsigned int));
	cout << "NUMFACETS: " << numFacets << endl;
	ASSERT_MSG(numFacets != 0, "numFacet Problem");

	// getting Facets
	vector<facet> facets;

	for (unsigned int i = 0; i < numFacets; i++) {

		ASSERT_MSG(inFile, "unexpected EOF");

		facet f;
		inFile >> f;

		facets.push_back(f);

		unsigned short dummy = 0xFFFF;
		inFile.read((char*) &dummy, sizeof(unsigned short));

	}

	return facets;
}

#endif
