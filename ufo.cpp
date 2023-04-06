#include <iostream>
#include "ufo_funcs.hpp"
using namespace std;

int main() {

  greet();

  string codeword = "codecademy";
  string answer = "__________";
  int misses = 0;

  vector <char> incorrect;
  bool guess = false;

  char letter;

  while (answer != codeword && misses < 7){
    display_misses(misses);
    display_status(incorrect, answer);

    cout << "\nPlease enter your guess: ";
    cin >> letter;

    for (int i = 0; i < codeword.length(); i++){

      if (letter == codeword[i]){
      answer[i] = letter;
      guess = false;
    }

    
  }

  if (guess){
    cout << "\nCorrect!\n";
  }
  else {
    cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
    incorrect.push_back(letter);
    misses++;
  }

  end_game(answer, codeword);
  
}
}
