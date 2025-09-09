# Makefile for Smart Parking Management System
# Author: [Your Name]
# Date: [Current Date]

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = parking
SOURCE = main.cpp

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SOURCE)
	@echo "🔨 Compiling Smart Parking Management System..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)
	@echo "✅ Compilation successful! Run with: ./$(TARGET)"

# Clean build files
clean:
	@echo "🧹 Cleaning build files..."
	rm -f $(TARGET)
	@echo "✅ Clean complete!"

# Install (copy to /usr/local/bin - requires sudo)
install: $(TARGET)
	@echo "📦 Installing parking system..."
	sudo cp $(TARGET) /usr/local/bin/
	@echo "✅ Installation complete! You can now run 'parking' from anywhere."

# Uninstall
uninstall:
	@echo "🗑️  Uninstalling parking system..."
	sudo rm -f /usr/local/bin/$(TARGET)
	@echo "✅ Uninstallation complete!"

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: $(TARGET)
	@echo "🐛 Debug build complete!"

# Release build (optimized)
release: CXXFLAGS += -O3 -DNDEBUG
release: clean $(TARGET)
	@echo "🚀 Release build complete!"

# Run the program
run: $(TARGET)
	@echo "🚗 Starting Smart Parking Management System..."
	./$(TARGET)

# Check for memory leaks (requires valgrind)
memcheck: $(TARGET)
	@echo "🔍 Running memory check..."
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Display help
help:
	@echo "🚗 Smart Parking Management System - Build Help"
	@echo "==============================================="
	@echo "Available targets:"
	@echo "  all       - Build the program (default)"
	@echo "  clean     - Remove build files"
	@echo "  debug     - Build with debug symbols"
	@echo "  release   - Build optimized release version"
	@echo "  run       - Build and run the program"
	@echo "  install   - Install to system (requires sudo)"
	@echo "  uninstall - Remove from system (requires sudo)"
	@echo "  memcheck  - Run with valgrind memory checker"
	@echo "  help      - Show this help message"

# Declare phony targets
.PHONY: all clean install uninstall debug release run memcheck help
