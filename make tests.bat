:: Antoine Labrecque

g++ -Wall -Wextra -pedantic -o tests.exe tests.o list.o Node.o item.o protectedChar.o

set sources=""
for %%S in ( *.cpp ) do (
    if `"dir /b %%~nS.o %%~nS.h %%S /o-d"` gtr %%~nS.o (
        g++ -Wall -Wextra -pedantic -c %%S
    )
)
