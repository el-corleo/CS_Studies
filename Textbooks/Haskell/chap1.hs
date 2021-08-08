-- Comment
{-
	Multiline comment
-}

import Data.List
import System.IO

-- Int: min=-2^63; max=2^63
maxInt = maxBound :: Int
minInt = minBound :: Int

-- Integer: an unbounded whole number (as big as memory can hold)
-- Float: single-precision floating point
-- Double: double-precision floating point (up to 11 decimal places)
bigDouble = 3.99999999999 + 0.00000000005
brokenBigDouble = 3.999999999999 + 0.000000000005

-- Bool
boolean = True

-- Char
character = 'c'

-- Tuple
tup = (3, 2)

-- immutable
always5 :: Int
always5 = 5

{- 
	always5 = 6
	
	error: Multiple declarations of 'always5'
-}

-- sum is a built-in function
-- [1..100] populates a list of numbers from 1 to 100
sumOfNums = sum [1..100]
mod_5_4 = mod 5 4       -- prefix operator
alt_mod_5_4 = 5 `mod` 4 -- infix operator
neg_add = 5 + (-4)      -- requires parentheses

-- sqrt :: Floating a => a -> a
-- fromIntegral is a cast from Int to Float
num9 = 9 :: Int
sqrtOf9 = sqrt (fromIntegral num9)

-- In-built math functions
piVal = pi
epow9 = exp 9
logOf9 = log 9    -- natural log (i.e., ln)
is9 = log (exp 9)
squared9 = 9 ** 2
truncated = truncate 9.999
rounded = round 9.999
ceilinged = ceiling 9.999
floored = floor 9.999
minOfThese = min 9 10
maxOfThese = max 9 10
-- more:
-- sin, cos, tan, asin, acos, atan, sinh, cosh, tanh, asinh, acosh, atanh

-- Logical operators
andOp = True && False
orOp = True || False
notOp = not True
equals = 5 == 5
notEquals = 5 /= 4

-- Lists: singly-linked data structures
primes = [3, 5, 7, 11]
thirdElem = primes !! 2                 -- Lists are zero-indexed
firstElem = head primes
remainingElems = tail primes
lastElem = last primes
allButLastElem = init primes
morePrimes = primes ++ [13, 17, 19]     -- Note the ++ for concatenation
lastPrime = morePrimes ++ [23]          -- Must wrap 23 in brackets to act like a list
colonForm = 3 : 5 : 7 : 11 : []         -- Creates a list like primes
multiDimList = [[2, 3, 5], [7, 11, 13]]
primesExtended = 2 : morePrimes         -- can only append to front of list
lenPrimes = length primes
lenPrimesExt = length primesExtended
nullCheck = null []
nullCheck' = null primes
invert = reverse primes
listOfOnlyFirstTwoElems = take 2 primes
listWithoutFirstTwoElems = drop 2 primes                     -- lists are immutable so doesn't actually change primes, just creates a new list without the first x elems
maxNum = maximum primes
minNum = minimum primes
prodOfPrimes = product primes
sumOfPrimes = sum primes
inList = 4 `elem` primes								-- Check for membership
letters = ['a'..'z']
letters' = ['K'..'P']
stepBy3 = [3,6..90]
down = [20,19..1]                       -- Must list second number when going down
infiniteList = take 24 [13,26..]        -- No upper bound; Haskell's lazy execution means it only generates as many elements as are needed
firstThree = [1,2,3]
cycles = take ((length firstThree) * 10) (cycle firstThree)
cycles' = take (((length firstThree) * 10) - 1) (cycle firstThree)
repetition = take 10 (repeat 'a')
listComp = [ 2 * x | x <- [1..10]]      -- Set builder notation inspired syntax
listComp' = [ 2 * x | x <- [1..10], x < 5 && x*2 > 4]     
listCompRedux = [ 2 * x | x <- [1..10], x < 5, x*2 > 4]     
fizzBuzz = [if (x `mod` 5 == 0 && x `mod` 3 == 0) then "FIZZBUZZ"
            else if (x `mod` 5 == 0) then "FIZZ"
            else if (x `mod` 3 == 0) then "BUZZ"
            else "" | x <- [1..100]]
listComb = [ x + y | x <- [1, 2, 3], y <- [2, 4, 6]]  -- [1+2, 1+4, 1+6, 2+2...] 
listComb' = [ x + y | x <- [1, 2, 3], y <- [2, 4, 6, 8]]
length' xs = sum [ 1 | _ <- xs]
xxs = [[1,3,5,2,3,1,2,4,5],[1,2,3,4,5,6,7,8,9],[1,2,4,2,1,6,3,1,3,2,3,6]]
nestedListComp = [ [ x | x <- xs, even x ] | xs <- xxs]

-- Custom functions
multiply :: (Num a) => a -> a -> a
multiply x y = x * y
toThePower x y = x ** y

-- Functions composed of other functions
increment :: (Num a) => a -> a
increment x = x + 1
incThenMult :: (Num a) => a -> a -> a
incThenMult x y = (increment x) * y

-- Conditional functions
-- else is REQUIRED when using if
doubleIfSmall x = if x < 10
                   then x * 2
                   else x
inlineDoubleIfSmall x = if x < 10 then x * 2 else x

-- Comparisons
lessThan = [1, 2, 3] < [2, 3, 4]
lessThanClose = [1, 2, 3] < [1, 1, 3]
diffFrom = "bug" /= "buggy"

-- Tuples are heterogeneous; whereas, Lists are homogeneous
-- Tuples are of fixed size; whereas, Lists are singly-linked
tupHomo = (1, 2)
tupHetero = (3, "monkeys")
tupList = [(1, 2), (3, 4)]    -- Note that since lists are homogenous, you can't have tuples of different sizes or different compositions, e.g., [(1, 2), (3, 4, 5)] and [(1, 2), ('a'', 'b')]
firstTupElem = fst tupHomo
secondTupElem = snd tupHomo   -- Only work on pairs
list1 = [1 .. 5]
list2 = ['e', 'd' .. 'a']
zippedList = zip list1 list2
list3 = [1 ..]
list4 = ['a' .. 'g']
zippedList' = zip list3 list4 -- will only produce pairs up to length on smallest list


{- 
    Practical example

	Find a right triangle where:
	   - All side lengths are integers
	   - All side lengths are <= 10
	   - All sides add up to 24
-}
-- my attempt
rightTri :: (Eq a, Floating a) => a -> a -> a -> Bool
rightTri x y z = ((x ** 2) + (y ** 2)) == (z ** 2)
candidates = [(x, y, z) | x <- [1 .. 10 ], y <- [1 .. 10], z <- [1 .. 10], (x + y + z ) == 24, (rightTri x y z) ]

-- Book solution
bookSolution = [(a, b, c) | c <- [1 .. 10 ], a <- [1 .. c], b <- [1 .. a], a^2 + b^2 == c^2, a+b+c == 24 ]















