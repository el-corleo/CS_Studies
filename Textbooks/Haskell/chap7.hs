import qualified Data.Map as Map
{-
  Data type anatomy:

    data Bool = False | True

    use data keyword to signal new type; then comes data type name;
    next are the constructors (i.e., the different values the type can take on)

    both type name and constructors must start with a capital letter
-}

-- example from book: Shape
--    deriving seems equivalent to extends/implements in java
--    deriving (Show) gives it the equivalent of a toString() method
data Shape = Circle Float Float Float | Rectangle Float Float Float Float
  deriving (Show)

area :: Shape -> Float
area (Circle _ _ r) = pi * r^2
area (Rectangle x1 y1 x2 y2) = (abs $ x1 - x2) * (abs $ y1 - y2)


-- Shape 2.0
data Point = Point Float Float deriving (Show)
data Shape' = Circle' Point Float | Rectangle' Point Point deriving (Show)

area' :: Shape' -> Float
area' (Circle' _ r) = pi * r^2
area' (Rectangle' (Point x1 y1) (Point x2 y2)) = (abs $ x1 - x2) * (abs $ y1 - y2)

nudge :: Shape' -> Float -> Float -> Shape'
nudge (Circle' (Point x y) r) dx dy = Circle' (Point (x + dx) (y + dy)) r
nudge (Rectangle' (Point x1 y1) (Point x2 y2)) dx dy = Rectangle' (Point (x1 + dx) (y1 + dy)) (Point (x2 + dx) (y2 + dy))


{-
  Can export custom data types in modules
  e.g.

  module Shapes
  ( Point(..),
    Shape(..),
    area,
    nudge
  ) where

  ...

  The '..' in Point(..) means that we are exporting all constructors from the data type
-}

-- Record Syntax
-- Person has a FirstName, LastName, Age, Height, PhoneNum, FavoriteIceCream
-- This is the cubersome way to do it:
data Person = Person String String Int Float String String deriving (Show)
firstName :: Person -> String
firstName (Person firstName _ _ _ _ _) = firstName
-- etc. for all other fields

-- The superior way to do it: Record Syntax
data Person' = Person' { firstName' :: String,
                        lastName' :: String,
                        age' :: Int,
                        height' :: Float,
                        phoneNum' :: String,
                        favIceCream' :: String
                      } deriving (Show)

-- 3D Vector
data Vector3D a = Vector3D a a a deriving (Show)

vplus :: (Num a) => Vector3D a -> Vector3D a -> Vector3D a
(Vector3D i j k) `vplus` (Vector3D l m n) = Vector3D (i+l) (j+m) (k+n)

dotProd :: (Num a) => Vector3D a -> Vector3D a -> a
(Vector3D i j k) `dotProd` (Vector3D l m n) = i*l + j*m + k*n

{-
  Use 'deriving' keyword to make data Type possess the characteristics of other types

  e.g.,

  data Person = Person {
                  firstName :: String,
                  lastName :: String,
                  age :: Int
                } deriving (Eq, Show, Read)

  Now when comparing two Persons Haskell will check if all constructor values are the same
  (So long as the types of all constructors are also (Eq))
-}

-- read function needs a cast
data Dog = Dog { sound :: String, age :: Int } deriving (Show, Read)

dogStr = "Dog { sound = \"Woof\", age = 5 }"
-- read dogStr :: Dog


-- type synonyms can help improve the readability of the code
--  NOTE: type synonyms often function as code documentation in Haskell, apparently
type Name = String
type PhoneNumber = String
type PhoneBook = [(Name, PhoneNumber)]

isInPhoneBook :: Name -> PhoneNumber -> PhoneBook -> Bool
isInPhoneBook name pnum pbk = (name, pnum) `elem` pbk


-- can parameterize
type AssocList k v = [(k, v)]

-- can partially apply
type IntMap v = Map.Map Int v

{-
   type constructors /= value constructors

   "Make sure that you really understand the distinction between type constructors and value constructors. Just because we made a type synonym called IntMap or AssocList doesn’t mean that we can do stuff like AssocList [(1,2), (4,5),(7,9)]. All it means is that we can refer to its type by using different names. We can do [(1,2),(3,5),(8,9)] :: AssocList Int Int, which will make the numbers inside assume a type of Int."
-}

-- Either
data LockerState = Taken | Free deriving (Eq, Show)

type Code = String

type LockerMap = Map.Map Int (LockerState, Code)

lockerLookup :: Int -> LockerMap -> Either String Code
lockerLookup lockerNum map = case Map.lookup lockerNum map of
  Nothing -> Left $ "Locker " ++ show lockerNum ++ " doesn't exist!"
  Just (state, code) -> if state /= Taken
                           then Right code
                           else Left $ "Locker " ++ show lockerNum ++ " is already taken!"


-- implementing a BST in Haskell
data Tree a = EmptyTree | Node a (Tree a) (Tree a) deriving (Show)

singleton :: a -> Tree a
singleton x = Node x EmptyTree EmptyTree

treeInsert :: (Ord a) => a -> Tree a -> Tree a
treeInsert x EmptyTree = singleton x
treeInsert x (Node a left right)
  | x == a = Node x left right
  | x < a = Node a (treeInsert x left) right
  | x > a = Node a left (treeInsert x right)

treeElem :: (Ord a) => a -> Tree a -> Bool
treeElem x EmptyTree = False
treeElem x (Node a left right)
  | x == a = True
  | x < a = treeElem x left
  | x > a = treeElem x right

-- "Remember that pretty much everything that traverses a list one item at a time and returns a value can be implemented with a fold!" <-- Honestly, still not sure how fold black magic works; must study
nums = [6,3,7,2,9,1,6,4,8,7,5,3,6,5]

numsTree = foldr treeInsert EmptyTree nums

