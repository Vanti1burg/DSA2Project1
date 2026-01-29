CXX = g++
CXXFLAGS = -g -Wall

TARGET = main
OBJECTS = main.o fileReader.o hash.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.cpp fileReader.hpp hash.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

fileReader.o: fileReader.cpp fileReader.hpp
	$(CXX) $(CXXFLAGS) -c fileReader.cpp
hash.o : hash.cpp hash.cpp
	$(CXX) $(CXXFLAGS) -c hash.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)
