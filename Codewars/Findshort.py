#Return the length of the shortest word in a string

def find_short(s):
    l = s
    for word in s.split():
        if len(word) < len(l):
            l = word
    return len(l)

string = "This is a very beautiful test sentence"
print(find_short(string)) #Should be 1 (a)