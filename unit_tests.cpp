#ifndef __UNIT_TEST_HPP__
#define __UNIT_TEST_HPP__

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
#include "sort.hpp"
#include "list.hpp"
#include "container.hpp"
#include "bubble_sort.hpp"
#include "sort.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(ListContainerTestSet, BasicTest) {
    // Setup the elements under test
    Op* seven = new Op(7);
    ListContainer* test_container = new ListContainer();

    // Exercise some functionality of the test elements
    test_container->add_element(seven);

    // Assert that the container has at least a single element
    // otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}

TEST(ListContainerTestSet, SwapTest) {
    // Setup the elements under test
    Op* seven = new Op(7);
    Op* ten = new Op(10);
    ListContainer* test_container = new ListContainer();

    // Exercise some functionality of the test elements
    test_container->add_element(seven);
    test_container->add_element(ten);

    // Assert that the container has at least a single element
    // otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
    EXPECT_EQ(test_container->at(1)->evaluate(), 10);
  
    test_container->swap(0,1);
  
    EXPECT_EQ(test_container->at(0)->evaluate(), 10);
    EXPECT_EQ(test_container->at(1)->evaluate(), 7);
}

TEST(SortTestSet, BubbleSortTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    ListContainer* container = new ListContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

#endif //__UNIT_TEST_HPP__
