#include "base.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Pow.hpp"
#include "add.hpp"
#include "sub.hpp"
//#include "rand.hpp"
#include "container.hpp"
#include "vector.hpp"
#include "sort.hpp"
#include "selectionSort.hpp"
#include "list.hpp"
#include "Bubble_sort.hpp"
#include <iostream>

int main(){
	Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);
    
    std::cout << container->at(0)->evaluate() << ", " << container->at(1)->evaluate() << ", " << container->at(2)->evaluate() << ", " << std::endl;
    
    container->set_sort_function(new SelectionSort());
    container->sort();
    
    std::cout << container->at(0)->evaluate() << ", " << container->at(1)->evaluate() << ", " << container->at(2)->evaluate() << ", " << std::endl;
    
    
    return 0;
}
