import Data.Set (fromList)

main :: IO ()
main = do
  s <- tail . init <$> getLine
  print $ length . fromList $ map head $ words s
