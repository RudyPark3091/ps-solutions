off :: Int -> [Int] -> [Int]
off n =
  map $ \x ->
    if x `mod` n == 0
      then 0
      else x

main :: IO ()
main = do
  k <- readLn :: IO Int
  l <- readLn :: IO Int
  m <- readLn :: IO Int
  n <- readLn :: IO Int
  d <- readLn :: IO Int
  print $ length . filter (== 0) $ off k $ off l $ off m $ off n [1 .. d]
