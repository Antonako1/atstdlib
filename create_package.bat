@echo off 
cd /d %~dp0
cd z-win
@REM call build.bat "Release"
call build.bat
set "EXPORT_NAME=ATSTDLIB_EXPORT_X86_64"
set "SEVENZIP=C:\Program Files\7-Zip"
:: FILE STRUCTURE
::
:: ATSTDLIB_EXPORT_X86_64
::  |
::  -- LICENSE.TXT
::  -- README.MD
::  |
::  -- \INCLUDE
::  ||
::  |-- ATSTDLIB.H
::  |
::  -- \LIBS
::  |
::  -- \Windows
::  ||
::  |-- ATSTDLIB.LIB
::  |-- ATSTDLIB.DLL
::  -- \Linux
::   |
::   -- ATSTDLIB.SO
CD /D %~dp0
RMDIR /S /Q .\%EXPORT_NAME%
MKDIR %EXPORT_NAME%
CD .\%EXPORT_NAME%
MKDIR .\INCLUDE
MKDIR .\LIBS\WINDOWS
MKDIR .\LIBS\LINUX

CD /D %~dp0
