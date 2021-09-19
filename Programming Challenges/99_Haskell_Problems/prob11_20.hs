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


-------------------------------------------------------------
-- PROBLEM 14
-- Duplicate the elements of a list
duplicate :: [a] -> [a]
duplicate [] = []
duplicate (x:xs) = x : x : duplicate xs

-- solutions from website
dupli list = concat [[x,x] | x <- list]
-- dupli' = (<**> [id,id])                 -- Applicative
dupli''' xs = xs >>= (\x -> [x,x])      -- list monad


-------------------------------------------------------------
-- PROBLEM 15
-- Replicate the elements of a list a given number of times.
-- successful adaptation based off of solution from above (but I don't quite understand how it works)
replicate' :: [a] -> Int -> [a]
replicate' [] _ = []
replicate' xs n = xs >>= (\x -> take n $ repeat x)

-- version easier for me to understand
expand :: a -> Int -> [a]
expand _ 0 = []
expand x n = x : expand x (n-1)

replicate'' :: [a] -> Int -> [a]
replicate'' [] _ = []
replicate'' xs n = concat $ foldl (\acc x -> (expand x n):acc) [] xs

-- solutions from website
repli :: [a] -> Int -> [a]
repli xs n = concatMap (take n . repeat) xs
-- solution like mine but using where (I need to learn to use this feature)
repli' :: [a] -> Int -> [a]
repli' xs n = foldl (\acc e -> acc ++ repli'' e n) [] xs
  where
    repli'' _ 0 = []
    repli'' x n = x : repli'' x (n-1)


-------------------------------------------------------------
-- PROBLEM 16
-- Drop every N'th element from a list.
dropEvery :: [a] -> Int -> [a]
dropEvery [] _ = []
dropEvery x 0 = x
dropEvery x n = take (n-1) x ++ dropEvery (drop n x) n

-- solutions from website
-- using list comprehension
dropEvery' xs n = [ i | (i,c) <- ( zip xs [1,2..] ), (mod c n) /= 0 ]


-------------------------------------------------------------
-- PROBLEM 17
-- Split a list into two parts; the length of the first part is given.
split :: [a] -> Int -> ([a], [a])
split [] _ = ([],[])  -- should probably be an error
split x n = (take n x, drop n x)


-------------------------------------------------------------
-- PROBLEM 18
-- Extract a slice from a list.
slice :: [a] -> Int -> Int -> [a]
slice [] _ _ = []
slice x start end
  | end > length x || start < 0  = error "Index out of bounds"
  | start > end     = error "Impossible slice."
  | start == end    = []
  | otherwise       = cutEnd (drop (start-1) x) (end-start)
  where cutEnd y n = take n y

-- solution from website
slice' xs i k = drop (i-1) $ take k xs


-------------------------------------------------------------
-- PROBLEM 19
-- Rotate a list N places to the left.
rotate :: [a] -> Int -> [a]
rotate [] _ = []
rotate x 0 = x
rotate x n
  | n > 0     = drop n x ++ take n x
  | otherwise = drop (l+n) x ++ take (l+n) x
  where l = length x

-- solutions from website
rotate' xs n = take len . drop (n `mod` len) . cycle $ xs
    where len = length xs

rotate'' xs n = take (length xs) $ drop (length xs + n) $ cycle xs


-------------------------------------------------------------
-- PROBLEM 20
-- Remove the K'th element from a list.
removeAt :: [a] -> Int -> (a, [a])
removeAt [] _ = error "List cannot be empty."
removeAt x n
  | n > length x  = error "Index out of bounds"
  | n < 0         = error "Index out of bounds"
  | otherwise     = (x !! (n-1), take (n-1) x ++ drop n x)

