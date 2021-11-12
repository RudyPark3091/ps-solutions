import Data.Bits
import Data.Char

solve :: String -> String -> String
solve s1 s2 = map (intToDigit . fn) z
  where
    z = zip s1 s2
    fn (x, y) = digitToInt x `xor` digitToInt y

main :: IO ()
main = do
  s1 <- getLine
  s2 <- getLine
  putStrLn $ solve s1 s2
