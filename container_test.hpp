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


TEST(VectorContainerTestSet, SwapTest) {
    // Setup the elements under test
    Op* seven = new Op(7);
    VectorContainer test_container = new VectorContainer();

    // Exercise some functionality of hte test elements
    test_container->add_element(seven);

    // Assert that the container has at least a single element
    // otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}

#endif 
