# CXX = g++
# CXXFLAGS = -std=c++20

# # COO_DIR = cpp
# # HPP_DIR = hpp
# OBJ_DIR = obj

# COO_SOURCES = csvreader.cpp users.cpp main.cpp requarment.cpp#$(wildcard $(COO_DIR)/*.cpp) 
# HPP_SOURCES = csvreader.hpp users.hpp requarment.hpp#$(wildcard $(HPP_DIR)/*.cpp)

# COO_OBJECTS = $(patsubst $(COO_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(COO_SOURCES))
# HPP_OBJECTS = $(patsubst $(HPP_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(HPP_SOURCES))

# TARGET = utms.out

# all: $(TARGET)

# $(OBJ_DIR)/%.o: $(COO_DIR)/%.cpp
# 	$(CXX) -c $(CXXFLAGS) -o $@ $<

# $(OBJ_DIR)/%.o: $(HPP_DIR)/%.cpp
# 	$(CXX) -c $(CXXFLAGS) -o $@ $<

# $(TARGET): $(COO_OBJECTS) $(HPP_OBJECTS)
# 	$(CXX) $^ -o $@ $(LDFLAGS)

# clean:
# 	rm -f $(OBJ_DIR)/*.o $(TARGET)

CXX = g++
CXXFLAGS = -std=c++20 
SOURCES = csvreader.cpp users.cpp main.cpp requarment.cpp
HEADERS = csvreader.hpp users.hpp requarment.hpp
OBJECTS = $(SOURCES:.cpp=.o) 
TARGET = utms.out 

all: $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(TARGET)
