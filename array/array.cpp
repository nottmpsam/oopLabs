#include <iostream>
#include <climits>
#include <cassert>
#include "array.h"

template <typename T>
bool Array<T>::operator==(const Array<T>& tempArray) const {
    if (nElements != tempArray.nElements) {
        return false;
    }
    for (int i = 0; i < nElements; ++i) {
        if (array[i] != tempArray.array[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool Array<T>::DeleteIndex(int position) {
    if (position < 0 || position > nElements) {
        std::cerr << "Error: index is not right! " <<
            std::endl;
        return false;
    }
    nElements = nElements - 1;
    for (int i = position; i < nElements; ++i) {
        array[i] = array[i + 1];
    }
    return true;
}

template <typename T>
T Array<T>::FindMin() const {
    T min = array[0];
    for (int i = 0; i < nElements; ++i) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
};

template <typename T>
Array<T> Array<T>::operator+(const T& temp) const {

    if(memory == nElements)
    {
        Array tempArray(memory+1, nElements + 1);
        for (int i = 0; i < nElements; ++i)
            tempArray.array[i] = array[i];
        tempArray.array[tempArray.nElements-1] = temp;
        return tempArray;
    }
    Array tempArray(memory, nElements + 1);
    for (int i = 0; i < nElements; ++i)
        tempArray.array[i] = array[i];
    tempArray.array[tempArray.nElements - 1] = temp;
    return tempArray;
}

template <typename T> 
Array<T>& Array<T>::operator+=(const T& temp) 
{
    if(memory == nElements)
    {
        Array tempArray(memory+1, nElements + 1);
        for (int i = 0; i < nElements; ++i)
            tempArray.array[i] = array[i];
        tempArray.array[tempArray.nElements-1] = temp;
        *this = tempArray;
        return *this;
    }
    Array tempArray(memory, nElements + 1);
    for (int i = 0; i < nElements; ++i)
        tempArray.array[i] = array[i];
    tempArray.array[tempArray.nElements - 1] = temp;
    *this = tempArray;
    return *this;
}
template <typename T>
bool Array<T>::operator!=(const Array<T>& tempArray)  const {
    if (nElements != tempArray.nElements) {
        return true;
    }
    for (int i = 0; i < nElements; ++i) {
        if (array[i] != tempArray.array[i]) {
            return true;
        }
    }
    return false;
}
template<typename T>
T Array<T>::operator[](int position) const
{
    if (position < 0 && (position + nElements >= 0)) {
        return array[position + nElements];
    }
    if (position < nElements && position >= 0) {
        return array[position];
    }
    assert(false && "Error: index is not right.");
    return array[0];

}
template <typename T>
T& Array<T>::operator[](int position) {
    if (position < 0 && (position + nElements >= 0)) {
        return array[position + nElements];
    }
    if (position < nElements && position >= 0) {
        return array[position];
    }
    assert(false && "Error: index is not right.");
    return array[0];
}

template <typename T>
std::istream& operator >> (std::istream& is, Array<T>& t)
{
    assert((is >> t.nElements) || (t.nElements < 0));
    delete [] t.array;
    is >> t.memory;
    t.memory = (t.memory <= t.nElements ? (t.nElements == 0 ? 1: t.nElements) : t.memory);
    t.array = new T[t.memory];
   
    t.FillArray();
    return is;
}

template<typename T>
Array<T>::Array(int m_, int n_)
{
    memory = (m_ == 0 ? 1 : (m_ < 0 ? -m_ : m_));
    nElements = (n_ < 0 ? 0 : n_);
    if (nElements > memory)
    {
        memory = nElements;
    }
    array = new T[memory];
}

template <typename T>
std::ostream& operator<<(std::ostream &os, const Array<T> &t)
{
    for (int i = 0; i < t.nElements; ++i)
        os << t.array[i] << "  ";
    return os;
}

template <typename T>
T Array<T>::FindMax() const {
    T max = array[0];
    for (int i = 0; i < nElements; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}



template <typename T>
bool Array<T>::InsertIndex(int position, const T& key) {
    if (position < 0 || position > nElements) {
        std::cerr << "Error: index is not right! " <<
            std::endl;
        return false;
    }
    nElements = nElements + 1;
    if (nElements > memory) {
        Array tempArray = *this;
        delete[] array;
        memory = memory + 1;
        array = new T [memory];
        for (int i = 0; i < nElements; ++i)
            array[i] = tempArray.array[i];
    }
    for (int i = nElements - 1; i > position; --i)
        array[i] = array[i - 1];
    array[position] = key;
    return true;
}



template <typename T>
Array<T>& Array<T>::operator-=(int position) {
    if (position < 0 || position > nElements) {
        std::cerr << "Error: index is not right! " <<
            std::endl;
        return *this;
    }
    nElements = nElements - 1;
    for (int i = position; i < nElements; ++i) {
        array[i] = array[i + 1];
    }
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator-(const T& key) {
    for (int i = 0; i < nElements; ++i)
    {
            if (key == array[i]) {
                nElements = nElements - 1;
                for (int j = i; j < nElements; ++j) {
                    array[j] = array[j + 1];
                }
                return *this;
            }
            
    }
    std::cerr << "Nothing was found!" << std::endl;
    return *this;
}

template <typename T>
void Array<T>::SortArray() {

    int Lt = 0;
    int R = 0;
    int L = nElements - 1;
    int Rt = nElements - 1;
    T b, c;
    while ((R != Rt) && (L != Lt)) {
        R = Rt;
        for (int i = Lt; i < R; i++) {
            if (array[i] > array[i + 1]) {
                b = array[i];
                array[i] = array[i + 1];
                array[i + 1] = b;
                Rt = i;
            }
        }
        if (R != Rt) {
            L = Lt;
            for (int i = Rt; i > L; i--)
                if (array[i] < array[i - 1]) {
                    c = array[i];
                    array[i] = array[i - 1];
                    array[i - 1] = c;
                    Lt = i;
                }
        }
    }
}
template <typename T>  
bool Array<T>::DeleteElem(const T& key) {

    for (int i = 0; i < nElements; ++i)
        if (key == array[i])
        {
            nElements = nElements - 1;
            for (int j = i; j < nElements; ++j)
                array[j] = array[j+1];
            return true;
        }

    return false;
}


template <typename T>
int Array<T>::FindElem(const T& key) const {
      for (int i = 0; i < nElements; ++i)
        if (key == array[i])
            return i;
    return -1;
}

template <typename T>
Array<T>& Array<T>::operator+=(const Array& tempArray)
{   
   Array ted = *this;
   memory = ted.memory + tempArray.memory;
   nElements = ted.nElements + tempArray.nElements;
   delete [] array;
   array = new T [memory];
   for (int i = 0; i < ted.nElements; ++i)
       array[i] = ted.array[i];
   for (int i = ted.nElements, j = 0; i < nElements; ++j, ++i)
      array[i] = tempArray.array[j];
   return *this; 
}

template <typename T>
Array<T> Array<T>::operator+(const Array<T>& tempArray) const
{
    Array ted(memory+tempArray.memory,nElements+tempArray.nElements);
    for (int i = 0; i < nElements; ++i)
        ted.array[i] = array[i];
    for (int i = nElements, j = 0; i < ted.nElements; ++j, ++i)
        ted.array[i] = tempArray.array[j];
    return ted;
}

template<typename T>
Array<T>::Array(const Array<T>& tempArray)
{
	memory = tempArray.memory;
    nElements = tempArray.nElements;
    array = new T [memory];
    for (int i = 0; i < nElements; ++i) {
        array[i] = tempArray.array[i];
    }
}
template <typename T>
void Array<T>::ShiftArray(int position, int count, int direction) {
    if (direction) {
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < position; ++j)
            {
                array[j] = array[j + 1];
            
            }
            array[position--] = 0;
        }
    } else {        
        for (int i = 0; i < count; ++i) {
            for (int j = nElements - 1; j > position; --j){
                array[j] = array[j - 1];
              
            }
           array[position++] = 0;
        }
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& tempArray)
{
    if (this != &tempArray) {
        delete[] array;
        memory = tempArray.memory;
        nElements = tempArray.nElements;
        array = new T[memory];
        for (int i = 0; i < nElements; ++i)
            array[i] = tempArray.array[i];
    }
    return *this;
}

template<typename T>
void Array<T>::FillArray()
{
	for(int i = 0; i < nElements; ++i)
		std::cin >> array[i];
}

