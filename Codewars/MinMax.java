//Write a function that returns both the minimum and maximum number of the given list/array.


class MinMax 
{
    public static int[] minMax(int[] arr) 
    {
      int min = arr[0], max = arr[0];
      for (int i = 0; i< arr.length;i++)
      {
        if (min > arr[i])
        {
          min = arr[i];
        }
        if (max < arr[i])
        {
          max = arr[i];
        }
      }
      int [] newarr = {min, max};
      return newarr;
    }

    public static void main (String [] args)
    {
        int [] arr = {0,3,1,2,4,5,10,20,6};
        int [] newarr = minMax (arr);
        for (int i = 0; i < newarr.length; i++)
        {
            System.out.println(newarr[i]);
        }

    }
}