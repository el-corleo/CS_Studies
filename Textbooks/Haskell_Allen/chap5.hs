{-# LANGUAGE NoMonomorphismRestriction #-}

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

-- End of chap exercises
-- 1.) c
-- 2.) a
-- 3.) b (even though, I don't think it 'has' to return an element from the list)
-- 4.) c (same gripe as the above)
-- Type 1
-- 1.)  a.) Num a => a
--      b.) Num a => (a, [Char])
--      c.) (Integer,[Char])
--      d.) Bool
--      e.) Int
--      f.) Bool
-- 2.) Num a => a
-- 3.) Num a => a -> a
-- 4.) Fractional a => a
-- 5.) [Char]
--
-- Type 2
-- 1.) constrained poly, full poly, concrete, concrete
-- 2.) constrained poly, constrained poly, constrained poly
-- 3.) full poly, constrained poly, constrained poly
-- 4.) full poly, full poly, constrained poly
