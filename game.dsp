# Microsoft Developer Studio Project File - Name="game" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (ALPHA) Dynamic-Link Library" 0x0602

CFG=game - Win32 Debug Arcade
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "game.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "game.mak" CFG="game - Win32 Debug Arcade"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "game - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "game - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "game - Win32 Debug Alpha" (based on\
 "Win32 (ALPHA) Dynamic-Link Library")
!MESSAGE "game - Win32 Release Alpha" (based on\
 "Win32 (ALPHA) Dynamic-Link Library")
!MESSAGE "game - Win32 Debug Demo" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "game - Win32 Release Demo" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "game - Win32 Debug Arcade" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "game - Win32 Release Arcade" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""$/Quake 2 Engine/Sin/code/game", FTDAAAAA"
# PROP Scc_LocalPath "."

!IF  "$(CFG)" == "game - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir "."
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir "."
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /G5 /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "SIN" /FR /YX /FD /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "SIN" /d "SIN_DISABLECOPYPROTECTION"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winmm.lib /nologo /base:"0x11000000" /subsystem:windows /dll /map /machine:I386 /out:"..\Release/gamex86.dll"
# SUBTRACT LINK32 /incremental:yes /debug

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir "."
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir "."
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /G5 /W3 /Gm /GX /Zi /Od /I "\newsin\code\game" /D "BUILDING_REF_GL" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "SIN" /FR /YX /FD /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG" /d "SIN" /d "SIN_DISABLECOPYPROTECTION"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib /nologo /base:"0x11000000" /subsystem:windows /dll /map /debug /machine:I386 /out:"..\Debug/gamex86.dll"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug Alpha"
# PROP BASE Intermediate_Dir "Debug Alpha"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\DebugAxp"
# PROP Intermediate_Dir ".\DebugAxp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
CPP=cl.exe
# ADD BASE CPP /nologo /Gt0 /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /MTd /c
# ADD CPP /nologo /Gt0 /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /QA21164 /MTd /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /base:"0x20000000" /subsystem:windows /dll /debug /machine:ALPHA
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /base:"0x20000000" /subsystem:windows /dll /debug /machine:ALPHA /out:"..\DebugAxp/gameaxp.dll"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "game___W"
# PROP BASE Intermediate_Dir "game___W"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\ReleaseAXP"
# PROP Intermediate_Dir ".\ReleaseAXP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
CPP=cl.exe
# ADD BASE CPP /nologo /MT /Gt0 /W3 /GX /Zd /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MT /Gt0 /W3 /GX /Zd /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /QA21164 /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /base:"0x20000000" /subsystem:windows /dll /machine:ALPHA /out:"..\Release/gamex86.dll"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib /nologo /base:"0x20000000" /subsystem:windows /dll /machine:ALPHA /out:"..\ReleaseAXP/gameaxp.dll"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "game___W"
# PROP BASE Intermediate_Dir "game___W"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "game___W"
# PROP Intermediate_Dir "game___W"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /G5 /W3 /Gm /GX /Zi /Od /I "\newsin\code\game" /D "BUILDING_REF_GL" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "SIN" /FR /YX /FD /c
# ADD CPP /nologo /G5 /W3 /Gm /GX /Zi /Od /I "\newsin\code\game" /D "BUILDING_REF_GL" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "SIN" /D "SIN_DEMO" /FR /YX /FD /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "SIN" /d "SIN_DISABLECOPYPROTECTION"
# ADD RSC /l 0x409 /d "_DEBUG" /d "SIN" /d "SIN_DISABLECOPYPROTECTION"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /map /debug /machine:I386 /out:"..\Debug/gamex86.dll"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:"0x11000000" /subsystem:windows /dll /map /debug /machine:I386 /out:"../Demo_Debug/gamex86.dll"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "game___0"
# PROP BASE Intermediate_Dir "game___0"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "game___0"
# PROP Intermediate_Dir "game___0"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /G5 /W3 /GX /Zd /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "SIN" /FR /YX /FD /c
# ADD CPP /nologo /G5 /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "SIN" /D "SIN_DEMO" /FR /YX /FD /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "SIN" /d "SIN_DISABLECOPYPROTECTION"
# ADD RSC /l 0x409 /d "NDEBUG" /d "SIN" /d "SIN_DISABLECOPYPROTECTION"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winmm.lib /nologo /base:"0x20000000" /subsystem:windows /dll /machine:I386 /out:"..\Release/gamex86.dll"
# SUBTRACT BASE LINK32 /incremental:yes /debug
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winmm.lib /nologo /base:"0x11000000" /subsystem:windows /dll /machine:I386 /out:"..\Demo_Release/gamex86.dll"
# SUBTRACT LINK32 /incremental:yes /debug

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "game___3"
# PROP BASE Intermediate_Dir "game___3"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../Arcade_Debug"
# PROP Intermediate_Dir "./Arcade_Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /G5 /W3 /Gm /GX /Zi /Od /I "\newsin\code\game" /D "BUILDING_REF_GL" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "SIN" /FR /YX /FD /c
# ADD CPP /nologo /G5 /W3 /Gm /GX /Zi /Od /I "\newsin\code\game" /D "BUILDING_REF_GL" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "SIN" /D "SIN_ARCADE" /FR /YX /FD /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "SIN" /d "SIN_DISABLECOPYPROTECTION"
# ADD RSC /l 0x409 /d "_DEBUG" /d "SIN" /d "SIN_DISABLECOPYPROTECTION"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib /nologo /base:"0x11000000" /subsystem:windows /dll /map /debug /machine:I386 /out:"..\Debug/gamex86.dll"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib /nologo /base:"0x11000000" /subsystem:windows /dll /map /debug /machine:I386 /out:"..\Arcade_Debug/gamex86.dll"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "game___4"
# PROP BASE Intermediate_Dir "game___4"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../Arcade_Release"
# PROP Intermediate_Dir "./Arcade_Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /G5 /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "SIN" /FR /YX /FD /c
# ADD CPP /nologo /G5 /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "SIN" /D "SIN_ARCADE" /FR /YX /FD /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "SIN" /d "SIN_DISABLECOPYPROTECTION"
# ADD RSC /l 0x409 /d "NDEBUG" /d "SIN" /d "SIN_DISABLECOPYPROTECTION"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winmm.lib /nologo /base:"0x11000000" /subsystem:windows /dll /machine:I386 /out:"..\Release/gamex86.dll"
# SUBTRACT BASE LINK32 /incremental:yes /map /debug
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winmm.lib /nologo /base:"0x11000000" /subsystem:windows /dll /map /machine:I386 /out:"..\Arcade_Release/gamex86.dll"
# SUBTRACT LINK32 /incremental:yes /debug

