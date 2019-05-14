/*
Ecrivez la fonction fizzBuzz qui transfère les éléments de la liste L vers les listes F,B et FB de sorte que
Les multiples de 3 mais pas 5 vont dans la liste F
Les multiples de 5 mais pas 3 vont dans la liste B
Les multiples de 3 et de 5 vont dans la liste FB
Les autres éléments restent dans la liste L
Tous les déplacements d'éléments doivent être effectués avec la méthode http://www.cplusplus.com/reference/forward_list/forward_list/splice_after/.

 */
#include "fizzy.h"
#include <cassert>
#include <iostream>
using std::forward_list;
using namespace std;

//Vous pouvez ajouter des fonctions annexes si nécessaire

void fizzBuzz(std::forward_list<int>& L,
              std::forward_list<int>& F,
              std::forward_list<int>& B,
              std::forward_list<int>& FB)
{
  assert(F.empty() and B.empty() and FB.empty());
  //Parcours de la liste L
  forward_list<int>::iterator prevIt = L.before_begin();
  for (forward_list<int>::iterator it = L.begin(); it != L.end(); ++it) {

      std::cout << "prev : " << *prevIt << " \n";
      std::cout << "it : " << *it << " \n";
      if(!(*it % 3))
      {
          if(*it % 5){
              //Fizz
              //std::cout << "FIZZ : " << *it << " |prev : "<< *prevIt << "\n";
                  F.splice_after(F.before_begin(),L,prevIt);
          }else{
              //fizzbuz
               //std::cout << "FIZZBUZ : " << *it << "\n";
              //FB.splice_after(FB.before_begin(),L,prevIt);
          }
      }else if(!(*it % 5)){
          //buzz
           //std::cout << "BUZZ : " << *it << "\n";
         // B.splice_after(B.before_begin(),L,prevIt);

      }

     prevIt = it;

  }

}
