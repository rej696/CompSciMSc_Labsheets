--Lists

sorted :: [Int] -> Bool
sorted [] = True
sorted [x] = True
sorted (x:y:ys) | x < y = sorted (y:ys)
                | otherwise = False

ourTake :: Int -> [Int] -> [Int]
ourTake _ [] = []
ourTake n (x:xs) | n == 0 = []
                 | otherwise = x : ourTake (n - 1) xs

listSwap :: [(Int, [Char])] -> [([Char], Int)]
listSwap [] = []
listSwap ((n, st) : xs) = (st, n) : listSwap xs

halving :: Int -> [Int]
halving n | n == 0 = []
          | odd n  = n : halving (n-1)
          | even n = n : halving (div n 2)
halving _ = []

collatz :: Int -> [Int]
collatz n
  | n == 1 = [1]
  | even n = n : collatz (div n 2)
  | odd n = n : collatz ((3 * n) + 1)
collatz _ = []

colLength :: Int -> Int
colLength = length . collatz

-- TODO Pattern Matching

maxList :: [Int] -> Int
maxList [] = 0
maxList [x] = x
maxList (x:xs) = undefined


allDucks :: [String] -> Bool
allDucks [] = undefined
allDucks (x:xs) = undefined

duckDuckGoose :: [String] -> Bool
duckDuckGoose = undefined

--Pairs

ducks :: [(String,Int)]
ducks = [("Donald",6),("Daisy",5),("Huey",2),("Louie",2),("Dewey",2)]

noDDucks :: [(String,Int)] -> [(String,Int)]
noDDucks [] = []
noDDucks ((name,age):xs) = undefined

youngOrShort = undefined

describeDucks = undefined
