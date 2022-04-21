/* Implementation of quick sort */
#include <stdio.h> /* Funky wunky I/O libwawy X3 */
#define SIZE 10 /* Array size can be changed according to problem statement */

void swap(int *a, int *b);
int partition(int arr[], int lo, int hi);
void quicksort(int arr[], int lo, int hi);

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int lo, int hi)
{
    int pvt=arr[hi],i=lo-1,j=lo;
    while(j<=hi-1){
        if(arr[j]<=pvt){
            i++;
            swap(&arr[i],&arr[j]);
        }
        j++;
    }
    i++;
    swap(&arr[i],&arr[hi]);
    return i;
}

void quicksort(int arr[], int lo, int hi)
{
    if((lo>=hi)||(lo<0)){
        return;
    }
    int p=partition(arr, lo, hi);
    quicksort(arr,lo,p-1);
    quicksort(arr,p+1,hi);
}