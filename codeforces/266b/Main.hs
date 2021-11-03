tick :: String -> String
tick [] = []
tick [x] = [x]
tick (x:xs) =
  if x == 'B' && head xs == 'G'
    then 'G' : 'B' : tick (tail xs)
    else x : tick xs

input :: IO (Int, Int)
input = do
  s <- getLine
  let is = map read $ words s
   in return (head is, is !! 1)

solve :: Int -> Int -> String -> Int -> IO ()
solve n t s time =
  if t == time
    then putStrLn s
    else solve n t (tick s) $ time + 1

main :: IO ()
main = do
  (n, t) <- input
  s <- getLine
  solve n t s 0
