/************************************************************/
/*  Lab 3 tester                                            */
/*  To compile:                                             */
/*     g++ lab3tester.cpp -std=c++0x                        */
/*  To run:                                                 */
/*     ./a.out                                              */
/************************************************************/

#include "iteratorintro.h"
#include <iostream>

int main(void){
	DList<int> regular;
	Sentinel<int> sentinel;
	DList<int>::const_iterator it;
	DList<int>::iterator it2;
	std::cout << "testing regular doubly linked list" << std::endl;

	for(int i=0;i<3;i++){
		regular.push_front(i);
	}
	for(it=regular.cbegin();
                  it!=regular.cend();it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	for(it2=regular.begin();
                  it2!=regular.end();it2++){
		*it2 = *it2 +1;
	}
	std::cout << "after increment: " << std::endl;
	for(it=regular.cbegin();
                  it!=regular.cend();it++){
		std::cout << *it << " ";
	}
}
