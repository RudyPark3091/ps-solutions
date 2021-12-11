import Data.List

makeFullRow :: Int -> String
makeFullRow n = replicate n '#'

makeEmptyRow :: Int -> Bool -> String
makeEmptyRow n left =
  if left
    then xs
    else reverse xs
  where
    xs = '#' : replicate (n - 1) '.'

makeRow :: Int -> Int -> String
makeRow n idx =
  if even idx
    then makeFullRow n
    else makeEmptyRow n $ odd $ idx `div` 2

main :: IO ()
main = do
  [a, b] <- map read . words <$> getLine :: IO [Int]
  putStrLn $ intercalate "\n" $ map (makeRow b) [0 .. a - 1]
