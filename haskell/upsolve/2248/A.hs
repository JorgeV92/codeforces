import Data.List  (delete)

solve :: String -> String 
solve s = delete '1' (delete '0' s)

main :: IO ()
main = do 
  input <- getContents
  let tokens = words input 
  case tokens of 
    [] -> pure ()
    (tStr : testCases) -> do 
      let t = read tStr :: Int 
      mapM_ (putStrLn . solve) (take t testCases)
