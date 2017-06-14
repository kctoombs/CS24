// ranges2.cpp - version 2 of preRanges function
// Kenneth Toombs, Aaron Chang. 11/3/14

#include <iostream>
#include <cstdlib> // to parse command line argument
using namespace std;

// preRanges - fills result array with pre-ranges of array x;
// pre-conditions: n is greater than 0;
//                 sizes of both x and result are at least n
// post-condition: result[i] is the range of the values from x[0]
//                 through x[i], inclusive, for i=0 to n-1
void preRanges(float x[], int n, float result[]) {
  float max = x[0];
  float min = x[0];
  result[0] = 0;

  for(int i = 1; i < n; i++){
      if(x[i] > max)
	max = x[i];
      if(x[i] < min)
	min = x[i]; 
      result[i] = max - min;
    }    
}

// main tests the preRanges function - DO NOT CHANGE main
int main(int argc, char *argv[]) {
    // small test data set
    float a[] = {67.5, 22.1, 45.0, 8.2, 70.5, 50};
    int aSize = 6;
    float ranges[aSize];

    cout << "Results of small test:" << endl;
    preRanges(a, aSize, ranges);
    cout << "i" << "\t" << "a[i]" << "\t" << "ranges[i]" << endl;
    for (int i=0; i<aSize; i++)
        cout << i << "\t" << a[i] << "\t" << ranges[i] << endl;


    // larger test data set
    int big(20000);
    if (argc > 1)
        big = atoi(argv[1]); // atoi is from <cstdlib>
        
    float b[big], bResult[big]; // just process random garbage
    cout << endl << "Starting larger test: size = " << big << endl;
    preRanges(b, big, bResult);
    cout << "...Done: total big range = " << bResult[big-1] << endl;

    return 0;
}
