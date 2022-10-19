# compiler options
CXXFLAGS = -std=c++11 -pedantic -Wall -Wuninitialized -Werror
all: main.o Scraper.o Cli.o
	g++ $(CXXFLAGS) -o all main.o Scraper.o Cli.o
# only need to link if main.cpp has changed
main.o: src/main.cpp
	g++ -c $(CXXFLAGS) src/main.cpp
# only compile if Scraper.h or Scraper.cpp has changed since last compile
Scraper.o: src/Scraper.h  src/Scraper.cpp
	g++ -c $(CXXFLAGS) src/Scraper.cpp
Cli.o: src/Cli.h  src/Cli.cpp
	g++ -c $(CXXFLAGS) src/Cli.cpp
clean:
	rm -f all main.o Scraper.o Cli.o