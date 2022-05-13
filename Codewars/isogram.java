/*An isogram is a word that has no repeating letters, consecutive or non-consecutive. 
Implement a function that determines whether a string that contains only letters is an isogram. 
Assume the empty string is an isogram
*/


public class isogram 
{
    public static boolean isIsogram(String str) 
    {
      for (int i = 0; i < str.length(); i++)
      {
        for (int j = 0; j < str.length(); j++)
        {
          if (str.charAt(i) == str.charAt(j) && i != j)
          {
            return false;
          }
        }
      }
      return true;
      
    } 

    public static void main (String [] args)
    {
        System.out.print(isIsogram("isogram"));
    }
}