!ENDIF 

# Begin Target

# Name "game - Win32 Release"
# Name "game - Win32 Debug"
# Name "game - Win32 Debug Alpha"
# Name "game - Win32 Release Alpha"
# Name "game - Win32 Debug Demo"
# Name "game - Win32 Release Demo"
# Name "game - Win32 Debug Arcade"
# Name "game - Win32 Release Arcade"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\actor.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ammo.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\animals.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\archive.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\areaportal.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\armor.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\assaultrifle.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bacrodai.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\behavior.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bouncingbetty.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\box.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bspline.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\bullet.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\camera.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\camgun.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\chaingun.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\class.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\console.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ctf.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ctf_turret.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\deadbody.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\doors.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\earthquake.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\entity.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\eonandpeon.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\explosion.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fists.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_main.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_phys.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_spawn.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_utils.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gamescript.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genericbullet.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\genericrocket.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gibs.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\glowstick.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\grapple.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gravpath.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hammer.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\health.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\heligun.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\inventoryitem.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\item.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\keys.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\launcher.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\lensflare.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\light.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\listener.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\magnum.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\misc.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mover.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mutanthands.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\navigate.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\object.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\path.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\peon.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\player.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\PlayerStart.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\powerups.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pulserifle.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\q_shared.c

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\quantumd.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\reactiveshields.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rocket_turret.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rocketlauncher.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\script.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\scriptmaster.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\scriptslave.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\scriptvariable.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\secgun.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\securityturret.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sentient.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\shield.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\shotgun.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\shotrocketlauncher.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\silencer.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\skeet.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sniperrifle.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\speargun.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\specialfx.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\spidermine.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\steering.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\str.cpp

