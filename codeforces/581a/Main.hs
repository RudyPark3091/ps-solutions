import Data.List

main :: IO ()
main = do
  [a, b] <- map read . words <$> getLine :: IO [Int]
  putStrLn $ show (min a b) ++ " " ++ show (abs (a - b) `div` 2)
