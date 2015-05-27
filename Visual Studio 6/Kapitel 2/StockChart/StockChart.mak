# Microsoft Developer Studio Generated NMAKE File, Based on StockChart.dsp
!IF "$(CFG)" == ""
CFG=StockChart - Win32 Debug
!MESSAGE Keine Konfiguration angegeben. StockChart - Win32 Debug wird als\
 Standard verwendet.
!ENDIF 

!IF "$(CFG)" != "StockChart - Win32 Release" && "$(CFG)" !=\
 "StockChart - Win32 Debug"
!MESSAGE Ungültige Konfiguration "$(CFG)" angegeben.
!MESSAGE Sie können beim Ausführen von NMAKE eine Konfiguration angeben
!MESSAGE durch Definieren des Makros CFG in der Befehlszeile. Zum Beispiel:
!MESSAGE 
!MESSAGE NMAKE /f "StockChart.mak" CFG="StockChart - Win32 Debug"
!MESSAGE 
!MESSAGE Für die Konfiguration stehen zur Auswahl:
!MESSAGE 
!MESSAGE "StockChart - Win32 Release" (basierend auf\
  "Win32 (x86) Application")
!MESSAGE "StockChart - Win32 Debug" (basierend auf  "Win32 (x86) Application")
!MESSAGE 
!ERROR Eine ungültige Konfiguration wurde angegeben.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "StockChart - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\StockChart.exe"

!ELSE 

ALL : "$(OUTDIR)\StockChart.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ChartProperty.obj"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StockChart.obj"
	-@erase "$(INTDIR)\StockChart.pch"
	-@erase "$(INTDIR)\StockChart.res"
	-@erase "$(INTDIR)\StockChartDoc.obj"
	-@erase "$(INTDIR)\StockChartView.obj"
	-@erase "$(INTDIR)\StockProperty.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\StockChart.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)\StockChart.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\StockChart.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\StockChart.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\StockChart.pdb" /machine:I386 /out:"$(OUTDIR)\StockChart.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ChartProperty.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\StockChart.obj" \
	"$(INTDIR)\StockChart.res" \
	"$(INTDIR)\StockChartDoc.obj" \
	"$(INTDIR)\StockChartView.obj" \
	"$(INTDIR)\StockProperty.obj"

"$(OUTDIR)\StockChart.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "StockChart - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\StockChart.exe" "$(OUTDIR)\StockChart.bsc"

!ELSE 

ALL : "$(OUTDIR)\StockChart.exe" "$(OUTDIR)\StockChart.bsc"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ChartProperty.obj"
	-@erase "$(INTDIR)\ChartProperty.sbr"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\ChildFrm.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\StockChart.obj"
	-@erase "$(INTDIR)\StockChart.pch"
	-@erase "$(INTDIR)\StockChart.res"
	-@erase "$(INTDIR)\StockChart.sbr"
	-@erase "$(INTDIR)\StockChartDoc.obj"
	-@erase "$(INTDIR)\StockChartDoc.sbr"
	-@erase "$(INTDIR)\StockChartView.obj"
	-@erase "$(INTDIR)\StockChartView.sbr"
	-@erase "$(INTDIR)\StockProperty.obj"
	-@erase "$(INTDIR)\StockProperty.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\StockChart.bsc"
	-@erase "$(OUTDIR)\StockChart.exe"
	-@erase "$(OUTDIR)\StockChart.ilk"
	-@erase "$(OUTDIR)\StockChart.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\StockChart.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\StockChart.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\StockChart.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ChartProperty.sbr" \
	"$(INTDIR)\ChildFrm.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\StockChart.sbr" \
	"$(INTDIR)\StockChartDoc.sbr" \
	"$(INTDIR)\StockChartView.sbr" \
	"$(INTDIR)\StockProperty.sbr"

"$(OUTDIR)\StockChart.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\StockChart.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\StockChart.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ChartProperty.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\StockChart.obj" \
	"$(INTDIR)\StockChart.res" \
	"$(INTDIR)\StockChartDoc.obj" \
	"$(INTDIR)\StockChartView.obj" \
	"$(INTDIR)\StockProperty.obj"

"$(OUTDIR)\StockChart.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(CFG)" == "StockChart - Win32 Release" || "$(CFG)" ==\
 "StockChart - Win32 Debug"
SOURCE=.\ChartProperty.cpp

!IF  "$(CFG)" == "StockChart - Win32 Release"

DEP_CPP_CHART=\
	".\ChartProperty.h"\
	".\StdAfx.h"\
	".\StockChart.h"\
	".\StockChartDoc.h"\
	

"$(INTDIR)\ChartProperty.obj" : $(SOURCE) $(DEP_CPP_CHART) "$(INTDIR)"\
 "$(INTDIR)\StockChart.pch"


!ELSEIF  "$(CFG)" == "StockChart - Win32 Debug"

DEP_CPP_CHART=\
	".\ChartProperty.h"\
	".\StockChart.h"\
	".\StockChartDoc.h"\
	

"$(INTDIR)\ChartProperty.obj"	"$(INTDIR)\ChartProperty.sbr" : $(SOURCE)\
 $(DEP_CPP_CHART) "$(INTDIR)" "$(INTDIR)\StockChart.pch"


!ENDIF 

SOURCE=.\ChildFrm.cpp

!IF  "$(CFG)" == "StockChart - Win32 Release"

DEP_CPP_CHILD=\
	".\ChildFrm.h"\
	".\StdAfx.h"\
	".\StockChart.h"\
	

