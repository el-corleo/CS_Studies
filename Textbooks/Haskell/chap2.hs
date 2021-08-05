-- Function declarations and Type system
factorial :: Integer -> Integer
factorial n = product [1 .. n]

circumfrence :: Float -> Float
circumfrence r = 2 * pi * r

-- Type variables act as generics
-- functions using type variables are referred to as polymorphic functions
reverseTup :: (a, b) -> (b, a)
reverseTup (a, b) = (b, a)


-- Type classes define interfaces for functions and operators for a given type
-- Must use type constraint notation
-- e.g., (==) :: (Eq a) => a -> a-> Bool [defines the == operator]
--       (Num b, Integral a) => a -> b   [defines fromIntegral function]

-- show prints to console for any type that can be represented as a string
-- read takes a string as input and converts to appropriate type
showFloat = show 5.334
readListAndAppend n = read "[1,2,3]" ++ n
-- note read "4" doesn't work because the compiler doesn't know which type it should convert 4 to
-- Type annotations solve this issue
annotated = read "4" :: Int

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
-- better because of error reporting
maximum'' :: (Ord a) => [a] -> a
maximum'' []     = error "maximum of emplty list!"
maximum'' [x]    = x
maximum'' (x:xs) = max x (maximum'' xs)


-- define replicate recursively
-- my attempt
replicate' :: Int -> a -> [a]
replicate' times item
    | times == 1 = [item]
    | otherwise  = item:(replicate' (times-1) item)

-- book
-- better in that it deals with edge cases like 0 and negative numbers
replicate'' :: Int -> a -> [a]
replicate'' n x
    | n <= 0    = []
    | otherwise = x : replicate'' (n-1) x


-- define take recursively
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
-- black magic (?)... don't quite understand this
quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
    let smallerOrEqual = [a | a <- xs, a <= x]
        larger         = [a | a <- xs, a > x]
    in quicksort smallerOrEqual ++ [x] ++ quicksort larger


