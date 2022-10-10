# compiler options
CXXFLAGS = -std=c++11 -pedantic -Wall -Wuninitialized -Werror -Iheaders
all: main.o Scraper.o
	g++ $(CXXFLAGS) -o all main.o Scraper.o
# only need to link if main.cpp has changed
main.o: main.cpp
	g++ -c $(CXXFLAGS) main.cpp
# only compile if Scraper.h or Scraper.cpp has changed since last compile
Scraper.o: headers/Scraper.h Scraper.cpp
	g++ -c $(CXXFLAGS) Scraper.cpp
clean:
	rm -f all main.o Scraper.o