# Smart Parking Management System

A comprehensive C++ implementation of a parking lot management system using linked lists with real-time parking visualization. The program efficiently manages vehicle parking, exit operations, and provides detailed statistics with beautiful console interface.

## 🌟 Features

- **Dynamic parking management** with user-defined capacity
- **Real-time parking visualization** with status indicators
- **Smart plate number validation** and normalization
- **Owner information tracking** with entry timestamps
- **Advanced search functionality** for quick vehicle lookup
- **Comprehensive statistics** with occupancy rates and status
- **Data structure optimization** using linked lists for efficient operations
- **Input validation** and error handling for robust performance
- **Interactive console interface** with emoji-enhanced user experience
- **Memory management** with proper cleanup and destructor implementation

## 🚗 System Capabilities

- Park vehicles with automatic duplicate detection
- Exit vehicles with detailed time tracking
- Search for specific vehicles by plate number
- Display all parked vehicles in organized format
- View real-time parking statistics and occupancy rates
- Clear entire parking lot with confirmation
- Normalize plate numbers (uppercase, space removal)
- Validate owner names and plate formats

## 💻 Requirements

- **C++11 or later**
- **GCC compiler (g++)** or any modern C++ compiler
- **Terminal/Console** that supports emoji and ASCII characters
- **Windows/Linux/macOS** compatible

## 🚀 Quick Start

### Option 1: Direct Compilation
```bash
# Clone the repository
git clone https://github.com/PRANAVZALKE/smart-parking-system.git

# Navigate to source directory
cd smart-parking-system/src

# Compile the program
g++ -std=c++11 -o parking main.cpp

# Run the program
./parking
```

### Option 2: Using Makefile
```bash
cd smart-parking-system/src
make
./parking
```

## 📖 Usage Instructions

1. **Run the program**
2. **Enter parking lot capacity** when prompted (recommended: 10-50 spaces)
3. **Choose from the menu options:**
   - Park a new vehicle
   - Exit an existing vehicle
   - View all parked vehicles
   - Search for a specific vehicle
   - Check parking statistics
   - Clear all vehicles
   - Exit the system

## 💡 Example Usage

```
🚗 Welcome to Smart Parking Management System!
==================================================
Enter parking lot capacity: 20

🚗 === SMART PARKING MANAGEMENT SYSTEM ===
1. 🅿️  Park Car
2. 🚪 Exit Car
3. 📋 Display All Parked Cars
4. 🔍 Search Car
5. 📈 View Statistics
6. 🧹 Clear All Cars
7. ❌ Exit Program
---------------------------------------------
Enter your choice (1-7): 1

Enter car plate number: ABC 123
Enter owner name: John Smith

✅ Car parked successfully!
📋 Details: Plate: ABC123, Owner: John Smith
🕒 Entry Time: Mon Jan 15 14:30:25 2024
📊 Available spots: 19/20
```

## 🏗️ System Architecture

The system uses an efficient **linked list data structure** for parking management:

- **LIFO (Last In, First Out)** approach for optimal space utilization
- **Dynamic memory allocation** for scalable parking capacity
- **O(1) insertion** for parking operations
- **O(n) search** for vehicle lookup and exit operations
- **Memory-efficient** node-based structure

### Core Components

- **Car Structure**: Stores vehicle information (plate, owner, timestamp)
- **ParkingLot Class**: Manages all parking operations and validations
- **Input Validation**: Ensures data integrity and format compliance
- **Time Tracking**: Records entry/exit timestamps for each vehicle

## 📊 System Performance

- **Time Complexity:**
  - Park Car: O(1)
  - Exit Car: O(n)
  - Search Car: O(n)
  - Display All: O(n)
  
- **Space Complexity:** O(n) where n = number of parked vehicles

## 🗂️ Project Structure

```
smart-parking-system/
├── README.md
├── src/
│   ├── main.cpp
│   └── Makefile
├── screenshots/
│   ├── main_menu.png
│   ├── parking_process.png
│   ├── vehicle_display.png
│   └── statistics_view.png
├── docs/
│   ├── system_design.md
│   └── user_manual.md
└── .gitignore
```

## ⚙️ Customization Options

You can modify the following parameters in the code:

- **Plate validation rules**: Modify `isValidPlate()` function
- **Owner name requirements**: Customize `isValidOwner()` function
- **Time format**: Change `getCurrentTime()` implementation
- **Display formatting**: Modify console output in display functions
- **Capacity limits**: Adjust validation ranges

## 🔧 Technical Highlights

This project demonstrates:

- **Object-oriented programming** with classes and encapsulation
- **Dynamic memory management** with proper cleanup
- **Data structure implementation** using linked lists
- **Input validation and error handling**
- **Time manipulation** with C++ time libraries
- **String processing** and normalization
- **Console interface design** with formatted output

## 🐛 Troubleshooting

- **Compilation errors**: Ensure you have C++11 or later support
- **Display issues**: Check terminal emoji support or disable emojis
- **Memory issues**: Verify proper destructor implementation
- **Input problems**: Check string input handling with spaces

## 👨‍💻 Author

**Pranav Arvind Zalke**  
CSE AI/DS Student
PIET, Parul University 

## 📄 License

This project is open source and available under the MIT License.

## 🙏 Acknowledgments

- Linked list data structure implementation
- C++ standard library for time and string manipulation
- Console interface design patterns
- Object-oriented programming principles

## 🤝 Contributing

Feel free to fork this project and submit pull requests for improvements:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

## 🌟 Future Enhancements

- GUI implementation using Qt or other frameworks
- Database integration for persistent storage
- Multi-level parking support
- Payment system integration
- Mobile app connectivity
- Real-time sensor integration
