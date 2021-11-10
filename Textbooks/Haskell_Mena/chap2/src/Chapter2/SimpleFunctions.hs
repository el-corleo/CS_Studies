module Chapter2.SimpleFunctions where

firstOrEmpty :: [[Char]] -> [Char]
firstOrEmpty lst = if not (null lst) then head lst else "empty"

(+++) :: [a] -> [a] -> [a]
lst1 +++ lst2 = if null lst1
                then lst2
                else (head lst1) : (tail lst1 +++ lst2)

reverse2 :: [a] -> [a]
reverse2 list = if null list
                then []
                else reverse2 (tail list) +++ [head list]

-- Algebraic Data Types are abbreviated ADT, because Haskell cares not that there is already
-- a commonly used term (Abstract Data Type) that uses that acronym already
data Client = GovOrg      String
            | Company     String Integer String String
            | Individual  Person Bool
            deriving (Show)

data Person = Person String String Gender
            deriving (Show)

-- can be used akin to Enums
data Gender = Male | Female | Unspecified deriving (Show)


data TimeMachine = TimeMachine Manufacturer Model Name TravelFunctions Price deriving (Show)

type Manufacturer = String
type Model = Integer
type Name = String
data TravelFunctions = Past | Future | PastAndFuture deriving (Show)
type Price = Integer


-- Ackermann Function
ackermann :: Integer -> Integer -> Integer
ackermann m n
  | m == 0            = n + 1
  | m > 0 && n == 0   = ackermann (m-1) 1
  | m > 0 && n > 0    = ackermann (m-1) $ ackermann m (n-1)

-- unzip function
unzip' :: [(a, b)] -> ([a], [b])
unzip' xs = ([x | (x,y) <- xs], [y | (x,y) <- xs])
