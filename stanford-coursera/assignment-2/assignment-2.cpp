/*
This file contains all of the 100,000 integers between 1 and 100,000 
(inclusive) in some order, with no integer repeated. Your task is to compute 
the number of inversions in the file given, where the i-th row of the file 
indicates the i-th entry of an array. Because of the large size of this 
array, you should implement the fast divide-and-conquer algorithm covered in 
the video lectures. The numeric answer for the given input file should be 
typed in the space below. So if your answer is 1198233847, then just type 
1198233847 in the space provided without any space / commas / any other 
punctuation marks. You can make up to 5 attempts, and we'll use the best one 
for grading.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Inversion {
  private:
    int arrSize;
    int* arr;
    int invCount;
    string inputFileName;

  public:
    Inversion(string fileName);
    int getInversionCount();
    int* countInversion(int* inputArr, int arrSize);
    int* getArray();
    int getArraySize();
    int getInputFileSize();
    ~Inversion();
};

int main (){
  cout << "Program start" << endl;
  Inversion Inv("assignment-2-IntegerArray.txt");
  cout << "Input read successful" << endl;
  cout << Inv.getInversionCount() << endl;
  return 0;
}

Inversion::Inversion(string fileName){
  ifstream inputFile;
  int i = 0;

  //get size and dynamically allocate memory for the array
  inputFileName = fileName;
  invCount = 0;
  arrSize = getInputFileSize();
  cout << "size of input: " << arrSize << endl;


  //open and save input from the text file
  inputFile.open(inputFileName);
  arr = new int[arrSize];
  while (inputFile >> arr[i]) {
    i++;
  }
  inputFile.close();
}

int Inversion::getInversionCount(){
  int* tmpArr = new int[arrSize];
  tmpArr = countInversion(arr, arrSize);
  delete tmpArr;
  return invCount;
}

int* Inversion::getArray(){
  return arr;
}

int Inversion::getArraySize(){
  return arrSize;
}

int Inversion::getInputFileSize(){
  ifstream inputFile;
  int a = 0;
  int size = 0;

  inputFile.open(inputFileName);
  cout << "Successfully opened input file" << endl;
  while (inputFile >> a)
  {
    size++;
  }
  inputFile.close();
  return size;
}

Inversion::~Inversion(){
  delete arr;
}

int* Inversion::countInversion(int* inputArr, int size){
  int* leftHalf;
  int* rightHalf;
  int* sortedArr;
  int leftPtr = 0;
  int rightPtr = 0;
  int lastElement; //only used for odd size input array
  bool lastElementUsed = false;
  
  //mergesort base case
  if(size == 1) {
    return inputArr;
  }

  if(size%2 == 1) {
    leftHalf = new int[(size-1)/2];
    rightHalf = new int[(size-1)/2];
    sortedArr = new int[size];
    lastElement = inputArr[size-1];

    //split original array into halves
    for (int i=0; i<(size-1)/2; i++){
      leftHalf[i] = inputArr[i];
    }
    for (int i=(size-1)/2; i<size-1; i++){
      rightHalf[i - (size-1)/2] = inputArr[i];
    }

    //sort the left and right half arrays
    leftHalf = countInversion(leftHalf, (size-1)/2);
    rightHalf = countInversion(rightHalf, (size-1)/2);

    //merge the left and right half arrays and count inversions
    leftPtr = 0;
    rightPtr = 0;
    for(int i=0; i<size; i++){
      if(!lastElementUsed){
        // lastElement used in last
        if(leftPtr == (size-1)/2 && rightPtr == (size-1)/2) {
          sortedArr[i] = lastElement;
          lastElementUsed = true;
        }
        // lastElement used in middle
        else if(lastElement <= leftHalf[leftPtr] 
                  && lastElement <= rightHalf[rightPtr]) {
          sortedArr[i] = lastElement;
          lastElementUsed = true;
        }
      }
      else {
        if(leftHalf[leftPtr] <= rightHalf[rightPtr]) {
          sortedArr[i] = leftHalf[leftPtr];
          leftPtr++;
        }
        else { //inversion observed! (rightHalf[rPtr] < leftHalf[lPtr])
          sortedArr[i] = rightHalf[rightPtr];
          rightPtr++;
          invCount += ((size-1)/2 - leftPtr);
        }
      }
    }

  }

  else {
    leftHalf = new int[size/2];
    rightHalf = new int[size/2];
    sortedArr = new int[size];

    //split original array into halves
    for (int i=0; i<size/2; i++){
      leftHalf[i] = inputArr[i];
    }
    for (int i=size/2; i<size; i++){
      rightHalf[i-size/2] = inputArr[i];
    }

    //sort the left and right half arrays
    leftHalf = countInversion(leftHalf, size/2);
    rightHalf = countInversion(rightHalf, size/2);

    //merge the left and right half arrays and count inversions
    leftPtr = 0;
    rightPtr = 0;
    for(int i=0; i<size; i++){
      if(leftHalf[leftPtr] <= rightHalf[rightPtr]) {
        sortedArr[i] = leftHalf[leftPtr];
        leftPtr++;
      }
      else { //inversion observed! (rightHalf[rPtr] < leftHalf[lPtr])
        sortedArr[i] = rightHalf[rightPtr];
        rightPtr++;
        invCount += ((size-1)/2 - leftPtr);
      }
    }
  }

  delete leftHalf;
  delete rightHalf;
  return sortedArr;
}
