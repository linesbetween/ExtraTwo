#include <iostream>
using namespace std;
#include "Classic.h"

void bravo(const Cd & disk);
int main() {

	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);

	Cd *pcd = &c1;

	cout << "Using object directly: \n";
	c1.report(); // use Cd method
	c2.report(); // use Classic method

	cout << "Using type cd * pointer to objects:\n";
	pcd->report(); // use cd method for cd object
	pcd = &c2;
	pcd->report(); // use Classic method for classic object

	cout << "Calling a function with a Cd reference argument:\n";
	bravo(c1);
	bravo(c2);


	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.report();

	system("pause");
	return 0;
}
void bravo(const Cd & disk) {
	disk.report();
}