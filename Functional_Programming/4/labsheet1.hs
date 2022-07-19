import Data.Char

----List Comprehension

toLowerSt :: String -> String
toLowerSt [] = []
toLowerSt (c:cs) = toLower c : toLowerSt cs

toLowerSt' :: String -> String
toLowerSt' cs = [toLower c | c <- cs]

onlyLetters :: String -> String
onlyLetters [] = []
onlyLetters (c:cs) | isLetter c  = c : onlyLetters cs
                   | otherwise   =     onlyLetters cs

onlyLetters' :: String -> String
onlyLetters' cs = [c | c <- cs, isLetter c]

onlyNumsOrLetters :: String -> String
onlyNumsOrLetters cs = [c | c <- cs, isDigit c || isLetter c]

onlyNumsOrLetters' :: String -> String
onlyNumsOrLetters' cs = filter (\ c -> isDigit c || isLetter c) cs

onlyLettersToLower :: String -> String
onlyLettersToLower cs = [toLower c | c <- cs, isLetter c]
