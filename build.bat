@echo off
chcp 65001 > log
del log

:: "Visual Studio 17 2022" / Ninja

set BUILD_TYPE=Ninja
set BUILD_FOLDER=build_ninja
set SOURCE_FOLDER=.

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%
cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SOURCE_FOLDER%
cmake --build .

cd ..
