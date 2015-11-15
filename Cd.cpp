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
	performers=s1;
	label=s2;
	selections = n;
	playtime = x;
	cntP=0;
	cntL=0;

	//count array length for *s1 and *s2
	int i =0;
	while (s1[i]!='\0'){
		cntP++;
		i++;
	}

	i =0;
	while (s2[i]!='\0'){
		cntL++;
		i++;
	}
}


Cd::Cd(const Cd &d){
	cout<<"\n Cd copy constructor";
	//delete[] label;
	//cout<<"delete default label";
	//delete[] performers;

	cntP=d.cntP;
	cntL=d.cntL;
		label = new char [cntL];
		//cout<<"new label created";
	   for(int i=0;i<cntP;i++){
		label[i]=d.label[i];
	}
       performers=new char[cntP];
	   for(int i=0; i<cntL; i++) 
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
	for(int i=0;i<cntP;i++){
		cout<<performers[i];
	}

	cout<<"\n Label: ";
	for(int i=0;i<cntL;i++){
		cout<<label[i];
	}

	cout<<"\n Selections: "<<selections;
	cout<<"\n Playtime: "<<playtime;
	cout<<"\n";
	
}

Cd& Cd:: operator=(const Cd &d){
	cout<<"\n Cd overload =";
	delete[] label;
	delete[] performers;

	cntP=d.cntP;
	cntL=d.cntL;
	label = new char [sizeof(d.label)];
	   for(int i=0;i<cntL;i++){
		label[i]=d.label[i];
	}
       performers=new char[sizeof(d.performers)];
	   for(int i=0; i<cntP; i++) 
    {
        performers[i]=d.performers[i];
    }
   
	selections=d.selections;
	playtime=d.playtime;
	

	return *this;
}