#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "quick_sort.h"

/**
 * print_array - print out array `ar` of size `N`.
 */
static
void print_array(size_t N, double const ar[static N]) {
    for (int i = 0; i < N; i++) {
        printf("%g ", ar[i]);
    }
    printf("\n");
}

/**
 * is_sorted - check if array `ar` is monotonically increasing.
 */
static
bool is_sorted(size_t N, double const ar[static N]) {
    for (int i = 1; i < N; i++) {
        if (ar[i] < ar[i - 1]) {
            return false;
        }
    }
    return true;
}

// Test case 1: Random array
void test_random_array() {
    double ar[] = {3.2, 1.5, 4.8, 2.1, 0.9};
    size_t size = sizeof(ar) / sizeof(ar[0]);

    printf("Test 1: Random array\n");
    printf("Original array: ");
    print_array(size, ar);

    randomized_quicksort(ar, 0, size - 1);

    printf("Sorted array:   ");
    print_array(size, ar);
    printf("Is sorted: %s\n\n", is_sorted(size, ar) ? "PASS" : "FAIL");
}

// Test case 2: Already sorted array
void test_sorted_array() {
    double ar[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    size_t size = sizeof(ar) / sizeof(ar[0]);

    printf("Test 2: Already sorted array\n");
    printf("Original array: ");
    print_array(size, ar);

    randomized_quicksort(ar, 0, size - 1);

    printf("Sorted array:   ");
    print_array(size, ar);
    printf("Is sorted: %s\n\n", is_sorted(size, ar) ? "PASS" : "FAIL");
}

// Test case 3: Array with duplicates
void test_array_with_duplicates() {
    double ar[] = {4.0, 2.0, 2.0, 4.0, 3.0};
    int size = sizeof(ar) / sizeof(ar[0]);

    printf("Test 3: Array with duplicates\n");
    printf("Original array: ");
    print_array(size, ar);

    randomized_quicksort(ar, 0, size - 1);

    printf("Sorted array:   ");
    print_array(size, ar);
    printf("Is sorted: %s\n\n", is_sorted(size, ar) ? "PASS" : "FAIL");
}

// Test case 4: Array with negative numbers
void test_array_with_negatives() {
    double ar[] = {-1.0, -3.0, -2.0, -5.0, 0.0};
    int size = sizeof(ar) / sizeof(ar[0]);

    printf("Test 4: Array with negative numbers\n");
    printf("Original array: ");
    print_array(size, ar);

    randomized_quicksort(ar, 0, size - 1);

    printf("Sorted array:   ");
    print_array(size, ar);
    printf("Is sorted: %s\n\n", is_sorted(size, ar) ? "PASS" : "FAIL");
}

// Test case 5: Empty array
void test_empty_array() {
    double ar[] = {};
    int size = sizeof(ar) / sizeof(ar[0]);

    printf("Test 5: Empty array\n");
    printf("Original array: (empty)\n");
    print_array(size, ar);

    randomized_quicksort(ar, 0, size - 1);

    printf("Sorted array:   ");
    print_array(size, ar);
    printf("Is sorted: %s\n\n", is_sorted(size, ar) ? "PASS" : "FAIL");
}

// Test case 6: Single-element array
void test_single_element_array() {
    double ar[] = {42.0};
    int size = sizeof(ar) / sizeof(ar[0]);

    printf("Test 6: Single-element array\n");
    printf("Original array: ");
    print_array(size, ar);

    randomized_quicksort(ar, 0, size - 1);

    printf("Sorted array:   ");
    print_array(size, ar);
    printf("Is sorted: %s\n\n", is_sorted(size, ar) ? "PASS" : "FAIL");

}

// Main function to run all test cases
int main() {
    printf("Randomized QuickSort Test Suite\n");
    printf("===============================\n");

    test_random_array();
    test_sorted_array();
    test_array_with_duplicates();
    test_array_with_negatives();
    test_empty_array();
    test_single_element_array();

    return 0;
}

