same :: String -> String -> Bool
same s1 s2 = s1 == s2

main :: IO ()
main = do
  s1 <- getLine
  s2 <- getLine
  putStrLn $
    if same s1 $ reverse s2
      then "YES"
      else "NO"
