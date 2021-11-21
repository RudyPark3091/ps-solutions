srs :: Int -> Int
srs n = 5 * n * (1 + n) `div` 2

main :: IO ()
main = do
  [n, k] <- map read . words <$> getLine :: IO [Int]
  print $ min n $ length . filter (<= 240 - k) $ map srs [1 .. 10]
