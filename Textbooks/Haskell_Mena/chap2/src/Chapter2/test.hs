{-# LANGUAGE ViewPatterns #-}
-- e.g., (parentName -> "Bobo") in the viewPattern function below
{-# LANGUAGE NamedFieldPuns #-}
--  e.g., Mom { name } in the parentName' function below
{-# LANGUAGE RecordWildCards #-}
--  e.g., Mom { .. } in the parentName''' function below
import Data.Char(toUpper)

data Parent = Mom { name :: String
                  , age :: Integer }
            | Dad { name :: String
                  , age :: Integer }
            deriving Show


parentName :: Parent -> String
parentName (Mom name _) = name
parentName (Dad name _) = name

parentName' :: Parent -> String
parentName' Mom { name } = name
parentName' Dad { name } = name

parentName'' :: Parent -> String
parentName'' Mom { .. } = name
parentName'' Dad { .. } = name


viewPattern :: Parent -> String
viewPattern (parentName'' -> "Bobo")  = "Ha! Your name is Bobo!"
viewPattern _                         = "Not interested."

-- Code from the book to make the name capitalized
nameInCapitals :: Parent -> Parent
nameInCapitals p@(Mom { name = initial:rest }) =
  let newName = (toUpper initial):rest
  in p { name = newName }
nameInCapitals p@(Mom { name = "" }) = p
