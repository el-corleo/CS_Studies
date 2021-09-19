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
