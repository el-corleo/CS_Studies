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
toientImproved :: Int -> Int
toientImproved m = foldl (\acc (p,x) -> acc * ((p-1) * p ^ (x-1))) 1 $ primeFactorsMult m


-- website solution
--  Nice use of list comprehension & product function
totientImproved' m = product [(p - 1) * p ^ (c - 1) | (p, c) <- primeFactorsMult m]


-------------------------------------------------------------
-- PROBLEM 39
-- A list of prime numbers.
-- Given a range of integers by its lower and upper limit, construct a list of all prime numbers in that range.
primesR :: Int -> Int -> [Int]
primesR lo hi
  | lo > hi  = error "Impossible range."
  | lo == hi = []
  | otherwise = takeWhile (\n -> n <= hi && n >= lo) primeNums
  where primeNums = [ x | x <- [lo..hi], isPrime x ]


-- website
primesR' :: Integral a => a -> a -> [a]
primesR' a b = takeWhile (== b) $ dropWhile (< a) $ sieve [2..]
  where sieve (n:ns) = n:sieve [ m | m <- ns, m `mod` n /= 0 ]

-- primesR'' :: Integral a => a -> a -> [a]
primesR'' :: Int -> Int -> [Int]
primesR'' a b
  | even a = filter isPrime [a+1,a+3..b]
  | True   = filter isPrime [a,a+2..b]


-------------------------------------------------------------
-- PROBLEM 40
-- Goldbach's conjecture says that every positive even number greater than 2 is the sum of two prime numbers. Example: 28 = 5 + 23. It is one of the most famous facts in number theory that has not been proved to be correct in the general case. It has been numerically confirmed up to very large numbers. Write a predicate to find the two prime numbers that sum up to a given even integer.

-- subtract first prime from n, if result is prime, you found your answer
goldbach :: Int -> (Int, Int)
goldbach n = summands primes n
  where summands (x:xs) n
          | (n `mod` 2) /= 0  = error "Invalid input."
          | x > (n-2)         = error "Goldbach was wrong."
          | isPrime (n-x)     = (x, n-x)
          | otherwise         = summands xs n


-------------------------------------------------------------
-- PROBLEM 41
-- Given a range of integers by its lower and upper limit, print a list of all even numbers and their Goldbach composition.
--
-- In most cases, if an even number is written as the sum of two prime numbers, one of them is very small. Very rarely, the primes are both bigger than say 50. Try to find out how many such cases there are in the range 2..3000.
goldbachList :: Int -> Int -> [(Int, Int)]
goldbachList lo hi
  | lo > hi                       = []
  | (lo `mod` 2 /= 0) || lo <= 2  = goldbachList (lo+1) hi
  | (hi `mod` 2 /= 0)             = goldbachList lo (hi-1)
  | otherwise                     = goldbach lo : goldbachList (lo+2) hi

goldbachSummandsBothLarge :: Int -> Int -> Int -> Int
goldbachSummandsBothLarge lo hi lim =
  length . filter (\(x,y) -> x > lim && y > lim) $ goldbachList lo hi

-- website answer
goldbachList' n m = map goldbach $ dropWhile (<4) $ filter even [n..m]

