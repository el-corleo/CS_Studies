-- PROBLEM 1
-- Find the last element of a list
-- myLast [1,2,3,4] yields 4
myLast :: [a] -> a
myLast [] = error "There is no last element in an empty list."
myLast (_:xs)
  | length xs == 1  = head xs
  | otherwise       = myLast xs

-- cool solutions
myLast''' = head . reverse

-------------------------------------------------------------
-- PROBLEM 2
-- Find the penultimate element of a list
-- myPen [1,2,3,4] yields 3
myPen :: [a] -> a
myPen [] = error "There is no penultimate element in an empty list."
myPen list@(x:xs)
  | length list == 1  = error "There is no penultimate in a list size 1."
  | length list == 2  = head list
  | otherwise         = myPen xs


-- As per Noughtmare's answer on SO [https://stackoverflow.com/questions/68872685/why-does-this-usage-in-haskell-fail-to-encompass-the-whole-list?noredirect=1#comment121718004_68872685]
myPen' :: [a] -> a
myPen' []     = error "Empty lists have no penultimate element."
myPen' [_]    = error "Lists size 1 have no penultimate element."
myPen' [x,_]  = x
myPen' (_:xs) = myPen' xs

-- cool solutions
myButLast' x = reverse x !! 1
myButLast'''' = head . tail . reverse


------------------------------------------------------------
-- PROBLEM 3
-- find the k'th element of a list
-- elementAt 3 [a, b, c, d, e] yields c
elementAt :: [a] -> Int -> a
elementAt [] _ = error "The list is empty."
elementAt xs x
  | x < 1         = error "Index must be positive."
  | x > length xs = error "The index exceeds the list length."
  | otherwise     = xs !! (x-1)



------------------------------------------------------------
-- PROBLEM 4
-- Find the number of elements of a list.
length' :: [a] -> Int
length' []  = 0
length' (_:xs) = 1 + length' xs

-- cool solutions
myLength :: [a] -> Int
myLength = sum . map (\_->1)

myLength1 :: [a] -> Int
myLength1 =  foldl (\n _ -> n + 1) 0


------------------------------------------------------------
-- PROBLEM 5
-- reverse a list
reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]

-- cool solutions
myReverse :: [a] -> [a]
myReverse list = reverse'' list []
  where
    reverse'' [] reversed     = reversed
    reverse'' (x:xs) reversed = reverse'' xs (x:reversed)

reverse''' :: [a] -> [a]
reverse''' =  foldl (flip (:)) []


------------------------------------------------------------
-- PROBLEM 6
-- isPalindrome
isPalindrome :: (Eq a) => [a] -> Bool
isPalindrome []     = True
isPalindrome [_]    = True
isPalindrome [x,y]  = if x == y then True else False
isPalindrome (x:xs)
  | (x == (head $ reverse xs)) && (isPalindrome (tail $ reverse xs))  = True
  | otherwise                                                         = False

-- cool solutions
isPalindrome' :: (Eq a) => [a] -> Bool
isPalindrome' []  = True
isPalindrome' [_] = True
isPalindrome' xs  = (head xs) == (last xs) && (isPalindrome' $ init $ tail xs)

-- WTAF?
isPalindromeM :: (Eq a) => [a] -> Bool
isPalindromeM = reverse >>= (==)
