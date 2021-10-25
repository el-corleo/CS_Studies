import Control.Monad.Writer

-- Inefficient because it appends lists using ++ poorly
gcdReverse :: Int -> Int -> Writer [String] Int
gcdReverse a b
	| b == 0 = do
			tell ["Finished with " ++ show a]
			return a
	| otherwise = do
			result <- gcdReverse b (a `mod` b)
			tell [show a ++ " mod " ++ show b ++ " = " ++ show (a `mod` b)]
			return result

-- Can use difference lists to make ++ more efficient
newtype DiffList a = DiffList { getDiffList :: [a] -> [a] }

toDiffList :: [a] -> DiffList a
toDiffList xs = DiffList (xs++)

fromDiffList :: DiffList a -> [a]
fromDiffList (DiffList f) = f []

instance Semigroup (DiffList a) where
	(DiffList f) <> (DiffList g) = DiffList (\xs -> f (g xs))

instance Monoid (DiffList a) where
	mempty = DiffList (\xs -> [] ++ xs)
	(DiffList f) `mappend` (DiffList g) = DiffList (\xs -> f (g xs))

gcd' :: Int -> Int -> Writer (DiffList String) Int
gcd' a b
	| b == 0 = do
			tell (toDiffList ["Finished with " ++ show a])
			return a
	| otherwise = do
			result <- gcd' b (a `mod` b)
			tell (toDiffList [show a ++ " mod " ++ show b ++ " = " ++ show (a `mod` b)])
			return result
