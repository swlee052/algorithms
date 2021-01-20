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
    int* inputArr;
    int cnt = 0;

  public:
    void getInput(string fileName, int arrSize);
    int countInversion();
};

int main (){
  int count;
  Inversion Inv;

  Inv.getInput("assignment-2-IntegerArray.txt");
  count = Inv.countInversion();
  cout << count << endl;
  return 0;
}

Inversion::getInput(string fileName){
  ifstream inputFile;
  int arrSize;
  inputFile.open(fileName);

  //get size and dynamically allocate memory for the array
  while (inputFile)
  {
    arrSize++;
  }
  this.arrSize = arrSize;
  inputArr = new int[arrSize];


  //open and save input from the text file
  if (inputFile.is_open()) {
    while (!inputFile.eof()) {
      inputFile >> inputArr[i];
      i++
    }
  }
  inputFile.close();
}


Inversion::countInversion(){

}