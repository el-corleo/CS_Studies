-- To compile a Haskell Program
-- $ ghc --make <filename>
import Data.Char
import Control.Monad

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

-- main = do
	-- line <- getLine
	-- if null line
		-- then return ()
		-- else do
			-- putStrLn $ reverseWords line
			-- main
--
-- reverseWords :: String -> String
-- reverseWords = unwords . map reverse . words

-- from Control.Monad we get 'when'
-- main = do
	-- input <- getLine
	-- when (input == "SWORDFISH") $ do
		-- putStrLn input

-- sequence takes a sequence of IO actions and stores them in a variable
-- main = do
	-- rs <- sequence [getLine, getLine, getLine]
	-- print rs
	-- -- another example of how to use it is when mapping functions over lists
	-- sequence $ map print [1,2,3,4]

main = do
	colors <- forM [1,2,3,4] (\a -> do
		putStrLn $ "What color do you associate with " ++ show a ++ "?"
		color <- getLine
		return color)
	putStrLn "Colors for 1,2,3,4:"
	mapM putStrLn colors
