-- dealing with input redirection (e.g., reading from a .txt file)
import Control.Monad
import Data.Char
import System.IO

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
-- main = interact respondPalindrome
--
-- respondPalindrome :: String -> String
-- respondPalindrome =
	-- unlines .
	-- map (\xs -> if isPal xs then "palindrome" else "is not palindrome") .
	-- lines
--
-- isPal :: String -> Bool
-- isPal []			= True
-- isPal [x]			= True
-- isPal (x:xs)	= x == (head $ reverse xs) && isPal (init xs)

-- book version of isPal
-- isPal :: String -> Bool
-- isPal xs = xs == reverse xs


-- reading a file from stdin
main = do
	handle <- openFile "randFile.txt" ReadMode
	contents <- hGetContents handle
	putStr contents
	hClose handle

-- "Just like getContents, hGetContents won’t attempt to read all the file at
-- once and store it in memory but will read the content only as needed."
	-- Thought: so does this make it good for data processing tasks?
	-- Another thought: since it appears to read from disk, would this make it really slow?

-- "Note the difference between a handle and the actual contents of the file. A handle just points to our current position in the file. The contents are what’s actually in the file."



