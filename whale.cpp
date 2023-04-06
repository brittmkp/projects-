#include <iostream>
#include <string>
#include <vector>
using namespace std; 
int main(){
  
  string input = "hey baby u like motorcylces ?";
  vector<char> vowels = {a, e, i, o, u};
  vector<char> result;

  for (int i = 0; i < input.size(); i++){
    
    for (int w = 0; w < vowels.size(); w++){

        if (input[i] == vowels[w]){
          result.push_back(input[i]);
        }

        for (int a = 0; a < results.size(); a++){
          cout << result[a];
        }
    }

  }
}