-- To compile a Haskell Program
-- $ ghc --make <filename>
import Data.Char

-- main = putStrLn "Hello, World!"

-- main = do
	-- putStrLn "Hi, what's your name?"
	-- name <- getLine
	-- putStrLn ("Hi " ++ name ++ ", how are you?")

-- main = do
	-- putStrLn "First Name: "
	-- firstName <- getLine
	-- putStrLn "Last Name: "
	-- lastName <- getLine
	-- let upperFirstName 	= map toUpper firstName
	-- let upperLastName 	= map toUpper lastName
	-- putStrLn $ 	"Hey, " ++ upperFirstName ++ " "
											-- ++ upperLastName ++ " "
											-- ++ ", how are you?"

main = do
	line <- getLine
	if null line
		then return ()
		else do
			putStrLn $ reverseWords line
			main

reverseWords :: String -> String
reverseWords = unwords . map reverse . words
