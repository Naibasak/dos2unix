@setlocal
@set MYCOMPILE=cl /nologo /MD /O2 /W3 /c /D_CRT_SECURE_NO_DEPRECATE
@set MYLINK=link /nologo
@set MYMT=mt /nologo

if exist *.exe^
	call del *.exe

%MYCOMPILE% *.c
%MYLINK% /out:unix2dos.exe u2d.obj

del *.obj *.manifest
