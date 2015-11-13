#include "Cd.h"
#include "Classic.h"
#include <iostream>
using namespace std;

Classic::Classic():Cd(){
	primary =new char[1];
	
}

Classic::Classic(char * s1, char * s2, char *s3, int n, double x):Cd(s1,s2,n,x){
	primary = s3;
}

Classic::~Classic(){
	cout<<"Classic Destroyed";
}

Classic::Classic(const Classic &right){
	for(int i=0;i<50;i++ ){
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

Classic& Classic::operator=(const Classic &right){

	for(int i=0;right.primary[i]!='\0';i++ ){
		primary[i]=right.primary[i];
	}

	Cd::Cd(right);

	return *this;
}
