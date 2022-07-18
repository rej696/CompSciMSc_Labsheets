data IntTree = Empty | Node Int IntTree IntTree

t :: IntTree
t = Node 4 (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
           (Node 5 Empty (Node 6 Empty Empty))


------------------------- Exercise 1

isEmpty :: IntTree -> Bool
isEmpty Empty = True
isEmpty _ = False

rootValue :: IntTree -> Int
rootValue Empty        = 0
rootValue (Node i _ _) = i

height :: IntTree -> Int
height Empty = 0
height (Node _ t1 t2) = (max (height t1) (height t2)) + 1

find :: Int -> IntTree -> Bool
find x Empty = False
find x (Node i t1 t2)
  | x == i = True
  | otherwise = find x t1 || find x t2


-------------------------

instance Show IntTree where
    show = unlines . aux ' ' ' '
      where
        aux _ _ Empty = []
        aux c d (Node x s t) =
          [ c:' ':m | m <- aux ' ' '|' s ] ++
          ['+':'-':show x] ++
          [ d:' ':n | n <- aux '|' ' ' t ]

------------------------- Exercise 2

member :: Int -> IntTree -> Bool
member _ Empty = False
member x (Node i l r)
  | x == i = True
  | x < i = member x l
  | otherwise = member x r

largest :: IntTree -> Int
largest Empty            = 0
largest (Node x l Empty) = x
largest (Node x l r)     = largest r

deleteLargest :: IntTree -> IntTree
deleteLargest Empty = Empty
deleteLargest (Node i l Empty) = l
-- deleteLargest (Node i l (Node _ _ Empty)) = (Node i l Empty)
deleteLargest (Node i l r) = (Node i l (deleteLargest r))

delete :: Int -> IntTree -> IntTree
delete _ Empty = Empty
delete y (Node x l r)
    | y < x     = (Node x (delete y l) r)
    | y > x     = (Node x l (delete y r))
    | isEmpty l = r
    | otherwise = (Node (largest l) (deleteLargest l) r)
