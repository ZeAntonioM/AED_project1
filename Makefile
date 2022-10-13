# compiler options
CXXFLAGS = -std=c++11 -pedantic -Wall -Wuninitialized -Werror
all: main.o Scraper.o Date.o Aula.o
	g++ $(CXXFLAGS) -o all main.o Scraper.o Date.o Aula.o
# only need to link if main.cpp has changed
main.o: src/main.cpp
	g++ -c $(CXXFLAGS) src/main.cpp
# only compile if Scraper.h or Scraper.cpp has changed since last compile
Scraper.o: src/Scraper.h  src/Scraper.cpp
	g++ -c $(CXXFLAGS) src/Scraper.cpp

Date.o: src/Date.h  src/Date.cpp
	g++ -c $(CXXFLAGS) src/Date.cpp

Aula.o: src/Aula.h  src/Aula.cpp 
	g++ -c $(CXXFLAGS) src/Aula.cpp
	
clean:
	rm -f all main.o Scraper.o Date.o Aula.o