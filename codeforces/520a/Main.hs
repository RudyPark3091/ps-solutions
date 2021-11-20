import Data.Char
import Data.List

main :: IO ()
main = do
  _ <- getLine
  s <- getLine
  putStrLn $
    if go s == 26
      then "YES"
      else "NO"
  where
    go s = length . map head . group $ sort $ map toLower s
