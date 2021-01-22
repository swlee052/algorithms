/*
Question 1
In this programming assignment you will implement one or more of the integer 
multiplication algorithms described in lecture. To get the most out of this 
assignment, your program should restrict itself to multiplying only pairs of 
single-digit numbers.  You can implement the grade-school algorithm if you 
want, but to get the most out of the assignment you'll want to implement 
recursive integer multiplication and/or Karatsuba's algorithm. So: what's the 
product of the following two 64-digit numbers?

3141592653589793238462643383279502884197169399375105820974944592
2718281828459045235360287471352662497757247093699959574966967627

[TIP: before submitting, first test the correctness of your program on some 
small test cases of your own devising. Then post your best test cases to the 
discussion forums to help your fellow students!]

[Food for thought: the number of digits in each input number is a power of 2. 
Does this make your life easier?  Does it depend on which algorithm you're 
implementing?]
*/

#include <iostream>
#include <string>

using namespace std;

class Multiplication {
  public:
  string karatsuba (string x, string y) {

    //preprocess signs
    string sign;
    sign = computeSign(x, y);
    x = eraseSign(x);
    y = eraseSign(y);

    // base case
    int x_size = getSize(x);
    int y_size = getSize(y);
    if (x_size==1 && y_size==1) { 
      return sign + strDigitMult(x, y);
    }
    
    // equalize sizes
    if (x_size < y_size) { 
      x = prependZero(x, y_size - x_size);
      x_size = y_size;
    }
    else if (x_size > y_size) {
      y = prependZero(y, x_size - y_size);
      y_size = x_size;
    }

    //compute splitting point "half" and number of zeros in z
    int half = x_size/2 + x_size%2;
    int num_zero = half;
    if (x_size % 2 == 1) {
      num_zero -= 1; 
    }
    string a = x.substr(0, half);         
    string b = x.substr(half, x_size);     
    string c = y.substr(0, half);            
    string d = y.substr(half, y_size);      
    string ac = karatsuba(a, c);
    string bd = karatsuba(b, d);
    string aPlusb = strAdd(a, b);                                  // a+b
    string cPlusd = strAdd(c, d);                                  // c+d
    string acPlusbd = strAdd(ac, bd);                              // ac+bd
    string bcPlusad = strSub(karatsuba(aPlusb, cPlusd), acPlusbd); // bc+ad
    string aczsq = appendZero(appendZero(ac, num_zero), num_zero); // acz^2
    string ret_val = strAdd(aczsq, appendZero(bcPlusad, num_zero)); 
    ret_val = strAdd(ret_val, bd); //acz^2+(bc+ad)z+bd
    ret_val = eraseFrontZero(ret_val);
    return sign + ret_val;
  }

  string gradeschool (string x, string y) { // not implemented
    return "0";
  }

  string strDigitMult(string x, string y){
    return to_string(stoi(x) * stoi(y));
  }

  string strDigitAdd(string x, string y){
    return to_string(stoi(x) + stoi(y));
  }

  string strDigitSub(string x, string y){
    return to_string(stoi(x) - stoi(y));
  }

  string strMult(string x, string y){ // not implemented
    return "0";
  }

  /* 
    Not worried of cases where the result is negative, cases like 
    strSub(1, -2), because such case will never occur within the karatsuba
    algorithm.
  */
  string strAdd(string x, string y){
    bool carry = false;
    int x_size = getSize(x);
    int y_size = getSize(y);
    string x_digit;
    string y_digit;
    string sum;
    string ret_val = "";

    if (x_size < y_size) { 
      x = prependZero(x, y_size - x_size);
      x_size = y_size;
    }
    else if (x_size > y_size) {
      y = prependZero(y, x_size - y_size);
      y_size = x_size;
    }

    for (int i=x_size-1; i>=0; i--){
      // get sum of two digits      
      x_digit = x.substr(i, 1);
      y_digit = y.substr(i, 1);
      sum = strDigitAdd(x_digit, y_digit);

      // add carry to the sum
      if (carry){ 
        sum = strDigitAdd(sum, "1");
        carry = false;
      }
      if (sum.length() > 1) {
        carry = true;
        ret_val = sum.substr(1, 1) + ret_val;
      }
      else {
        ret_val = sum.substr(0, 1) + ret_val;
      }
    }
    if (carry){ 
      ret_val = "1" + ret_val;
    }
    return ret_val;
  }

  /* 
    Not worried of cases where the result is negative, cases like 
    strSub(1, 2), because such case will never occur within the karatsuba
    algorithm.
  */
  string strSub(string x, string y){ // not implemented
    bool borrow = false;
    int x_size = getSize(x);
    int y_size = getSize(y);
    string x_digit;
    string y_digit;
    string sum;
    string ret_val = "";

    if (x_size < y_size) { 
      x = prependZero(x, y_size - x_size);
      x_size = y_size;
    }
    else if (x_size > y_size) {
      y = prependZero(y, x_size - y_size);
      y_size = x_size;
    }

    for (int i=x_size-1; i>=0; i--){
      // get subraction of two digits      
      x_digit = x.substr(i, 1);
      y_digit = y.substr(i, 1);
      sum = strDigitSub(x_digit, y_digit);

      // add carry to the sum
      if (borrow){ 
        sum = strDigitSub(sum, "1");
        borrow = false;
      }
      if(stoi(sum) < 0) {
        sum = strDigitAdd(sum, "10");
        borrow = true;
      }
      ret_val = sum + ret_val;
    }
    return ret_val;
  }

  string appendZero(string x, int num){
    string ret_val = x;
    for (int i=0; i<num; i++){
      ret_val += "0";
    }
    return ret_val;
  }

  string prependZero(string x, int num){
    string ret_val = x;
    for (int i=0; i<num; i++){
      ret_val = "0" + ret_val;
    }
    return ret_val;
  }

  string eraseFrontZero(string x) {
    while (x.substr(0,1) == "0"){
      x = x.substr(1);
    }
    return x;
  }

  int getSize (string x) {
    return x.length();
  }

  string computeSign(string x, string y) {
    if ((x.substr(0, 1) == "-") != (y.substr(0, 1) == "-")){
      return "-";
    }
    else {
      return "";
    }
  }

  string eraseSign(string x) {
    if (x.substr(0, 1) == "-") {
      int size = x.length();
      return x.substr(1, size-1);
    } 
    else{
      return x;
    }
  }
};

int main () {
  string a, b;
  Multiplication Mult;

  //take input
  cout << "type in the first number:" << endl;
  cin >> a;
  cout << "type in the second number:" << endl;
  cin >> b;

  //print
  cout << "karatsuba: " << Mult.karatsuba(a, b) << endl;
  cout << "grade school: " << Mult.gradeschool(a, b) << endl;

  return 0;
}