#include <iostream>

#include "integer.h"

using namespace std;

int Integer::numComparisons = 0;

ostream &operator <<(ostream &os, const Integer &integer) {
	os << integer.val;
	return os;
}

istream &operator >>(istream &in,Integer &integer){
	int val;
	in >> val;
	integer.setVal(val);
	return in;
}


Integer operator +(const Integer &i1, const Integer &i2) {
	Integer result = i1;
	return result += i2;
}

Integer operator -(const Integer &i1,const Integer &i2){
	Integer result =i1;
	return result -=i2;
}

Integer operator *(const Integer &i1,const Integer &i2){
	Integer result =i1;
	return result *=i2;
}

Integer operator /(const Integer &i1,const Integer &i2){
	Integer result =i1;
	return result /=i2;
}


Integer operator %(const Integer &i1,const Integer &i2){
	Integer result =i1;
	return result %=i2;
}


bool operator ==(const Integer &i1,const Integer &i2){
	Integer::numComparisons++;
	return i1.val == i2.val;
}


bool operator !=(const Integer &i1,const Integer &i2){
	Integer::numComparisons++;
	return i1.val != i2.val;
}


bool operator <(const Integer &i1,const Integer &i2){
	Integer::numComparisons++;
	return i1.val < i2.val;
}


bool operator >(const Integer &i1,const Integer &i2){
	Integer::numComparisons++;
	return i1.val > i2.val;
}



Integer &Integer::operator ++() {
val++;
return *this;
}

Integer Integer::operator ++(int) {
Integer temp=*this;
val++;
return temp;
}

Integer &Integer::operator --() {
val--;
return *this;
}

Integer Integer::operator --(int) {
Integer temp=*this;
val--;
return temp;
}




Integer &Integer::operator +=(const Integer &other) {
	val += other.val;
	return *this;
}


Integer &Integer::operator -=(const Integer &other){
	val -= other.val;
	return *this;
}

Integer &Integer::operator *=(const Integer &other){
	val *= other.val;
	return *this;
}


Integer &Integer::operator /=(const Integer &other){
	val /= other.val;
	return *this;
}

Integer &Integer::operator %=(const Integer &other){
	val %= other.val;
	return *this;
}

