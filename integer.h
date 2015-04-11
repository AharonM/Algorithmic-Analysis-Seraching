#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>
#include <fstream>

class Integer {
	friend std::ostream &operator <<(std::ostream &os, const Integer &integer);
	friend std::istream &operator >>(std::istream &in,Integer &integer);
	friend Integer operator +(const Integer &i1, const Integer &i2);
	friend Integer operator -(const Integer &i1,const Integer &i2);
	friend Integer operator *(const Integer &i1,const Integer &i2);
	friend Integer operator /(const Integer &i1,const Integer &i2);
	friend Integer operator %(const Integer &i1,const Integer &i2);
	friend bool operator ==(const Integer &i1,const Integer &i2);
	friend bool operator !=(const Integer &i1,const Integer &i2);
	friend bool operator <(const Integer &i1,const Integer &i2);
	friend bool operator >(const Integer &i1,const Integer &i2);

public:
	Integer(int val=0) : val(val){}
	Integer &operator ++();
	Integer operator ++(int);
	Integer &operator --();
	Integer operator --(int);
	Integer &operator +=(const Integer &other);
	Integer &operator -=(const Integer &other);
	Integer &operator *=(const Integer &other);
	Integer &operator /=(const Integer &other);
	Integer &operator %=(const Integer &other);
	static int getNumComparisons(){	return numComparisons;}
	static void resetNumComparisons(){numComparisons = 0;}
	int getVal() const{return val;}
	void setVal(int v) {val = v;}
private:
	int val;
	static int numComparisons;
};

#endif
