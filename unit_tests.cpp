#ifndef __UNIT_TEST_HPP__
#define __UNIT_TEST_HPP__

#include "gtest/gtest.h"

#include "op_test.hpp"
#include "list.hpp"
#include "container.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(ListContainerTestSet, SwapTest) {
    // Setup the elements under test
    Op* seven = new Op(7);
    List* test_container = new List();

    // Exercise some functionality of hte test elements
    test_container->add_element(seven);

    // Assert that the container has at least a single element
    // otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}
/*
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

    List* container = new List();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new bubble_sort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}
*/
#endif //__UNIT_TEST_HPP__
