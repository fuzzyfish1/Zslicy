//
// Created by fuzzyfish on 7/28/23.
//

#include "lib/superImposer.h"

#pragma once

#ifndef SUPER_IMPOSER_CXX
#define SUPER_IMPOSER_CXX

coord temp (const coord& a, const coord& b, const float& height) {

	const coord& hi = (a[2] >= b[2]) ? a : b;
	const coord& lo = (a[2] <= b[2]) ? b : a;

	coord t = (hi - lo).unitVec();
	float zDiff = lo[2] - height;

	return t * (zDiff / t[2]);
}

bool checkIntersect(const facet& f, const float& height) {
	// get one below, one above
	vector<int> g (3, -1);

	bool above = false;
	bool below = false;

	for (int i = 0; f.size(); i++) {
		above |= f[i][2] > height;
		below |= f[i][2] <= height;
	}
	return above && below;

}

vector<slice> superImpose(vector<facet> facets) {

	vector<struct move> m;

	for (const auto &f: facets) {
		// determine if a facet crosses through a plane


	}
}
#endif