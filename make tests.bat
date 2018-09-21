:: Antoine Labrecque

g++ -Wall -Wextra -pedantic -c protectedChar.cpp
g++ -Wall -Wextra -pedantic -c item.cpp
g++ -Wall -Wextra -pedantic -c Node.cpp
g++ -Wall -Wextra -pedantic -c list.cpp
g++ -Wall -Wextra -pedantic -c tests.cpp
g++ -Wall -Wextra -pedantic -o tests.exe tests.o list.o Node.o item.o protectedChar.o

for %%source in ( forfiles /m *.cpp /c "echo @fname" ) do
(
    if ( dir /b %%source.* /o-d
)