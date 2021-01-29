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
    long int invCount;
    string inputFileName;
    int* countInversion(int* inputArr, int arrSize);
    int getInputFileSize();

  public:
    Inversion(string fileName);
    long int getInversionCount();
    int* getArray();
    int getArraySize();
    ~Inversion();
};

int main (){
  Inversion Inv("assignment-2-IntegerArray.txt");
  //Inversion Inv("test.txt");
  cout << "#inversions: " << Inv.getInversionCount() << endl;
  return 0;
}

Inversion::Inversion(string fileName){
  ifstream inputFile;
  int i = 0;

  //initialize arrSize, invCount
  inputFileName = fileName;
  invCount = 0;
  arrSize = getInputFileSize();

  //initialize arr
  inputFile.open(inputFileName);
  arr = new int[arrSize];
  while (inputFile >> arr[i]) {
    i++;
  }
  inputFile.close();

  //count inversions
  int* tmpArr = new int[arrSize];
  tmpArr = countInversion(arr, arrSize);
  delete tmpArr;
}

long int Inversion::getInversionCount(){
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
  int leftIndex = 0;
  int rightIndex = 0;
  int leftSize = 0;
  int rightSize = 0;
  
  //mergesort base case
  if(size == 1) {
    return inputArr;
  }

  else if (size%2 == 1) {
    leftSize = (size+1)/2;
    rightSize = (size-1)/2;
  }

  else {
    leftSize = size/2;
    rightSize = size/2;
  }

  leftHalf = new int[leftSize];
  rightHalf = new int[rightSize];
  sortedArr = new int[size];

  //split original array into halves
  for (int i=0; i<leftSize; i++){
    leftHalf[i] = inputArr[i];
  }
  for (int i=leftSize; i<leftSize+rightSize; i++){
    rightHalf[i-leftSize] = inputArr[i];
  }

  //sort the left and right half arrays
  leftHalf = countInversion(leftHalf, leftSize);
  rightHalf = countInversion(rightHalf, rightSize);

  //merge the left and right half arrays and count inversions
  leftIndex = 0;
  rightIndex = 0;
  for(int i=0; i<size; i++){
    if (leftIndex == leftSize){ // left array all used
      sortedArr[i] = rightHalf[rightIndex];
      rightIndex++;
    }
    else if (rightIndex == rightSize){ // right array all used
      sortedArr[i] = leftHalf[leftIndex];
      leftIndex++;
    }
    else if(leftHalf[leftIndex] <= rightHalf[rightIndex]) {
      sortedArr[i] = leftHalf[leftIndex];
      leftIndex++;
    }
    else { //inversion observed! (rightHalf[rIx] < leftHalf[lIx])
      sortedArr[i] = rightHalf[rightIndex];
      rightIndex++;
      invCount += (leftSize - leftIndex);
      if (invCount < 0){
        cout << invCount << endl;
      }
      //cout << invCount << endl;
    }
  }
  delete leftHalf;
  delete rightHalf;
  return sortedArr;
}
