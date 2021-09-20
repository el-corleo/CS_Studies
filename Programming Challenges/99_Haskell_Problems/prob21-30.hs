import System.Random
-------------------------------------------------------------
-- PROBLEM 21
-- Insert an element at a given position into a list.
insertAt :: a -> [a] -> Int -> [a]
insertAt x xs n
  | n < 0 || n > length xs  = error "Index out of bounds."
  | otherwise               = take (n-1) xs ++ [x] ++ drop (n-1) xs

-- solution from website
-- Simple recursive solution that prepends each element up until the index in question and then appends the rest of the list
insertAt' x ys     1 = x:ys
insertAt' x (y:ys) n = y:insertAt' x ys (n-1)


-------------------------------------------------------------
-- PROBLEM 22
-- Create a list containing all integers within a given range.
range :: Int -> Int -> [Int]
range x y = [x..y]

-- from the website
-- This can't handle x > y; it returns an empty list
range' x y = take (y-x+1) $ iterate (+1) x


-------------------------------------------------------------
-- PROBLEM 23
-- Extract a given number of randomly selected elements from a list.
-- Didn't know how to do random; the following is a solution from the website

rnd_select xs n = do
  gen <- getStdGen
  return $ take n [ xs !! x | x <- randomRs (0, (length xs) - 1) gen]


-------------------------------------------------------------
-- PROBLEM 24
-- Lotto: Draw N different random numbers from the set 1..M.
diff_select :: Int -> Int -> IO [Int]
diff_select n to = diff_select' n [1..to]

diff_select' 0 _  = return []
diff_select' _ [] = error "too few elements to choose from"
diff_select' n xs = do r <- randomRIO (0,(length xs)-1)
                       let remaining = take r xs ++ drop (r+1) xs
                       rest <- diff_select' (n-1) remaining
                       return ((xs!!r) : rest)
-- WHAT I THINK IS GOING ON:
--    Creates a list from 1 to 'to'
--    Then selects an index 'r'
--    Assigns all numbers in array except for the number at 'r' to remaining array
--    Returns number at index 'r' prepended to n-1 recursive calls on the remaining array
