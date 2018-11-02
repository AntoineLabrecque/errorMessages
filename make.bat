:: Antoine Labrecque
SETLOCAL ENABLEEXTENSIONS
if %1 ==. (
    set "sources=list.cpp Node.cpp item.cpp protectedChar.cpp"
    for %%S in ( %sources% ) do (
        if `"dir /b %%~nS.o %%~nS.h %%S /o-d"` gtr %%~nS.o (
            g++ -Wall -Wextra -pedantic -c %%S
        )
    )

    g++ -Wall -Wextra -pedantic -o tests.exe tests.o list.o Node.o item.o protectedChar.o
)
if %1 == clean (
    echo
)
if %1 == burninate (
    rm *.exe
)