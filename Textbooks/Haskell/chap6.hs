import Data.Char
import Data.List 
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


-- foldl can cause stack overflow
--		according to the book 1000000 would be enough, but for me it wasn't
--		foldl' from the Data.List module is supposed to fix this
exSO = foldl (+) 0 (replicate 100000000000 1)
exSO' = foldl' (+) 0 (replicate 1000000000 1)
