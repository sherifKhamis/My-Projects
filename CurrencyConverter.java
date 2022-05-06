//Simple Currency Converter in JAVA with limited user input

import java.util.*;


public class CurrencyConverter 
{
    public static void main (String [] args)
    {
        //Input Currency menu
        System.out.println("*****Currency Converter in JAVA*****\n\n");
        System.out.print("Which Currency do you want to convert ?\nEUR (a)   USD (b)   GBP (c)   CNY (d)\nChoice:  ");
        Scanner input = new Scanner (System.in).useLocale(Locale.US);
        String iCurrency = input.next();

        //While loop to limit user input to abcd 
        while (!iCurrency.equals ("a") && !iCurrency.equals ("b") && !iCurrency.equals ("c") && !iCurrency.equals ("d"))
        {
                System.out.print("\nWrong input, try again !\nEUR (a)  USD (b)  GBP (c)  CNY (d)\nChoice:  ");
                iCurrency = input.next();
        }
        String iCurrencyName = "0";

        //Turn single letter input into a real currency name
        switch (iCurrency)
        {
            case "a":
            iCurrencyName = "EUR";
            break;

            case "b":
            iCurrencyName = "USD";
            break;

            case "c":
            iCurrencyName = "GBP";
            break;

            case "d":
            iCurrencyName = "CNY";
            break;
        }
        
        //Currency amount menu 
        System.out.print("\nHow much " + iCurrencyName + " do you have ?: ");
        double amount = input.nextDouble();

        //Target currency menu 
        System.out.print("\nWhich Currency do you want instead ?\nEUR (a)   USD (b)   GBP (c)   CNY (d)\nChoice:  ");
        String oCurrency = input.next();

        //while loop to limit user input to abcd only 
        while (!oCurrency.equals ("a") && !oCurrency.equals ("b") && !oCurrency.equals ("c") && !oCurrency.equals ("d"))
        {
                System.out.print("\nWrong input, try again !\nEUR (a)  USD (b)  GBP (c)  CNY (d)\nChoice:  ");
                oCurrency = input.next();
        }

        String oCurrencyName = "0";   
        double multiplyer = 0; 
        
        //Turn single letter input into a real currency name and choose the right exchange rate
        switch (oCurrency)
        {
            case "a":
            oCurrencyName = "EUR";
            switch (iCurrency)
            {
                case "a":
                multiplyer = 1.0;
                break;
                case "b":
                multiplyer = 0.91;
                break;
                case "c":
                multiplyer = 1.19;
                break;
                case "d":
                multiplyer = 0.14;
                break;  
            }            
            break;

            case "b":
            oCurrencyName = "USD";
            switch (iCurrency)
            {
                case "a":
                multiplyer = 1.1;
                break;
                case "b":
                multiplyer = 1;
                break;
                case "c":
                multiplyer = 1.32;
                break;
                case "d":
                multiplyer = 0.16;
                break;  
            }            
            break;

            case "c":
            oCurrencyName = "GBP";
            switch (oCurrency)
            {
                case "a":
                multiplyer = 0.84;
                break;
                case "b":
                multiplyer = 0.76;
                break;
                case "c":
                multiplyer = 1;
                break;
                case "d":
                multiplyer = 0.12;
                break;  
            }            
            break;

            case "d":
            oCurrencyName = "CNY";
            switch (iCurrency)
            {
                case "a":
                multiplyer = 7.01;
                break;
                case "b":
                multiplyer = 6.35;
                break;
                case "c":
                multiplyer = 8.38;
                break;
                case "d":
                multiplyer = 1;
                break;  
            }            
            break;
        }     

        double result = amount * multiplyer;

        //Output result
        System.out.print("\nYour " + amount + " " + iCurrencyName  + " are " + result + " " + oCurrencyName);
        
        input.close();
    }

}
