
SquareServerps.dll: dlldata.obj SquareServer_p.obj SquareServer_i.obj
	link /dll /out:SquareServerps.dll /def:SquareServerps.def /entry:DllMain dlldata.obj SquareServer_p.obj SquareServer_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib 

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL $<

clean:
	@del SquareServerps.dll
	@del SquareServerps.lib
	@del SquareServerps.exp
	@del dlldata.obj
	@del SquareServer_p.obj
	@del SquareServer_i.obj
