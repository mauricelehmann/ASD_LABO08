/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   insertionSort.h
 * Author: nichu
 *
 * Created on 15. mai 2019, 14:23
 */

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "listUtils.h"

template <class T>
void insertionSort(std::list<T>& L) {
  if(L.empty()){
     return;
  }
  auto k = next(L.begin());
  while(k != L.end()){
     auto i = k;
     while(i != L.begin() && *k < *(prev(i))){
        i = prev(i);
     }
     auto t = next(k);
     L.splice(i,L,k);
     k = t;
     std::cout << L << std::endl;
  }
}



#endif /* INSERTIONSORT_H */

