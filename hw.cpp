#include <iostream>
#include <vector>
using namespace std;
int main(){
   int x;
   vector<int> temp;
   cout << "Please enter 5 numbers: \n";
   while (cin >> x) temp.push_back(x);
   typedef vector<int>::size_type vec_sz;
   vec_sz n = temp.size();
   if (n<5){
       cout << "Not enough input, try again...";
       return 1;
   }
   for (vec_sz i = 0; i < n; ++i)
   cout << temp[i] << endl;
    return 0;
}