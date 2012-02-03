@echo off

cd ident_prx
call make_win.bat
cd ..

cd eboot_pbp
call make_win.bat
cd ..

cls
echo.
echo ALL DONE
echo.
pause