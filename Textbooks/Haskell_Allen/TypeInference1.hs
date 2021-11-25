module TypeInference1 where

f :: Num a => a -> a -> a
f x y = x + y + 3


f' x y = x + y + 3


-- Exercises
-- 1.) will become [Char] -> [Char]
myConcat x = x ++ " yo"

-- 2.) will become fractional, given the presence of a fraction
myMult x = (x / 3) * 5

-- 3.) will become Int -> [Char]
myTake x = take x "hey you"

-- 4.) Int -> Bool
myCom x = (>) x $ (length [1..10])

-- 5.) Char -> Bool


-- So this is possible
triple y = tripleItYo y
  where tripleItYo :: Integer -> Integer
        tripleItYo x = x * 3
