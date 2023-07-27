#include "common.h"
#include "point.h"
#include <stdlib.h>

using namespace std;

int main() {

	coord* a = new coord();

	cout << "GET CHECKS: ";

	ASSERT_MSG(a->getX() == 0, "fail1");
	ASSERT_MSG(a->getY() == 0, "fail2");
	ASSERT_MSG(a->getZ() == 0, "fail3");

	cout << "PASS" << endl << "SET CHECKS: ";

	a->setX(1);
	a->setY(2);
	a->setZ(3);

	ASSERT_MSG(a->getX() == 1, "fail1");
	ASSERT_MSG(a->getY() == 2, "fail2");
	ASSERT_MSG(a->getZ() == 3, "fail3");

	cout << "PASS" << endl << "EXPLICIT CONSTRUCTOR CHECKS: ";

	coord* b = new coord(3.0, 2.0, 1.0);

	ASSERT_MSG(b->getX() == 3.0, "fail1");
	ASSERT_MSG(b->getY() == 2.0, "fail2");
	ASSERT_MSG(b->getZ() == 1.0, "fail3");

	cout << "PASS" << endl << "operator [] ASSIGNMENTS CHECKS: ";

	coord c = *b;

	c[0] = 0.0;
	c[1] = 1.0;
	c[2] = 2.0;

	ASSERT_MSG(c.getX() == 0.0, "fail1");
	ASSERT_MSG(c.getY() == 1.0, "fail2");
	ASSERT_MSG(c.getZ() == 2.0, "fail3");

	cout << "PASS" << endl << "operator [] READ CHECKS: ";

	ASSERT_MSG(c[0] == 0.0, "fail1");
	ASSERT_MSG(c[1] == 1.0, "fail2");
	ASSERT_MSG(c[2] == 2.0, "fail3");

	cout << "PASS" << endl << "OPERATOR << CHECKS: ";

	cout << c;

	cout << "PASS" << endl << "COPY CONSTRUCTOR CHECKS: ";

	coord d(c);

	ASSERT_MSG((&d != &c), "same object");

	d[1] = 10.0;

	ASSERT_MSG(d[1] == 10.0, "fail1");
	ASSERT_MSG(c[1] == 2.0, "fail2");

	cout << "PASS" << endl << "op == CHECKS: ";

	coord e = coord(1.0, 2.0, 3.0);
	coord f(e);

	ASSERT_MSG((e == f), "fail1");

	e.setY(6.0);
	ASSERT_MSG(((e == f) == 0), "fail2");

	cout << "PASS" << endl << "operator +: ";

	coord g(1.0, 2.0, 3.0);
	coord h(2.0, 4.0, 6.0);

	coord i(3.0, 6.0, 9.0);

	ASSERT_MSG(((g + h) == i), "fail1");

	cout << "PASS" << endl << "operator *: ";

	int j = -2;

	i = coord(-2.0, -4.0, -6.0);

	ASSERT_MSG(((g * j) == i), "fail1");

	i = coord(-1.0, -2.0, -3.0);

}
