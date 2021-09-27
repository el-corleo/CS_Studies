-------------------------------------------------------------
-- PROBLEM 31
-- Determine whether a given integer number is prime.
-- NOTE: I know it would be better to only check prime numbers <= floor(sqrt(n))
isPrime :: Int -> Bool
isPrime n =
  let a = floor . sqrt $ fromIntegral n
      b = a - 1
  in foldl (\acc x -> if n `mod` x == 0 then False else acc) True [a, b .. 2]

-- my solution is missing the condition that n > 1


-------------------------------------------------------------
-- PROBLEM 32
-- Determine the greatest common divisor of two positive integer numbers. Use Euclid's algorithm.
myGCD :: Int -> Int -> Int
myGCD 0 b = abs b
myGCD a 0 = abs a
myGCD a b = myGCD b (a `mod` b)


-------------------------------------------------------------
-- PROBLEM 33
-- Determine whether two positive integer numbers are coprime. Two numbers are coprime if their greatest common divisor equals 1.
coprime :: Int -> Int -> Bool
coprime a b = myGCD a b == 1
