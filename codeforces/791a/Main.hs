import Data.String

mapString :: [String] -> [Int]
mapString = map read

calc :: Int -> Int -> Int -> Int
calc x y ans =
  if x > y
    then ans
    else calc (x * 3) (y * 2) $ ans + 1

main :: IO ()
main = do
  s <- getLine
  let xs = words s
  let xss = mapString xs
   in print $ calc (head xss) (xss !! 1) 0
