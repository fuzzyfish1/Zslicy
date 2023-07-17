#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <cassert>
#include <fstream>
#include <streambuf>
#include <string>
#include <bit>
#include <vector>

using namespace std;

struct facet {

	vector<vector<float>> points;
};

int main () {

	string FILENAME = "./cat.stl";

	ifstream inFile(FILENAME.c_str(), ios::in | ios::binary);

	char header[80] = "";
	char tempTringle[4];

	inFile.read(header, 80);
	inFile.read(tempTringle, 4);

	unsigned int numTringle = *( (unsigned int*) &tempTringle);

	cout << "HEADER: " << string(header) << endl;
	cout << "NUMTRINGLE: " << numTringle << endl;

	vector<facet> facets;

	for (unsigned int i = 0; i < numTringle; i++) {

		facet f;

		for (int j = 0; j < 4; j++) {

			vector <float> temp;

			for (int k = 0; k < 3; k++) {
				float Tf; // temp float
				inFile.read((char*) &Tf, 4);
				temp.push_back(Tf);

				char dummy[2];
				inFile.read(dummy, 2);
			}

			f.points.push_back(temp);
		}
		facets.push_back(f);
	}

	return 0;
}
