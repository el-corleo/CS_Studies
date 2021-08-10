-- define finding maximum element recursively
-- my attempt
maximum' :: [Int] -> Int
maximum' [x] = x
maximum' xs 
    | firstElem > otherElem = firstElem
    | otherwise             = otherElem
    where firstElem = head xs
          otherElem = maximum' (tail xs)

-- book
-- better because of error reporting [and because of Ord class limiting a to only things that can be ordered]
maximum'' :: (Ord a) => [a] -> a
maximum'' []     = error "maximum of emplty list!"
maximum'' [x]    = x
maximum'' (x:xs) = max x (maximum'' xs)


-- define replicate recursively
-- my attempt
replicate' :: Int -> a -> [a]
replicate' times item
    | times == 1 = [item]
    | otherwise  = item : (replicate' (times-1) item)

-- book
-- better in that it deals with edge cases like 0 and negative numbers
replicate'' :: Int -> a -> [a]
replicate'' n x
    | n <= 0    = []
    | otherwise = x : replicate'' (n-1) x


-- define take recursively
-- my attempt
take' :: Int -> [a] -> [a]
take' n xs
    | length xs == 0 = []
    | n <= 0         = []
    | otherwise      = (head xs) : take' (n - 1) (tail xs)

-- book
-- better because... more Haskellian (?)
take'' :: (Num i, Ord i) => i -> [a] -> [a]
take'' n _
    | n <= 0    = []
take'' _ []     = []
take'' n (x:xs) = x : take'' (n - 1) xs


-- define reverse recursively
-- my attempt
reverse' :: [a] -> [a]
reverse' []     = []
reverse' (x:xs) = reverse' xs ++ [x]

-- book
-- I'm catching on to their games! It was the exact same implementation verbatim (signatum? "symbol for symbol")


-- Now I see the diff between repeat and replicate:
-- repeat is an infinite list; whereas replicate specifies n times
-- book
-- infinite list; recursion with no base case
repeat' :: a -> [a]
repeat' x = x:repeat' x

nTimes :: Int -> a -> [a] 
nTimes n x = take n $ repeat' x


-- define zip recursively
-- my attempt
zip' :: [a] -> [b] -> [(a, b)]
zip' xs ys
    | (length xs == 1) || (length ys == 1) = [(head xs, head ys)]
    | otherwise                            = (head xs, head ys) : zip' (tail xs) (tail ys)

-- book
-- Drat! I fell back into the un-Haskellian mode of thinking
zip'' :: [a] -> [b] -> [(a, b)]
zip'' _ []          = []
zip'' [] _          = []
zip'' (x:xs) (y:ys) = (x,y):zip'' xs ys


-- Quicksort in Haskell
-- x is the pivot, and then you recursively perform on arrays that contain smaller and larger numbers than the pivot
--      smaller and larger arrays use list comprehension
quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
    let smallerOrEqual = [a | a <- xs, a <= x]
        larger         = [a | a <- xs, a > x]
    in quicksort smallerOrEqual ++ [x] ++ quicksort larger
