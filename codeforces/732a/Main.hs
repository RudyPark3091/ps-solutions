solve :: Int -> Int -> Int -> Int
solve k r ans =
  if yes
    then ans
    else solve k r $ ans + 1
  where
    yes = (k * ans - r) `mod` 10 == 0 || (k * ans) `mod` 10 == 0

main :: IO ()
main = do
  [k, r] <- map read . words <$> getLine :: IO [Int]
  print $ solve k r 1
