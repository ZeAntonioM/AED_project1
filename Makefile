# compiler options
CXXFLAGS = -std=c++11 -pedantic -Wall -Wuninitialized -Werror -Iheaders
all: main.o Scraper.o
	g++ $(CXXFLAGS) -o all main.o Scraper.o
# only need to link if main.cpp has changed
main.o: src/main.cpp
	g++ -c $(CXXFLAGS) src/main.cpp
# only compile if Scraper.h or Scraper.cpp has changed since last compile
Scraper.o: src/Scraper.h  src/Scraper.cpp
	g++ -c $(CXXFLAGS) src/Scraper.cpp
clean:
	rm -f all main.o Scraper.o