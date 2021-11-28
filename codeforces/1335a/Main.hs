solve :: [Int] -> IO [Int]
solve = return . map go
  where
    go x =
      x `div` 2 -
      if even x
        then 1
        else 0

input :: Int -> [Int] -> IO [Int]
input 0 acc = return acc
input n acc = do
  x <- readLn :: IO Int
  input (n - 1) $ x : acc

main :: IO ()
main = do
  n <- readLn :: IO Int
  input n [] >>= solve . reverse >>= mapM_ print