!IF  "$(CFG)" == "game - Win32 Release"

# ADD CPP /FR

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

# ADD BASE CPP /FR
# ADD CPP /FR

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

# ADD BASE CPP /FR
# ADD CPP /FR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\stungun.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\surface.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\testweapon.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\thrall.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\trigger.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\turret.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vehicle.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\viewthing.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\weapon.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\worldspawn.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\wrench.cpp

!IF  "$(CFG)" == "game - Win32 Release"

!ELSEIF  "$(CFG)" == "game - Win32 Debug"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Release Alpha"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Release Demo"

!ELSEIF  "$(CFG)" == "game - Win32 Debug Arcade"

!ELSEIF  "$(CFG)" == "game - Win32 Release Arcade"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\actor.h
# End Source File
# Begin Source File

SOURCE=.\ammo.h
# End Source File
# Begin Source File

SOURCE=.\archive.h
# End Source File
# Begin Source File

SOURCE=.\areaportal.h
# End Source File
# Begin Source File

SOURCE=.\armor.h
# End Source File
# Begin Source File

SOURCE=.\assaultrifle.h
# End Source File
# Begin Source File

SOURCE=.\bacrodai.h
# End Source File
# Begin Source File

SOURCE=.\behavior.h
# End Source File
# Begin Source File

SOURCE=.\bouncingbetty.h
# End Source File
# Begin Source File

SOURCE=.\box.h
# End Source File
# Begin Source File

SOURCE=.\bspline.h
# End Source File
# Begin Source File

SOURCE=.\bullet.h
# End Source File
# Begin Source File

SOURCE=.\camera.h
# End Source File
# Begin Source File

SOURCE=.\chaingun.h
# End Source File
# Begin Source File

SOURCE=.\class.h
# End Source File
# Begin Source File

SOURCE=.\console.h
# End Source File
# Begin Source File

SOURCE=.\container.h
# End Source File
# Begin Source File

SOURCE=.\ctf.h
# End Source File
# Begin Source File

SOURCE=.\ctf_turret.h
# End Source File
# Begin Source File

SOURCE=.\datamap.h
# End Source File
# Begin Source File

SOURCE=.\deadbody.h
# End Source File
# Begin Source File

SOURCE=.\doors.h
# End Source File
# Begin Source File

SOURCE=.\earthquake.h
# End Source File
# Begin Source File

SOURCE=.\entity.h
# End Source File
# Begin Source File

SOURCE=.\eonandpeon.h
# End Source File
# Begin Source File

SOURCE=.\explosion.h
# End Source File
# Begin Source File

SOURCE=.\fists.h
# End Source File
# Begin Source File

SOURCE=.\g_local.h
# End Source File
# Begin Source File

SOURCE=.\g_main.h
# End Source File
# Begin Source File

SOURCE=.\g_phys.h
# End Source File
# Begin Source File

SOURCE=.\g_spawn.h
# End Source File
# Begin Source File

SOURCE=.\g_utils.h
# End Source File
# Begin Source File

SOURCE=.\game.h
# End Source File
# Begin Source File

SOURCE=.\gamescript.h
# End Source File
# Begin Source File

SOURCE=.\genericbullet.h
# End Source File
# Begin Source File

SOURCE=.\genericrocket.h
# End Source File
# Begin Source File

SOURCE=.\gibs.h
# End Source File
# Begin Source File

SOURCE=.\grapple.h
# End Source File
# Begin Source File

SOURCE=.\gravpath.h
# End Source File
# Begin Source File

