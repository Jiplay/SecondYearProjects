module Main where

import Control.Exception
import System.Environment
import Text.Read

import ArgsManager (parse_args)

main = do  
    args <- getArgs
    parse_args args
