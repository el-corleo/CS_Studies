map' :: (a -> b) -> [a] -> [b]
map' f = foldr ((:) . f) []

length' :: [a] -> Int
length' = foldr (const $ (+) 1) 0
