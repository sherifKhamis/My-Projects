/*If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
  Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.*/

#include <stdio.h>

int solution(int number) 
{
  int result = 0;
  for (int a = number-1; a > 0; a--)
    {
      if (a % 3 == 0 || a % 5 == 0) 
        {
          result = result + a;
        }
    }
    return result;
}

int main ()
{
    printf("Solution of 23 = %d", solution(23));

}