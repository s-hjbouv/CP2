#include <iostream>
#include <fstream>

int main(int args, char** argv){
std::ifstream in("input.txt"); // Liste mit Daten einlesen

int var2;             // Variablen definieren
std::string var1; 
float a=1.8; 
float b=32;

for(int i=0; i<8; i++){ // Loop basteln
in >>var1;
in >>var2;
if (var1 == "F"){ // Unterscheidung, ob in Liste F oder C vorne steht
    double A = var2*a+b; // Celsius in Fahrenheit
    std::cout << var2 << " Grad Celsius sind " << A << " Grad Fahrenheit " << std::endl;
}
else if (var1 == "C"){
  double B = (var2-b)*a; // Fahrenheit in Celsius
    std::cout << var2 << " Grad Fahrenheit sind " << B << " Grad Celsius" << std::endl; 
}
else {
  std::cout << var2 << " ist weder Grad Fahrenheit noch Celsius. Bitte wähle eine andere Temperatur." << std::endl;
} 
}}

