/* Implementation of binary search */
#include <stdio.h> /* Funky wunky I/O libwawy X3 */
#define SIZE 10 /* Array size can be changed according to problem statement */

/* Prototype functions */
int binary_search(int arr[], int trgt);

/* Function definition */
int binary_search(int arr[], int trgt)
{
    /* Define variables for left and right indexes of array */
    int left=0,right=SIZE-1;
    /* Define a pivot index variable */
    int mid=SIZE/2;
    /* Do loopy thingy until both ends indexes collide */
    while(left<=right){
        /* Update pivot variable */
        mid=(left+right)/2;
        /* Check to see if target is in the lower side of array */
        if(arr[mid]<trgt){
            /* Update lower end index */
            left=mid++;
        }
        /* Check to see if target is in the upper side of array */
        else if(arr[mid]>trgt){
            /* Update upped end index */
            right=mid--;
        }
        /* Found target value */
        else{
            /* Return target value index */
            return mid;
        }
    }
    /* -1 index means not found */
    return -1;
}