/*You are given an array containing integers. 
The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N. 
Write a method that takes the array as an argument and returns this "outlier" N.*/

#include <iostream>
#include <vector>
using namespace std;

int FindOutlier(vector<int> arr)
{
    int result, even = 0, odd = 0;
    
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] % 2 == 0)
      {
        even++;
      }
      else 
      {
        odd++;
      }
    }
    if (even < 2)
    {
      for (int i = 0; i < arr.size(); i++)
      {
        if (arr[i] % 2 == 0)
        {
          result = arr[i];
        }
      }
    }
    else 
    {
      for (int i = 0; i < arr.size(); i++)
      {
        if (arr[i] % 2 != 0)
        {
          result = arr[i];
        }
      }
    }
    
    return result;
}

int main ()
{
    vector <int> arr = {1, 3, 4, 5, 9, 11, 13, 15, 17}; //all odd except one
    cout << FindOutlier (arr); // result = 4
}