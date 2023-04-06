#include <iostream>
#include <cmath>
using namespace std;

int main() {

  double a, b, c;
  cout << "Enter a: ";
  cin >> a;
  cout << "Enter b: ";
  cin >> b;
  cout << "Enter c: ";
  cin >> c;

  double root1, root2;
  root1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
  root2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);

  cout << root1 << "\n" << root2;

}