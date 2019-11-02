#ifndef __SORT_HPP__
#define __SORT_HPP__

#include "base.hpp"
#include "container.hpp"
//#include "bubble_sort.hpp"

class Container;

class Sort {
    public:
        /* Constructors */
        Sort(){ };

        /* Pure Virtual Functions */
        virtual void sort(Container* container) = 0;
};

#endif //__SORT_HPP__
