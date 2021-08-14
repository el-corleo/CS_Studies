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
