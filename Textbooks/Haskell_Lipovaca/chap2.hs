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
-- e.g., (==) :: (Eq a) => a -> a -> Bool [defines the == operator]
--       (Num b, Integral a) => a -> b   [defines fromIntegral function]

-- show prints to console for any type that can be represented as a string
-- read takes a string as input and converts to appropriate type
showFloat :: Float -> String
showFloat f = show f
readListAndAppend :: [Int] -> [Int]
readListAndAppend xs = read "[1,2,3]" ++ xs
-- note read "4" doesn't work because the compiler doesn't know which type it should convert 4 to
-- Type annotations solve this issue
annotated = read "4" :: Int
annotated' = read "4" :: Float
