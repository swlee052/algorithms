#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class QSComparisonCount{
  private:
    int* arr;
    int arrSize;
    pickPivotMode pivotMode;
    int compCount;
    int getPivotIndex(int start, int inputArrSize);
    int getMedianOfThree(int a, int b, int c);
    void countComparisons(int start, int inputArrSize);
    void swap(int a, int b);
    void putLeftOfPivot(int a);
    void putRightOfPivot(int a);
  public:
    QSComparisonCount(string fileName, pickPivotMode mode);
    int getArraySize();
    int getComparisonCount();
    int* getArray();
};

enum pickPivotMode {
  firstElement,
  lastElement,
  medianOfThree,
};

int main (){
  QSComparisonCount QSCC("quicksort-input.txt", firstElement);
  cout << "# comparisons during quicksort : " 
             << QSCC.getComparisonCount() << endl;
  return 0;
}

QSComparisonCount::QSComparisonCount(string fileName, pickPivotMode mode) {
  int i = 0;
  fstream inputFile;
  
  //initialize arrSize and pivotMode
  arrSize = 0;
  pivotMode = mode;
  inputFile.open(fileName);
  while (inputFile >> i) {
    arrSize++;
  }
  inputFile.close();

  //initialize array
  arr = new int[arrSize];
  i = 0;
  inputFile.open(fileName);
  while (inputFile >> arr[i]) {
    i++;
  }
  inputFile.close();

  //count comparisons
  countComparisons(0, arrSize);
}

void QSComparisonCount::countComparisons(int start, int inputArrSize) {
  int pivIx = getPivotIndex(start, inputArrSize);
  int lMaxIx = 0; // rightmost among those left of pivot (already compared)
  int rMaxIx = 0; // rightmost among those right of pivot (already compared)

  //base case
  if (inputArrSize <= 1){
    return;
  }

  for (int i=start; i<start+inputArrSize; i++){
    if (i == pivIx){
      continue;
    }
    else if (arr[i] <= arr[pivIx]){
      lMaxIx++;
      swap(lMaxIx, i);
    }
    else{
      rMaxIx++;
      swap(rMaxIx, i);
    }
  }
}

int QSComparisonCount::getPivotIndex(int start, int inputArrSize){
  switch(pivotMode){
    case firstElement:
      return start;
    case lastElement:
      return start + inputArrSize-1;
    case medianOfThree:
      if (inputArrSize%2 == 1){
        return getMedianOfThree(start, (start + inputArrSize-1)/2, 
                                                      inputArrSize-1);
      }
      else {
        return getMedianOfThree(start, (start + inputArrSize)/2 - 1, 
                                                      inputArrSize-1);
      }  
    default:
      cout << "Not a valid mode" << endl;
      exit(0);
  }
};

int QSComparisonCount::getMedianOfThree(int a, int b, int c){
  if (arr[a]<=arr[b] && arr[b]<=arr[c]) {
    return b;
  }
  else if (arr[b]<=arr[a] && arr[a]<=arr[c]){
    return c;
  }
  else
    return a;
}

int* QSComparisonCount::getArray(){
  return arr;
}

int QSComparisonCount::getArraySize(){
  return arrSize;
}

int QSComparisonCount::getComparisonCount(){
  return compCount;
}

void QSComparisonCount::swap(int a, int b){
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
} 
