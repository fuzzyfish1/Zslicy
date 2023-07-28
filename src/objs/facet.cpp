//
// Created by fuzzyfish on 7/27/23.
//

#include "../../include/obj/facet.h"

#pragma once

#ifndef FACET_CXX
#define FACET_CXX

facet::facet() {
	norm = coord();
	points = vector<coord>(3, coord());
}

facet::facet(coord n, coord p1, coord p2, coord p3) {
	this->norm = n;

	vector<coord> l;

	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);

	points = l;
}

facet::facet(const facet &other) {
	this->norm = other.getNorm();
	this->points = other.getCoords();
}

// TODO: change out the exception for out of range or somn official
facet::facet(coord n, vector<coord> points) {
	this->norm = n;

	if (points.size() != 3) {
		throw runtime_error("bro nutted the wrong number of points");
	}

	this->points = points;
}

// Getters + Setters
coord facet::getNorm() const { return this->norm; }

vector<coord> facet::getCoords() const { return this->points; }

void facet::setNorm(coord norm) { this->norm = norm; }

void facet::setPoints(vector<coord> points) {

	if (points.size() != 3) {
		throw runtime_error("bro nutted the wrong num of points facet.setPoints()");
	}

	this->points = points;
}


// TODO: requires that we finish op [] funcs first
ostream &operator<<(ostream &os, const facet &rhs) {

	os << "Normal:\n" << rhs.getNorm() << endl;

	for (int i = 0; i < 3; i++) {
		os << "Facet[" << i << "]: " << endl << rhs[i];
	}

	return os;
}
//TODO: I guess rebuild this BS
istream &operator>>(istream &is, const facet &rhs) {
	return is;
}

coord &facet::operator[](const int &index) {

	if (index >= points.size() || index < 0) {
		throw out_of_range(" triangle points index out of bounds on operator[]");
	}

	return this->points.at(index);
}

coord facet::operator[](const int &index) const {

	if (index >= points.size() || index < 0) {
		throw out_of_range("triangle points index out of bounds operator const");
	}
	return this->points.at(index);
}

facet &facet::operator=(const facet &other) {

	if (this == &other) {
		return *this;
	}

	this->norm = other.getNorm();
	this->points = other.getCoords();

	return *this;
}

bool facet::operator==(const facet &lhs) const {

	if (this == &lhs) {
		return true;
	}

	return lhs.getNorm() == this->norm && this->points == lhs.getCoords();

}

bool facet::operator!=(const facet &lhs) const {
	return !(*this == lhs);
}

#endif


