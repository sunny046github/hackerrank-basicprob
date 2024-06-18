
import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Solution {

    public static void main(String[] args) {
        int N,i;
            Scanner in=new Scanner(System.in);
            N=in.nextInt();
        BigInteger res=BigInteger.ONE;
       for(i=2;i<=N;i++){
       res = res.multiply(BigInteger.valueOf(i));
 
}
        System.out.println(res);
    }
}
