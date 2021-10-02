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


-------------------------------------------------------------
-- PROBLEM 34
-- Calculate Euler's totient function phi(m).
-- Euler's so-called totient function phi(m) is defined as the number of positive integers r (1 <= r < m) that are coprime to m.
--
-- Example: m = 10: r = 1,3,7,9; thus phi(m) = 4. Note the special case: phi(1) = 1.
totient :: Int -> Int
totient 1 = 1
totient m = length $ filter (\x -> coprime m x) [1..(m-1)]


-------------------------------------------------------------
-- PROBLEM 35
-- Determine the prime factors of a given positive integer. Construct a flat list containing the prime factors in ascending order.
-- borrowed primes generator: https://stackoverflow.com/questions/63596587/generating-finite-lists-of-primes-in-haskell
primes = sieve [2..]
sieve (p : xs) = p : sieve [ x | x <- xs, x `mod` p > 0  ]

primeFactors :: Int -> [Int]
primeFactors x = primeFactors' x primes
  where
    primeFactors' 1 _ = []
    primeFactors' x (n:ns)
      | isPrimeFactor x n = n : primeFactors' (x `div` n) (n:ns)
      | otherwise         = primeFactors' x ns
      where isPrimeFactor x n = x `mod` n == 0


-- can do with where:
-- primeFactors x  = primeFactors' x 2
--  where
--    primeFactors' 1 _ = []
--    primeFactors' n f
--      | n`mod` f == 0 = f : primeFactors' (n `div` f) f
--      | otherwise     = primeFactors' n (f+1)
--
-- But this solution from the website tries non-prime numbers unnecessarily


-------------------------------------------------------------
-- PROBLEM 36
-- Determine the prime factors of a given positive integer. Construct a list containing the prime factors and their multiplicity.
primeFactorsMult :: Int -> [(Int, Int)]
primeFactorsMult n =
  let xs = primeFactors n
  in zip xs (countFactors xs)
    where
      countFactors [] = []
      countFactors (ys) = (length (takeWhile (head ys ==) ys)) : (countFactors (dropWhile (head ys ==) ys))



-------------------------------------------------------------
-- PROBLEM 37
-- Calculate Euler's totient function phi(m) (improved).
