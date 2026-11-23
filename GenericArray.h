#ifndef GENERIC_ARRAY_H
#define GENERIC_ARRAY_H

#include <stdexcept>

template <typename T>
class GenericArray
{
private:
    T *data;
    int count;

public:
    GenericArray() : data(nullptr), count(0) {}

    ~GenericArray()
    {
        delete[] data;
    }

    // Give each copy its own array.
    GenericArray(const GenericArray &other)
        : data(new T[other.count]), count(other.count)
    {
        for (int i = 0; i < count; ++i)
        {
            data[i] = other.data[i];
        }
    }

    GenericArray& operator=(const GenericArray &other)
    {
        if (this != &other)
        {
            T *newData = new T[other.count];
            for (int i = 0; i < other.count; ++i)
            {
                newData[i] = other.data[i];
            }
            delete[] data;
            data = newData;
            count = other.count;
        }
        return *this;
    }

    void addElement(T element)
    {
        // Make room for one more element and copy the old values.
        T *newData = new T[count + 1];
        for (int i = 0; i < count; ++i)
        {
            newData[i] = data[i];
        }
        newData[count] = element;
        delete[] data;
        data = newData;
        ++count;
    }

    T at(int index) const
    {
        if (index < 0 || index >= count)
        {
            throw std::out_of_range("Array index is out of bounds.");
        }
        return data[index];
    }

    int size() const
    {
        return count;
    }

    T sum() const
    {
        T total = T{};
        for (int i = 0; i < count; ++i)
        {
            total += data[i];
        }
        return total;
    }

    T max() const
    {
        if (count == 0)
        {
            throw std::runtime_error("An empty array has no maximum.");
        }
        T largest = data[0];
        for (int i = 1; i < count; ++i)
        {
            if (data[i] > largest)
            {
                largest = data[i];
            }
        }
        return largest;
    }

    T min() const
    {
        if (count == 0)
        {
            throw std::runtime_error("An empty array has no minimum.");
        }
        T smallest = data[0];
        for (int i = 1; i < count; ++i)
        {
            if (data[i] < smallest)
            {
                smallest = data[i];
            }
        }
        return smallest;
    }

    T* slice(int begin, int end) const
    {
        // Use positions starting at 1 so i can match the  assignment example.
        if (begin < 1 || end < begin || end > count)
        {
            throw std::out_of_range("Slice bounds are invalid.");
        }
        int length = end - begin + 1;
        T *result = new T[length];
        for (int i = 0; i < length; ++i)
        {
            result[i] = data[begin - 1 + i];
        }
        return result;
    }
};

#endif
