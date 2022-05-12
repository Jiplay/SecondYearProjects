--
-- main.hs for FUN in
--
-- Made by julien.garsia
-- Login   <julien.garsia>
--
-- Started on  Thu Jan 28 9:28:03 AM 2021 julien.garsia
-- Last update Fri Jan 28 12:31:51 PM 2021 julien.garsia
--

import System.Environment
import Data.List
import System.IO
import System.Exit

checkRules :: [String] -> Bool 
checkRules [] = True
checkRules (x:xs) = 
    if x /= "sa" && x /= "sb" && x /= "sc" && x /= "pa" && x /= "pb" && x /= "ra" && x /= "rb" && x /= "rr" && x /= "rra" && x /= "rrb"  && x /= "rrr" then
        False
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
execActions (x:xs) l_a l_b
    | x == "sa" = execActions xs (swap l_a) l_b
    | x == "sb" = execActions xs l_a (swap l_b)
    | x == "sc" = execActions xs (swap l_a) (swap l_b)
    | x == "pa" = execActions xs (my_take l_b l_a) (tail l_b)
    | x == "pb" = execActions xs (tail l_a) (my_take l_a l_b)
    | x == "ra" = execActions xs (rotate l_a) l_b
    | x == "rb" = execActions xs l_a (rotate l_b)
    | x == "rr" = execActions xs (rotate l_a) (rotate l_b)
    | x == "rra" = execActions xs (rrotate l_a) l_b
    | x == "rrb" = execActions xs l_a (rotate l_b)
    | x == "rrr" = execActions xs (rrotate l_a) (rotate l_b)

main :: IO ()
main = do
    args <- getArgs
    actions <- getLine
    let array_action = words actions
    if checkRules array_action == False 
        then exitWith (ExitFailure 84)
    else do
        let sorted_list = execActions array_action args []
        if (sorted_list /= []) && sorted_list == (sort sorted_list) then putStrLn "OK"
        else putStrLn "KO"
