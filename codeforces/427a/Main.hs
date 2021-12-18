solve :: [Int] -> Int -> Int -> Int
solve [] c _ = c
solve (x:xs) c p
  | x == -1 && p > 0 = solve xs c $ p - 1
  | x == -1 && p == 0 = solve xs (c + 1) 0
  | x > 0 = solve xs c $ p + x
  | otherwise = c

main :: IO ()
main = do
  _ <- getLine
  xs <- map read . words <$> getLine :: IO [Int]
  print $ solve xs 0 0
