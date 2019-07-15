#include <iostream>
#include <array>
#include <fstream>
#include <math.h>


double epsi_0;
double epsi_r;
double rho_0;

int main(){

//Gittergröße definieren
std::array<std::array<std::array<double, 10>, 10>, 10> Gitter;
std::array<std::array<std::array<double, 10>, 10>, 10> phi_alt;
std::array<std::array<std::array<double, 10>, 10>, 10> phi_neu;
std::array<std::array<std::array<double, 10>, 10>, 10> phi_alt2;
std::array<std::array<std::array<double, 10>, 10>, 10> phi_neu2;
std::array<std::array<std::array<double, 10>, 10>, 10> rho;

////////////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////////////

// Ladung im Vakuum mit einer Seite 1000V und eine 0V:
//-----------------------------------------------------

//Randbedingungen des Gitters; eine Seite 1000V und eine Null
for( int i = 0; i < Gitter.size(); i++){
  for( int j = 0; j < Gitter.size(); j++){
    for( int k = 0; k < Gitter.size(); k++){
       if(i == 0){
       phi_alt[i][j][k] = 10000;
       }
       else{
       phi_alt[i][j][k] = 0.0;
       }
    }
  }
}

//Randbedingung rho Vakuum
for(int i = 0; i < Gitter.size(); i++){
  for(int j= 0; j < Gitter.size(); j++){
    for(int k= 0; k < Gitter.size(); k++){
    rho[i][j][k] = 0 ; 
        }
      }
    }
 
// Berechnen phi mit Abbruchbedingung
double d = 10;
while (d>0.1){
//for( int t=0; t < 1000; t++){
// Array für das phi(i,j,k)
  for( int i = 1; i < phi_neu.size()-1; i++){
    for( int j = 1; j < phi_neu.size()-1; j++ ){
      for( int k = 1;k < phi_neu.size()-1; k++ ){
      phi_neu[i][j][k] = (1.0/6.0)*(phi_alt[i+1][j][k]+phi_alt[i-1][j][k]+phi_alt[i][j+1][k]+phi_alt[i][j-1][k]+phi_alt[i][j][k+1]+phi_alt[i][j][k-1]-rho[i][j][k]);
      // Differenz für Abbruchkriterium
      d = sqrt((phi_alt[i][j][k]-phi_neu[i][j][k])*(phi_alt[i][j][k]-phi_neu[i][j][k])); 
      phi_alt[i][j][k] = phi_neu[i][j][k]; 
      }
    }
  }
}

// Phi_neu ausgeben
std::ofstream output_pot0("Potential0.txt");
for( int i = 0; i < phi_neu.size(); i++){
  //for( int j= 0; j < phi_neu.size(); j++ ){
    for( int k = 0; k < phi_neu.size(); k++ ){
  output_pot0 << i << " " << k << " " << phi_neu[i][5][k] <<std::endl; 
    }
 // }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

//Punktladung mit festem rho
//-------------------------------

//Randbedingungen des Gitters; Ladung in der Mitte und geladene Platte
for( int i = 0; i < Gitter.size(); i++){
   for( int j = 0; j < Gitter.size(); j++){
     for( int k = 0; k < Gitter.size(); k++){
       if(i == 0){
       phi_alt2[i][j][k] = 10000;
       }
       if( i == 5 && j == 5 && k == 5){
       phi_alt2[i][j][k] = 10000;
       }
       else{
       phi_alt2[i][j][k] = 0.0; 
       }
    }
  }
}

//Randbedingung rho fester Wert
for(int i = 0; i < Gitter.size(); i++){
 for(int j = 0; j < Gitter.size(); j++){
   for(int k= 0; k < Gitter.size(); k++){
     if( i == 5 && j == 5 && k == 5){
     rho[i][j][k] = 10000;
     }
     else{
     rho[i][j][k] = 0.0;
     }
   }  
 }
} 

 // Berechnen phi mit Abbruchbedingung

double b = 10;
while (b>0.1){
// Array für das phi(i,j,k)
for( int i = 1; i < phi_neu2.size()-1; i++){
    for( int j = 1; j < phi_neu2.size()-1; j++ ){
      for( int k = 1; k < phi_neu2.size()-1; k++ ){
      phi_neu2[i][j][k] =pow(pow((1.0/6.0)*(phi_alt2[i+1][j][k]+phi_alt2[i-1][j][k]+phi_alt2[i][j+1][k]+phi_alt2[i][j-1][k]+phi_alt2[i][j][k+1]+phi_alt2[i][j][k-1]-rho[i][j][k]),2),0.5);
      b = sqrt((phi_alt2[i][j][k]-phi_neu2[i][j][k])*(phi_alt2[i][j][k]-phi_neu2[i][j][k]));
      phi_alt2[i][j][k] = phi_neu2[i][j][k]; // Differenz für Abbruchkriterium    
      }
    }
}
}

// Phi_neu ausgeben
std::ofstream output_pot2("Potential2.txt");
for( int i = 0; i < phi_neu2.size(); i++){
//  for( int j= 0; j < phi_neu2.size(); j++ ){
    for( int k = 0;k < phi_neu2.size(); k++ ){
    output_pot2 <<i << " " << k <<" " <<  phi_neu2[i][5][k] <<std::endl;
    }
//  }
}
   



}
