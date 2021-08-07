{-
  Project Euler problem 16
  https://projecteuler.net/problem=16



2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
-}

twoToThe1000 = 2^1000

numToList :: Integer -> [Integer]
numToList 0 = []
numToList num = (num `mod` 10) : numToList (num `div` 10)

answer = sum $ numToList twoToThe1000
