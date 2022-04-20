/* Implementation of straight string search */
#include <stdio.h> /* Funky wunky I/O libwawy X3 */
#define TEXT_SIZE 23 /* Text size can be changed according to problem statement */
#define WORD_SIZE 3 /* Text size can be changed according to problem statement */
#define TABLE_SIZE WORD_SIZE+1 /* KMP Table size */

/* Prototype functions */
void create_pos_arr(int positions[], int t_len);
void kmp_table(int table[], char word[], int w_len);
void kmp_search(int table[], char text[], char word[], int t_len, int w_len, int pos[]);

void create_pos_arr(int positions[], int t_len)
{
    int i;
    for(i=0;i<t_len;i++)
        positions[i]=0;
}

void kmp_table(int table[], char word[], int w_len)
{
    int pos=1,cnd=0;
    table[0]=-1;
    while(pos<w_len){
        if(word[pos]==word[cnd])
            table[pos]=table[cnd];
        else{
            table[pos]=cnd;
            while((cnd>=0)&&(word[pos]!=word[cnd])){
                cnd=table[cnd];
            }
        }
        pos++;
        cnd++;
    }
    table[pos]=cnd;
}

void kmp_search(int table[], char text[], char word[], int t_len, int w_len, int pos[])
{
    int j=0,k=0,np=0;
    while(j<t_len){
        if(word[k]==text[j]){
            j++;
            k++;
            if(k==w_len){      
                pos[np]=j-k;
                np++;
                k=table[k];
            }
        }
        else{
            k=table[k];
            if(k<0){
                j++;
                k++;
            }
        }
    }
}