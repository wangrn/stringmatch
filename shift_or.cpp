#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void shift_or(char *Pstr, char *Tstr)
{
    int Pstr_len,Tstr_len,D, mask;
    Pstr_len = strlen(Pstr);
    Tstr_len = strlen(Tstr);
    unsigned int B[128];//128位假设
    
    //Preprocessing
    for(int i=0; i<128; i++)
    {
        B[i]=~0;         //设为全部非0
    }
    for(int i = 0; i < Pstr_len; i ++)
    {
        B[Pstr[i]] = B[Pstr[i]] & (~( 1<<i));     //其实就是shift-and反过来
    }
    mask= ~(1<<Pstr_len-1);
 
    //Searching
    D = ~0;                   //反的
    for(int i = 0; i < Tstr_len; i ++)
    {
        D = (D<<1) | B[Tstr[i]] ;             //少了一次位运算
 
        if(~(D|mask))
        {
            cout<<i-Pstr_len+1<<endl;
        }
    }
}

int main()
{
    shift_or("abc", "123abc456");
    return 0;
}
