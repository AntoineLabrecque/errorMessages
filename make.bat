:: Antoine Labrecque
setlocal enableextensions
if not "%1" == "build" (
    if not "%1" == "" (
        if "%1" == "run" (
            set "run=1"
        ) else (
            goto :fileCheck
        )
    )
)
shift
:fileCheck
if not "%1" == "tests" (
    if not "%1" == "app" (
        if not "%1" == "" (
            goto :buildCheck
        )
    )
    set "sources=errorMessagesJournalApp.cpp"
) else (
    set "sources=tests.cpp"
)
set "build=1"
:buildCheck
if "%build%"="1" (
    set "sources=list.cpp Node.cpp item.cpp protectedChar.cpp"
    for %%S in ( "%sources%" ) do (
        if `"dir /b %%~nS.o %%~nS.h %%S /o-d"` gtr %%~nS.o (
            g++ -Wall -Wextra -pedantic -c %%S
        )
    )

    ::g++ -Wall -Wextra -pedantic -o tests.exe tests.o list.o Node.o item.o protectedChar.o
    if "%run%" == "1" (
        tests.exe
    )
    exit /b
) else if "%1" == "burninate" (
    rm tests.exe errorMessagesJournalApp.exe
    goto :clean
    exit /b
) else if "%1" == "clean" (
    :clean
    rm -d tests.o errorMessagesJournalApp.o list.o Node.o item.o protectedChar.o
    exit /b
)