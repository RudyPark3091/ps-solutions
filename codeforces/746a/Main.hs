solve :: Int -> Int -> Int -> Int
solve a b c = 7 * x
  where
    x = minimum [a, b `div` 2, c `div` 4]

main :: IO ()
main = do
  a <- readLn :: IO Int
  b <- readLn :: IO Int
  c <- readLn :: IO Int
  print $ solve a b c
