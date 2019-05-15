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

	//On pourrait utiliser toujours before_begin() pour l'endroit de l'insérsion du splice
	//Seulement, dans le codecheck, les valeurs doivent être dans un ordre croissant
	auto ptrFB = FB.before_begin();
	auto ptrF = F.before_begin();
	auto ptrB = B.before_begin();
	
  	auto ptr = L.before_begin();
	while(next(ptr) != L.end()){
		//Si divisible par 3
		if(!(*next(ptr) % 3)){
		  //Si divisible par 5 -> fizzbuzz
			if(!(*next(ptr) % 5)){
			    FB.splice_after(ptrFB,L,ptr);
				++ptrFB;
			//Sinon -> fizz
			}else{
			    F.splice_after(ptrF,L,ptr);
				++ptrF;
			}
		}
	   //Si divisible par 5 et pas par 3 ->buzz
		else if(!(*next(ptr) % 5) && (*next(ptr) % 3)){
			B.splice_after(ptrB,L,ptr);
			++ptrB;
		}else{
			//On incrémente le pointeur uniquement si on a rien splice
			ptr++;
		}
	}

}