"$(INTDIR)\ChildFrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\StockChart.pch"


!ELSEIF  "$(CFG)" == "StockChart - Win32 Debug"

DEP_CPP_CHILD=\
	".\ChildFrm.h"\
	".\StockChart.h"\
	

"$(INTDIR)\ChildFrm.obj"	"$(INTDIR)\ChildFrm.sbr" : $(SOURCE) $(DEP_CPP_CHILD)\
 "$(INTDIR)" "$(INTDIR)\StockChart.pch"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "StockChart - Win32 Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\StockChart.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\StockChart.pch"


!ELSEIF  "$(CFG)" == "StockChart - Win32 Debug"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StockChart.h"\
	

"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) $(DEP_CPP_MAINF)\
 "$(INTDIR)" "$(INTDIR)\StockChart.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "StockChart - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)\StockChart.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StockChart.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "StockChart - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\StockChart.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\StockChart.pch" : \
$(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\StockChart.cpp

!IF  "$(CFG)" == "StockChart - Win32 Release"

DEP_CPP_STOCK=\
	".\ChartProperty.h"\
	".\ChildFrm.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\StockChart.h"\
	".\StockChartDoc.h"\
	".\StockChartView.h"\
	

"$(INTDIR)\StockChart.obj" : $(SOURCE) $(DEP_CPP_STOCK) "$(INTDIR)"\
 "$(INTDIR)\StockChart.pch"


!ELSEIF  "$(CFG)" == "StockChart - Win32 Debug"

DEP_CPP_STOCK=\
	".\ChartProperty.h"\
	".\ChildFrm.h"\
	".\MainFrm.h"\
	".\StockChart.h"\
	".\StockChartDoc.h"\
	".\StockChartView.h"\
	

"$(INTDIR)\StockChart.obj"	"$(INTDIR)\StockChart.sbr" : $(SOURCE)\
 $(DEP_CPP_STOCK) "$(INTDIR)" "$(INTDIR)\StockChart.pch"


!ENDIF 

SOURCE=.\StockChart.rc
DEP_RSC_STOCKC=\
	".\res\ico00001.ico"\
	".\res\ico00002.ico"\
	".\res\icon1.ico"\
	".\res\StockChart.ico"\
	".\res\StockChart.rc2"\
	".\res\StockChartDoc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\StockChart.res" : $(SOURCE) $(DEP_RSC_STOCKC) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StockChartDoc.cpp

!IF  "$(CFG)" == "StockChart - Win32 Release"

DEP_CPP_STOCKCH=\
	".\ChartProperty.h"\
	".\StdAfx.h"\
	".\StockChart.h"\
	".\StockChartDoc.h"\
	".\StockProperty.h"\
	

"$(INTDIR)\StockChartDoc.obj" : $(SOURCE) $(DEP_CPP_STOCKCH) "$(INTDIR)"\
 "$(INTDIR)\StockChart.pch"


!ELSEIF  "$(CFG)" == "StockChart - Win32 Debug"

DEP_CPP_STOCKCH=\
	".\ChartProperty.h"\
	".\StockChart.h"\
	".\StockChartDoc.h"\
	".\StockProperty.h"\
	

"$(INTDIR)\StockChartDoc.obj"	"$(INTDIR)\StockChartDoc.sbr" : $(SOURCE)\
 $(DEP_CPP_STOCKCH) "$(INTDIR)" "$(INTDIR)\StockChart.pch"


!ENDIF 

SOURCE=.\StockChartView.cpp

!IF  "$(CFG)" == "StockChart - Win32 Release"

DEP_CPP_STOCKCHA=\
	".\ChartProperty.h"\
	".\StdAfx.h"\
	".\StockChart.h"\
	".\StockChartDoc.h"\
	".\StockChartView.h"\
	

"$(INTDIR)\StockChartView.obj" : $(SOURCE) $(DEP_CPP_STOCKCHA) "$(INTDIR)"\
 "$(INTDIR)\StockChart.pch"


!ELSEIF  "$(CFG)" == "StockChart - Win32 Debug"

DEP_CPP_STOCKCHA=\
	".\ChartProperty.h"\
	".\StockChart.h"\
	".\StockChartDoc.h"\
	".\StockChartView.h"\
	

"$(INTDIR)\StockChartView.obj"	"$(INTDIR)\StockChartView.sbr" : $(SOURCE)\
 $(DEP_CPP_STOCKCHA) "$(INTDIR)" "$(INTDIR)\StockChart.pch"


!ENDIF 

SOURCE=.\StockProperty.cpp

!IF  "$(CFG)" == "StockChart - Win32 Release"

DEP_CPP_STOCKP=\
	".\StdAfx.h"\
	".\StockChart.h"\
	".\StockProperty.h"\
	

"$(INTDIR)\StockProperty.obj" : $(SOURCE) $(DEP_CPP_STOCKP) "$(INTDIR)"\
 "$(INTDIR)\StockChart.pch"


!ELSEIF  "$(CFG)" == "StockChart - Win32 Debug"

DEP_CPP_STOCKP=\
	".\StockChart.h"\
	".\StockProperty.h"\
	

"$(INTDIR)\StockProperty.obj"	"$(INTDIR)\StockProperty.sbr" : $(SOURCE)\
 $(DEP_CPP_STOCKP) "$(INTDIR)" "$(INTDIR)\StockChart.pch"


!ENDIF 


!ENDIF 

