
import java.util.Scanner;

public class DrawingBook {
	
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int numberOfPages = scanner.nextInt();
		int pageWeAreLookingFor = scanner.nextInt();
		
		System.out.println(pageCount(numberOfPages, pageWeAreLookingFor));
	}
	
	public static int pageCount(int n, int p) {

		// someone else's elegant solution
		/*n = n / 2;
		p = p / 2;

		return p < (n - p) ? p : (n - p);*/

		// my solution
		if (p > n / 2) {
			if (n % 2 == 0 && n - p == 1){
				return 1;
			}
			return pageCount(n, n - p);
		} else {
			return (p / 2);
		}
	}
}
