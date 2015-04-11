#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array;

template <typename T>
std::ostream &operator <<(std::ostream &os, const Array<T> &array);

template <typename T>
Array<T> operator+(const Array<T> &array, T val);

template <typename T>
Array<T> operator+(const Array<T> &array1, const Array<T> &array2);

template <typename T>
class Array {
	friend std::ostream &operator<< <>(std::ostream &os, const Array<T> &array);
	friend Array<T> operator+ <>(const Array<T> &array, T val);
    friend Array<T> operator+ <>(const Array<T> &array1, const Array<T> &array2);
    
public:
	Array(int capacity=100) : arr(new T[capacity]), capacity(capacity), size(0) {}
	Array(const Array<T> &other);
	~Array() {delete [] arr;}
	Array<T> & operator =(const Array<T> &rhs);
	T &operator [](int index);
	const T &operator [](int index) const;
	Array<T> &operator +=(T val);
	Array<T> &operator+=(const Array<T> &arr);
	int getSize() const {return size;}
	bool isEmpty();
    bool contains(T val) const;
    int find(T val) const;
    
private:
	void checkCapacity();
	T *arr;
	int capacity;
	int size;
};

#endif
