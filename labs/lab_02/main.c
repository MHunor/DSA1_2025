#include <stdio.h>
#include "utils.h"

int main(void)
{
    int n=3;
    if(isPrime(n)==0)
    {
        printf("nem prim szam\n");
    }
    else
        printf("prim szam\n");


    int m=1331;
    if(isPalindrome(m)==0){
        printf("nem palindrome szam\n");
    }
    else
        printf("palindrome szam\n");

}
