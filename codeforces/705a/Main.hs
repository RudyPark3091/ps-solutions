layer :: Int -> String
layer n
  | n == 1 = ""
  | even n = layer (n - 1) ++ "that I love "
  | otherwise = layer (n - 1) ++ "that I hate "

main :: IO ()
main = do
  n <- readLn :: IO Int
  putStrLn $ "I hate " ++ layer n ++ "it"
