main = do
  w <- getLine
  if even (read w) && read w > 2
     then putStrLn "YES"
     else putStrLn "NO"
