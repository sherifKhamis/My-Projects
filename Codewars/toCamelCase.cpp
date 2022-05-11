//Function that turns strings with dashes/underscores into camel case 

#include <string>
#include <cctype>
#include <iostream>
using namespace std;

string to_camel_case(string text)
{
  for (int i = 0; i < text.length(); i++)
  {
    if (text[i] == '-' || text[i] == '_')
    {
      text[i+1] = toupper(text[i+1]); 
      text.erase(text.begin() + i);
      
    }
  }
  
  return text;
}

int main ()
{
    string test = "this-is-a-test";
    cout << test << " = " << to_camel_case(test);
}