#include <iostream>
#include "GenericArray.h"

int main()
{
    GenericArray<int> int_array;
    for (int i = 1; i <= 12; ++i)
    {
        int_array.addElement(i * 10);
    }

    std::cout << "Integer array: ";
    for (int i = 0; i < int_array.size(); ++i)
    {
        std::cout << int_array.at(i) << ' ';
    }
    std::cout << "\nSize: " << int_array.size() << '\n';
    std::cout << "Sum: " << int_array.sum() << '\n';
    std::cout << "Maximum: " << int_array.max() << '\n';
    std::cout << "Minimum: " << int_array.min() << '\n';
    std::cout << "Value at index 2: " << int_array.at(2) << '\n';

    int begin = 5;
    int end = 10;
    int *sliced_array = int_array.slice(begin, end);
    std::cout << "Slice (positions 5 through 10): ";
    for (int i = 0; i < end - begin + 1; ++i)
    {
        std::cout << sliced_array[i] << ' ';
    }
    std::cout << '\n';

    // The slice is a separate array, so frees  separately.
    delete[] sliced_array;

    // Trying a different numerical type with the same class.
    GenericArray<double> double_array;
    double_array.addElement(1.5);
    double_array.addElement(2.5);
    double_array.addElement(-0.5);
    std::cout << "\nDouble array size: " << double_array.size() << '\n';
    std::cout << "Sum: " << double_array.sum() << '\n';
    std::cout << "Maximum: " << double_array.max() << '\n';
    std::cout << "Minimum: " << double_array.min() << '\n';

    // Shows the exact slice example from the assignment page
    GenericArray<int> example;
    for (int i = 0; i <= 8; i += 2)
    {
        example.addElement(i);
    }
    int *example_slice = example.slice(2, 4);
    std::cout << "\nExample slice(2, 4): ";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << example_slice[i] << ' ';
    }
    std::cout << '\n';
    delete[] example_slice;

    // Show that the  invalid bounds get caught.
    try
    {
        int *invalid_slice = int_array.slice(0, 3);
        delete[] invalid_slice;
    }
    catch (const std::out_of_range &error)
    {
        std::cout << "\nBounds check: " << error.what() << '\n';
    }

    return 0;
}
