CXX = g++
CXXFLAGS = -std=c++20 
SOURCES = requarment.cpp csvreader.cpp errors.cpp users.cpp student.cpp professor.cpp course.cpp major.cpp superCommand.cpp postCommand.cpp deleteCommand.cpp getCommand.cpp main.cpp run.cpp
HEADERS = requarment.hpp csvreader.hpp errors.hpp users.hpp student.hpp professor.hpp course.hpp major.hpp superCommand.hpp main.hpp
OBJECTS = $(SOURCES:.cpp=.o) 
TARGET = utms.out 

all: $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(TARGET)
