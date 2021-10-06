#include <iostream>
#include <fstream>
#include "Signal_Generator.h"
#include "amplifier.h"
#include "Mega644ADC.h"
#include "transmitter.h"

using namespace std;

float estimate(int k,int m);
int Divide(int p, int q);
int DivideFromLeft(int a, int b);
int DivideFromRight(int c, int d);

float x[800];	 	 
int main() {
	
	Signal_Generator signal;
	amplifier ampl;
	Mega644ADC mg;
	transmitter tr;

	//creastion txt pour les 800 samples

	ofstream out("data.txt");
	
	if(!out){
    	cout << "Cannot open file.\n";
        return 1;
    }
    
	for(int i = 0; i < 800; i++){
		x[i] = mg.transmit(ampl);
    	out << x[i] << "\n";
	}
	
	cout<<"data transmitted."<<endl;
	out.close();
	Divide(0,16);
	return 0;
	
}

int Divide(int p, int q){
	 DivideFromLeft(p,q);
}

int DivideFromLeft(int a, int b){
	if((b-a) == 8)
		return estimate(a,b);	 
	DivideFromLeft(a, ((a+b)/2));
	DivideFromRight( ((a+b)/2), b);
	
}

int DivideFromRight(int c, int d){
	if((d-c) == 8)
		return estimate(c,d);	 
	DivideFromLeft(c, ((c+d)/2) );
	DivideFromRight( ((c+d)/2), d );
	
}

float estimate(int k, int m){
		
	ifstream in("data.txt");
	
	if(!in){
		cout << "Cannot open file.\n";
		return 1;
	}
	
	float Sum = 0;
	for(int i = k; i < m; i++){
		in >> x[i];
		Sum += x[i];
	}

	cout << Sum << endl;
	in.close();
}

