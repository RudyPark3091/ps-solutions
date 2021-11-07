getPair :: IO (Int, Int)
getPair = do
  l <- getLine
  let ls = map read (words l)
   in return (head ls, ls !! 1)

loop :: Int -> [Int] -> IO [Int]
loop 0 acc = return acc
loop n acc = do
  (p, q) <- getPair
  loop (n - 1) $ (q - p) : acc

main :: IO ()
main = do
  n <- readLn :: IO Int
  loop n [] >>= print . length . filter (>= 2)
