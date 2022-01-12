solve :: [Int] -> [Int]
solve xs = filter (> 0) $ map (abc -) xs
  where
    abc = maximum xs

main :: IO ()
main = do
  xs <- map read . words <$> getLine :: IO [Int]
  putStrLn $ unwords $ map show . solve $ xs
