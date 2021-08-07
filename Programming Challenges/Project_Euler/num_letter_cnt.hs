{-
  Project Euler Problem 17
  https://projecteuler.net/problem=17



If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

-}
-- letters in each word
numLetterOneToNine = [3, 3, 5, 4, 4, 3, 5, 5, 4]
numLettersTwentyToNinety = [6, 6, 5, 5, 5, 7, 6, 6]
numLettersElevenToNineteen = [6, 6, 8, 8, 7, 7, 9, 8, 8]

listTimesScalar :: Int -> [Int] -> [Int]
listTimesScalar scalar nums = map (*scalar) nums

-- +3 is for "ten"
sum1To99 = (sum numLetterOneToNine) + 3 + (sum numLettersElevenToNineteen) + (sum $ listTimesScalar 10 numLettersTwentyToNinety) + (sum $ listTimesScalar 8 numLetterOneToNine)

-- 3 * 990 is for "and"; 7 * 9 * 100 is for "hundred"; 3 * 9 is for "ten"; 3 + 8 is for "one thousand"
sum100To999 = (3 * 891) + (sum $ listTimesScalar 100 numLetterOneToNine) + (7 * 9 * 100) + (sum $ listTimesScalar 90 numLettersTwentyToNinety) + (3 * 9) + (sum $ listTimesScalar 9 numLettersElevenToNineteen) + (sum $ listTimesScalar 81 numLetterOneToNine) + (3 + 8)


answer = sum1To99 + sum100To999
