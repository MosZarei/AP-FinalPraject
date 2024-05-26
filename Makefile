CXX = g++
CXXFLAGS = -std=c++20 
SOURCES = csvreader.cpp users.cpp main.cpp requarment.cpp run.cpp student.cpp
HEADERS = csvreader.hpp users.hpp requarment.hpp main.hpp student.hpp
OBJECTS = $(SOURCES:.cpp=.o) 
TARGET = utms.out 

all: $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(TARGET)
