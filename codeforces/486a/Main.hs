solve :: Int -> Int
solve n =
  if even n
    then n2
    else n2 - n
  where
    n2 = n `div` 2

main :: IO ()
main = do
  n <- readLn :: IO Int
  print $ solve n
