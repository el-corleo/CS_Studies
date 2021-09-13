-------------------------------------------------------------
-- PROBLEM 11
-- Modify the result of problem 10 in such a way that if an element has no duplicates it is simply copied into the result list. Only elements with duplicates are transferred as (N E) lists.
-- from Prob 9 & 10
pack :: (Eq a) => [a] -> [[a]]
pack [] = []
pack (x:xs) = (x : takeWhile (==x) xs) : pack (dropWhile (==x) xs)

encode :: (Eq a) => [a] -> [(Int, a)]
encode x = reverse $ foldl (\acc a -> (length a, head a):acc) [] (pack x)

data Encoded a = Multiple Int a | Single a deriving (Show)

encodeMod :: (Eq a) => [a] -> [Encoded a]
encodeMod x = foldl (\acc a -> if fst a > 1 then Multiple (fst a) (snd a) : acc else Single (snd a) : acc) [] convertedX
  where
    convertedX = encode x

-- from website (much cleaner/readable than mine)
encodeModified :: Eq a => [a] -> [ListItem a]
encodeModified = map encodeHelper . encode
  where
    encodeHelper (1,x) = Single x
    encodeHelper (n,x) = Multiple n x


-------------------------------------------------------------
-- PROBLEM 12
--
