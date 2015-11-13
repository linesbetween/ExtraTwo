#include "Cd.h"
#include <iostream>
#include <iomanip>
using namespace std;


Cd::Cd(){
	cout<<"\n Cd default constructor called";
	label= new char[1];
	performers = new char[1];
	selections = 0;
	playtime=0.0;
	
}
Cd::Cd(char *s1, char *s2, int n, double x){
	label=s1;
	performers=s2;
	selections = n;
	playtime = x;

}


Cd::Cd(const Cd &d){
	cout<<"\n Cd copy constructor";
	//delete[] label;
	//cout<<"delete default label";
	//delete[] performers;
		label = new char [sizeof(d.label)];
		//cout<<"new label created";
	   for(int i=0;label[i]!='\0';i++){
		label[i]=d.label[i];
	}
       performers=new char[sizeof(d.performers)];
	   for(int i=0; d.performers[i]!='\0'; i++) 
    {
        performers[i]=d.performers[i];
    }
   
	selections=d.selections;
	playtime=d.playtime;
	
}
	

Cd::~Cd(){
	cout<<"\n destroyed Cd";
	delete []label;
	delete [] performers;
}


void Cd::report() const{
	cout<<"\n Performer: ";
	for(int i=0;label[i]!='\0';i++){
		cout<<label[i];
	}

	cout<<"\n Label: ";
	for(int i=0;performers[i]!='\0';i++){
		cout<<performers[i];
	}

	cout<<"\n Selections: "<<selections;
	cout<<"\n Playtime: "<<playtime;
	cout<<"\n";
	
}

Cd Cd:: operator=(const Cd &d){
	cout<<"\n Cd overload =";
	delete[] label;
	delete[] performers;
		label = new char [sizeof(d.label)];
	   for(int i=0;label[i]!='\0';i++){
		label[i]=d.label[i];
	}
       performers=new char[sizeof(d.performers)];
	   for(int i=0; d.performers[i]!='\0'; i++) 
    {
        performers[i]=d.performers[i];
    }
   
	selections=d.selections;
	playtime=d.playtime;

	return *this;
}