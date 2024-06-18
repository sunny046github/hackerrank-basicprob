
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        int n = reader.nextInt();
        int[] array = new int[n];
        for(int i = 0 ; i < n; i++ )
        {
            array[i] = reader.nextInt();
        }
        System.out.println(getLengthOfLIS(array));
    }
    public static int getLengthOfLIS(int[] array)
    {
        TreeSet<Integer> s = new TreeSet<Integer>();
        for( int i = 0 ; i < array.length ; i++)
        {
           //if array[i] is newly added?
           if( s.add(array[i]) )
           {
               //if array[i] is not the last element?
               if( array[i] != s.last() )
               {
                    //remove it's next element; s.higher() gives the least element 
                   //which is greater than array[i]
                   s.remove(s.higher(array[i]));
               }
           }
        }
        return s.size();
    }
}
