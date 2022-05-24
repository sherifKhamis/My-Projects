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
        System.out.println("\n\n*****ATM in JAVA*****\n\n");
        System.out.print("Welcome, please enter your pin number. PIN:  ");
        Scanner input = new Scanner (System.in);
        int pin = input.nextInt();
        if (!checkPin(pin))
        {
            System.out.print("\nWrong PIN, try again!\n\n");
            menu();
        }
        input.nextLine();
        System.out.println("\nWhat do you want to do ?");
        System.out.print("Deposit (a)\nWithdraw (b)\nCheck Balance (c)\nExit (d)\nChoice: ");
        String choice = input.nextLine();
        switch (choice)
        {
            case "a":
            System.out.print("How much do you want to deposit ?: ");
            int amount = input.nextInt();
            deposit(pin, amount);
            menu();
            break;

            case "b":
            System.out.print("How much do you want to withdraw ?: ");
            int withdrawAmount = input.nextInt();
            withdraw(pin, withdrawAmount);
            menu();
            break;

            case "c":
            System.out.print("\nYour Balance is " + checkBalance(pin) + "$");
            menu();
            break;

            default:
            menu();
            break;

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

    public static int checkBalance (int pin)
    {
        int balance;
        try 
        {   Scanner fScn = new Scanner(new File("DB.txt"));
            while(fScn.hasNextLine())
            {   
                String data = fScn.nextLine();
                if(data.contains("PIN: " + pin))
                {
                    data = fScn.nextLine();
                    balance = Integer.parseInt(data.substring(9, 13)); 
                    return balance;
                }  
            }
        }
        catch (IOException e) 
        {
            System.out.println("An error occurred.");
            e.printStackTrace();
        } 
        return 0;    
    }

    public static void deposit (int pin, int amount)
    {
    
        File fileToBeModified = new File("DB.txt");
         
        String oldContent = "";
         
        BufferedReader reader = null;
         
        FileWriter writer = null;

        int balance = checkBalance(pin);
        int newBalance = balance + amount;
         
        try
        {
            reader = new BufferedReader(new FileReader(fileToBeModified));
             
            //Reading all the lines of input text file into oldContent
             
            String line = reader.readLine();
             
            while (line != null) 
            {
                oldContent = oldContent + line + System.lineSeparator();
                 
                line = reader.readLine();
            }
             
            //Replacing oldString with newString in the oldContent
             
            String newContent = oldContent.replaceAll(balance + "", newBalance+ "");             
            //Rewriting the input text file with newContent
             
            writer = new FileWriter(fileToBeModified);
             
            writer.write(newContent);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        finally
        {
            try
            {
                //Closing the resources
                 
                reader.close();
                 
                writer.close();
            } 
            catch (IOException e) 
            {
                e.printStackTrace();
            }
        }
    }

    public static void withdraw (int pin, int amount)
    {
    
        File fileToBeModified = new File("DB.txt");
         
        String oldContent = "";
         
        BufferedReader reader = null;
         
        FileWriter writer = null;

        int balance = checkBalance(pin);
        int newBalance = balance - amount;
         
        try
        {
            reader = new BufferedReader(new FileReader(fileToBeModified));
             
            //Reading all the lines of input text file into oldContent
             
            String line = reader.readLine();
             
            while (line != null) 
            {
                oldContent = oldContent + line + System.lineSeparator();
                 
                line = reader.readLine();
            }
             
            //Replacing oldString with newString in the oldContent
             
            String newContent = oldContent.replaceAll(balance + "", newBalance+ "");
             
            //Rewriting the input text file with newContent
             
            writer = new FileWriter(fileToBeModified);
             
            writer.write(newContent);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        finally
        {
            try
            {
                //Closing the resources
                 
                reader.close();
                 
                writer.close();
            } 
            catch (IOException e) 
            {
                e.printStackTrace();
            }
        }
    }
    
}

