#include "Cd.h"
#include "Classic.h"
#include <iostream>
using namespace std;

Classic::Classic():Cd(){
	cout<<"\n Classic default constructor called ";
	primary =new char[1];
	
}

Classic::Classic(char * s1, char * s2, char *s3, int n, double x):Cd(s1,s2,n,x){
	primary = s3;
}

Classic::~Classic(){
	cout<<"\n Classic Destroyed";
	delete [] primary;
}

Classic::Classic(const Classic &right){
	cout<<"\n Classic copy constructor ";
	//delete[] primary;
	primary=new char[sizeof(right.primary)];
	   for(int i=0; right.primary[i]!='\0'; i++) 
    {
        primary[i]=right.primary[i];
    }

	Cd::Cd(right);
}

void Classic::report() const{
	cout<<"\n Primary: ";
	for(int i=0;primary[i]!='\0';i++){
		cout<<primary[i];
	}
	Cd::report();
}

Classic Classic::operator=(const Classic &right){
	cout<<"\n Classic overload =";
	delete[] primary;
	primary=new char[sizeof(right.primary)];
	   for(int i=0; right.primary[i]!='\0'; i++) 
    {
        primary[i]=right.primary[i];
    }

	Cd::Cd(right);

	return *this;
}
