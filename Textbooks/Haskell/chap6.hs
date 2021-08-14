import qualified Data.Map as Map
import           Data.Char
import           Data.List
-- To import only specific functions:
-- 		import Data.List (nub, sort)
-- To import all except for some specific functions:
-- 		import Data.List hiding (nub, sort)
-- To import methods that would clash with methods in the current module:
-- 		import qualified Data.List as DL


-- functions from Data.List
numUniques :: (Eq a) => [a] -> Int
numUniques = length . nub


sentence :: String
sentence = "there are many words in this string aren't there"
wordsOfSentence = words sentence
sortedWords = sort wordsOfSentence
groupedWordsOfSentence = group sortedWords
numUniqueWords = numUniques groupedWordsOfSentence


numWords :: String -> [(String, Int)]
numWords = map (\ws -> (head ws, length ws)) . group . sort . words


-- finding substring
exTails = tails "party"
exIsPrefixOf = "hell" `isPrefixOf` "hello"

isIn :: (Eq a) => [a] -> [a] -> Bool
needle `isIn` haystack = any (needle `isPrefixOf`) (tails haystack)


-- ceaser cipher
aUni = ord 'a'
char97 = chr 97
encode :: Int -> String -> String
encode offset msg = map (\c -> chr $ ord c + offset) msg

decode :: Int -> String -> String
decode offset msg = map (\c -> chr $ ord c - offset) msg
-- book version
decode' :: Int -> String -> String
decode' shift msg = encode (negate shift) msg


-- Apropos ciphers, how about El Gamal?
elGamal :: Int -> Int -> Int -> Int
elGamal x y z = x^y `mod` z

base = 5
n = 13

keyGen :: Int -> Int
keyGen y = elGamal base y n

alice_pub_key = keyGen 6
bobo_pub_key = keyGen 7
bobo_secret_msg = 13 + (keyGen $ keyGen (alice_pub_key * 7))
decrypted_msg = bobo_secret_msg - (keyGen $ keyGen (bobo_pub_key * 6))




-- foldl can cause stack overflow
--		according to the book 1000000 would be enough, but for me it wasn't
--		foldl' from the Data.List module is supposed to fix this
exSO = foldl (+) 0 (replicate 100000000000 1)
exSO' = foldl' (+) 0 (replicate 1000000000 1)


-- first natural number such that the sum of its digits equals 40
-- my attempt
splitDigits :: Int -> [Int]
splitDigits 0 = []
splitDigits x = (x `mod` 10) : splitDigits (x `div` 10)

sumDigits :: Int -> Int
sumDigits x = sum $ splitDigits x

findNumSumsTo :: Int -> Int
findNumSumsTo limit = head [x | x <- [9999..], (sumDigits x) == limit]


-- book version
-- Uses find function from Data.List
-- 		find :: (a -> Bool) -> [a] -> Maybe a
-- 		Maybe type is of either size 0 or size 1
-- 		returns Nothing or Just a
digitSum :: Int -> Int
digitSum = sum . map digitToInt . show

firstTo40 :: Maybe Int
firstTo40 = find (\x -> digitSum x == 40) [1..]


-- Lookup
phoneBook = [
    ("bobo", "1"),
    ("boba", "2"),
    ("bobi", "3"),
    ("bobu", "4"),
    ("bobe", "5")
    ]

-- throws RuntimeError if key not in list
findKey :: (Eq k) => k -> [(k, v)] -> v
findKey key xs = snd . head . filter (\(k,v) -> key == k) $ xs

-- better version
findKey' :: (Eq k) => k -> [(k, v)] -> Maybe v
findKey' key [] = Nothing
findKey' key ((k, v):xs)
    | key == k  = Just v
    | otherwise = findKey' key xs

-- as a fold
findKey'' :: (Eq k) => k -> [(k, v)] -> Maybe v
findKey'' key xs = foldr (\(k, v) acc -> if key == k then Just v else acc) Nothing xs


-- fromList :: (Ord k) => [(k, v)] -> Map.Map k v
phoneBookMap = Map.fromList $ phoneBook


-- Map.lookup :: (Ord k) => k -> Map.Map k a -> Maybe a
-- Map.insert :: (Ord k) => k -> Map.Map k a -> Map.Map k a
-- Map.size :: Map.Map k a -> Int


-- Map.fromListWith
addValues = Map.fromListWith (+) [(1, 2), (1, -2), (2, 0), (3, 1), (3, -1)]


{-
   - Modules

    "However, Geometry.hs must be in the same folder as the module that’s
    importing it." <- There has to be some packaging system, I guess?

   Example:

   module Geometry3D
   ( sphereVolume,
     sphereArea,
     cubeVolume,
     cubeArea,
     cuboidVolume,
     cuboidArea
     -- All of the functions exported for external use (i.e., public functions)
   ) where

    sphereVolume :: Float -> Float
    sphereVolume r = (4.0/3.0) * pi * (r^3)

    sphereArea :: Float -> Float
    sphereArea r = 4 * pi (r^2)

    cubeVolume :: Float -> Float
    cubeVolume s = cuboidVolume s s s

    cubeArea :: Float -> Float
    cubeArea s = cuboidArea s s s

    cuboidVolume :: Float -> Float -> Float -> Float
    cuboidVolume l w h = (rectArea l w) * h

    cuboidArea :: Float -> Float -> Float -> Float
    cuboidArea l w h = (rectArea l w) * 2 + (rectArea w h) * 2 + (rectArea h l) * 2

    rectArea :: Float -> Float -> Float
    rectArea l w = l * w

-}

{-
   Heirarchical Modules

   - Geometry3D
        |
        | Sphere
        | Cuboid
        | Cube


    ...

    module Geometry3D.Cuboid
    ( volume,
      area
    ) where

    volume :: Float -> Float -> Float -> Float
    volume l w h = (rectArea l w) * h

    ...

    module Geometry3D.Cube
    ( volume,
      area
    ) where

    import qualified Geometry3D.Cuboid as Cuboid

    volume :: Float -> Float
    volume s = Cuboid.volume s s s

    ...

    "If we want to juggle two or more of these modules, we need to do qualified imports because they export functions with the same names."
-}
