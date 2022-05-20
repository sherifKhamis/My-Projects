import java.io.*;
import java.util.*;


public class ATM 
{
    public static void createDB ()
    {
        try 
        {
            FileWriter myWriter = new FileWriter("DB.txt");
            myWriter.write("\n\nPIN: 1234\nBalance: 5021$\n\nPIN: 2321\nBalance: 2021$\n\nPIN: 2901\nBalance: 921$");
            myWriter.write("\n\nPIN: 3921\nBalance: 4021$\n\nPIN: 2991\nBalance: 301$\n\nPIN: 2012\nBalance: 121$");
            myWriter.write("\n\nPIN: 1251\nBalance: 2621$\n\nPIN: 2306\nBalance: 6666$\n\nPIN: 7033\nBalance: 1921$");
            myWriter.close();
        } 
        catch (IOException e) 
        {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    public static void main (String [] args)
    {
        createDB();
        menu();
    }

    public static void menu ()
    {
        System.out.println("*****ATM in JAVA*****\n\n");
        System.out.print("Welcome, please enter your pin number. PIN:  ");
        Scanner input = new Scanner (System.in);
        int pin = input.nextInt();
        if (!checkPin(pin))
        {
            System.out.print("\nWrong PIN, try again!\n\n");
            menu();
        }
    }

    public static boolean checkPin (int pin)
    {
        
        try 
        {   Scanner fScn = new Scanner(new File("DB.txt"));
            while(fScn.hasNextLine())
            {   
                String data = fScn.nextLine();
                if(data.contains("PIN:"))
                {
                    int newpin;
                    newpin = Integer.parseInt(data.substring(5));  
                    if (newpin == pin)
                    {
                        return true;
                    }
                }  
            }
        }
        catch (IOException e) 
        {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

        return false;
    }
}

