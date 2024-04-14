# Specify the compiler
CXX = g++

# Specify the build flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Specify the source files
SRCS = fast_ncd.cpp
HDRS = fast_ncd.h

# Specify the test files
TEST_SRCS = $(wildcard test_*.cpp)

# Specify the object files
OBJS = $(SRCS:.cpp=.o)

# Specify the test object files
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Specify the output file
OUT = libnewFastNCD.so

# Specify the test output file
TEST_OUT = test_program

# Specify the libraries to link against
LIBS = -lboost_iostreams -lboost_system -lboost_filesystem -lsnappy -pthread

# Catch2 files
CATCH_CPP = catch2/catch_amalgamated.cpp

# Default target
all: $(OUT)

# Build the shared library
$(OUT): $(OBJS)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(LIBS)

# Rule for building the object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@

# Test target
test: $(TEST_OUT)

# Build the test binary
$(TEST_OUT): $(TEST_OBJS) $(OUT)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) $(CATCH_CPP)

# Clean target
clean:
	rm -f $(OBJS) $(OUT) $(TEST_OBJS) $(TEST_OUT)
