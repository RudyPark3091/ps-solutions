solve :: Int -> (Int, Int)
solve n = foldr (\y (a, b) -> (a + (b `div` y), b `mod` y)) (0, n) lst
  where
    lst = [1, 5, 10, 20, 100]

main :: IO ()
main = do
  n <- readLn :: IO Int
  print $ fst $ solve n
