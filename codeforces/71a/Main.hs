import Control.Monad

comp :: String -> String
comp s =
  if length s <= 10
    then s
    else head s : show (length s - 2) ++ [last s]

loop :: Int -> IO ()
loop x = do
  s <- getLine
  putStrLn $ comp s
  when (x > 1) $ loop $ x - 1

main = do
  n <- getLine
  loop $ read n
