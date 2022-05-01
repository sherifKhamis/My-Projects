#Currency Converter in Python, with 
#live api exchange rates and functions
#to limit letter and number user input


import requests
print("\t\t\tCurrency Converter") #header

def limitLetter (wanted, errormessage):
    #function to limit letter user input

    userInput = input()
    for x in wanted:
        if x == userInput:
            return userInput
    print("\n## Wrong input, try again! ##")
    print(errormessage)
    return limitLetter(wanted,errormessage)

#Starting currency menu and user input window
iCurrencyMessage = "\nWhich currency do you want to exchange ?\n   EUR(a)   USD(b)   GBP(c)   CNY(d)"
print(iCurrencyMessage)
iCurrencyKey = limitLetter ("abcd", iCurrencyMessage)
currencies = {"a" : "EUR", "b" : "USD", "c" : "GBP", "d" : "CNY"}

#Starting currency amount menu and user input window
amountMessage = "\nHow much " + currencies[iCurrencyKey] + " do you have ?"
print(amountMessage)

def limitNumber (errormssg):
    #function to limit input to numbers only
    
    numberInput = input()
    counter = 0
    for x in numberInput:
        if (ord(x) < 48 and ord(x) != 46) or ord(x) > 57:
            break
        else:
            counter += 1
    if counter == len(numberInput):
        return numberInput
    else:
        print("Wrong input, try again!")
        print(errormssg)
        numberInput = limitNumber(errormssg)
    return numberInput

amount = limitNumber (amountMessage)
#Target currency menu and user input window
oCurrencyMessage = "\nWhich currency do you want instead ?\n   EUR(a)   USD(b)   GBP(c)   CNY(d)"
print(oCurrencyMessage)
oCurrencyKey = limitLetter ("abcd", oCurrencyMessage)

#api code
apiKey = "d0c3f9d767-4fa9912e0f-r9o59i" #needs to be updated before use
url = "https://api.fastforex.io/convert?from=" + currencies[iCurrencyKey] + "&to=" + currencies[oCurrencyKey] + "&amount="+ amount +" &api_key=" + apiKey
headers = {"Accept": "application/json"}
response = requests.request("GET", url, headers=headers)
data = response.json()
result = data["result"][currencies[oCurrencyKey]]
print("Your " + amount + " " + currencies[iCurrencyKey] + " are " + str(result) + " " + currencies[oCurrencyKey])