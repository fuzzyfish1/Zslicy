#include "lib/common.h"
#include "obj/facet.h"
#include "lib/fileParser.h"

#pragma once

#ifndef FILEPARSER_CXX
#define FILEPARSER_CXX

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