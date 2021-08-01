-- Curried functions are functions that take only a single parameter as input and return a function that takes a single input
is5     = max 4 5
isAlso5 = (max 4) 5 -- max actually only takes one parameter 

-- book example
-- NOTE: Parentheses in definition are optional
-- notice that the type of the left is the parameter and the one on the right is the return value
-- Thus, mult3 takes an Int and returns a function that takes an Int and returns a function that takes an Int and returns an Int
mult3 :: Int -> (Int -> (Int -> Int))
mult3 x y z = x * y * z

result  = mult3 2 3 4
result' = ((mult3 2) 3) 4
areSame = result == result'


-- function composition
-- QUESTION: why don't we need to specify inputs for mult2With9? Shouldn't it be mult2with9 x y = mult3 9 x y?
mult2With9 :: Int -> (Int -> Int)
mult2With9 = mult3 9

result'' = mult2With9 8 3


-- Sections
-- NOTE: that negative numbers are an exception:
--    if you wish to subtract using sections, it should be (subtract 4) and NOT (-4)
divideBy10 :: (Floating a) => a -> a
divideBy10 = (/10)

divided   = divideBy10 90
divided'  = 90 / 10
divided'' = (/10) 90

areSame' = divided == divided' && divided == divided''


-- Higher order functions: functions that take other functions as parameters and/or return a function
-- Parentheses are mandatory here as the first parameter is a function that takes in a parameter a and returns something of the same type
applyTwice :: (a -> a) -> a -> a
applyTwice f x = f (f x)

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys

flip' :: (a -> b -> c) -> (b -> a -> c)
flip' f = g
    where g x y = f y x

flipSimpler :: (a -> b -> c) -> (b -> a -> c)
flipSimpler f x y = f y x

-- built-in functions (I wrote them down and thus needed the ')
map' :: (a -> b) -> [a] -> [b]
map' _ [] = []
map' f (x:xs) = f x : map' f xs

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' p (x:xs)
    | p x       = x : filter' p xs
    | otherwise = filter' p xs

-- quicksort (again)
-- the book claims this is more 'readable' than the list comprehension version; I disagree; set-builder notation is much more readable in my opinion
quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = 
    let smallerOrEqual = filter (<= x) xs
        larger         = filter (> x) xs
    in quicksort smallerOrEqual ++ [x] ++ quicksort larger

-- largest number under 100,000 divisible by 3829
-- by using head, we guarantee that Haskell stops evaluating after finding the first value, hence being able to use the infinite list
largestDivisor = head (filter p [100000, 99999..])
    where p x = x `mod` 3829 == 0

-- sum of all odd squares under 10000
-- my attempt [mine is infinite and can only be fixed by putting an upper bound on the list [1..], e.g., [1..100] 
sumOfOddSq = sum [x^2 | x <- [1..], odd (x^2) && (x^2) < 10000]

-- book
sumOfOddSq' = sum (takeWhile (<10000) (filter odd (map (^2) [1..])))
-- better version of my attempt
sumOfOddSq'' = sum (takeWhile (<10000) [m | m <- [n^2 | n <- [1..]], odd m])


-- Collatz chain length
chain :: Integer -> [Integer]
chain 1 = [1]
chain n
    | even n = n : chain (n `div` 2)
    | odd n  = n : chain (n * 3 + 1)

numLongChains :: Int
numLongChains = length (filter isLong (map chain [1..100]))
    where isLong xs = length xs > 15 


-- lambda functions
-- easy to abuse if we don't understand currying
-- e.g., map (+3) [1, 2, 3] is equivalent to map (\x -> x + 3) [1, 2, 3]
-- Also: "If a pattern match fails in a lambda, a runtime error occurs, so be careful!"
numLongChains' :: Int
numLongChains' = length (filter (\xs -> length xs > 15) (map chain [1..100])) 

anotherExample = zipWith (\a b -> (a * 30 - 3) / b) [5, 4, 3] [3, 4, 5]

-- anotherEquivalence
addThree :: Int -> Int -> Int -> Int
addThree x y z = x + y +z

addThree' :: Int -> Int -> Int -> Int
addThree' = \x -> \y -> \z -> x + y + z



