#include <string>
#include <bit>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

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

#ifndef FACET
#define FACET

class facet {

	private:
		coord norm;

		vector<coord> points;

	public:

		// Constructors + destructors
		facet() {
			norm = coord();
			points = vector<coord>(3, coord());
		}

		facet(coord n, coord p1, coord p2, coord p3) {
			this->norm = n;

			vector<coord> l;

			l.push_back(p1);
			l.push_back(p2);
			l.push_back(p3);

			points = l;
		}

		facet(const facet& other) {
			this->norm = other.getNorm();
			this->points = other.getCoords();
		}

		// TODO: change out the exception for out of range or somn official
		facet(coord n, vector<coord> points) {
			this->norm = n;

			if (points.size() != 3) {
				throw exception("bro nutted the wrong number of points");
			}

			this->points = points;
		}

		// Getters + Setters
		coord getNorm() const {return this->norm;}

		vector<coord> getPoints() const { return this->points;}

		void setNorm(coord norm) { this->norm = norm;}

		void setPoints(vector<coord> points) {

			if (points.size() != 3) {
				throw exception ("bro nutted the wrong num of points facet.setPoints()");
			}

			this->points = points;
		}

		// TODO: requires that we finish op [] funcs first
		friend ostream& operator << (ostream& os, const facet& rhs) {

			os << "Normal:\n" << normal << endl;

			for (int i = 0; i < rhs; i++) {
				os << "Facet[" << i << "]: " << endl << rhs;
			}

			return os;
		}

		coord& operator [] (const int& index) {

			if (index >= points.size() || index < 0) {
				throw out_of_range(" triangle points index out of bounds on operator[]");
			}

			return this->points.at(index);
		}

		coord operator[] (const int& index) const {

			if (index >= points.size() index < 0) {
				throw out_of_range("triangle points index out of bounds operator const");
			}
			return this->points.at(index);
		}

		facet& operator = (const facet& other) {

			if (this == &other) {
				return *this;
			}

			this->norm = other.getNorm();
			this->points = other.getPoints();

			return *this;
		}

		bool operator == (const facet& lhs) const {

			if (this == &lhs) {
				return true;
			}

			return lhs.getNorm() == this->norm && this->points == lhs.getPoints();

		}

		bool operator != (const facet& lhs) const {
			return !(*this == lhs);
		}
};


#endif
