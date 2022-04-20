/* Boring merge sort */
#include <stdio.h> /* Funky wunky I/O libwawy X3 */
#define SIZE 10 /* Array size can be changed according to problem statement */

void top_down_merge_sort(int arr[], int res[], int n);
void top_down_split_merge(int res[], int beg, int end, int arr[]);
void top_down_merge(int arr[], int beg, int mid, int end, int res[]);
void arr_copy(int arr[], int beg, int end, int res[]);

void top_down_merge_sort(int arr[], int res[], int n)
{
    arr_copy(arr,0,n,res);
    top_down_split_merge(res,0,n,arr);
}

void top_down_split_merge(int res[], int beg, int end, int arr[])
{
    if(end-beg<=1)
        return;
    int mid=(end+beg)/2;
    top_down_split_merge(arr,beg,mid,res);
    top_down_split_merge(arr,mid,end,res);
    top_down_merge(res,beg,mid,end,arr);
}

void top_down_merge(int arr[], int beg, int mid, int end, int res[])
{
    int k=beg,i=beg,j=mid;
    for(k=beg;k<end;k++){
        if((i<mid)&&(j>=end||arr[i]<=arr[j])){
            res[k]=arr[i];
            i++;
        }
        else{
            res[k]=arr[j];
            j++;
        }
    }
}

void arr_copy(int arr[], int beg, int end, int res[])
{
    int k;
    for(k=beg;k<end;k++)
        res[k]=arr[k];
}