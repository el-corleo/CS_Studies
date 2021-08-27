-- dealing with input redirection (e.g., reading from a .txt file)
import Control.Monad
import Data.Char

-- main = forever $ do
	-- l <- getLine
	-- putStrLn $ map toUpper l

-- does the same as above
-- main = do
	-- contents <- getContents
	-- putStr $ map toUpper contents

-- main = do
	-- contents <- getContents
	-- putStr (shortLinesOnly contents)
--
-- shortLinesOnly :: String -> String
-- shortLinesOnly = unlines . filter (\line -> length line < 10) . lines

-- interact takes a function that takes a string from input and returns a string
-- main = interact longLinesOnly
--
-- longLinesOnly :: String -> String
-- longLinesOnly = unlines . filter (\line -> length line > 10) . lines

-- Check if is palindrome
main = interact respondPalindrome

respondPalindrome :: String -> String
respondPalindrome =
	unlines .
	map (\xs -> if isPal xs then "palindrome" else "is not palindrome") .
	lines

isPal :: String -> Bool
isPal []			= True
isPal [x]			= True
isPal (x:xs)	= x == (head $ reverse xs) && isPal (init xs)

-- book version of isPal
-- isPal :: String -> Bool
-- isPal xs = xs == reverse xs
