@echo off
cd /d %~dp0
call .\scripts\globals.bat
cd ..\..

set "TESTPROJ=test_exec"


COPY .\build\win\%PROJECTNAME%.dll .\build\test
.\build\test\%TESTPROJ%.exe %*
echo %ERRORLEVEL%
cd ..