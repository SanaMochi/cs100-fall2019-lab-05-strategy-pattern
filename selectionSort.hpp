
#include "base.hpp"
//#include "container.hpp"
#include "sort.hpp"

class selectionSort: public Sort {
    public:
        /* Constructors */
        Sort();

        /* Pure Virtual Functions */
        virtual void sort(Container* container){
		int size = container.size();
		Base* smallest;
			for(int i = 0; i < size; i++){
				smallest; = containter.at(i);
				for(int j = i; j < size; j++){
					if(smallest->evaluate() > container.at(j)->evaluate()){
						container.swap(i, j);
					}
			}
			
		}
};
