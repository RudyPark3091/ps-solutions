main :: IO ()
main = do
  n <- readLn :: IO Int
  s <- getLine
  let anton = length $ filter (== 'A') s
      danik = length s - anton
   in putStrLn $ go anton danik
  where
    go a d
      | a > d = "Anton"
      | a < d = "Danik"
      | otherwise = "Friendship"
