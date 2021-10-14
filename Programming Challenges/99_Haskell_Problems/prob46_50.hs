import Control.Monad (replicateM)
-------------------------------------------------------------
-- PROBLEM 46
-- Define predicates and/2, or/2, nand/2, nor/2, xor/2, impl/2 and equ/2 (for logical equivalence) which succeed or fail according to the result of their respective operations; e.g. and(A,B) will succeed, if and only if both A and B succeed.
--
-- A logical expression in two variables can then be written as in the following example: and(or(A,B),nand(A,B)).
--
-- Now, write a predicate table/3 which prints the truth table of a given logical expression in two variables.
logAnd :: Bool -> Bool -> Bool
logAnd a b = a && b

logOr :: Bool -> Bool -> Bool
logOr a b = a || b

logXor :: Bool -> Bool -> Bool
logXor a b = (a && not b) || ((not a) && b)

logNand :: Bool -> Bool -> Bool
logNand a b = not (a && b)

logEqu :: Bool -> Bool -> Bool
logEqu a b = a == b

-- table I couldn't figure out by myself
--   My explanation of the answer:
--    - Take a function that takes two bools and spits out a bool as input
--    - Spit out an IO() as output
--    - putStrLn prints everything out
--    - concatMap add a "\n" to each line
--    - a list comprehension creates every possible permutation of True and False for a and b and adds the result of passing them through the chosen function
table :: (Bool -> Bool -> Bool) -> IO()
table f = putStrLn $ concatMap (++ "\n")
          [show a ++ " " ++ show b ++ " " ++ show (f a b)
            | a <- [True, False], b <- [True, False]]


-------------------------------------------------------------
-- PROBLEM 48
-- Generalize problem P47 in such a way that the logical expression may contain any number of logical variables. Define table/2 in a way that table(List,Expr) prints the truth table for the expression Expr, which contains the logical variables enumerated in List.
-- WANTED TO ADAPT THE ABOVE SOLUTION
--  couldn't figure out how to list all permutations for a list of indeterminate length
--  My explanation:
--    - args n appears to create a list of lists of the 2^n permutations of [True, False]
--    - toStr takes each permutation list, adds appropriate spacing, then concatenates into a single string
--    - this is then concatenated to the result of the function on the n variables and printed to the console
table' :: Int -> ([Bool] -> Bool) -> IO()
table' n f = mapM_ putStrLn [toStr a ++ " => " ++ show (f a) | a <- args n]
  where args n = replicateM n [True, False]
        toStr = unwords . map (\x -> show x ++ space x)
        space True = "  "
        space False = " "





