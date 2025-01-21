#include "MinHeap.hpp"
#include <gtest/gtest.h>
int main(int argc, char** argv){
    // Initialize Google Test framework
    // ::testing::InitGoogleTest(&argc, argv);

    // Run all tests
    // return RUN_ALL_TESTS();
    try {
        throw std::logic_error("Heap is empty");
    } catch (const std::logic_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}
