module ArgsManager
    (
        getRule,
        getStart,
        getLines,
        getWindow,
        getMove,
        verify_args,
        parse_args,
        begin,
        start_rule,
    ) where

import Text.Read
import Control.Exception
import Rules

import System.Exit


parse_args:: [String] -> IO()
parse_args args = do
    let error = verify_args args
    let rule = getRule args
    let lines = getLines args
    let moove = getMove args
    let start = getStart args
    let window = getWindow args
    begin rule start lines window moove error

begin:: Int -> Int -> Int -> Int -> Int -> Int -> IO()
begin rule start line window moove err
    | start < 0 = do
        putStrLn "Bad start number"
        exitWith (ExitFailure 84)
    | rule < 0 = do
        putStrLn "Bad rule"
        exitWith (ExitFailure 84)
    | line < 0 = do
        putStrLn "Bad line Number"
        exitWith (ExitFailure 84)
    | window < 0 = do
        putStrLn "Bad Window Number"
        exitWith (ExitFailure 84)
    | err == 1 = do
        putStrLn "Bad or missing argument"
        exitWith (ExitFailure 84)
    | rule == 30 =
        start_rule start line window moove 1 [0] 30
    | rule == 90 =
        start_rule start line window moove 1 [0] 90
    | rule == 110 =
        print "will do (probably)"
    | otherwise = do
        putStrLn "I can run rule 30/90/110 and that all"
        exitWith (ExitFailure 84)




getRule:: [String] -> Int
getRule (a:b:cx)
    | "--rule" == a = read b
    | cx == [] = 0
getRule (a:b:cx) = getRule cx

getStart:: [String] -> Int
getStart (a:b:cx)
    | "--start" == a = read b
    | cx == [] = 0
getStart (a:b:cx) = getStart cx

getLines:: [String] -> Int
getLines (a:b:cx)
    | "--lines" == a = read b
    | cx == [] = 77680
getLines (a:b:cx) = getLines cx

getWindow:: [String] -> Int
getWindow (a:b:cx)
    | "--window" == a = read b
    | cx == [] = 80
getWindow (a:b:cx) = getWindow cx

getMove:: [String] -> Int
getMove (a:b:cx)
    | "--move" == a = read b
    | cx == [] = 0
getMove (a:b:cx) = getMove cx

verify_args:: [String] -> Int
verify_args (a:b:cx)
    | a /= "--rule" && a /= "--start" && a /= "--lines" && a /= "--window" && a /= "--move" = 1
    | cx == [] = 0
verify_args (a:b:cx) = verify_args cx
