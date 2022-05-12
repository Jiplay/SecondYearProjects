
mySucc :: Int -> Int 
mySucc s = s + 1

myIsNeg :: Int -> Bool
myIsNeg a 
    | a < 0 = True
    | otherwise = False

myAbs :: Int -> Int
myAbs a
    | a >= 0 = a
    | otherwise = a * (-1)

myMin :: Int -> Int -> Int 
myMin a b 
    | a < b = a 
    | b < a = b
    | otherwise = a

myMax :: Int -> Int -> Int 
myMax a b 
    | a < b = b
    | b < a = a
    | otherwise = a

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead (x:xs) = x
myHead [] = error "Empty list"

myTail :: [a] -> [a]
myTail (x:xs) = xs
myTail [] = error "Empty list"

myLength :: [a] -> Int
myLength (x:xs) = 1 + myLength xs
myLength [] = 0


-- main = do 
--    a = [4, 5, 2, 4]
--    print(mySucc 2)
--    print(myIsNeg 3)
--    print(myAbs (-3))
--    print(myMin 3 2)
--    print(myMax 3 4)
--    print(myTuple 2 3)
--    print(myTruple 2 3 1)
--    print(myFst (2, 3))
--    myHead lostNumbers
