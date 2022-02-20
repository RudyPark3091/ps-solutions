solve :: Int -> [Int]
solve x =
  if even x
    then lst n
    else lst (n - 1) ++ [3]
  where
    lst n = replicate n 2
    n = x `div` 2

main :: IO ()
main = do
  n <- readLn :: IO Int
  print $ n `div` 2
  putStrLn $ unwords $ map show (solve n)
