data Mood = Blah | Woot deriving Show

changeMood :: Mood -> Mood
changeMood Blah = Woot
changeMood _    = Blah


awesome = ["Papuchon", "curry", ":)"]
also = ["Quake", "The Simons"]
allAwesome = [awesome, also]


-- 1.
-- type signature of length: length :: [a] -> Integer
--
-- 2.
-- a.) 5
-- b.) 3
-- c.) 2
-- d.) 5
--
-- 3.
-- 6/3 works
--
-- 4.
-- 6 `div` (length [1,2,3]) fixes it (although only for integer division)
--
-- 5.
-- Bool, True
--
-- 6.
-- Bool, False
--
-- 7.
-- a.) True
-- b.) lists must be homogenous of type
-- c.) 5
-- d.) False
-- e.) 9 is not of type Bool
--
-- 8.
isPalindrome :: String -> Bool
isPalindrome s = s == reverse s

-- 9.
absoluteVal :: Integer -> Integer
absoluteVal n = if n < 0 then (-n) else n

-- 10.
f :: (a, b) -> (c, d) -> ((b, d), (a, c))
f x y = ((snd x, snd y), (fst x, fst y))


-- Correcting Syntax
x = (+)

f' xs = w `x` 1
  where w = length xs

-- Matching types
-- 1. c
-- 2. b
-- 3. a
-- 4. d
