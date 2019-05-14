#include <iostream>
#include "fizzy.h"

using namespace std;

template <class T>
ostream& operator<< (ostream& os, forward_list<T> L) {
  for(const T& el : L)
    os << el << " ";
  return os;
}

forward_list<int> readList() {
  forward_list<int> L;
  auto p = L.before_begin();
  int i;
  //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
  for (int i = 17; i >= 0; i--) {
      L.insert_after(p,i);
  }
  // while(cin >> i) {
  //   L.insert_after(p,i);
  //   ++p;
  // };
  return L;
}

int main() {
  forward_list<int> L = readList();
  cout << "L: " << L << endl;

  forward_list<int> F,B,FB;
  fizzBuzz(L,F,B,FB);

  cout << endl;
  cout << "L: " << L << endl;
  cout << "F: " << F << endl;
  cout << "B: " << B << endl;
  cout << "FB: " << FB << endl;
}
