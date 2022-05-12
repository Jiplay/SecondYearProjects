module Rules
    ( someFunc,
      start_rule,
      update_line,
      print_rule
    ) where

import Data.List
import Data.Bits

someFunc :: IO ()
someFunc = putStrLn "someFunc"

start_rule:: Int -> Int -> Int -> Int -> Int -> [Int] -> Int -> IO ()
start_rule start line wd mv n i r
    | n < start + line = putStr(print_rule i wd mv 0) >> start_rule start line wd mv (n + 1) (update_line i [] n (-n) r) r
    | n - 1 < start  = start_rule start line wd mv (n + 1) (update_line i [] n (-n) r) r
    | n == start + line = putStr(print_rule i wd mv 0)
    | otherwise = putStr(print_rule i wd mv 0) >> start_rule start line wd mv (n + 1) (update_line i [] n (-n) r) r

update_line:: [Int] -> [Int] -> Int -> Int -> Int -> [Int]
update_line i sv it n r
    | n <= it && r == 90 && (xor (elem (n - 1) i) (elem (n + 1) i)) = update_line i (n:sv) it (n + 1) r
    | n <= it && r == 30 && (xor (elem (n + 1) i) ((elem n i) || (elem (n - 1) i))) = update_line i (n:sv) it (n + 1) r
    | n <= it = update_line i sv it (n + 1) r
    | otherwise = sort sv

print_rule:: [Int] -> Int -> Int -> Int -> String
print_rule i wd mv pos
    | pos < wd && elem ((div wd 2) - pos + mv) i = '*':print_rule i wd mv (pos + 1)
    | pos < wd && notElem (((div wd 2) - pos) + mv) i = ' ':print_rule i wd mv (pos + 1)
    | otherwise = "\n"
