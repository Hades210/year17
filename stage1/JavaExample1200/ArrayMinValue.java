import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.UIManager;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.util.Arrays;



public class ArrayMinValue extends JFrame {

	private JPanel contentPane;
	private JTextField textField;
	private JLabel label;

	private JLabel label_1;

	public static void main(String[] args) {
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
		} catch (Throwable e) {
			e.printStackTrace();
		}

		EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				try {
					ArrayMinValue frame = new ArrayMinValue();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public ArrayMinValue() {
		setTitle("\u83B7\u53D6\u4E00\u7EC4\u6700\u5C0F\u503C");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100,100,450,149);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5,5,5,5));
		setContentPane(contentPane);
		contentPane.setLayout(null);

		textField = new JTextField();
		textField.setBounds(6,36,414,30);
		contentPane.add(textField);
		textField.setColumns(10);

		JButton button = new JButton("\u8BA1\u7B97");
		button.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				do_button_actionPerformed(e);
			}
		});

		button.setBounds(16,76,90,30);
		contentPane.add(button);

		label = new JLabel("\u6700\u5C0F\u503C\uFF1A");
		label.setBounds(116,82,304,18);
		contentPane.add(label);

		label_1 = new JLabel("\u8BF7\u5728\u6587\u672C\u6846\u4E2D\u8F93\u5165\u591A\u4E2A\u6574\u6570\uFF0C\u4EE5\u7A7A\u683C\u4E3A\u5206\u9694\u7B26\u3002\u4F8B\u5982\uFF1A 3 5 2 562 125");
		label_1.setBounds(6,6,422,18);
		contentPane.add(label_1);
	}

	protected void do_button_actionPerformed(ActionEvent e) {
		String arrayStr = textField.getText().trim();
		for (int i = 0; i < arrayStr.length(); i ++) {
			char charAt = arrayStr.charAt(i);
			if(!Character.isDigit(charAt) && charAt != ' ') {
				JOptionPane.showMessageDialog(null,"input contains invalid contains");
				textField.setText("");
				return;
			}
		}

		String[] numStrs = arrayStr.split(" {1,}");
		int[] numArray = new int[numStrs.length];

		for(int i = 0; i < numArray.length; i ++) {
			numArray[i] = Integer.valueOf(numStrs[i]);
		}

		int min = numArray[0] ;

		for(int j = 0; j < numArray.length; j ++) {
			if (min > numArray[j]) {
				min = numArray[j];
			}
		}
		label.setText("The smallest number: " + min);
	}
}
