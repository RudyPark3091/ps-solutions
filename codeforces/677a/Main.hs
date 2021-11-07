parse :: String -> IO [Int]
parse = return . map read . words

solve :: Int -> [Int] -> Int
solve h hs = length hs + length taller
  where
    taller = filter (> h) hs

main :: IO ()
main = do
  (_:h:_) <- parse =<< getLine
  hs <- parse =<< getLine
  print $ solve h hs
