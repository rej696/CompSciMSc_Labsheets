data Duck = Duck String Int Float | Duckling String Int Float
  deriving Show

donald :: Duck
donald = Duck "Donald" 6 0.7

daisy :: Duck
daisy = Duck "Daisy" 5 0.3

huey :: Duck
huey = Duckling "Huey" 2 0.2

dewey :: Duck
dewey = Duckling "Dewey" 2 0.5

duckFamily :: [Duck]
duckFamily = [donald,daisy,huey,dewey]

birthday' :: String -> Int -> Float -> Maybe Duck
birthday' name age height
  | age < 0  = Nothing
  | age < 2 = Just (Duckling name (age + 1) height)
  | otherwise = Just (Duck name (age + 1) height)

birthday :: Duck -> Maybe Duck
birthday (Duck name age height) = birthday' name age height
birthday (Duckling name age height) = birthday' name age height

tall :: Duck -> Bool
tall (Duck _ _ height) = height > 0.6
tall (Duckling _ _ height) = height >= 0.25
