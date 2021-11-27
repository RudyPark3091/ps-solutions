solve :: [Int] -> Int -> Int -> Int -> Int
solve [] _ _ ans = ans
solve (x:xs) mr ls ans
  | x > mr = solve xs x ls $ ans + 1
  | x < ls = solve xs mr x $ ans + 1
  | otherwise = solve xs mr ls ans

main :: IO ()
main = do
  xs@(x:_) <- getLine >> map read . words <$> getLine :: IO [Int]
  print $ solve xs x x 0
