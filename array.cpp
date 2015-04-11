#include <iostream>

#include "array.h"
#include "array_exception.h"

using namespace std;

#define DEBUG true

template <typename T>
ostream &operator <<(ostream &os, const Array<T> &array) {
	os << "{";
	for (int i = 0; i < array.size; i++)
		os << array.arr[i] << (i < array.size-1 ? ", " : "");
	os << "}";
	return os;
}

template <typename T>
Array<T> &Array<T>::operator+=(const Array<T> &obj){
	int j = size;
	size += obj.size;
	checkCapacity();
	for (int i=0; i < size; i++)
    arr[j+i] = obj.arr[i];
	return *this;
}

template <typename T>
Array<T> operator+(const Array<T> &array, T val){
	Array<T> result;
	result.size = array.size;
	result.checkCapacity();
	for (int x = 0; x < result.size; x++) 
		result.arr[x] = array.arr[x];
	result.arr[result.size] = val;
	result.size++;
	return result;
}

template <typename T>
Array<T> operator+(const Array<T> &array1, const Array<T> &array2){
	Array<T> result = array1;
	return result += array2;
}

template <typename T>
Array<T>::Array(const Array<T> &other) : arr(new T[other.capacity]), capacity(other.capacity), size(other.size) {
	for (int i = 0; i < size; i++) 
		arr[i] = other.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs) {
	if (this == &rhs) return *this;
	delete [] arr;
	size = rhs.size;
	capacity = rhs.capacity;
	arr = new T[capacity]; 
	for (int i = 0; i < size; i++) 
		arr[i] = rhs.arr[i];
	return *this;
}

template <typename T>
T &Array<T>::operator [](int index) {
	if (index < 0 || index >= size) throw ArrayException("Index out of bounds");
	return arr[index];
}

template <typename T>
const T &Array<T>::operator [](int index) const {
	if (index < 0 || index >= size) throw ArrayException("Index out of bounds");
	return arr[index];
}

template <typename T>
Array<T> &Array<T>::operator +=(T val) {
	checkCapacity();
	arr[size] = val;
	size++;
	return *this;
}

template <typename T>
void Array<T>::checkCapacity() {
	if (size < capacity) return;

	capacity *= 2;
	T *newArr = new T[capacity];
	for (int i = 0; i < size; i++)
		newArr[i] = arr[i];
	delete [] arr;
	arr = newArr;
	if (DEBUG) cerr << "Increased array capacity to " << capacity << endl;
}

template <typename T>
bool Array<T>::isEmpty(){
	if (size == 0)
	return true;
	else
	return false;
}

template <typename T>
bool Array<T>::contains(T val) const{
	for (int i=0; i < size; i++){
		if(arr[i] == val)
			return true;}
	return false;
}

template <typename T>
int Array<T>::find(T val) const{
	for(int i=0; i < size; i++){
	if(arr[i] == val)
	return i;}
	return -1;
}
