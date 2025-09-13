#include "ulliststr.h"
#include <iostream>
#include <string>

void testBasicOperations() {
    std::cout << "=== Testing Basic Operations ===" << std::endl;
    
    ULListStr list;
    
    // Test empty list
    std::cout << "Empty list size: " << list.size() << std::endl;
    std::cout << "Empty list is empty: " << (list.empty() ? "true" : "false") << std::endl;
    
    // Test push_back
    list.push_back("first");
    list.push_back("second");
    list.push_back("third");
    
    std::cout << "After push_back operations:" << std::endl;
    std::cout << "Size: " << list.size() << std::endl;
    std::cout << "Elements: ";
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;
    
    // Test front and back
    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;
}

void testPushFront() {
    std::cout << "\n=== Testing Push Front ===" << std::endl;
    
    ULListStr list;
    
    // Test push_front on empty list
    list.push_front("alpha");
    std::cout << "After push_front on empty: " << list.get(0) << std::endl;
    
    // Test push_front on non-empty list
    list.push_front("beta");
    list.push_front("gamma");
    
    std::cout << "After multiple push_front:" << std::endl;
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;
}

void testPopOperations() {
    std::cout << "\n=== Testing Pop Operations ===" << std::endl;
    
    ULListStr list;
    
    // Fill list
    for (int i = 0; i < 15; i++) {
        list.push_back("item" + std::to_string(i));
    }
    
    std::cout << "Initial size: " << list.size() << std::endl;
    
    // Test pop_back
    list.pop_back();
    std::cout << "After pop_back, size: " << list.size() << std::endl;
    std::cout << "New back: " << list.back() << std::endl;
    
    // Test pop_front
    list.pop_front();
    std::cout << "After pop_front, size: " << list.size() << std::endl;
    std::cout << "New front: " << list.front() << std::endl;
    
    // Test popping until empty
    while (!list.empty()) {
        list.pop_back();
    }
    std::cout << "After popping all, size: " << list.size() << std::endl;
    std::cout << "Is empty: " << (list.empty() ? "true" : "false") << std::endl;
}

void testMixedOperations() {
    std::cout << "\n=== Testing Mixed Operations ===" << std::endl;
    
    ULListStr list;
    
    // Mixed push operations
    list.push_back("back1");
    list.push_front("front1");
    list.push_back("back2");
    list.push_front("front2");
    
    std::cout << "Mixed operations result: ";
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;
    
    // Test set operation
    list.set(1, "modified");
    std::cout << "After set(1, 'modified'): ";
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;
}

void testLargeOperations() {
    std::cout << "\n=== Testing Large Operations (Array Boundaries) ===" << std::endl;
    
    ULListStr list;
    
    // Test filling beyond one array size (ARRSIZE = 10)
    for (int i = 0; i < 25; i++) {
        list.push_back("val" + std::to_string(i));
    }
    
    std::cout << "After adding 25 elements:" << std::endl;
    std::cout << "Size: " << list.size() << std::endl;
    std::cout << "First few: " << list.get(0) << ", " << list.get(1) << ", " << list.get(2) << std::endl;
    std::cout << "Last few: " << list.get(22) << ", " << list.get(23) << ", " << list.get(24) << std::endl;
    
    // Test push_front with full arrays
    for (int i = 0; i < 15; i++) {
        list.push_front("front" + std::to_string(i));
    }
    
    std::cout << "After adding 15 front elements:" << std::endl;
    std::cout << "Size: " << list.size() << std::endl;
    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;
}

void testEdgeCases() {
    std::cout << "\n=== Testing Edge Cases ===" << std::endl;
    
    ULListStr list;
    
    // Test pop on empty list (should do nothing)
    list.pop_back();
    list.pop_front();
    std::cout << "Pop on empty list - size: " << list.size() << std::endl;
    
    // Test single element operations
    list.push_back("single");
    std::cout << "Single element - front: " << list.front() << ", back: " << list.back() << std::endl;
    
    list.pop_front();
    std::cout << "After removing single element - size: " << list.size() << std::endl;
    
    // Test alternating push/pop
    list.push_back("a");
    list.push_front("b");
    list.pop_back();
    list.push_back("c");
    
    std::cout << "After alternating operations: ";
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    try {
        testBasicOperations();
        testPushFront();
        testPopOperations();
        testMixedOperations();
        testLargeOperations();
        testEdgeCases();
        
        std::cout << "\n=== All Tests Completed Successfully! ===" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}