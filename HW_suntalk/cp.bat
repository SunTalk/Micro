@echo off

cls
gcc %1.c -o %1.exe -DDBG

if %ERRORLEVEL% EQU 0 (
	%1.exe
)