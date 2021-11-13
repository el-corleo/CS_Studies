-- 1.
filterOnes :: [Integer] -> [Integer]
filterOnes xs = filter (== 1) xs

filterOnes' :: [Integer] -> [Integer]
filterOnes' xs = filter (\x -> x == 1) xs

-- 2.
filterANumber :: Integer -> [Integer] -> [Integer]
filterANumber n xs = filter (== n) xs

-- 3.
filterNot :: Eq a => a -> [a] -> [a]
filterNot n xs = filter (/= n) xs

-- 4.
data Client = GovOrg String
            | Company String
            deriving Show

isGovOrg :: Client -> Bool
isGovOrg (GovOrg _) = True
isGovOrg _          = False

clientList = [(GovOrg "Bobo"), (Company "Slobo")]


filterGovOrgs :: [Client] -> [Client]
filterGovOrgs xs = filter (isGovOrg) xs
