import java.util.Scanner;

public class ArrayMinValueSimple {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String str = scan.nextLine().trim();

		for(int i = 0; i < str.length(); i ++) {
			char charAt = str.charAt(i);

			if (!Character.isDigit(charAt) && charAt != ' ') {
				System.out.println("Invalid Input");
				System.exit(-1);
			}
		}

		String[] strArr = str.split(" {1,}");
		int[] myints = new int[strArr.length];

		for(int i = 0; i < myints.length; ++ i) {
			myints[i] = Integer.valueOf(strArr[i]);
		}

		int min = myints[0];
		for(int i = 0; i < myints.length; ++ i) {
			if(min > myints[i])
				min = myints[i];
		}

		System.out.println(min);
	}

}
