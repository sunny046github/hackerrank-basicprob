
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int rounds = input.nextInt();
        int[] ar = new int[rounds];
        int i = 0;
        for(i = 0; i < rounds; i++)
            ar[i] = input.nextInt();
        int count = 0;
        i = 0;
        while(i != rounds-1)
        {
            if(i != ar.length - 2 && ar[i+2] == 0)
                i+=2;
            else
                i++;
            count++;
        }    
        System.out.println(count);
    }
}
