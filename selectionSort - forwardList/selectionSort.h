#ifndef selectionsort_h
#define selectionsort_h

#include "forwardListUtils.h"

template <class T>
void selectionSort(std::forward_list<T>& L) {

//  Complétez cette fonction
	if(!L.empty()){
		auto j = L.before_begin();
		while(next(next(j)) != L.end())
		{
			auto min = next(j);
			auto i = j;
			while(next(i) != L.end()){
				if(*next(i) < *next(min))
					min = i;
				++i;
			}
			L.splice_after(j,L,min);
			++j;
			std::cout << L << "\n";
		}
	}
}

#endif