SOURCE=.\health.h
# End Source File
# Begin Source File

SOURCE=.\heligun.h
# End Source File
# Begin Source File

SOURCE=.\inventoryitem.h
# End Source File
# Begin Source File

SOURCE=.\item.h
# End Source File
# Begin Source File

SOURCE=.\lensflare.h
# End Source File
# Begin Source File

SOURCE=.\light.h
# End Source File
# Begin Source File

SOURCE=.\LINKLIST.H
# End Source File
# Begin Source File

SOURCE=.\listener.h
# End Source File
# Begin Source File

SOURCE=.\magnum.h
# End Source File
# Begin Source File

SOURCE=.\misc.h
# End Source File
# Begin Source File

SOURCE=.\mover.h
# End Source File
# Begin Source File

SOURCE=.\mutanthands.h
# End Source File
# Begin Source File

SOURCE=.\navigate.h
# End Source File
# Begin Source File

SOURCE=.\object.h
# End Source File
# Begin Source File

SOURCE=.\path.h
# End Source File
# Begin Source File

SOURCE=.\peon.h
# End Source File
# Begin Source File

SOURCE=.\player.h
# End Source File
# Begin Source File

SOURCE=.\PlayerStart.h
# End Source File
# Begin Source File

SOURCE=.\powerups.h
# End Source File
# Begin Source File

SOURCE=.\prioritystack.h
# End Source File
# Begin Source File

SOURCE=.\pulserifle.h
# End Source File
# Begin Source File

SOURCE=.\q_shared.h
# End Source File
# Begin Source File

SOURCE=.\quantumd.h
# End Source File
# Begin Source File

SOURCE=.\queue.h
# End Source File
# Begin Source File

SOURCE=.\rocket_turret.h
# End Source File
# Begin Source File

SOURCE=.\rocketlauncher.h
# End Source File
# Begin Source File

SOURCE=.\script.h
# End Source File
# Begin Source File

SOURCE=.\scriptmaster.h
# End Source File
# Begin Source File

SOURCE=.\scriptslave.h
# End Source File
# Begin Source File

SOURCE=.\scriptvariable.h
# End Source File
# Begin Source File

SOURCE=.\secgun.h
# End Source File
# Begin Source File

SOURCE=.\securityturret.h
# End Source File
# Begin Source File

SOURCE=.\sentient.h
# End Source File
# Begin Source File

SOURCE=.\shotgun.h
# End Source File
# Begin Source File

SOURCE=.\shotrocketlauncher.h
# End Source File
# Begin Source File

SOURCE=.\silencer.h
# End Source File
# Begin Source File

SOURCE=.\skeet.h
# End Source File
# Begin Source File

SOURCE=.\sniperrifle.h
# End Source File
# Begin Source File

SOURCE=.\speargun.h
# End Source File
# Begin Source File

SOURCE=.\specialfx.h
# End Source File
# Begin Source File

SOURCE=.\spidermine.h
# End Source File
# Begin Source File

SOURCE=.\stack.h
# End Source File
# Begin Source File

SOURCE=.\steering.h
# End Source File
# Begin Source File

SOURCE=.\str.h
# End Source File
# Begin Source File

SOURCE=.\stungun.h
# End Source File
# Begin Source File

SOURCE=.\surface.h
# End Source File
# Begin Source File

SOURCE=.\testweapon.h
# End Source File
# Begin Source File

SOURCE=.\thrall.h
# End Source File
# Begin Source File

SOURCE=.\trigger.h
# End Source File
# Begin Source File

SOURCE=.\turret.h
# End Source File
# Begin Source File

SOURCE=.\vector.h
# End Source File
# Begin Source File

SOURCE=.\vehicle.h
# End Source File
# Begin Source File

SOURCE=.\viewthing.h
# End Source File
# Begin Source File

SOURCE=.\weapon.h
# End Source File
# Begin Source File

SOURCE=.\worldspawn.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\game.def
# End Source File
# End Group
# End Target
# End Project
