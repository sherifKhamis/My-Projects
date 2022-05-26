import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JTextField;
import java.awt.Font;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Color;

public class Calculator {

	private JFrame frame;
	private JTextField textField;
	
	
	double number1, number2, result;
	
	String answer;
	String action;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Calculator window = new Calculator();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Calculator() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setForeground(Color.GRAY);
		frame.setBounds(100, 100, 442, 734);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		textField = new JTextField();
		textField.setBounds(10, 11, 408, 160);
		textField.setFont(new Font("Arial", Font.BOLD, 30));
		frame.getContentPane().add(textField);
		textField.setColumns(10);
		
		JButton btnDelete = new JButton("Delete");
		btnDelete.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String delete = null;
				if (textField.getText().length() > 0)
				{
					StringBuilder str = new StringBuilder(textField.getText());
					str.deleteCharAt(textField.getText().length()-1);
					delete = str.toString();
					textField.setText(delete);
				}
			}
		});
		btnDelete.setFont(new Font("Arial", Font.BOLD, 15));
		btnDelete.setBounds(329, 182, 89, 72);
		frame.getContentPane().add(btnDelete);
		
		JButton btnDevide = new JButton("/");
		btnDevide.setFont(new Font("Arial", Font.BOLD, 30));
		btnDevide.setBounds(329, 265, 89, 72);
		btnDevide.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				number1 = Double.parseDouble(textField.getText());
				textField.setText("");
				action = "/";
			}
		});
		frame.getContentPane().add(btnDevide);
		
		JButton btnX = new JButton("X");
		btnX.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				number1 = Double.parseDouble(textField.getText());
				textField.setText("");
				action = "x";
			}
		});
		btnX.setFont(new Font("Arial", Font.BOLD, 30));
		btnX.setBounds(329, 356, 89, 72);
		frame.getContentPane().add(btnX);
		
		JButton btnPlus = new JButton("+");
		btnPlus.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				number1 = Double.parseDouble(textField.getText());
				textField.setText("");
				action = "+";
			}
		});
		btnPlus.setFont(new Font("Arial", Font.BOLD, 30));
		btnPlus.setBounds(329, 449, 89, 72);
		frame.getContentPane().add(btnPlus);
		
		JButton btnMinus = new JButton("-");
		btnMinus.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				number1 = Double.parseDouble(textField.getText());
				textField.setText("");
				action = "-";
			}
		});
		btnMinus.setFont(new Font("Arial", Font.BOLD, 30));
		btnMinus.setBounds(329, 542, 89, 72);
		frame.getContentPane().add(btnMinus);
		
		JButton btn0 = new JButton("0");
		btn0.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number = textField.getText()+btn0.getText();
				textField.setText(number);
			}
		});
		btn0.setFont(new Font("Arial", Font.BOLD, 30));
		btn0.setBounds(119, 508, 89, 72);
		frame.getContentPane().add(btn0);
		
		JButton btn9 = new JButton("9");
		btn9.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number = textField.getText()+btn9.getText();
				textField.setText(number);
			}
		});
		btn9.setFont(new Font("Arial", Font.BOLD, 30));
		btn9.setBounds(218, 411, 89, 72);
		frame.getContentPane().add(btn9);
		
		JButton btn8 = new JButton("8");
		btn8.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number = textField.getText()+btn8.getText();
				textField.setText(number);
			}
		});
		btn8.setFont(new Font("Arial", Font.BOLD, 30));
		btn8.setBounds(119, 411, 89, 72);
		frame.getContentPane().add(btn8);
		
		JButton btn7 = new JButton("7");
		btn7.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number = textField.getText()+btn7.getText();
				textField.setText(number);
			}
		});
		btn7.setFont(new Font("Arial", Font.BOLD, 30));
		btn7.setBounds(10, 411, 89, 72);
		frame.getContentPane().add(btn7);
		
		JButton btn6 = new JButton("6");
		btn6.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number = textField.getText()+btn6.getText();
				textField.setText(number);
			}
		});
		btn6.setFont(new Font("Arial", Font.BOLD, 30));
		btn6.setBounds(219, 310, 89, 72);
		frame.getContentPane().add(btn6);
		
		JButton btn5 = new JButton("5");
		btn5.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number = textField.getText()+btn5.getText();
				textField.setText(number);
			}
		});
		btn5.setFont(new Font("Arial", Font.BOLD, 30));
		btn5.setBounds(119, 310, 89, 72);
		frame.getContentPane().add(btn5);
		
		JButton btn4 = new JButton("4");
		btn4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number = textField.getText()+btn4.getText();
				textField.setText(number);
			}
		});
		btn4.setFont(new Font("Arial", Font.BOLD, 30));
		btn4.setBounds(10, 310, 89, 72);
		frame.getContentPane().add(btn4);
		
		JButton btn3 = new JButton("3");
		btn3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number = textField.getText()+btn3.getText();
				textField.setText(number);
			}
		});
		btn3.setFont(new Font("Arial", Font.BOLD, 30));
		btn3.setBounds(219, 211, 89, 72);
		frame.getContentPane().add(btn3);
		
		JButton btn2 = new JButton("2");
		btn2.setFont(new Font("Arial", Font.BOLD, 30));
		btn2.setBounds(119, 211, 89, 72);
		btn2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number = textField.getText()+btn2.getText();
				textField.setText(number);
			}
		});
		frame.getContentPane().add(btn2);
		
		JButton btn1 = new JButton("1");
		btn1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number = textField.getText()+btn1.getText();
				textField.setText(number);
			}
		});
		btn1.setFont(new Font("Arial", Font.BOLD, 30));
		btn1.setBounds(10, 211, 89, 72);
		frame.getContentPane().add(btn1);
		
		JButton btnResult = new JButton("=");
		btnResult.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				number2 = Double.parseDouble(textField.getText());
				if (action == "+")
				{
					result = number1 + number2;
					answer = String.format("%.1f + %.1f = %.2f", number1, number2, result);
					textField.setText(answer);
				}
				else if (action == "-")
				{
					result = number1 - number2;
					answer = String.format("%.1f - %.1f = %.2f", number1, number2, result);
					textField.setText(answer);
				}
				else if (action == "x")
				{
					result = number1 * number2;
					answer = String.format("%.1f x %.1f = %.2f", number1, number2, result);
					textField.setText(answer);
				}
				else if (action == "/")
				{
					result = number1 / number2;
					answer = String.format("%.1f / %.1f = %.2f", number1, number2, result);
					textField.setText(answer);
				}
			}
		});
		btnResult.setFont(new Font("Arial", Font.BOLD, 30));
		btnResult.setBounds(119, 591, 89, 72);
		frame.getContentPane().add(btnResult);
	}
}
