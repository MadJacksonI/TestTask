TARGET = TestTaskProgram

CXX = g++

CXXFLAGS = -Wall -g

OBJS = main.o GanearateFlightCodes.o FilterUniqFlightCode.o CompareFlightCode.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

GanearateFlightCodes.o: GanearateFlightCodes.cpp
	$(CXX) $(CXXFLAGS) -c GanearateFlightCodes.cpp

FilterUniqFlightCode.o: FilterUniqFlightCode.cpp
	$(CXX) $(CXXFLAGS) -c FilterUniqFlightCode.cpp

CompareFlightCode.o: CompareFlightCode.cpp
	$(CXX) $(CXXFLAGS) -c CompareFlightCode.cpp

clean:
	rm -rf $(OBJS) $(TARGET)
