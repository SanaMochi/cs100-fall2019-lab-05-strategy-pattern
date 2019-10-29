#ifndef _LIST_HPP_
#define _LIST_HPP_

#include "base.hpp"
#include "container.hpp"
#include "sort.hpp"
#include "list.hpp"
#include <list>
#include <iterator>

using namespace std;

class List : public Container {
    list<Base*> list1;
    public:
    
		List() {} ;
        //List(Sort* function) : sort_function(function) { };

        /* Non Virtual Functions */
        void set_sort_function(Sort* sort_function) {
			// set the type of sorting algorithm
			this->sort_function = sort_function;
		}

        /* Pure Virtual Functions */
        // push the top pointer of the tree into container
        void add_element(Base* element) {
			list1.push_back(element);
		}
		
        // iterate through trees and output the expressions (use stringify())
        void print() {
			for (list <Base*> :: iterator it = list1.begin(); it != list1.end(); it++) {
				cout << (*it)->stringify() << " ";
			}
		}		
		
        // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
        void sort() {
			set_sort_function(sort_function);
			if (sort_function == nullptr) {
				throw "sort_function is nullptr";
				return;
			}
			sort_function->sort(this);
		}

        /* Essentially the only functions needed to sort */
        //switch tree locations
        void swap(int i, int j) {
			
			if (i < 0 || i >= list1.size() || j < 0 || j >= list1.size()) {
				throw "index out of bounds";
			}
			
			Base* temp;
			list <Base*> :: iterator it = list1.begin();
			for (int index = 0; i < index; index++) {
				if (i == index) {
					temp = *it;
				}
				it++;
			}			
			
			list <Base*> :: iterator it2 = list1.begin();
			for (int index2 = 0; j < index2; index2++) {
				if (j == index2) {
					*it = *it2;
					*it2 = temp;
				}
				it2++;
			}
		}
        
        // get top ptr of tree at index i
        Base* at(int i) {
			if (i < 0 || i >= list1.size()) {
				throw "index out of bounds";
			}
			list <Base*> :: iterator it = list1.begin();
			for (int index = 0; i < index; index++) {
				if (i == index) {
					return *it;
				}
				it++;
			}
		}
        
        // return container size
        int size() {
			return list1.size();
		}
};

#endif // _LIST_HPP_
