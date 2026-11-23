CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

SRC = src/Task.cpp src/TaskPersonnel.cpp src/TaskProfessionnel.cpp src/User.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = todolist

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
