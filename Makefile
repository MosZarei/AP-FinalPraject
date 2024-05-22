CXX = g++
CXXFLAGS = -std=c++20

COO_DIR = cpp
HPP_DIR = hpp
OBJ_DIR = obj

COO_SOURCES = #$(wildcard $(COO_DIR)/*.cpp)
HPP_SOURCES = #$(wildcard $(HPP_DIR)/*.cpp)

COO_OBJECTS = $(patsubst $(COO_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(COO_SOURCES))
HPP_OBJECTS = $(patsubst $(HPP_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(HPP_SOURCES))

TARGET = utms.out

all: $(TARGET)

$(OBJ_DIR)/%.o: $(COO_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(HPP_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(TARGET): $(COO_OBJECTS) $(HPP_OBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
