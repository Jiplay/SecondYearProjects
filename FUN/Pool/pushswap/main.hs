--
-- main.hs for FUN in
--
-- Made by julien.garsia
-- Login   <julien.garsia>
--
-- Started on  Thu Jan 28 9:28:03 AM 2021 julien.garsia
-- Last update Sat Jan 29 12:49:29 PM 2021 julien.garsia
--

import System.Environment
import Data.List
import System.IO
import System.Exit

checkRules :: [String] -> Bool 
checkRules [] = True
checkRules (x:xs) = 
    if x /= "sa" && x /= "sb" && x /= "sc" && x /= "pa" && x /= "pb" 
        && x /= "ra" && x /= "rb" && x /= "rr" && x /= "rra"
        && x /= "rrb"  && x /= "rrr"
        then False
    else
        checkRules xs

swap :: [string] -> [string]
swap [] = []
swap (x:[]) = [x]
swap (x:y:xs) = (y:x:xs)

my_take :: [string] -> [string] -> [string]
my_take [] snd = snd
my_take fst snd = [fst !! 0] ++ snd

rotate :: [string] -> [string]
rotate [] = []
rotate (x:xs) = reverse (x:(reverse xs))

rrotate :: [string] -> [string]
rrotate [] = []
rrotate x = (last x):(init x)

execActions :: [String] -> [String] -> [String] -> [String]
execActions [] l_a l_b = l_a
execActions (x:xs) l_a l_b = case x of
    "sa" -> execActions xs (swap l_a) l_b
    "sb" -> execActions xs l_a (swap l_b)
    "sc" -> execActions xs (swap l_a) (swap l_b)
    "pa" -> execActions xs (my_take l_b l_a) (tail l_b)
    "pb" -> execActions xs (tail l_a) (my_take l_a l_b)
    "ra" -> execActions xs (rotate l_a) l_b
    "rb" -> execActions xs l_a (rotate l_b)
    "rr" -> execActions xs (rotate l_a) (rotate l_b)
    "rra" -> execActions xs (rrotate l_a) l_b
    "rrb" -> execActions xs l_a (rotate l_b)
    "rrr" -> execActions xs (rrotate l_a) (rotate l_b)
    _ -> l_a

check_list :: [String] -> IO ()
check_list a = 
    if (a /= []) && a == (sort a)
        then putStrLn "OK"
    else
        putStrLn "KO"

main :: IO ()
main = do
    args <- getArgs
    actions <- getLine
    let array_action = words actions
    if checkRules array_action == False 
        then exitWith (ExitFailure 84)
    else
        check_list $ execActions array_action args []
