// Stewart Kerns
// File: HW5.cpp
// Date: 05/06/2023
// Version: 1.0
// Last Update: 05/10/2023
// Purpose: This program has methods to do a heap sort using the algorithm
// found at the following location. In addition to those methods, it also
// contains tests of different arrays to demonstrate how the sorting is working
//
//https://en.wikipedia.org/wiki/Heapsort

#include <iostream>

using std::cout;
using std::endl;

// This method is the method that does the heap sort process according to the
// algorithm listed
// PRE-CONDITION: array exists to sort
// PROCESS: Sort the array in place in ascending order
// POST-CONDITION: Order of the array is permanently changed
void heapSort(int *, int);

// This method does the heapify process according to the algorithm listed
// PRE-CONDITION: Array exist to transfer into a heap order
// PROCESS: move the array in place
// POST-CONDITION: Order of the array is permanently changed
void heapify(int *, int);

// This method sifts an element down in the heap and is used in both heapify
// and heapSort
// PRE-CONDITION: array exists to sort elements down, start and end positions
// are given
// PROCESS: sift the position given down
// POST-CONDITION: array order is permanently changed
void siftDown(int *, int, int);

// This method finds the element number for the parent of a given element
// PRE-CONDITION: none
// PROCESS: determine the element of the parent
// POST-CONDITION: none, element of the parent returned
int parent(int);

// This method finds the element number for the left child of a given element
// PRE-CONDITION: none
// PROCESS: determine the element of the left child
// POST-CONDITION: none, element of the left child returned
int leftChild(int);

// This method finds the element number for the right child of a given element
// PRE-CONDITION: none
// PROCESS: determine the element of the right child
// POST-CONDITION: none, element of the right child returned
int rightChild(int);

// This method prints all the elements of an array given the array and the
// size of the array
// PRE-CONDITION: array exists
// PROCESS: print each element to the standard output
// POST-CONDITION: nothing changed, printed statements output
void printArray(int *, int);

// This method tests out heap sort on a given array of a given length
// PRE-CONDITION: array exists
// PROCESS: heapsorts the array, prints statements showing the heapsort
// properly working
// POST-CONDITION: array is permanently changed, printed statements to the
// standard output
void testHeapSort(int *, int);

int main() {

    //create const ints and arrays to test out various edge cases
    const int TEST1 = 0, TEST2 = 1, TEST3 = 2, TEST4 = 5, TEST5 = 6, TEST6 = 10;
    const int TEST7 = 5, TEST8 = 6, TEST9 = 6, TEST10 = 6;
    int * testArray1 = new int[TEST1] {};
    int * testArray2 = new int[TEST2] {1};
    int * testArray3 = new int[TEST3] {5, 1};
    int * testArray4 = new int[TEST4] {1, 2, 3, 4, 5};
    int * testArray5 = new int[TEST5] {6, 5, 4, 3, 2, 1};
    int * testArray6 = new int[TEST6] {25, 0, 12, -5, 17, 3, 2, 99, -25, 18};
    int * testArray7 = new int[TEST7] {0, 3, 5, 4, 5};
    int * testArray8 = new int[TEST8] {0, 3, 5, 4, 5, 5};
    int * testArray9 = new int[TEST9] {};
    int * testArray10 = new int[TEST10] {};


    cout << "\nThis test will test an empty array." << endl;
    testHeapSort(testArray1, TEST1);

    cout << "\nThis test will test an array with a single element." << endl;
    testHeapSort(testArray2, TEST2);

    cout << "\nThis test will test an array with only two elements." << endl;
    testHeapSort(testArray3, TEST3);

    cout << "\nThis test will test an array with an odd number of elements "
            "and already in order." << endl;
    testHeapSort(testArray4, TEST4);

    cout << "\nThis test will test an array with an even number of elements "
            "and in reverse order." << endl;
    testHeapSort(testArray5, TEST5);

    cout << "\nThis test will test an array that's a bit larger an also "
            "contains negative numbers." << endl;
    testHeapSort(testArray6, TEST6);

    cout << "\nThis test will test an array with two duplicates" << endl;
    testHeapSort(testArray7, TEST7);

    cout << "\nThis test will test an array with three duplicates" << endl;
    testHeapSort(testArray8, TEST8);
//    testHeapSort(testArray6, TEST9);
//    testHeapSort(testArray6, TEST10);

    delete [] testArray1;
    delete [] testArray2;
    delete [] testArray3;
    delete [] testArray4;
    delete [] testArray5;
    delete [] testArray6;
    delete [] testArray7;
    delete [] testArray8;
    delete [] testArray9;
    delete [] testArray10;

    return 0;

}
void testHeapSort(int * array, int length){

    //print statements to the standard output to show the heapsort working
    cout << "Testing array of " << length << " numbers." << endl;
    printArray(array, length);
    cout << "Sorting array." << endl;
    heapSort(array, length);
    printArray(array, length);
}

void printArray(int * array, int length){

    //print each element formatted in the array
    cout << "The array is: [";
    for (int i = 0; i < length; i++){
        if(i < length - 1){
            cout << array[i] << ",";
        }
        else{
            cout << array[i];
        }
    }
    cout << "]" << endl;
}

void heapSort(int * array, int length){
    //put the array into heap order
    heapify(array, length);

    //sort the array with the algorithm pulled from wiki
    int end = length - 1;
    while (end > 0){
        std::swap(array[end], array[0]);
        end--;

        siftDown(array, 0, end);
    }
}

void heapify(int * array, int length){

    //heapify the array using the algorithm from wiki
    int start = parent(length - 1);

    while (start >= 0 ){
        siftDown(array, start, length - 1);
        start--;
    }
}

void siftDown(int * array, int start, int end){

    //use the algorithm from wiki to sift elements down
    int root = start;
    int child;
    int swap;
    bool flag = false;
    while (leftChild(root) <= end && !flag){
        child = leftChild(root);
        swap = root;

        if (array[swap] < array[child]){
            swap = child;
        }
        if (child + 1 <= end && array[swap] < array[child + 1]){
            swap = child + 1;
        }
        if (swap == root){
            flag = true;
        }
        else{
            std::swap(array[root], array[swap]);
            root = swap;
        }
    }
}


int parent(int i){

    //return the parent of the given element
    return ((i - 1) / 2);
}
int leftChild(int i){

    //return the left child of the given element
return (2 * i) + 1;
}
int rightChild(int i){

    //return the right child of the given element
    return (2 * i) + 2;
}
