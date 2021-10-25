import Data.Char
import Data.List


-- "...functors are things that can be mapped over, like lists, Maybes, and trees."

main = do line <- fmap reverse getLine
					putStrLn $ "You said " ++ line ++ " backwards."

-- "If you ever find yourself binding the result of an I/O action to a name, only to apply a function to that and call that something else, consider using fmap."
-- "If you want to apply multiple functions to some data inside a functor, you can declare your own function at the top level, make a lambda function, or, ideally, use function composition"

main = do line <- fmap (intersperse '-' . reverse . map toUpper) getLine
					putStrLn line

-- "It’s not very important that you get how the (->) r instance for Applicative works, so don’t despair ifyou don’t understand this all right now."
-- 	Praise Jeebus, because I have absolutely no clue what the hell this whole chap is about
-- 	Methinks it won't click until my second Haskell book
