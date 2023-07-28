#include <string>
#include <bit>
#include <vector>
#include <iostream>
#include <fstream>

#include "common.h"
#include "../obj/facet.h"
#include "../obj/coord.h"

#pragma once

using namespace std;

/*
*	STL fileParser takes a stl spits out facet list
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

#ifndef FILEPARSER_H
#define FILEPARSER_H

vector<facet> parseFile(string filePath);

#endif