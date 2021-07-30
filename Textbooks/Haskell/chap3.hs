-- Order matters; reverse the two functions below and you will always lose
winIf7 :: Int -> String
winIf7 7 = "You win!"
winIf7 x = "You lose!"

recursiveFact :: Integer -> Integer
recursiveFact 0 = 1
recursiveFact n = n * recursiveFact (n - 1)

-- when there is no default case, the program crashes when encountering unexpected input
incomplete :: Char -> Char
incomplete 'a' = succ 'a'
incomplete 'b' = succ 'b'
incomplete 'c' = succ 'c'

-- tuples
addVectors :: (Double, Double) -> (Double, Double) -> (Double, Double)
addVectors (x1, y1) (x2, y2) = (x1 + x2, y1 + y2) 

-- pattern matching can also be used with list comprehensions
xs = [(1,3), (2,2), (3,1)]
xsCombined = [a + b | (a, b) <- xs]

-- reimplementing head function
head' :: [a] -> a
head' [] = error "Empty list."
head' x = x !! 0
head'' (x:_) = x

-- as-patterns keep references of following object in preceding variable
firstLetter :: String -> String
firstLetter orig@(x:xs) = "First letter of " ++ orig ++ " is " ++ [x]

-- guards are conditions
-- functions like if-elif-else statements
-- errors are thrown if no suitable pattern is found; hence otherwise avoids errors
bmiTell :: Double -> String
bmiTell bmi
    | bmi <= 18.5 = "Underweight"
    | bmi <= 25.0 = "Just right"
    | bmi <= 30.0 = "Danger"
    | otherwise   = "Fatty"

-- where keyword to store calculation result
bmiTell' :: Double -> Double -> String
bmiTell' weight height
    | bmi <= skinny = "Underweight"
    | bmi <= normal = "Just right"
    | bmi <= heavy  = "Danger"
    | otherwise     = "Fatty"
    where bmi    = weight / height^2
          skinny = 18.5
          normal = 25.0
          heavy  = 30.0

initials :: String -> String -> String
initials firstname lastname = [f] ++ ". " ++ [l] ++ "."
    where (f:_) = firstname
          (l:_) = lastname

initials' :: String -> String -> String
initials' (f:_) (l:_) = [f] ++ ". " ++ [l] ++ "."

-- can also define temporary functions in where blocks
calcBmis :: [(Double, Double)] -> [Double]
calcBmis xs = [bmi w h | (w, h) <- xs]
    where bmi weight height = weight / height^2

calcBmis' :: [(Double, Double)] -> [Double]
calcBmis' xs = [bmi | (w, h) <- xs, let bmi = w / h^2]

calcBmis'' :: [(Double, Double)] -> [Double]
calcBmis'' xs = [bmi | (w, h) <- xs, let bmi = w / h^2, bmi < 20.0]

-- let binds variables to expressions in the 'in' block
-- can't be used across guards
cylinder :: Double -> Double -> Double
cylinder r h = 
    let sideArea = 2 * pi * r * h
        topArea  = pi * r^2
    in  sideArea + 2 * topArea

squares = [let square x = x * x in (square 5, square 3, square 1)]
random = (let a = 1; b = 2; c = 3 in a*b*c, let foo = "Hey "; bar = "You" in foo ++ bar)

-- case expressions are like switch statements
caseHead :: [a] -> a
caseHead xs = case xs of []    -> error "Empty list"
                         (x:_) -> x
