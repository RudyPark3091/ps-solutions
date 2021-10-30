parse :: String -> IO [Int]
parse s = return $ map read $ words s

sub :: Int -> Int
sub x =
  if lastChar == '0'
    then x `div` 10
    else x - 1
  where
    lastChar = last $ show x

loop :: Int -> Int -> IO Int
loop n x =
  if n > 0
    then loop (n - 1) $ sub x
    else return x

main :: IO ()
main = getLine >>= parse >>= \(n:k:_) -> loop k n >>= print
