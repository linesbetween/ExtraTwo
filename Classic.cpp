#include "Cd.h"
#include "Classic.h"
#include <iostream>
using namespace std;

Classic::Classic():Cd(){
	cout<<"\n Classic default constructor called ";
	primary =new char[1];
	
}

Classic::Classic(char * s1, char * s2, char *s3, int n, double x):Cd(s2,s1,n,x){
	primary = s3;
	cntPri=0;
	int i =0;
	while (s3[i]!='\0'){
		cntPri++;
		i++;
	}
}

Classic::~Classic(){
	cout<<"\n Classic Destroyed";
	delete [] primary;
}

Classic::Classic(const Classic &right){
	cout<<"\n Classic copy constructor ";
	//delete[] primary;
	cntPri=right.cntPri;
	primary=new char[cntPri];
	   for(int i=0; i<cntPri; i++) 
    {
        primary[i]=right.primary[i];
    }

	Cd::Cd(right);
}

void Classic::report() const{
	cout<<"\n Primary: ";
	for(int i=0;i<cntPri;i++){
		cout<<primary[i];
	}
	Cd::report();
}

Classic& Classic::operator=(const Classic &right){
	cout<<"\n Classic overload =";
	delete[] primary;
	cntPri=right.cntPri;
	primary=new char[cntPri];
	   for(int i=0; i<cntPri; i++) 
    {
        primary[i]=right.primary[i];
    }
	
	//below copied from Cd::Cd Cd:: operator=(const Cd &d)
	delete[] label;
	delete[] performers;
	cntP=right.cntP;
	cntL=right.cntL;
	cout<<"\n cntL "<<cntL;
		label = new char [cntL];
	   for(int i=0;i<cntL;i++){
		   cout<<"\n"<< right.label[i];
		label[i]=right.label[i];
	}

	  // cout<<"\n sizeof(right.performers) "<<sizeof(right.performers);
       performers=new char[cntP];
	   for(int i=0; i<cntP; i++) 
    {	
		//cout<<"\n"<<right.performers[i];
        performers[i]=right.performers[i];
    }
   
	selections=right.selections;
	playtime=right.playtime;	   
		
	   return *this;
}
