poly2n :: String -> Int
poly2n s =
  case s of
    "Tetrahedron" -> 4
    "Cube" -> 6
    "Octahedron" -> 8
    "Dodecahedron" -> 12
    "Icosahedron" -> 20
    _ -> 0

main :: IO ()
main = do
  _ <- getLine
  ss <- words <$> getContents
  print $ sum $ map poly2n ss
