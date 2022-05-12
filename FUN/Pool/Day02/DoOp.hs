--
-- DoOp.hs for B-FUN-300-PAR-3-2-funPoolDay2-julien.garsia
--
-- Made by julien.garsia
-- Login   <julien.garsia>
--
-- Started on  Wed Jan 27 9:17:30 AM 2021 julien.garsia
-- Last update Fri Jan 28 9:02:25 AM 2021 julien.garsia
--

myElem :: Eq a => a -> [a] -> Bool
myElem a (x:xs) 
    | a == x = True
    | otherwise = myElem a xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv x 0 = Nothing
safeDiv x y = Just (div x y)

safeNth :: [a] -> Int -> Maybe a
safeNth [] a = Nothing
safeNth (x:xs) 0 = Just x
safeNth (x:xs) a
    | a > length xs = Nothing
    | a < 0 = Nothing
    | otherwise = safeNth xs (a-1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc x = fmap succ x

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup a [] = Nothing
myLookup a (x:xs)
    | a == fst x = Just (snd x)
    | otherwise = myLookup a xs

main :: IO ()
main =
    print $ myLookup 2 [(1,"foo"),(2,"bar"),(3,"baz")]

