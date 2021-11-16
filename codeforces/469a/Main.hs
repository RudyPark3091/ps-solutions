import Data.List

parse :: String -> IO [Int]
parse = return . map read . words

main :: IO ()
main = do
  n <- readLn :: IO Int
  (_:ps) <- parse =<< getLine
  (_:qs) <- parse =<< getLine
  let xs = map head . group . sort $ ps ++ qs
   in putStrLn $ go xs n
  where
    go xs n =
      if n /= length xs
        then "Oh, my keyboard!"
        else "I become the guy."
