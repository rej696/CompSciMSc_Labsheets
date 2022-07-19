
# toLowerSt :: String -> String
# toLowerSt cs = [toLower c | c <- cs]

to_lower_st = lambda cs : [c.lower() for c in cs]

# onlyLetters :: String -> String
# onlyLetters cs = [c | c <- cs, isLetter c]

only_letters = lambda cs : [c for c in cs if c.isalpha()]

# onlyNumsOrLetters :: String -> String
# onlyNumsOrLetters cs = [c | c <- cs, isDigit c || isLetter c]

only_nums_or_letters = lambda cs : [c for c in cs if c.isalpha() or c.isdigit()]

# onlyLettersToLower :: String -> String
# onlyLettersToLower cs = [toLower c | c <- cs, isLetter c]

only_letters_to_lower = lambda cs : [c.lower() for c in cs if c.isalpha()]


def apply(function, string):
    # Helper function to show function application like haskell
    print("".join(function(string)))


if __name__ == "__main__":
    apply(to_lower_st, "Hello World")
    apply(only_letters, "Hello World")
    apply(only_nums_or_letters, "2 Fast 2 Furious")
    apply(only_letters_to_lower, "2 Fast 2 Furious")

