/* Implementation of recursive merge sort */
#include <stdio.h> /* Funky wunky I/O libwawy X3 */
#define SIZE 10 /* Array size can be changed according to problem statement */

/* Prototype functions */
void merge_sort(int arr[], int len);
void merge(int arr[], int left[], int right[], int len);

void merge_sort(int arr[], int len)
{
    if(len<=1)
        return;
    int i,li=0,ri=0,ls=len/2,rs=len-ls;
    int left[ls];
    int right[rs];
    for(i=0;i<len;i++){
        if(i<ls){
            left[li]=arr[i];
            li++;
        }
        else{
            right[ri]=arr[i];
            ri++;
        }
    }
    merge_sort(left,ls);
    merge_sort(right,rs);
    merge(arr,left,right,len);
}

void merge(int arr[], int left[], int right[], int len)
{
    int i=0,li=0,ri=0,ls=len/2,rs=len-ls;
    while(li<ls&&ri<rs){
        if(left[li]<=right[ri]){
            arr[i]=left[li];
            li++;
        }
        else{
            arr[i]=right[ri];
            ri++;
        }
        i++;
    }
    while(li<ls){
        arr[i]=left[li];
        i++,li++;
    }
    while(ri<rs){
        arr[i]=right[ri];
        i++,ri++;
    }
}
