#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include "sort.hpp"
#include "base.hpp"
//#include "container.hpp"

class Container;

class BubbleSort : public Sort {
    public:
        /* Constructors */
        //Bubble_sort();

        /* Pure Virtual Functions */
        void sort(Container* container) {
		    int i, j;  
		    int n = container->size()-1;
			for (i = 0; i < n; i++) {
				// Last i elements are already in place  
				for (j = 0; j < n-i; j++) { 
					if (container->at(j)->evaluate() > container->at(j+1)->evaluate()) {
						container->swap(j, j+1);  
					}
				}
			}
		}
};

#endif //BUBBLE_SORT
