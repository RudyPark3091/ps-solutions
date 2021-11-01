check :: Char -> Bool
check c = c /= '4' && c /= '7'

isLucky :: String -> Bool
isLucky = any check

countLucky :: String -> Int
countLucky = length . filter (not . check)

solve :: String -> IO String
solve s =
  return $
  if isLucky $ show $ countLucky s
    then "NO"
    else "YES"

main :: IO ()
main = getLine >>= solve >>= putStrLn
