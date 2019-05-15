/*
	Codecheck :

Test 1 :

	6 4 5 7 2 3 1 0 9 8 END
	6 4 5 7 2 3 1 0 9 8
	0 6 4 5 7 2 3 1 9 8
	0 1 6 4 5 7 2 3 9 8
	0 1 2 6 4 5 7 3 9 8
	0 1 2 3 6 4 5 7 9 8
	0 1 2 3 4 6 5 7 9 8
	0 1 2 3 4 5 6 7 9 8
	0 1 2 3 4 5 6 7 9 8
	0 1 2 3 4 5 6 7 9 8
	0 1 2 3 4 5 6 7 8 9

Test 2 :
	5 3 1 0 2 6 4 END
	5 3 1 0 2 6 4
	0 5 3 1 2 6 4
	0 1 5 3 2 6 4
	0 1 2 5 3 6 4
	0 1 2 3 5 6 4
	0 1 2 3 4 5 6
	0 1 2 3 4 5 6

Test 3 :

	42 24 END
	42 24
	24 42

Test 4:
	42 END
	42

Test 5 :
	END
 */
#ifndef selectionsort_h
#define selectionsort_h

#include "listUtils.h"

template <class T>
void selectionSort(std::list<T>& L) {

   //void splice (iterator position, list& x, iterator i);
	auto j = L.begin();
	while(j != prev(L.end()))
	{
		auto min = j;
		auto i = next(j);
		while(i != L.end()){
			if(*i < *min)
				min = i;
			i = next(i);
		}
		L.splice(j,L,min);
		j = next(min);
		std::cout << L << "\n";
	}
}

#endif
