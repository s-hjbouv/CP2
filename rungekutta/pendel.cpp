#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

//y''(t)=g/R*siny(t) with lenth R=1
//y''(t)=-9.81*siny(t)
//y(t=0)=y0
//y'(t=0)=0

int main(){

//define vectors
std::vector<double> vdy;
std::vector<double> vy;
std::vector<double> vy0{0,0.1963,0.3927,M_PI_4,M_PI_2,2.3562}; //initial angles:0,1/16*pi, 1/8*pi, 1/4*pi, 1/2*pi, 3/4*pi

//stepwidth
double h=0.1;
double g=-9.81;

//outer loop
for (int i=0; i<vy0.size(); i++){
    std::cout<<"Anfangswinkel: "<<vy0[i]<<std::endl;
    std::cout<<"Auslenkung y"<<std::endl;
    
    //inner loop
    //total timespan: 30 s

    vdy.clear ();   vdy.push_back (0.0);
    vy.clear ();    vy.push_back(vy0[i]);
    for (int j=0; j<300; j++){
	double k1=h/2.0*g*sin(vy[j]);
	double k2=h/2.0*g*sin(vy[j]+h/2*vdy[j]+h/4*k1);
	double k4=h/2.0*g*sin(vy[j]+h*vdy[j]+h*k2);
	double dy=vdy[j]+1.0/3.0*(k1+4*k2+k4);
	vdy.push_back(dy);
	double y=vy[j]+h*vdy[j]+h/3.0*(k1+2*k2);
	vy.push_back(y);
	
	//print vector
    	std::cout<<vy[j]<<std::endl;

    }
    //output files
    char filename[64];
    strcpy (filename, "phase.");
    char *pos = strchr (filename, '.');
    sprintf (pos+1, "%1d", i);
	ofstream y0 (filename);
	for (int i=0;i<300;i++){
    	y0<<vy[i]<<endl;
	}


    char filename1[64];
    strcpy (filename1, "dy.");
    char *posi = strchr (filename1, '.');
    sprintf (posi+1, "%1d", i);
        ofstream dy (filename1);
        for (int i=0;i<300;i++){
        dy<<vdy[i]<<endl;
        }


}
    

}
