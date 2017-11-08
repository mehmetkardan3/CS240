#include <iostream>
#include <ctime>
#include <cstdlib>
#include<time.h>
#include <vector>
using namespace std;

void selectionSort(vector<int> &vec);
void insertionSort(vector<int> &vec);
void quickSort(vector<int> &vec, int i, int k);
int Partition(vector<int> &vec, int i, int k);
void print(vector<int> vec);
void fillVector(vector<int> &vec, int size);

int main(){
	vector<int> vector1;
	vector<int> vector2;
	vector<int> vector3;
	clock_t t;
	
	fillVector(vector1,10000);
	
	vector2=vector1;
	vector3=vector1;
	
	print(vector1);
	t=clock();
	selectionSort(vector1);
	t=clock()-t;
	print(vector1);
	cout << "Execution time for selection sort: " << ((float)t/CLOCKS_PER_SEC) << endl;
	
	print(vector2);
	t=clock();
	insertionSort(vector2);
	t=clock()-t;
	print(vector2);
	cout << "Execution time for insertion sort: " << ((double)t/CLOCKS_PER_SEC) << endl;
	
	print(vector3);
	t=clock();
	quickSort(vector3,0,vector3.size()-1);
	t=clock()-t;
	print(vector3);
	cout << "Execution time for quicksort: " << ((double)t/CLOCKS_PER_SEC) << endl;
	
	
}

void fillVector(vector<int> &vec, int size){
	int i;
	srand (time(NULL));
	for(i=0 ; i < size ; i++){
		vec.push_back((rand()%900000)+100000);
	}
}

void selectionSort(vector<int> &vec){
	int i;
	int j;
	int temp;
	int smallest;
	for (i = 0; i < vec.size(); ++i) {
   		smallest = i;
   		for (j = i + 1; j < vec.size(); ++j) {
      
     	 	if (vec[j] < vec[smallest]) {
        		smallest = j;
      		}
   		}
   		temp = vec[i];
   		vec[i] = vec[smallest];
   		vec[smallest] = temp;
	}
}

void insertionSort(vector<int> &vec){
	int i = 0;
   	int j = 0;
   	int temp = 0;
   
   	for (i = 1; i < vec.size(); ++i) {
      j = i;
    	while (j > 0 && vec[j] < vec[j - 1]) {
        	temp = vec[j];
         	vec[j] = vec[j - 1];
         	vec[j - 1] = temp;
        	--j;
      	}
   	}
   
}


void quickSort(vector<int> &vec, int i, int k){
	int j = 0;
	
   	if (i >= k) {
      	return;
   	}

   	j = Partition(vec, i, k);
   
   	quickSort(vec, i, j);
   	quickSort(vec, j + 1, k);
   
   	return;
}


int Partition(vector<int> &vec, int i, int k) {
   int l = 0;
   int h = 0;
   int midpoint = 0;
   int pivot = 0;
   int temp = 0;
   bool done = false;
   
   midpoint = i + (k - i) / 2;
   pivot = vec[midpoint];
   
   l = i;
   h = k;
   
   while (!done) {
	    while (vec[l] < pivot) {
         	++l;
      	}
      
      	while (pivot < vec[h]) {
         	--h;
      	}
      
      	if (l >= h) {
         	done = true;
      	}
      
      	else {
        	temp = vec[l];
        	vec[l] = vec[h];
        	vec[h] = temp;
        	++l;         
			--h;
      	}
   	}   
   	return h;
}


void print(vector<int> vec){
	int i;
	cout << "Vector is: < ";
	for(i=0 ; i < vec.size() ; i++){
		cout << vec.at(i) << " ";
	}
	cout << ">" << endl;
}
