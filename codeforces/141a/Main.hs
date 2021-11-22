import Data.List

main :: IO ()
main = do
  s1 <- getLine
  s2 <- getLine
  s3 <- getLine
  putStrLn $
    if sort (s1 ++ s2) == sort s3
      then "YES"
      else "NO"
