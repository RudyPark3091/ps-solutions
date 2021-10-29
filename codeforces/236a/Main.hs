import Data.List

distAcc :: String -> String -> Int
distAcc [] acc = length acc
distAcc (x:xs) acc =
  if contains
    then distAcc xs acc
    else distAcc xs $ x : acc
  where
    contains = [x] `isInfixOf` acc

dist :: String -> Int
dist = flip distAcc []

main :: IO ()
main = do
  s <- getLine
  putStrLn $ go s
  where
    go s =
      if even (dist s)
        then "CHAT WITH HER!"
        else "IGNORE HIM!"
