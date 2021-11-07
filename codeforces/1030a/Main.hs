main :: IO ()
main = do
  _ <- getLine
  xs <- getLine
  let easy = (== 0) $ length . filter (/= "0") $ words xs
   in putStrLn $
      if easy
        then "EASY"
        else "HARD"
