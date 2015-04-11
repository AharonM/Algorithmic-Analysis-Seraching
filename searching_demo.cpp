#include <iostream>

#include "array.h"
#include "array.cpp"
#include "integer.h"
#include "timer.h"

bool linearSearch(Array<Integer> ,int ,Integer ); 
bool binarySearch(Array<Integer> ,Integer ,Integer ,Integer );

using namespace std;

int main() {
	Array<Integer> arr;
	Integer val;
	Timer t;
	int i=0,numComp = 0;
	ifstream infile("data.input");
	while(!infile.eof()){
	infile >> val;
	arr += val;}
	infile.close();
	infile.clear();
	int size = arr.getSize();
	infile.open("data.input");
	t.start();
	while(!infile.eof()){
	infile >> val;
	linearSearch(arr,size,val);	
	i++;
	}
	t.end();

	numComp = Integer::getNumComparisons();
	cout << "Average Number of Comparisons for LinearSearch: " << numComp/i <<endl;
	cout << "Total time of LinearSearch: " << t << endl << endl;
	
	Integer::resetNumComparisons();
	numComp = 0;
	i = 0;
	infile.close();
	infile.clear();
	infile.open("data.input");
	t.start();
	while(!infile.eof()){
	infile >> val;
	binarySearch(arr,arr[0],arr[size-1],val);
	i++;
	}
	t.end();
	infile.close();
	numComp = Integer::getNumComparisons();
	cout << "Average Number of Comparisons for BinarySearch: " << numComp/i <<endl;
	cout << "Total time of BinarySearch: " << t << endl;

	return 0;
}


bool linearSearch(Array<Integer> arr, int n, Integer val) {
   for (int i = 0; i < n; i++)
      if (arr[i] == val) return true;
   return false;	
}


bool binarySearch(Array<Integer> arr, Integer lo, Integer hi, Integer val) {
	if (lo > hi) return false;
	int mid = (lo.getVal() + hi.getVal() ) / 2;
	if (arr[mid] == val) 	
		return true;
	else if (arr[mid] < val)
		return binarySearch(arr, mid+1, hi, val);
	else 
		return binarySearch(arr, lo, mid-1, val);
}
