#pragma once
#include <algorithm>
#include <cstddef> // size_t
#include <cassert> // assert
#include <iostream> // cout
#include <cstring> // memcpy

class myVector
{
    size_t size_; // the current # of inserted elements
    size_t capacity_; // the maximum current elements available
    int* data_; // our pointer to the heap
public:
    ~myVector() // destructor
    {
        delete[] data_;
    }

    myVector()
    {
        size_ = 0;
        capacity_ = 10; // we will make capacity 10 by default
        data_ = new int[capacity_];
    }

    // overloaded constructor to initialize with a certain size
    myVector(const size_t capacity)
    {
        size_ = 0;
        capacity_ = capacity;
        data_ = new int[capacity];
    }

    int& operator[](const size_t index) // overloaded our [] operator to return a specific index;
    {
        return data_[index];
    }

    int front() const
    {
        assert(size_ > 0);
        return data_[0];
    }

    int back() const
    {
        assert(size_ > 0);
        return data_[size_ - 1];
    }

    int at(const size_t index) const
    {
        assert(index < size_);
        return data_[index];
    }

    bool empty() const
    {
        return size_ == 0;
    }

    size_t size() const
    {
        return size_;
    }

    size_t capacity() const
    {
        return capacity_;
    }

    void clear()
    {
        delete[] data_; // clear heap
        data_ = new int[capacity_];
        data_ = new int[capacity_];
        size_ = 0;
    }

    void push_back(int value)
    {
        if (size_ == capacity_)
        {
            if (capacity_ == 0)
            {
                capacity_ = 1;
            }
            std::cout << "Maximum size(" << size_ << ") reached, doubling capacity to " << capacity_ * 2 << "\n";
            auto* buf = new int[capacity_ * 2]; // make a buffer to store data

            memcpy(buf, data_, size_ * sizeof(int)); // copy our data to our buffer

            delete[] data_; // delete our old data
            data_ = buf; // set data = buffer
            capacity_ *= 2;
        }
        data_[size_] = value;
        size_++;
    }
    void push_back_range(int arrayToPush[], size_t sizeOfArray)
    {
        for (int i = 0; i < sizeOfArray; i++)
        {
            push_back(arrayToPush[i]);
        }
    }

    void replace(size_t index, int value)
    {
        assert(index < size_);
        data_[index] = value;
    }

    int pop(const size_t index)
    {
        assert(index < size_);
        
        int value = data_[index];
        for (int i = index; i < size_ - 1; i++) // keeps contiguous
        {
            data_[i] = data_[i+1];
        }
        size_--;
        return value;
    }
    int pop_back()
    {
        int value = data_[size_ - 1];
        data_[size_ - 1] = 0; // sentinel value;
        size_--;
        return value;
    }

    void shrink_to_fit() // shrinks capacity to equal size and frees unused space
    {
        auto buf = new int[size_]; // create a buffer which contains all 
        memcpy(buf, data_, size_ * sizeof(int));

        delete[] data_;
        data_ = buf;
        capacity_ = size_;
    }

    void erase(const size_t index)
    {
        assert(index < size_);
        for (int i = index; i < size_ - 1; i++) // erases & keeps contiguous
        {
            data_[i] = data_[i+1];
        }
        size_--;
    }

    void iterate()
    {
        for (int i = 0; i < size_; i++)
        {
            if (i == size_ -1)
            {
                std::cout << "[" << data_[i]  << "]\nCurrent Size: " << size_ << "\nCurrent Capacity: " << capacity_ << "\n";
                return;                
            }
            std::cout << "[" << data_[i]  << "]--";
        }
        
    }
    void reserve(size_t newCapacity)
    {
        if (newCapacity <= capacity_)
        {
            std::cout << "Error: New capacity is less than previous capacity";
            return;
        }
        auto* buf = new int[newCapacity];
        memcpy(buf, data_, size_ * sizeof(int));
        delete[] data_;
        data_ = buf;
        capacity_ = newCapacity;
    }
    
    void stats() const {
        std::cout << "size      = " << size_ << "\n";
        std::cout << "capacity  = " << capacity_ << "\n";
        std::cout << "data ptr  = " << static_cast<const void*>(data_) << "\n";
        std::cout << "heap bytes= " << capacity_ * sizeof(int) << "\n";
    }
    
    /*
     * TODO FUNCTIONS:
     * ELEMENT ACCESS:
     * at <- access specified element w/ bounds checking
     * operator[]  <- access specified element
     * front <- returns front
     * back <- returns back
     * ITERATORS:  <- come back to this???
     * CAPACITY:
     * empty <- checks if empty
     * size <- returns number of elements
     * max_size <- returns maximum possible number of elements with current RAM
     * reserve <- reserves storage (if size is known beforehand)
     * capacity <- returns number of elements that can be held with current allocated storage
     * shrink_to_fit <- frees unused memory
     * MODIFIERS:
     * clear <- clears contents
     * insert <- inserts elements
     * insert_range <- inserts a range of elements (lists for example)
     * emplace <- constructs element in-place
     * erase <- erases elements
     * push_back <- adds an element to the end
     * emplace_back <- constructs an element in-place at the end
     * append_range <- adds a range of elements to the end
     * pop_back <- removes last element
     * resize <- changes number of elements stored
     * swap <- swaps contents
     */
};
