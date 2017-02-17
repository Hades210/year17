import java.util.Scanner;
import java.text.DecimalFormat;

public class ConvertMoney {
	// 大写数字
	private final static String[] STR_NUMBER = {"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};
	private final static String[] STR_UNIT = {"","拾","佰","仟","万","拾","佰","仟","亿","拾","佰","仟"}; //整数单位
	private final static String[] STR_UNIT2 = {"角","分","厘"}; //小数单位
	
	public static void main(String[] args) {
		
		Scanner scan = new Scanner (System.in); 
		System.out.println("请输入一个金额:");
		while (true)
		{
			//获取金额转换后的字符串
			String convert = convert(scan.nextDouble());
			System.out.println(convert);
		}
	}
	
	private static String convert(double d) {
		//实例化DecimalFormat对象
		DecimalFormat df = new DecimalFormat("#0.###");
		//格式化double数字
		String strNum = df.format(d);
		
		//判断是否包含小数点
		if(strNum.indexOf(".") != -1) {
			String num = strNum.substring(0,strNum.indexOf("."));
			//整数部分大于12不能转换
			if(num.length() > 12) {
				System.out.println("数字太大，不能转换");
				return "";
			}
		}
		
		String point = ""; //小数点
		if(strNum.indexOf(".") != -1) {
			point = "元";
		} else {
			point = "元整";
		}
		
		//转换结果
		String result = getInteger(strNum) + point + getDecimal(strNum);
		if(result.startsWith("元")) { // 判断字符串是否已“元”结尾
			result = result.substring(1,result.length()); //截取字符串
		}
		return result;
	}
	
	private static String numReplace(String num, String oldStr, String newStr) {
		while(true) {
			//判断字符串中是否包含指定字符
			if(num.indexOf(oldStr) == -1) {
				break;
			}
			//替换字符串
			num = num.replaceAll(oldStr,newStr);
		}
		return num;
	}
	
	private static String getInteger(String num) {
		if(num.indexOf(".") != -1) 
			num = num.substring(0,num.indexOf("."));
		num = new StringBuffer(num).reverse().toString(); //反转字符串
		StringBuffer temp = new StringBuffer(); //创建一个StringBuffer对象
		for(int i = 0; i < num.length(); i ++) {
			temp.append(STR_UNIT[i]);
			temp.append(STR_NUMBER[num.charAt(i) - 48]);
		}
		
		num = temp.reverse().toString(); // 反转字符串
		num = numReplace(num,"零拾","零");
		num = numReplace(num,"零佰","零");
		num = numReplace(num,"零仟","零");
		num = numReplace(num,"零万","万");
		num = numReplace(num,"零亿","亿");
		num = numReplace(num,"零零","零");
		num = numReplace(num,"亿万","亿");
		
		if(num.lastIndexOf("零") == num.length() - 1) {
			num = num.substring(0,num.length() - 1);
		}
		return num;
	}
	
	private static String getDecimal(String num) {
		if(num.indexOf(".") == -1) 
			return "";
		num = num.substring(num.indexOf(".")+1);
		// 反转字符串
		num = new StringBuffer(num).reverse().toString();
		StringBuffer temp = new StringBuffer();
		
		for(int i = 0; i < num.length();i++) {
			temp.append(STR_UNIT2[i]);
			temp.append(STR_NUMBER[num.charAt(i) - 48]);
		}
		
		num = temp.reverse().toString();
		num = numReplace(num,"零角","零");
		num = numReplace(num,"零分","零");
		num = numReplace(num,"零厘","零");
		num = numReplace(num,"零零","零");
		
		if(num.lastIndexOf("零") == num.length() - 1) {
			num = num.substring(0,num.length() -1 );
		}
		
		return num;
	}
}
