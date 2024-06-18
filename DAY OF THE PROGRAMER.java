import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class DayOfTheProgrammer {
	static String solve(int year) {
        if( year == 1918 ) return "26.09.1918";
        if( isLeap( year ) ) return "12.09." + Integer.toString( year );
        else return "13.09." + Integer.toString( year );
    }

    static boolean isLeap( int year ) {
        if( year % 4 != 0 ) return false;
        if( year > 1918 && year % 100 == 0 && year % 400 != 0 ) return false;
        return true;
    }
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        int year = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        System.out.println(solve(year));
        scanner.close();
    }
}