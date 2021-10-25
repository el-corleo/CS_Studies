import Data.List


main = do
  contents <- getContents
  let threes = groupsOf 3 (map read $ lines contents)
      roadSystem = map (\[a,b,c] -> Section a b c) threes
      path = optimalPath roadSystem
      pathString = concat $ map (show .fst) path
      pathTime = sum $ map snd path
  putStrLn $ "The optimal path is: " ++ pathString
  putStrLn $ "Time: " ++ show pathTime



solveRPN :: String -> Double
solveRPN = head . foldl foldingFunction [] . words
  where foldingFunction (x:y:ys) "*" = (y * x):ys
        foldingFunction (x:y:ys) "+" = (y + x):ys
        foldingFunction (x:y:ys) "-" = (y - x):ys
        foldingFunction xs numberString = read numberString:xs


-- "We could also use a triple of(Int, Int, Int) to represent a road section. Using tuples instead ofmaking yourown algebraic data types is good for some small, localized stuff, but it’s usually better to make a new type for more complex representations. It gives the type system more information about what’s what. We can use (Int, Int, Int) to represent a road section or a vector in 3D space, and we can operate on those two, but that allows us to mix them up. Ifwe use Section and Vector data types, then we can’t accidentally add a vector to a section ofa road system."

data Section = Section { getA :: Int, getB :: Int, getC :: Int }
  deriving (Show)

type RoadSystem = [Section]

heathrowToLondon :: RoadSystem
heathrowToLondon = [  Section 50 10 30,
                    Section 5 90 20,
                    Section 40 2 25,
                    Section 10 8 0
                 ]

data Label = A | B | C deriving (Show)
type Path = [(Label, Int)]


roadStep :: (Path, Path) -> Section -> (Path, Path)
roadStep (pathA, pathB) (Section a b c) =
  let timeA = sum (map snd pathA)
      timeB = sum (map snd pathB)
      forwardTimeToA = timeA + a
      crossTimeToA = timeB + b + c
      forwardTimeToB = timeB + b
      crossTimeToB = timeA + a + c
      newPathToA = if forwardTimeToA <= crossTimeToA
                      then (A, a):pathA
                      else (C, c):(B, b):pathB
      newPathToB = if forwardTimeToB <= crossTimeToB
                      then (B, b):pathB
                      else (C, c):(A, a):pathA
  in (newPathToA, newPathToB)



optimalPath :: RoadSystem -> Path
optimalPath roadSystem =
  let (bestAPath, bestBPath) = foldl roadStep ([], []) roadSystem
   in if sum (map snd bestAPath) <= sum (map snd bestBPath)
         then reverse bestAPath
         else reverse bestBPath


groupsOf :: Int -> [a] -> [[a]]
groupsOf 0 _ = undefined
groupsOf _ [] = []
groupsOf n xs = take n xs : groupsOf n (drop n xs)

