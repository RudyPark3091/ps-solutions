solve :: Int -> Int -> Int
solve a b =
  if x `mod` 10 == 0
    then x `div` 10
    else x `div` 10 + 1
  where
    x = abs (a - b) -- `div` 10

iter :: Int -> IO ()
iter n =
  if n > 0
    then do
      [a, b] <- map read . words <$> getLine :: IO [Int]
      print $ solve a b
      iter $ n - 1
    else return ()

main :: IO ()
main = do
  t <- readLn :: IO Int
  iter t
