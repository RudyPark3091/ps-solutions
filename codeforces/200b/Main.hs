import Data.List

solve :: [Double] -> Double
solve xs = sum xs / genericLength xs

parse :: String -> IO [Double]
parse = return . map read . words

main :: IO ()
main = do
  _ <- getLine
  p <- parse =<< getLine
  print $ solve p
