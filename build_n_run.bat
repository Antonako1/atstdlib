@echo off 
cd /d %~dp0
cd z-win
call build.bat
if %ERRORLEVEL% NEQ 0 exit /B 1
call run.bat %*
cd /d %~dp0
