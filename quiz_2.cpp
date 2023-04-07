#include <iostream>
#include <cmath>
using namespace std;

double calculate_vol(double h, double r);
const double PI = 3.14159265;

int main(){
    double h, r;
    cout << "Enter in a height for your cylinder: ";
    cin >> h;
    cout << "Enter in a radius for your cylinder: ";
    cin >> r;
    cout << "The volume of your cylinder = " << calculate_vol(h,r) * PI << endl;

}

double calculate_vol(double height, double radius){
    return pow(height, 2.0) * radius;
}