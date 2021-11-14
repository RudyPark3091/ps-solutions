import Data.List

parse :: String -> IO [Int]
parse = return . map read . words

main :: IO ()
main = do
  s <- parse =<< getLine
  print $ 4 - (length . map head . group . sort $ s)
