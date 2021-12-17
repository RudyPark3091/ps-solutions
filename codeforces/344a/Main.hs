import Data.List

solve :: [String] -> IO Int
solve = return . length . group

rd :: Int -> [String] -> IO [String]
rd n acc =
  if n > 0
    then do
      x <- getLine
      rd (n - 1) $ x : acc
    else return acc

main :: IO ()
main = do
  n <- readLn :: IO Int
  rd n [] >>= solve >>= print
