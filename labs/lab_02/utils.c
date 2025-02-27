//
// Created by madarasz.hunor on 2/27/2025.
//

#include "utils.h"

#include <tgmath.h>

bool isPrime(int number){
    if (number <= 1)
        return false;
    if (number ==2)
        return true;
    if (number ==3)
        return true;
    for (int i = 3; i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
        return true;
    }
}
bool isPalindrome(int number){
   int reverse = 0;
   int temp = number;
   while (temp != 0){
       reverse = reverse * 10 + temp % 10;
       temp = temp / 10;

   }
   return reverse == number;

}
