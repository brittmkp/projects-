#include <iostream>
using namespace std; 

int main(){
  for (int i; i <= 100; i++){
    if (i % 15 == 0){
      cout << "fizzbuzz"<< endl;
    }
    else if (i % 5 == 0){
      cout << "buzz" << endl;
    }
    else if (i % 3 == 0){
      cout << "fizz" << endl;
    }
    else {
      cout << i << endl;
    }
  }
}