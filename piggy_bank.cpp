#include <iostream>
#include "conversion.hpp"
using namespace std;

int main() {

  int pesos;
  int reais;
  int soles;
  int dollars;

  cout << "Enter number of Colombian Pesos: ";
  cin >> pesos;
  cout << "You have $" << d_peso(pesos) << " in USD" << endl;
  cout << "Enter number of Brazilian Reais: ";
  cin >> reais;
  cout << "You have $" << d_reais(reais) << " in USD" << endl;
  cout << "Enter number of Peruvian Soles: ";
  cin >> soles;
  cout << "You have $" << d_soles(soles) << " in USD" << endl;
  return 0;

  
  
}