#include <iostream>
#include "Classic.h"
#include "Cd.h"
using namespace std;


void bravo(const Cd & disk);
int main() {

	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);

	Cd *pcd = &c1;

	cout << "\n Using object directly: ";
	c1.report(); // use Cd method
	c2.report(); // use Classic method

	cout << "\n Using type cd * pointer to objects:";
	pcd->report(); // use cd method for cd object
	pcd = &c2;
	pcd->report(); // use Classic method for classic object

	cout << "\n Calling a function with a Cd reference argument:";
	bravo(c1);
	bravo(c2);


	cout << "\n Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.report();

	system("pause");
	return 0;
}

void bravo(const Cd & disk) {
	disk.report();
}