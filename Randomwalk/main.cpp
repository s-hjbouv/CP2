#include <iostream>
#include <vector>
#include <random>
#include <fstream>


int main(){

 double x1;
 double x2;
 double x1a;

 std::vector<int> Teilchenpositionen(10000000,0); //Teilchenzahl und ihre Positionen

//Vektoren für die Zeitschritte, Wegschritte und x**2; Zeitpositionen, Wegschrittpositionen; Zähler  
  std::vector<double> Zeitschritt(10);
  std::vector<double> Wegschritt(Teilchenpositionen.size());
  std::vector<double> M1(10); //Vektor für erstes Moment
  std::vector<double> M2(10); //Vektor für zweites Moment
  std::vector<std::string> o(M1.size());
 // std::vector<double> Zeitpositionen
  std::vector<double> Counter(20,0);

std::mt19937 gen; //Zufallszahl definieren
gen.seed(5); //Beginn Zufallszahlen

//------------------------------------------------------------------------------

// Schleife über Zeitschritte  
for(int t =0; t< Zeitschritt.size(); t++) {
    x1=0;
    x2=0;
    for(int i = 0; i < Teilchenpositionen.size(); i++) { //Schleife über Teilchenanzahlvektor
      //Zufallszahlen
      std::uniform_real_distribution<double> dis(0,1);
     // std::cout <<"Zufallszahlen " <<dis(gen) << std::endl; // Zufallszahlen ausgeben
     
     //Schrittrichtung entscheiden
      if(dis(gen) > 0.5){
      Wegschritt[i] = Teilchenpositionen[i]++;
      }
      else{
      Wegschritt[i] = Teilchenpositionen[i]--;
      }
     // Zeitschritt.push_back(t);  //neue Werte an Vektor hängen
     // Wegschritt.push_back(Wegschritt[i]); 
    }

    // 1.Moment: Aufsummieren der Wegschritte pro Zeiteinheit
    for (int m = 0; m < Wegschritt.size(); m++){
      x1+= Wegschritt[m]; //Aufsummieren
    }  
    x1a = x1/Teilchenpositionen.size();
   // std::cout <<" 1. Moment: " << x1/Teilchenpositionen.size() <<std::endl;

    // 2.Moment: Aufsummieren der Wegschritte zum Quadrat minus Mittelwert(1.Moment) pro Zeiteinheit
    for (int m=0; m < Wegschritt.size(); m++){
      x2+= (Wegschritt[m]-x1a)*(Wegschritt[m]-x1a);
    }  
   // std::cout << "2. Moment: " << x2/Teilchenpositionen.size() << std::endl;
    
    M1.push_back(x2/Teilchenpositionen.size());
    M2.push_back(x1/Teilchenpositionen.size());

}
// M1 und M2 mit Python geplottet

//----------------------------------------------------------------------
//----------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//
 // D über Regression berechnen: 2D = 0.999682  Regression mit Excel
 // -- D = 0.499841
 // 2.Moment = 2D*Zeitschritt
 // Zeitschritt: 1s

//--------------------------------------------------


// Schleife zum Zählen der Anzahl der Teilchenpositionen
for(int k = 0; k< Teilchenpositionen.size(); k++){
  for (int i = -10; i<10; i++){
    if (i == Teilchenpositionen[k]){
      Counter[i+10]++;
      }
  }
}

// Zähler ausgeben
for (int i = 0; i< Counter.size(); i++){
std::cout << i << " : " << Counter[i] << std::endl;
}

//Gaußverteilung geplottet mit Canopy
//








//Vektoren als File ausgeben
//std::ofstream output_Zeitschritt("./Zeitschritt.txt");
//std::ofstream output_Wegschritt("./Wegschritt.txt");

//Vektoren ausgeben
//for(int n=0; n<Zeitschritt.size(); n++){
//  std::cout << "Zeitschritt " << Zeitschritt[n] <<std::endl;
//  std::cout <<"Wegschritt " <<Wegschritt[n] <<std::endl; 
//}



return 0;

}
