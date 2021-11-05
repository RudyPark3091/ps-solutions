isDistinct :: String -> Bool
isDistinct s = length s == length (comp s [])

comp :: String -> String -> String
comp [] acc = acc
comp (x:xs) acc =
  if x `elem` acc
    then comp xs acc
    else comp xs $ x : acc

solve :: Int -> Int
solve n =
  if isDistinct s
    then read s
    else solve $ n + 1
  where
    s = show n

main :: IO ()
main = do
  y <- readLn :: IO Int
  print $ solve $ y + 1
