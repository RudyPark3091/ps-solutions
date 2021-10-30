main :: IO ()
main =
  getLine >>= go >>= \x ->
    print $
    x `div` 5 +
    if x `mod` 5 == 0
      then 0
      else 1
  where
    go :: String -> IO Int
    go x = return $ read x
