import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for(int i=0;i<t;i++)
        {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int s = scanner.nextInt();
            int result = (m + s - 1) % n;
            if(result == 0)
                result = n;
            System.out.println(result);
        }
        
    }
}
