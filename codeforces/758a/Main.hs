solve :: [Int] -> Int
solve xs = foldr ((+) . (-) m) 0 xs
  where
    m = maximum xs

main :: IO ()
main = do
  _ <- getLine
  xs <- map read . words <$> getLine :: IO [Int]
  print $ solve xs
