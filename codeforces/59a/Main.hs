import Data.Char (toLower, toUpper)

isLc :: Char -> Bool
isLc = flip elem ['a' .. 'z']

useLc :: String -> Bool
useLc s = lcLen s >= length s - lcLen s
  where
    go = length . filter isLc
    lcLen s = go s

main :: IO ()
main = do
  w <- getLine
  putStrLn $
    if useLc w
      then map toLower w
      else map toUpper w
