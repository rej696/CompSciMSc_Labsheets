
true = \x y -> x
false = \x y -> y

-- Exercise 1
f = \x y -> x (y y y) x
-- Calc f true true
(\x y -> x (y y y) x) (\x y -> x) (\x y -> x)
(\y -> (\x y -> x) (y y y) (\x y -> x)) (\x y -> x)
(\x y -> x) ((\x y -> x) (\x y -> x) (\x y -> x)) (\x y -> x)
(\y -> ((\x y -> x) (\x y -> x) (\x y -> x))) (\x y -> x)
(\x y -> x) (\x y -> x) (\x y -> x)
(\y -> (\x y -> x)) (\x y -> x)
(\x y -> x) --true

-- Calc f true false
(\x y -> x (y y y) x) (\x y -> x) (\x y -> y)
(\y -> (\x y -> x) (y y y) (\x y -> x)) (\x y -> y)
(\x y -> x) ((\x y -> y) (\x y -> y) (\x y -> y)) (\x y -> x)
(\y -> ((\x y -> y) (\x y -> y) (\x y -> y))) (\x y -> x)
(\x y -> y) (\x y -> y) (\x y -> y)
(\y -> y) (\x y -> y)
(\x y -> y) -- False

-- Calc f false true
(\x y -> x (y y y) x) (\x y -> y) (\x y -> x)
(\y -> (\x y -> y) (y y y) (\x y -> y)) (\x y -> x)
(\x y -> y) ((\x y -> x) (\x y -> x) (\x y -> x)) (\x y -> y)
(\y -> y) (\x y -> y)
(\x y -> y) -- False

-- Calc f false false
(\x y -> x (y y y) x) (\x y -> y) (\x y -> y)
(\y -> (\x y -> y) (y y y) (\x y -> y)) (\x y -> y)
(\x y -> y) ((\x y -> y) (\x y -> y) (\x y -> y)) (\x y -> y)
(\y -> y) (\x y -> y)
(\x y -> y) -- False

-- F is AND

-- Exercise 2
zero = \f x -> x
one  = \f x -> f x
two  = \f x -> f (f x)

succ = \n f x -> f (n f x)
add  = \m n f x -> m f (n f x)
mult = \m n f x -> m (n f) x

-- Verify succ 1 ->b* 2
(\n f x -> f (n f x)) (\f x -> f x)
(\f x -> f ((\f x -> f x) f x))
(\f x -> f ((\x -> f x) x))
(\f x -> f (f x)) -- Two

-- Normal form of add 2 3 == 5
five = \f x -> f (f (f (f (f x))))

-- Beta Reduction of add 2 3
(\m n f x -> m f (n f x)) (\f x -> f (f x)) (\f x -> f (f (f x)))
(\n f x -> (\f x -> f (f x)) f (n f x)) (\f x -> f (f (f x)))
(\f x -> (\f x -> f (f x)) f ((\f x -> f (f (f x))) f x))
(\f x -> (\x -> f (f x)) ((\f x -> f (f (f x))) f x))
(\f x -> f (f ((\f x -> f (f (f x))) f x)))
(\f x -> f (f ((\x -> f (f (f x))) x)))
(\f x -> f (f (f (f (f x))))) -- Five

-- Normal form of mult 2 2 == 4
four = \f x -> f (f (f (f x)))

-- Beta Reduction of mult 2 2
(\m n f x -> m (n f) x) (\f x -> f (f x)) (\f x -> f (f x))
(\n f x -> (\f x -> f (f x))  (n f) x) (\f x -> f (f x))
(\f x -> (\f x -> f (f x))  ((\f x -> f (f x)) f) x)
(\f x -> (\f x -> f (f x))  (\x -> f (f x)) x)
(\f x -> (\x -> (\x -> f (f x)) ((\x -> f (f x)) x))   x)
(\f x -> (\x -> f (f x)) ((\x -> f (f x)) x))
(\f x -> (f (f ((\x -> f (f x)) x))))
(\f x -> (f (f (f (f x))))) -- Four
