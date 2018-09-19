#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* * * * * * * * * * * * *
   Raymond Wu
   Systems pd10
   HW02 -- Hot Swapping
   2018-09-18
   * * * * * * * * * * * */

int main() {

  //>> Create an array large enough to store 10 ints

  int myIntsV1[10];

  
  //>> Populate the array with random values

  int * arrV1Pointer = (int *) &myIntsV1; // creates a copy of pointer to elem 0 of myIntsV1 array
  int i;

  srand( time(NULL) );      // Seeds the random number generator :: return the current EPOCH time
                            // Only need to SEED ONCE!
  
  for ( i=0 ; i<sizeof(myIntsV1)/sizeof(int) ; i++ ) {
    *arrV1Pointer = rand(); // Returns the next random number in the sequence seeded by srand()

    arrV1Pointer++;
  }

  
  //>> Set the last value in the array to 0

  arrV1Pointer--;           // back up! arrV1Pointer pointing to memory after last elem...
  *arrV1Pointer = 0;

  
  //>> Print out the values in this array

  printf("Henceforth are the values in array 0... \n");

  arrV1Pointer = (int *) &myIntsV1;  // reset arrV1Pointer to elem 0 of array
  for ( i=0 ; i<sizeof(myIntsV1)/sizeof(int) ; i++ ) {
    printf("\t %d \n", *arrV1Pointer);
    arrV1Pointer++;
  }


  //>> Create a separate array large enough to store 10 ints

  int myIntsV2[10];

  
  //>> USING ONLY POINTERS -- Populate the second array with the values in the first but in reverse order

  int * arrV2Pointer = (int *) &myIntsV2;          // creates a copy of pointer to elem 0 of myIntsV2 array
  arrV2Pointer += sizeof(myIntsV2)/sizeof(int)-1;  // pointer now points to last elem of array

  arrV1Pointer = (int *) &myIntsV1;                // reset arrV1Pointer to elem 0 of array
  
  for ( i=0 ; i<sizeof(myIntsV2)/sizeof(int) ; i++ ) {
    *arrV2Pointer = *arrV1Pointer;
    arrV2Pointer--; // increment backward thru myIntsV2 array
    arrV1Pointer++; // increment forward  thru myIntsV1 array
  }
  

  //>> Print out the values in the second array

  printf("Henceforth are the values in array 1... \n");

  arrV2Pointer = (int *) &myIntsV2;  // reset arrV2Pointer to elem 0 of array
  for ( i=0 ; i<sizeof(myIntsV2)/sizeof(int) ; i++ ) {
    printf("\t %d \n", *arrV2Pointer);
    arrV2Pointer++;
  }

  
  return 0;
}
