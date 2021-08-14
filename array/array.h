#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
template <typename T> 
class Array
{
private:
	T* array;
	int memory, nElements;
public:
	~Array() {
          delete[] array;
    }

    Array(const Array<T>&);
    explicit Array(int m_ = 1, int n_ = 0);
    
    Array<T>& operator+=(const Array<T>& tempArray);
    Array<T>& operator+=(const T& temp);
    
    Array<T>&operator-(const T& key);
    Array<T>&operator-=(int position);

    Array<T> operator+(const Array<T>& tempArray) const;
    Array<T> operator+(const T& key) const;
    Array<T>& operator=(const Array<T>& tempArray);
    
    bool operator==(const Array <T>& tempArray) const;
    bool operator!=(const Array <T>& tempArray) const;
        
    int FindElem(const T& key) const;
    bool DeleteElem(const T& key);
    void SortArray();
    void FillArray();

    bool DeleteIndex(int position);
    bool InsertIndex(int position, const T& key);
    void ShiftArray(int position, int count, int direction = 0);
  
    T operator[](int position) const;
    T& operator[](int position);
    T FindMax() const;
    T FindMin() const; 

    template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const Array<U>& t);
    template <typename U>
        friend std::istream& operator>>(std::istream& is, Array<U>& t);
};
#endif
