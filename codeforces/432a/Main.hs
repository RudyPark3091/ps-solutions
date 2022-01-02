solve :: [Int] -> Int -> Int
solve xs k = l `div` 3
  where
    m = 5 - k
    l = length $ filter (m >=) xs

main :: IO ()
main = do
  [n, k] <- map read . words <$> getLine :: IO [Int]
  ys <- map read . words <$> getLine :: IO [Int]
  print $ solve ys k
