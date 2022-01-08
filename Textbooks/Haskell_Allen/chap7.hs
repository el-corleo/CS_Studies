module ChapSeven where

k (x, y) = x
k1 = k ((4-1), 10)
k2 = k ("three", (1+2))
k3 = k (3, True)

f :: (a, b, c) -> (d, e, f) -> ((a, d), (c, f))
f (i, _, k) (x, _, z) = ((i, x), (k, z))

-- Exercises
-- 1. a. k :: (a, b) -> a
--    b. k2 :: [Char]; No
--    c. k3
-- 2. as above


-- case matching
data CryptoWallet = BTC Integer | ETH Integer | SOL Integer deriving (Show)

displayBTCAmount :: CryptoWallet -> Integer
displayBTCAmount (BTC amt) = amt
displayBTCAmount _ = error "Not a BTC wallet."

-- palindrome
pal :: [Char] -> [Char]
pal xs =
  case xs == reverse xs of
    True  -> "Yes"
    False -> "No"

pal' :: [Char] -> [Char]
pal' xs =
  case y of
    True  -> "Yes"
    False -> "No"
  where y = xs == reverse xs

hasMoney :: CryptoWallet -> IO()
hasMoney wallet =
  case wallet of
    BTC amt  -> if amt > 0 then putStrLn "I'm rich!" else putStrLn "Haven't even a pot to piss in."
    ETH amt  -> if amt > 0 then putStrLn "I'm rich!" else putStrLn "Haven't even a pot to piss in."
    SOL amt  -> if amt > 0 then putStrLn "I'm rich!" else putStrLn "Haven't even a pot to piss in."

-- exercises: case practice
-- 1.
funcC x y = if (x > y) then x else y
funcC' x y =
  case x > y of
    True  -> x
    False -> y
-- 2.
ifEvenAdd2 n = if even n then (n + 2) else n
ifEvenAdd2' n =
  case even n of
    True  -> n + 2
    False -> n
-- 3.
nums x =
  case compare x 0 of
    LT -> -1
    GT -> 1
    EQ -> 0
