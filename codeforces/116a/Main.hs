import Control.Monad (when)

getPair :: IO (Int, Int)
getPair = do
  s <- getLine
  let p = map read $ words s
   in return (head p, p !! 1)

loop :: Int -> Int -> Int -> IO Int
loop now n ans = do
  (a, b) <- getPair
  let next = now + b - a
   in if n > 1
        then loop next (n - 1) $ max ans next
        else return ans

main = do
  n <- readLn :: IO Int
  loop 0 n 0 >>= print
