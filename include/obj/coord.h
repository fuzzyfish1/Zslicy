#include <string>
#include <bit>
#include <vector>
#include <iostream>
#include <fstream>

#pragma once

using namespace std;

/*
*	This File Defines Coordinate Systems
*
*	System: Linux Mint 21.1 x86_64
*	Author: Zain Ali
*	IDE: terminal, nano, gcc 11.3.0
*
*	Totally not overengineered ...
*
*/

#ifndef COORDS_H
#define COORDS_H

class coord {

private:
    float x, y, z;

public:

	coord();

	coord(float x, float y, float z);

	coord(const coord &other);

//		~coords() {}

	// Getters + Setters
	float getX() const;

	float getY() const;

	float getZ() const;

	void setX(const float &x);

	void setY(const float &y);

	void setZ(const float &z);

	// operators
	friend ostream& operator<< (ostream &os, const coord& rhs);

	/* reads the next 3 ie 1 point */
	friend istream& operator>> (istream &is, const coord& rhs);

	float &operator[](const int &index);

	// TODO: explore making this func private
	float operator[](const int &index) const;

	coord& operator=(const coord &other);

	bool operator==(const coord &lhs) const;

	coord operator+(const coord &lhs) const;

	coord operator*(const int &lhs) const;

	coord operator-(const coord &lhs) const;

	bool operator!=(const coord &lhs) const;

	/*
 Constructors + destructors
    coord() : x(0), y(0), z(0) {}

    coord(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    coord(const coord &other) {
        //coord(other.getX(), other.getY(), other.getZ());
        this->x = other.getX();
        this->y = other.getY();
        this->z = other.getZ();
    }

//		~coords() {}

    // Getters + Setters
    float getX() const { return this->x; }

    float getY() const { return this->y; }

    float getZ() const { return this->z; }

    void setX(const float &x) { this->x = x; }

    void setY(const float &y) { this->y = y; }

    void setZ(const float &z) { this->z = z; }

    // operators
    friend ostream& operator<< (ostream &os, const coord& rhs) {
        os << "(" << rhs.getX() << ", " << rhs.getY() << ", " << rhs.getZ() << ")";

        return os;
    }

    // reads the next 3 ie 1 point
    friend istream& operator>> (istream &is, const coord& rhs) {

        float f;

        v = vector<float>(3, -1);
        for (int i = 0; i < 3; i++) {

            is.read((char *) &f, 4);
            v.at(i) = f;
        }

        return is;
    }

    float &operator[](const int &index) {

        if (index == 0) {
            return this->x;

        } else if (index == 1) {
            return this->y;

        } else if (index == 2) {
            return this->z;

        } else {
            throw out_of_range("point operator[] () index out of range");
        }

    }

    // TODO: explore making this func private
    float operator[](const int &index) const {

        if (index == 0) {
            return this->x;

        } else if (index == 1) {
            return this->y;

        } else if (index == 2) {
            return this->z;

        } else {
            throw out_of_range("point operator[] () const  index out of range");
        }

    }

    coord &operator=(const coord &other) {

        if (this == &other) {
            return *this;
        }

        this->setX(other.getX());
        this->setY(other.getY());
        this->setZ(other.getZ());

        return *this;
    }

    bool operator==(const coord &lhs) const {

        if (this == &lhs) {
            return true;
        }

        bool ret = true;

        for (int i = 0; i < 3; i++) {
            ret &= (*this)[i] == lhs[i];
        }

        return ret;
    }

    coord operator+(const coord &lhs) const {

        coord ret(*this);

        for (int i = 0; i < 3; i++) {
            ret[i] += lhs[i];
        }

        return ret;
    }

    coord operator*(const int &lhs) const {
        coord ret(*this);

        for (int i = 0; i < 3; i++) {
            ret[i] *= lhs;
        }

        return ret;
    }

    coord operator-(const coord &lhs) const {
        coord ret;

        return *this + lhs * -1;
    }

    bool operator!=(const coord &lhs) const {

        return !(*this == lhs);

    }

		// might not need this
		operator / (float& lhs) {}
*/
    // Fast Inverse Sq Root
};


/*
// Note: lhs -> left hand side
ostream& operator << (ostream& lhs, const coord& rhs) {

}*/

#endif
