-- apparently this is a fine way to define a general infix operator for functions
x -: f = f x

-- This is syntax for writing the parameter before the function
threeHundred = 100 -: (*3)

thisIsFalse = True -: not

-- Using the birds landing on pole example
type Birds = Int
type Pole = (Birds, Birds)

landLeft :: Birds -> Pole -> Maybe Pole
landLeft n (left, right)
	| abs((left + n) - right) < 4 = Just (left + n, right)
  | otherwise										= Nothing

landRight :: Birds -> Pole -> Maybe Pole
landRight n (left, right)
	| abs(left - (right + n)) < 4 = Just (left, right + n)
  | otherwise										= Nothing

-- Suitable when not returning maybes:
-- birdsOnPole = (0, 0) -: landLeft 1 -: landRight 1 -: landLeft 2
-- Otherwise, must use monad bind operator to chain
balancedBirdsOnPole = landLeft 1 (0,0) >>= landRight 1 >>= landLeft 2
unbalancedBirdsOnPole = landLeft 1 (0,0) >>= landRight 4 >>= landLeft (-1) >>= landRight (-4)


-- do notation helps us avoid having to write out chained lambdas
foo :: Maybe String
foo = Just 3 >>= (\x -> Just "!" >>= (\y -> Just (show x ++ y)))
-- the above is equivalent to the following
foo' :: Maybe String
foo' = do
  x <- Just 3
  y <- Just "!"
  Just (show x ++ y)

-- "If any of the values that we try to extract from are Nothing, the whole do expression will result in a Nothing."
-- "When to use do notation and when to explicitly use >>= is up to you."
