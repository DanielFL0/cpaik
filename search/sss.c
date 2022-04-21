/* Implementation of straight string search */
#include <stdio.h> /* Funky wunky I/O libwawy X3 */
#define SIZE 10 /* Array size can be changed according to problem statement */

int strln(const char *s);
char *strfind(const char *s, const char *f);

int strln(const char *s)
{
    int i=0;
    while(s[i]!='\0')
	i++;
    return i;
}

char *strfind(const char *s, const char *f)
{
    int i=0,j=0,f_len=strln(f);
    while(s[j]!='\0'){
	if(i==f_len) return (char *)s+j-i;
	printf("s[%d]: %c f[%d]: %c\n",j,s[j],i,f[i]);
	if((s[j]==f[i])&&(i<f_len))
	    i++;
	else
	    i=0;
	j++;
    }
    return NULL;
}