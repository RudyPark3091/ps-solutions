import Data.List

solve :: [Int] -> [Int]
solve p = [x | (_, x) <- sort $ zip p [1 ..]]

parse :: String -> IO [Int]
parse s = return $ map read $ words s

main :: IO ()
main = do
  n <- readLn :: IO Int
  p <- parse =<< getLine
  putStrLn $ unwords $ map show . solve $ p
