import java.io.*;
import java.util.*;

public class TaumAndBday {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
      
        for(int i = 0;i<numCases;i++){
            // have to use long because of the contraints which will not fit in int
            long numBlackGifts = sc.nextLong(); 
            long  numWhiteGifts = sc.nextLong();
            long  costBlackGift = sc.nextLong();
            long  costWhiteGift = sc.nextLong();
            long  conversionCost = sc.nextLong();
            long price = 0;
            if((costWhiteGift+conversionCost)<costBlackGift){
                price = (costWhiteGift+conversionCost)*numBlackGifts + (numWhiteGifts*costWhiteGift);
            }else if ((costBlackGift+conversionCost) < costWhiteGift){
                price = ((costBlackGift + conversionCost) * numWhiteGifts) + (numBlackGifts*costBlackGift);
            }else{
                price = (costBlackGift * numBlackGifts) + (costWhiteGift * numWhiteGifts);
            }
            System.out.println(price);
        }
    }
}
