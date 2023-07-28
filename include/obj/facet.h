#include <string>
#include <bit>
#include <vector>
#include <iostream>
#include <fstream>
#include "coord.h"

using namespace std;
#pragma once

/*
*	This File Defines Facets
*
*	System: Linux Mint 21.1 x86_64
*	Author: Zain Ali
*	IDE: terminal, nano, gcc 11.3.0
*
*	TESSELATION:
*
*	all 2d flat polygons can be represented with triangles
*	all curves can be represented by an infinite number of triangles
*	curves can be aproximated with a certain number of accuracy
*	with a lot of triangles
*
*	STL files:
*
*	stl files encode only information about the surface of a 3d print
*	allowing us to make gcode for wall thickness and infill easier
*	to do this they use facets
*
*	FACET:
*		coord normal  -> normal vector representing which way is out on the surface
*		vector<coord> points -> 3 points encoding the triangle in the tesselation
*
*/

#ifndef FACET_H
#define FACET_H

class facet {

private:
	coord norm;

	vector<coord> points;

public:

	facet();

	facet(coord n, coord p1, coord p2, coord p3);

	facet(const facet &other);

	facet(coord n, vector<coord> points);

	coord getNorm() const;

	vector<coord> getCoords() const;

	void setNorm(coord norm);

	void setPoints(vector<coord> points);

	// TODO: requires that we finish op [] funcs first
	//for printing
	friend ostream& operator << (ostream& os, const facet& rhs);

	// for fileReading
	friend istream& operator >> (istream& is, const facet&rhs);

	coord& operator [] (const int& index);

	coord operator[] (const int& index) const;

	facet& operator = (const facet& other);

	bool operator == (const facet& lhs) const;

	bool operator != (const facet& lhs) const;

};

#endif
