import java.util.Scanner;


public class Solution {

	private String[] strArray;
	
	public boolean read(){
		
		Scanner sc = new Scanner(System.in);
		int n = Integer.valueOf(sc.nextLine());
		strArray = new String[n];
		int i = 0;
		while(i < n){
			
			strArray[i++] = sc.nextLine();
		}
		
		return true;
	}
	
	public void solve(){
		
    	for(String s : strArray){
	    	int len = s.length();
	    	int sum = len;
	    	for(int i=1; i<len;i++){
	    		int count = 0;
	    		for(int j=0,k=i; j<len && k<len; j++,k++){
	    			  if(s.charAt(k) == s.charAt(j)){
	    				  count++;
	    			  }else{
	    				  break;
	    			  }
	    		}
	    		sum = sum + count;
	    	}
	    	System.out.println(sum);
    	}
    	
	}
	public void solveIt(){
		
    	for(String s : strArray){
	    	int len = s.length();
	    	long sum = len;
	    	char ch = s.charAt(0);
	    	int pos = s.indexOf(ch, 1);	    	
	    	while(pos != -1){
	    		long count = 1;
	    		for(int j=1,k=pos+1; j<len && k<len; j++,k++){
	    			  if(s.charAt(k) == s.charAt(j)){
	    				  count++;
	    			  }else{
	    				  break;
	    			  }
	    		}
	    		sum = sum + count;
	    		pos = s.indexOf(ch, pos+1);
	    	}
	    	System.out.println(sum);
    	}
    	
	}

	public void solveZ(){
		
    	for(String s : strArray){
	    	int len = s.length();
	    	long sum = len;
	    	int[] z = new int[len];
	    	int l=0,r=0;
	    	for(int k=1;k<len;k++){
	    		int j;
	    		if(k < r){
	    			j = ((r-k) < z[k-l] )? (r-k) : z[k-l];
	    		}else{
	    			j = 0;
	    		} 
	    		while(k+j < len){
	    			
	    			if(s.charAt(k+j) == s.charAt(j)){
	    				j++;
	    			}else{
	    				break;
	    			}
	    		}
	    		z[k] = j;
	    		sum = sum + z[k];
	    		if(k+j > r){
	    			l = k;
	    			r= k+j;
	    		}

	    	}
	    	System.out.println(sum);
    	}
    	
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Solution s = new Solution();
		if(s.read()){
			s.solveZ();
		}
		
	}

}
