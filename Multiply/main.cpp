#include <iostream>  // zum Eingeben und Ausgeben
#include <fstream>   // zum Einlesen externer Dateien
#include <vector>    // um Vektoren zu verwenden

int main(int argc, char** argv){
  std::ifstream in("input.txt");  // Liste mit Daten einlesen      

int var2;
std::string var1;
float a=1.8;
float b=32;
  
int main(){
  std::vector<double> FVektor;
  std::vector<double> FCVektor;
  while(var1 =="F"){
  FVektor.push_back(var1);
  }
  for(int i=0; i< FVektor.size(); i++){
  FCVektor[i] = var2*a+b;
  std::cout << FCVektor  << std::endl;
}}

int main(){
  std::vector<double> CVektor;
  std::vector<double> CFVektor;
  while(var1 =="C"){
    CVektor.push_back(var1);
  }
for(int i=0; i< CVektor.size; i++){
    CFVektor[i] = (var2-b)*a; 
std::cout << CFVektor  << std::endl;
}}
}


//int var2;             // Variablen definieren
//std::string var1; 
//float a=1.8; 
//float b=32;

//for(int i=0; i<4; i++){ // Loop basteln
//in >>var1;
//in >>var2; 

//if (var1 == "C"){ // Unterscheidung, ob in Liste F oder C vorne steht 
 // double A = var2*a+b; // Celsius in Fahrenheit
   // std::cout << var2 << " Grad Celsius sind " << A << " Grad Fahrenheit " << std::endl;
//}
//else if (var1 == "F"){
 // double B = (var2-b)*a; // Fahrenheit in Celsius
  //  std::cout << var2 << " Grad Fahrenheit sind " << B << " Grad Celsius" << std::endl; 
//}
//else {
// std::cout << var2 << " ist weder Grad Fahrenheit noch Celsius. Bitte wähle eine andere Temperatur." << std::endl;
//}
//}}
