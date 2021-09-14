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
encodeModified :: Eq a => [a] -> [Encoded a]
encodeModified = map encodeHelper . encode
  where
    encodeHelper (1,x) = Single x
    encodeHelper (n,x) = Multiple n x


-------------------------------------------------------------
-- PROBLEM 12
-- Given a run-length code list generated as specified in problem 11. Construct its uncompressed version.
isMultiple :: Encoded a -> Bool
isMultiple (Multiple _ _) = True
isMultiple _ = False

getSeq :: Encoded a -> [a]
getSeq (Multiple n x) = take n (repeat x)
getSeq (Single x) = [x]

decode :: [Encoded a] -> [a]
decode x = foldl (\acc a -> foldr (:) acc (getSeq a)) [] x

-- easy to understand answer from website
decode' :: [Encoded a] -> [a]
decode' [] = []
decode' ((Single x):xs) = x:decode' xs
decode' ((Multiple 2 x):xs) = x:x:decode' xs
decode' ((Multiple n x):xs) = x:decode' ((Multiple (n-1) x):xs)


-------------------------------------------------------------
-- PROBLEM 13
-- Implement the so-called run-length encoding data compression method directly. I.e. don't explicitly create the sublists containing the duplicates, as in problem 9, but only count them.
makeEncodedType :: [a] -> Encoded a
makeEncodedType [x] = Single x
makeEncodedType x = Multiple (length x) (head x)

encodeDirect :: (Eq a) => [a] -> [Encoded a]
encodeDirect [] = []
encodeDirect x = makeEncodedType (takeWhile (==a) x) : encodeDirect (dropWhile (==a) x)
  where a = head x







