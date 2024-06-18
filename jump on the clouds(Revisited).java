import java.util.*;
public class A
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();
        int k = in.nextInt();
        
        int[] array = new int[n];
        for(int x = 0; x < n; x++)
        {
            array[x] = in.nextInt();
        }
        
        int cloud = 0;
        int e = 100;
        for(int y = 0; y < n; y++)
        {
            cloud = (cloud + k) % n;
            e--;
            
            if(array[cloud] == 1)
            {
                e -= 2;
            }
            
            if(cloud == 0)
            {
                break;
            }
        }
        
        System.out.println(e);
    }
}


