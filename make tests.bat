:: Antoine Labrecque

g++ -Wall -Wextra -pedantic -c protectedChar.cpp
g++ -Wall -Wextra -pedantic -c item.cpp
g++ -Wall -Wextra -pedantic -c Node.cpp
g++ -Wall -Wextra -pedantic -c list.cpp
g++ -Wall -Wextra -pedantic -c tests.cpp
g++ -Wall -Wextra -pedantic -o tests.exe tests.o list.o Node.o item.o protectedChar.o

for %%S in ( *.cpp ) do (
    if `dir /b %%~nS.* /o-d` == %%S echo "hi"
)