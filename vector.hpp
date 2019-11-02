#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <vector>
#include "container.hpp"
//#include "base.hpp"

using namespace std;

class VectorContainer: public Container{
	 protected:
        Sort* sort_function;
		vector<Base*> vector1;
    public:
    
        /* Constructors */
        //Container() : sort_function(nullptr) { };
        //Container(Sort* function) : sort_function(function) { };

        /* Non Virtual Functions */
        void set_sort_function(Sort* sort_function){ // set the type of sorting algorithm
			this->sort_function = sort_function;
		}

        // push the top pointer of the tree into container
        virtual void add_element(Base* element){
			vector1.push_back(element);
		}
        // iterate through trees and output the expressions (use stringify())
        virtual void print(){
			for(int i = 0; i < vector1.size(); i++){
				vector1.at(i)->stringify();
			}
		}
        // calls on the previously set sorting-algorithm. Checks if sort_function is not
        // null, throw exception if otherwise
        virtual void sort(){
			if(sort_function == nullptr){
				throw "sort_function is nullptr";
			return;
			}
			//sort
			sort_function->sort(this);
			
		}

        /* Functions Needed to Sort */
        //switch tree locations
        virtual void swap(int i, int j){
			Base* temp;
			temp = vector1.at(i);
			vector1.at(i) = vector1.at(j);
			vector1.at(j) = temp;
		}
        // get top ptr of tree at index i
        virtual Base* at(int i){
			return vector1.at(i);
		}
        // return container size
        virtual int size(){
			return vector1.size();
		}
};
#endif
