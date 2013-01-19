#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void shift_and(char *Pstr, char *Tstr)
 {
     int i,Pstr_len,Tstr_len,D;
     Pstr_len = strlen(Pstr);
     Tstr_len = strlen(Tstr);
     unsigned int B[128];//128位假设是
 
     //Preprocessing
     for(i=0;i<128;i++)
     {
         B[i]=0;
     }
     for(i=0;i<Pstr_len;i++)
     {
         B[Pstr[i]] = B[Pstr[i]] | ( 1<<i);
     }
 
     //Searching
     D = 0;
     for(i=0;i<Tstr_len;i++)
     {
         D = ((D<<1)|1) & B[Tstr[i]] ;
         if( D &(1<<(Pstr_len-1)))
         {
             cout<<i-Pstr_len+1<<endl;
         }
     }
 
 }
