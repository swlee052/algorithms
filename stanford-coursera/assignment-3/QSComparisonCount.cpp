#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum pickPivotMode {
  firstElement,
  lastElement,
  medianOfThree,
};

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

  public:
    QSComparisonCount(string fileName, pickPivotMode mode);
    int getArraySize();
    int getComparisonCount();
    int* getArray();
};

int main (){
  QSComparisonCount QSCC("quicksort-input.txt", medianOfThree);
  //QSComparisonCount QSCC("test.txt", medianOfThree);
  cout << "# comparisons during quicksort : " 
             << QSCC.getComparisonCount() << endl;
  return 0;
}

QSComparisonCount::QSComparisonCount(string fileName, pickPivotMode mode) {
  int i = 0;
  fstream inputFile;
  
  //initialize arrSize, compCount and pivotMode
  arrSize = 0;
  compCount = 0;
  pivotMode = mode;
  inputFile.open(fileName);
  while (inputFile >> i) {
    arrSize++;
  }
  inputFile.close();

  //initialize arr
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
  // base case
  if (inputArrSize <= 1){
    return;
  }

  int pivIx = getPivotIndex(start, inputArrSize);
  int pivot = arr[pivIx];
 
  // put pivot at front and set rFirstIx
  swap(pivIx, start); 
  int rFirstIx = start + 1; //index of the first element in right partition

  // partition around the pivot
  for (int i=start+1; i<start+inputArrSize; i++){
    //cout << i << ", " << arr[i] << endl;
    if (arr[i] <= pivot){
      swap(rFirstIx, i);
      rFirstIx++;
    }
  }

  // place pivot at its right index
  swap(start, rFirstIx-1);

  // update comparison count
  compCount += inputArrSize-1;

  // recurse
  countComparisons(start, rFirstIx-start-1); // left partition
  countComparisons(rFirstIx, inputArrSize-rFirstIx+start); // right partition
}

int QSComparisonCount::getPivotIndex(int start, int inputArrSize){
  switch(pivotMode){
    case firstElement:
      return start;
    case lastElement:
      return start + inputArrSize-1;
    case medianOfThree:
      if (inputArrSize%2 == 1){
        return getMedianOfThree(start, start+(inputArrSize-1)/2, 
                                                start+inputArrSize-1);
      }
      else {
        return getMedianOfThree(start, start+inputArrSize/2 - 1, 
                                                start+inputArrSize-1);
      }  
    default:
      cout << "Not a valid mode" << endl;
      exit(0);
  }
};

int QSComparisonCount::getMedianOfThree(int a, int b, int c){
  if ((arr[a]<=arr[b] && arr[b]<=arr[c])
      || (arr[c]<=arr[b] && arr[b]<=arr[a])) {
    return b;
  }
  else if ((arr[b]<=arr[a] && arr[a]<=arr[c])
           || (arr[c]<=arr[a] && arr[a]<=arr[b])){
    return a;
  }
  else{
    return c;
  }
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
