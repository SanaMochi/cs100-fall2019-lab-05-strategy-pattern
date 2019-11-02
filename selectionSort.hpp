#ifndef __SELECT_SORT_HPP__
#define __SELECT_SORT_HPP__

#include "base.hpp"
//#include "container.hpp"
#include "sort.hpp"

class Container;

class SelectionSort: public Sort {
    public:
        /* Constructors */
        //Sort();

        virtual void sort(Container* container){
		int size = container->size();
		
		Base* smallest;
			for(int i = 0; i < size; i++){
				smallest = container->at(i);
				for(int j = i; j < size; j++){
					if(smallest->evaluate() > container->at(j)->evaluate()){
						container->swap(i, j);
					}
				}
			}
			
		}
};
#endif
