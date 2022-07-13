import Data.Char

---Maps

toLowerSt :: String -> String
toLowerSt = map toLower

vowels :: [Char]
vowels = ['a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U']

toLowerCons :: Char -> Char
toLowerCons c
  | elem c vowels = c
  | otherwise = toLower c

toLowerConsSt :: String -> String
toLowerConsSt = map toLowerCons

---Filters

onlyLetters :: String -> String
onlyLetters [] = []
onlyLetters (c:cs) | isLetter c  = c : onlyLetters cs
                   | otherwise   =     onlyLetters cs

onlyLetters' :: String -> String
onlyLetters' = filter isLetter

onlyNumsOrLetters :: String -> String
onlyNumsOrLetters = filter (\c -> isDigit c || isLetter c)

onlyLettersToLower1 st = map toLower (filter isLetter st)

onlyLettersToLower2 st = filter isLetter (map toLower st)

---Zips

firstNames :: [String]
firstNames = ["Adam","Brigitte","Charlie","Dora"]

secondNames :: [String]
secondNames = ["Ashe","Brown","Cook","De Santis"]

wholeNames :: [(String, String)]
wholeNames = zip firstNames secondNames

countNames :: [String] -> [(Int, String)]
countNames = zip [1..]

wholeNames2 :: [String]
wholeNames2 = zipWith (++) firstNames secondNames

wholeNames2' :: [String]
wholeNames2' = zipWith (\x y -> x ++ " " ++ y) firstNames secondNames


rollCall :: [String] -> [String]
rollCall = zipWith call xs
           where call x y = x ++ ": " ++ y ++ "? 'Present!'"
                 xs   = map show [1..]
