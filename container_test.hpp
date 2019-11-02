#ifndef __CONTAINER_TEST_HPP__
#define __CONTAINER_TEST_HPP__

#include "gtest/gtest.h"
 
#include "base.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Pow.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "container.hpp"
#include "vector.hpp"
#include "selectionSort.hpp"
#include "sort.hpp"

TEST(VectorContainerTestSet, BasicTest) {
    // Setup the elements under test
    Op* seven = new Op(7);
    VectorContainer * test_container = new VectorContainer();

    // Exercise some functionality of hte test elements
    test_container->add_element(seven);

    // Assert that the container has at least a single element
    // otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}

TEST(VectorContainerTestSet, SwapTest) {
    // Setup the elements under test
    Op* seven = new Op(7);
    Op* one = new Op(1);
    VectorContainer * test_container = new VectorContainer();

    test_container->add_element(seven);
    test_container->add_element(one);

    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
    EXPECT_EQ(test_container->at(1)->evaluate(), 1);
    
    test_container->swap(0,1);
    
    EXPECT_EQ(test_container->at(0)->evaluate(), 1);
    EXPECT_EQ(test_container->at(1)->evaluate(), 7);
}

//SortTestSet
TEST(VectorContainerTestSet, SelectionSortTest) {
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

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}


#endif 
