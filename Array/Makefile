CC = g++
CFLAG = -std=c++11 -g

SOURCEDIR = .
BUILDDIR = ./build

EXECUTABLE = TestArray
SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

all : dir $(BUILDDIR)/$(EXECUTABLE)

dir:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(BUILDDIR)/*.o $(BUILDDIR)/$(EXECUTABLE)