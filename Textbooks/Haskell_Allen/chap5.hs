-- currying
subtractStuff :: Integer -> Integer -> Integer
subtractStuff x y = x - y - 10

subtractOne :: Integer -> Integer
subtractOne = subtractStuff 1

subtractOne' :: Integer -> Integer
subtractOne' x = subtractStuff x 1

-- Exercises
-- 1.) a
-- 2.) d
-- 3.) b [WRONG! Should be d]
h :: (Num a, Num b) => a -> b -> b
h x y = fst (y, x)
-- 4.) d [WRONG! Should be c]
-- 5.) a
jackal :: (Ord a, Eq b) => a -> b -> a
jackal x y = x
-- 6.) e
-- 7.) e [WRONG! Should be d]
kessel :: (Ord a, Num b) => a -> b -> a
kessel x y = x
-- 8.) e [WRONG! Should be a]
-- 9.) c

