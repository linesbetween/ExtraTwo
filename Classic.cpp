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

Classic& Classic::operator=(const Classic &right){
	cout<<"\n Classic overload =";
	delete[] primary;
	primary=new char[sizeof(right.primary)];
	   for(int i=0; right.primary[i]!='\0'; i++) 
    {
        primary[i]=right.primary[i];
    }
	
	//below copied from Cd::Cd Cd:: operator=(const Cd &d)
	delete[] label;
	delete[] performers;
	cout<<"\n sizeof(right.label) "<<sizeof(right.label);
		label = new char [sizeof(right.label)];
	   for(int i=0;label[i]!='\0';i++){
		   cout<<"\n"<< right.label[i];
		label[i]=right.label[i];
	}

	  // cout<<"\n sizeof(right.performers) "<<sizeof(right.performers);
       performers=new char[sizeof(right.performers)];
	   for(int i=0; right.performers[i]!='\0'; i++) 
    {	
		//cout<<"\n"<<right.performers[i];
        performers[i]=right.performers[i];
    }
   
	selections=right.selections;
	playtime=right.playtime;	   
		
	   return *this;
}
