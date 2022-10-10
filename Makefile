# compiler options
CXXFLAGS = -std=c++11 -pedantic -Wall -Wuninitialized -Werror
main: main.o Scraper.o
	g++ $(CXXFLAGS) -o main main.o Scraper.o 
# only need to link if main.cpp has changed
main.o: main.cpp
	g++ -c $(CXXFLAGS) main.cpp 
# only compile if Scraper.h or Scraper.cpp has changed since last compile
Scraper.o: Scraper.h Scraper.cpp
	g++ -c $(CXXFLAGS) Scraper.cpp 
# only compile if person.h or person.cpp has changed since last compile
clean:
	rm -f main main.o Scraper.o