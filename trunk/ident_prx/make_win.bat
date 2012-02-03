@echo off
del /q *.elf
del /q *.o
del /q *.pbp
del /q *.prx
del /q *.s
del /q *.sfo
cls
make
psp-build-exports -s exports.exp
psp-packer ident_ng.prx
copy /b ident_ng.prx ..\ident_ng.prx
pause
del /q *.elf
del /q *.o
del /q *.pbp
del /q *.prx
del /q *.sfo