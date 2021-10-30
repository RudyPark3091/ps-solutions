parses :: String -> IO [Int]
parses s = return $ map read $ words s

tpl :: [Int] -> IO (Int, Int, Int)
tpl xs = return (head xs, xs !! 1, xs !! 2)

sums :: Int -> Int -> Int
sums a n = n * (2 * a + (n - 1) * a) `div` 2

solve :: (Int, Int, Int) -> IO Int
solve (k, n, w) =
  return $
  if s >= 0
    then s
    else 0
  where
    s = sums k w - n

main :: IO ()
main = getLine >>= parses >>= tpl >>= solve >>= print
