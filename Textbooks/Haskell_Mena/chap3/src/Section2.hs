module Section2 where

import Data.List (permutations, subsequence)


permutationsStartingWith :: Char -> String -> [String]
permutationsStartingWith letter = filter (\l -> head l == letter) . permutations

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


-- Function composition with point-free style
--  sidenote: point-free is a math reference as parameters to functions in math are sometimes referred to as 'points'
duplicateOdds list = map (*2) $ filter odd list
-- this is functionally equivalent to the point-free composed function
duplicateOdds' = map (*2) . filter odd
