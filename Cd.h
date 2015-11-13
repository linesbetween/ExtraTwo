#ifndef CD_H
#define CD_H
#include<string>
using namespace std;


// base class
class Cd { // represents a CD disk
protected: 
	char *performers;
	char *label;
	int selections; // number of selections
	double playtime; // playing time in minutes
	//Actual length of performers and label name

public:
	Cd(char* , char*, int n, double x);
	Cd(const Cd &d);
	Cd();
	~Cd(); // this is called after "copy = c2;", which is too early... 

	//made virtual for polymorphism
	virtual void report() const; // reports all the CD data
	virtual Cd & operator=(const Cd &d);
};

#endif

