import Control.Monad

calc :: IO ()
calc = do
  [a, b] <- map read . words <$> getLine :: IO [Int]
  print $
    if a `mod` b == 0
      then 0
      else b * (a `div` b + 1) - a

solve :: Int -> IO ()
solve n =
  if n > 0
    then calc >> solve (n - 1)
    else return ()

main :: IO ()
main = do
  t <- readLn :: IO Int
  solve t
