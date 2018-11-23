:: Antoine Labrecque
setlocal enableextensions enabledelayedexpansion
if "%1" == "burninate" (
    rm tests.exe errorMessagesJournalApp.exe
    goto :clean
    exit /b
) else if "%1" == "clean" (
    :clean
    rm -d tests.o errorMessagesJournalApp.o list.o Node.o item.o protectedChar.o
    exit /b
) else if "%1" == "run" (
    set "run=1"
) else if not "%1" == "all" (
        if not "%1" == "" (
            goto :fileCheck
            exit /b
        )
    )
)
shift
:fileCheck
if "%1" == "tests" (
    set "sources=tests.cpp"
) else if not "%1" == "app" (
        if not "%1" == "" (
            set "sources=%1.cpp"
            goto :buildCheck
            exit /b
        )
    )
)
set "sources=errorMessagesJournalApp.cpp"
:buildCheck
if "%sources%" == "errorMessagesJournalApp.cpp" (
    goto :listDependency
    exit /b
) else if "%sources%" == "tests.cpp" (
    goto :listDependency
    exit /b
) else if "%sources%" == "list.cpp" (
    :nodeDependency
    set "sources=%sources% Node.cpp"
    goto :itemDependency
    exit /b
) else if "%sources%" == "Node.cpp" (
    :itemDependency
    set "sources=%sources% item.cpp"
    goto :protectedCharDependency
    exit /b
) else if "%sources%" == "item.cpp" (
    :protectedCharDependency
    set "sources=%sources% protectedChar.cpp"
)
for /f %%S in ( 'dir /b %sources%' ) do (
    for /f %%T in ( tmp.txt ) do (
        echo ERROR: file tmp.txt exists!
        exit /b
    )
    dir /b /o-d %%~nS.o %%~nS.h %%S > tmp.txt
    set /p tmp= < tmp.txt
    rm tmp.txt
    if not "!tmp!" == "%%~nS.o" (
        g++ -Wall -Wextra -pedantic -c %%S
    )
)

::g++ -Wall -Wextra -pedantic -o tests.exe tests.o list.o Node.o item.o protectedChar.o
if "%run%" == "1" (
    tests.exe
)
exit /b
:listDependency
set "sources=%sources% list.cpp"
goto :nodeDependency
exit /b
:: Antoine Labrecque