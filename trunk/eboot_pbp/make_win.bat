@echo off
del /q *.elf
del /q *.o
del /q *.pbp
del /q *.prx
del /q *.s
del /q *.sfo
copy /b grafika_.h grafika.h
.\win\get_date y > temp.txt
set /p VER_MAJOR=<temp.txt
.\win\get_date w > temp.txt
set /p VER_MINOR=<temp.txt
.\win\get_date Y > temp.txt
set /p VER_MAJOR_YEAR=<temp.txt
.\win\get_date W > temp.txt
set /p VER_MINOR_WEEK=<temp.txt
del /q temp.txt
echo. >> grafika.h
echo #define VER_MAJOR %VER_MAJOR% >> grafika.h
echo #define VER_MINOR %VER_MINOR% >> grafika.h
echo. >> grafika.h
echo #define VER_MAJOR_YEAR "%VER_MAJOR_YEAR%" >> grafika.h
echo #define VER_MINOR_WEEK "%VER_MINOR_WEEK%" >> grafika.h
cls
make -f makefile.win
if exist EBOOT.PBP copy /b EBOOT.PBP ..\EBOOT.PBP
if not exist EBOOT.PBP (
echo.
echo ERROR!!!
echo.
pause
call %0
exit
)
pause
del /q grafika.h
del /q *.elf
del /q *.o
del /q *.pbp
del /q *.prx
del /q *.s
del /q *.sfo