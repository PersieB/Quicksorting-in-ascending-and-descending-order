/*
 * Author: Percy George Brown
 * The program sorts an array into both ascending and descending order
 * Array is randomly generated, and must have size between 2 and 100.
 * Quicksort method is used to sort the array.
 * Created on 05 April 2020, 09:03
 */
#include <iostream>            //including necessary header files
#include <cstdlib>
#include <ctime>
#include <stdio.h>
using namespace std;

/*
*This method prints the elements in an array
*Elements printed are separated by spaces
*Takes array and size as parameters
*/

void output(int array[], int size){
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

/*
*This method uses quicksort process to sort the array in an ascending order
*Uses the middle element as pivot
*Sorts both left and right asides of the pivot till the full array is sorted
*Takes three parameters; lower index, highest index and array
*/

void ascend_quick_sort(int array[], int left_position, int right_position){
    int i = left_position;
    int j = right_position;
    int storage;         //temporary variable for swa[[ing without losing any data
    int middle_pivot = array[(left_position + right_position)/2];         //middle element as pivot
    while(i <= j){
        while(array[i] < middle_pivot)         //left side of pivot - smaller values
        i++;
        while(array[j] > middle_pivot)        //right side of pivot - bigger values
        j--;

        if(i <= j){                        //begins the swap
            storage = array[i];
            array[i] = array[j];
            array[j] = storage;
            i++;
            j--;
        }
    }
    if(left_position < j){                              //checks again to make sure everthing is sorted
        ascend_quick_sort(array, left_position, j);
    }
    if(i < right_position){
        ascend_quick_sort(array, i, right_position);
    }

}

/*
*This method uses quicksort process to sort the array in an descending order
*Also Uses the middle element as pivot
*Sorts both left and right asides of the pivot till the full array is sorted
*Takes three parameters; lower index, highest index and array
*/


void descend_quick_sort(int array[], int left_position, int right_position){
    int x = left_position;
    int y = right_position;
    int temporary;                 //temporary variable for swa[[ing without losing any data
    int pivot = array[(right_position + left_position)/2];       //middle element as pivot
    while(x <=y){
        while(array[x] > pivot)              //left side
        x++;
        while(array[y] < pivot)           //right side
        y--;
        if(x <=y){                       //begin the swapping
            temporary = array[x];
            array[x] = array[y];
            array[y] = temporary;
            x++;
            y--;
        }
    }
}

/*
*Main method
*Takes array size from user and randomly generates elements
*Prints the original array, sorts it in ascending and descending orders and prints out the sorted arrays
*/

int main(){

    int size = 0;

    // Input an array size
    while (size < 2 || size > 100){                   //array size should be between 2 and 100
        cout << "Enter size of the array [2 - 100]: ";
        cin >> size;
    }

    // Generate a random array of the given size
    int array[size];                 //random generation of elements
    srand((unsigned)time(0));

    for(int i=0; i<size; i++)
        array[i] = (rand()%100)+1;

    // TODO: print the array to the user
    cout << "The original array is: ";           //prints original array
    output(array, size);



    // TODO: Implement a sorting algorithm to sort the array in ascending order

    ascend_quick_sort(array, 0, size-1);            //sorts into ascending order


    // TODO: Print the sorted array to the user
    cout << "The sorted array in ascending form: ";    //prints sorted array
    output(array, size);

    // TODO: Extra-mile: Sort the array in descending order and print to the user
    descend_quick_sort(array, 0, size-1);                   //sorts into descending order
    cout << "The sorted array in descending order: ";
    output(array, size);                                  //prints sorted array
}
