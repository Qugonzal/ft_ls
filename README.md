## General info

mls is my replica of 'ls' (a famous command).
Compiles with a Makefile using 'gcc'.

## __SYNOPSYS__
mls [_OPTION_]... [_FILE_]...

## __DESCRIPTION__
List information about the *FILE(s)* (current directory by default if no *FILE* specified).
Sort entries alphabetically if -t is not specified.

## __OPTIONS__
`-1` list one file per line

`-a` do not ignore entries starting with '.'

`-l` use a long listing format

`-r` reverse order while sorting

`-R` list subdirectories recursively

`-t` sort by time, newest first
