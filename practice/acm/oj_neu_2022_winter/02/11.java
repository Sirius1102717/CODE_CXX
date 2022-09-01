import java.util.Scanner;
 
public class Main {
	
       public static void main(String[] args) {
    	  Scanner input=new Scanner( System.in);
    	  long n=input.nextLong();
    	  long a=input.nextLong();
		  long b=input.nextLong();
    	  for(int i=1;i<n;i++) {
    		 // System.out.println("s:"+a+"   "+b);
    		  long a1=input.nextLong();
    		  long b1=input.nextLong();
    		  if(a1>=a&&b1>=b) 
    			  {
    			  a=a1;
        		  b=b1;
    			  continue;
    			  }
    		  long d1=a/a1;
    		  if(a%a1!=0) d1++;
    		  
    		  long d2=b/b1;
    		  if(b%b1!=0) d2++;
    	//System.out.println("ss:"+d1+"   "+d2);
    		  long d=Math.max(d1, d2);
    		 
    		  a=d*a1;
    		  b=d*b1;
    		 
    	  }
    	  System.out.println(a+b);
          
	}
}