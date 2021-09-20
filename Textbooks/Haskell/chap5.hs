-- Curried functions are functions that take only a single parameter as input and return a function that takes a single input
is5     = max 4 5
isAlso5 = (max 4) 5 -- max actually only takes one parameter

-- book example
-- NOTE: Parentheses in definition are optional
-- notice that the type on the left is the parameter and the one on the right is the return value
-- Thus, mult3 takes an Int and returns a function that takes an Int and returns a function that takes an Int and returns an Int
mult3 :: Int -> (Int -> (Int -> Int))
mult3 x y z = x * y * z

result  = mult3 2 3 4
result' = ((mult3 2) 3) 4
areSame = result == result'


-- function composition
-- QUESTION: why don't we need to specify inputs for mult2With9? Shouldn't it be mult2With9 x y = mult3 9 x y?
-- If you read the above example, you'll see that similarly mult2With9 only takes one input but returns a function that takes another input
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
-- The below is functionally equivalent to the much uglier:
lD = head (filter (\x -> x `mod` 3829 == 0) [100000, 99999..])
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
addThree x y z = x + y + z

addThree' :: Int -> Int -> Int -> Int
addThree' = (\x -> (\y -> (\z -> x + y + z)))


-- Traversing lists with folds
sum' :: [Int] -> Int
sum' xs = foldl (\acc x -> acc + x) 0 xs

sum'' :: [Int] -> Int
sum'' = foldl (+) 0


-- NOTE: "Generally, if you have a function like foo a = bar b a, you can rewrite it as foo = bar b because of currying."


-- experiment
--      first elems are subtracted from 0 and thus result in a negative value when the elem is positive
minusL :: [Int] -> Int
minusL = foldl (-) 0
minusR :: [Int] -> Int
minusR = foldr (-) 0


-- On using foldr to build new lists: "However, the ++ function is much slower than :, so we usually use right folds when we’re building up new lists from a list. One big difference between the two types of folds is that right folds work on infinite lists, whereas left ones don’t!"

-- implement elem using foldr
-- my attempt: FAILURE
--elem' :: a -> [a] -> Bool
--elem' x xs = foldr (\j k -> j == k) x xs

-- book
-- "Remember that the type of the accumulator value and the type of the end result are always the same when dealing with folds."
elem' :: (Eq a) => a -> [a] -> Bool
elem' y ys = foldr (\x acc -> if x == y then True else acc) False ys
-- QUESTION: why is the acc the second parameter instead of the first in the lambda?!?

-- other functions re-implemented with folds
reverse' :: [a] -> [a]
reverse' = foldl (\acc x -> x : acc) []

reverse'' :: [a] -> [a]
reverse'' = foldl (flip (:)) []
-- reverse''' = foldr (flip (:)) [] -- impossible because could possibly be infinite

product' :: (Num a) => [a] -> a
product' = foldl (\x acc -> x * acc) 1
-- QUESTION: same as above, why is the accumulator the second parameter?

filter'' :: (a -> Bool) -> [a] -> [a]
filter'' p = foldr (\x acc -> if p x then x : acc else acc) []


-- $
-- "You can imagine $ as almost being the equivalent of writing an opening parenthesis and then writing a closing parenthesis on the far right side of the expression."
this       = sum (map sqrt [1..130])
sameAsThis = sum $ map sqrt [1..130]

that         = sqrt 3 + 4 + 9   -- sqrt 3 + (4 + 9)
diffFromThat = sqrt $ 3 + 4 + 9 -- sqrt (3 + 4 + 9)

-- applies all operations to 3 and stores them in a list
whoa = map ($ 3) [(4+), (5*), (10/), (^2), sqrt]


-- function composition f ( g (x))
funcComp = map (negate . abs) [5, -3, -6, 7]
funcComp' = map (negate . sum . tail) [[1..5], [-3..6], [1..7]]

equiv   = sum (replicate 5 (max 6.7 8.9))
equiv'  = (sum . replicate 5) (max 6.7 8.9)
equiv'' = sum . replicate 5 $ max 6.7 8.9


sameAsBelow = replicate 2 (product (map (*3) (zipWith max [1,2] [4,5])))
sameAsAbove = replicate 2 . product . map (*3) $ zipWith max [1,2] [4,5]


-- Point-free style
-- A note on style: "However, if a function is too complex, writing it in point-free style can actually be less readable. For this reason, making long chains of function composition is discouraged. The preferred style is to use let bindings to give labels to intermediary results or to split the problem into subproblems that are easier for someone reading the code to understand."
fn x = ceiling (negate (tan (cos (max 50 x))))
fn' = ceiling . negate . tan . cos . max 50

