# Smart Parking Management System - User Manual

## 📖 Table of Contents

1. [Getting Started](#getting-started)
2. [System Overview](#system-overview)
3. [Operating Instructions](#operating-instructions)
4. [Feature Guide](#feature-guide)
5. [Input Guidelines](#input-guidelines)
6. [Troubleshooting](#troubleshooting)
7. [Tips & Best Practices](#tips--best-practices)

## 🚀 Getting Started

### System Requirements
- **Operating System:** Windows, Linux, or macOS
- **Compiler:** C++11 compatible compiler (GCC, Clang, MSVC)
- **Memory:** Minimum 512MB RAM
- **Storage:** 50MB free space
- **Terminal:** Console with basic text support

### Installation Steps

1. **Download/Clone the project:**
   ```bash
   git clone https://github.com/[USERNAME]/smart-parking-system.git
   cd smart-parking-system
   ```

2. **Compile the program:**
   ```bash
   cd src
   g++ -std=c++11 -o parking main.cpp
   ```

3. **Run the application:**
   ```bash
   ./parking
   ```

### First Launch
Upon launching, you'll be prompted to enter the parking lot capacity:
```
🚗 Welcome to Smart Parking Management System!
==================================================
Enter parking lot capacity: 20
```

**Recommended capacity ranges:**
- Small parking: 10-50 spots
- Medium parking: 50-200 spots  
- Large parking: 200-1000 spots

## 🏢 System Overview

### Main Interface
The system presents a user-friendly menu with emoji indicators:

```
🚗 === SMART PARKING MANAGEMENT SYSTEM ===
1. 🅿️  Park Car
2. 🚪 Exit Car
3. 📋 Display All Parked Cars
4. 🔍 Search Car
5. 📈 View Statistics
6. 🧹 Clear All Cars
7. ❌ Exit Program
---------------------------------------------
Enter your choice (1-7):
```

### Status Indicators
- ✅ Success operations
- ❌ Error conditions
- ⚠️ Warnings
- 🚫 Blocked operations
- 💡 Helpful tips
- 📊 Statistics
- 🕒 Time information

## 🎯 Operating Instructions

### Starting the System

1. **Launch the application**
2. **Set parking capacity** (one-time setup)
3. **Navigate using the numbered menu**
4. **Follow on-screen prompts**

### Basic Workflow

```
Start → Set Capacity → Main Menu → Choose Operation → Enter Data → View Results → Continue
```

## 🔧 Feature Guide

### 1. 🅿️ Park Car

**Purpose:** Add a new vehicle to the parking lot

**Steps:**
1. Select option `1` from main menu
2. Enter car plate number when prompted
3. Enter owner's name when prompted
4. System validates and parks the vehicle

**Example:**
```
Enter car plate number: ABC 123
Enter owner name: John Smith

✅ Car parked successfully!
📋 Details: Plate: ABC123, Owner: John Smith
🕒 Entry Time: Mon Jan 15 14:30:25 2024
📊 Available spots: 19/20
```

**Features:**
- Automatic plate normalization (removes spaces, converts to uppercase)
- Duplicate prevention
- Capacity checking
- Timestamp recording

### 2. 🚪 Exit Car

**Purpose:** Remove a vehicle from the parking lot

**Steps:**
1. Select option `2` from main menu
2. Enter the plate number of the car to exit
3. System locates and removes the vehicle

**Example:**
```
Enter car plate number to exit: abc123

✅ Car exited successfully!
📋 Details: Plate: ABC123, Owner: John Smith
🕒 Entry Time: Mon Jan 15 14:30:25 2024
🕒 Exit Time: Mon Jan 15 16:45:10 2024
📊 Available spots: 20/20
```

**Features:**
- Flexible plate number input (case-insensitive)
- Complete parking history display
- Automatic spot availability update

### 3. 📋 Display All Parked Cars

**Purpose:** View all currently parked vehicles

**Steps:**
1. Select option `3` from main menu
2. System displays formatted table of all parked cars

**Example Output:**
```
🚗 === ACTIVE PARKED CARS ===
------------------------------------------------------------
#     Plate       Owner          Entry Time
------------------------------------------------------------
1     ABC123      John Smith     Mon Jan 15 14:30:25 2024
2     XYZ789      Jane Doe       Mon Jan 15 15:22:18 2024
3     DEF456      Bob Johnson    Mon Jan 15 15:45:33 2024
------------------------------------------------------------
📊 Total parked: 3/20 | Available: 17
```

**Features:**
- Organized tabular format
- Position numbering
- Real-time statistics
- Empty lot detection

### 4. 🔍 Search Car

**Purpose:** Find specific vehicle information

**Steps:**
1. Select option `4` from main menu
2. Enter the plate number to search
3. View detailed vehicle information

**Example:**
```
Enter car plate number to search: abc123

🔍 Car Found!
📋 Plate: ABC123
👤 Owner: John Smith
🕒 Entry Time: Mon Jan 15 14:30:25 2024
📍 Position in queue: 1
```

**Features:**
- Case-insensitive search
- Detailed information display
- Queue position tracking

### 5. 📈 View Statistics

**Purpose:** Monitor parking lot performance and utilization

**Steps:**
1. Select option `5` from main menu
2. View comprehensive statistics

**Example Output:**
```
📈 === PARKING STATISTICS ===
🏢 Total Capacity: 20 spots
🚗 Cars Parked: 12 vehicles
🅿️  Available Spots: 8 spaces
📊 Occupancy Rate: 60.0%
🟢 Status: Moderate
```

**Status Categories:**
- 🔴 **FULL:** 100% occupancy
- 🟡 **Nearly Full:** 80-99% occupancy  
- 🟢 **Moderate:** 50-79% occupancy
- 🟢 **Plenty of Space:** 0-49% occupancy

### 6. 🧹 Clear All Cars

**Purpose:** Remove all vehicles from parking lot

**Steps:**
1. Select option `6` from main menu
2. Confirm the action when prompted
3. All vehicles are cleared from the system

**Safety Feature:**
```
⚠️  Are you sure you want to clear all cars? (y/N): y
✅ All cars have been cleared from the parking lot.
```

**Use Cases:**
- End of day cleanup
- System maintenance
- Emergency situations

### 7. ❌ Exit Program

**Purpose:** Safely close the application

**Steps:**
1. Select option `7` from main menu
2. System performs cleanup and exits

**Exit Message:**
```
👋 Thank you for using Smart Parking Management System!
🚗 Drive safely!
```

## 📝 Input Guidelines

### Plate Number Format

**Accepted Formats:**
- `ABC123` (standard format)
- `abc 123` (with spaces - will be normalized)
- `Abc-123` (with hyphens)
- `12345` (numbers only)

**Requirements:**
- Length: 3-10 characters
- Alphanumeric characters allowed
- Spaces and special characters are automatically removed
- Case-insensitive (converted to uppercase)

**Invalid Examples:**
- `AB` (too short)
- `ABCDEFGHIJK` (too long)
- `` (empty)

### Owner Name Format

**Requirements:**
- Minimum 2 characters
- Can include spaces and special characters
- Case-sensitive (preserved as entered)

**Valid Examples:**
- `John Smith`
- `María García`
- `O'Connor`
- `李明`

**Invalid Examples:**
- `J` (too short)
- `` (empty)

## 🔧 Troubleshooting

### Common Issues

#### Issue: "Invalid plate number!"
**Cause:** Plate doesn't meet length requirements (3-10 characters)
**Solution:** Enter a plate number between 3-10 characters

#### Issue: "Car already parked!"
**Cause:** Attempting to park a vehicle that's already in the system
**Solution:** Use the search function to verify, or exit the car first

#### Issue: "Parking lot is full!"
**Cause:** No available parking spaces
**Solution:** Wait for vehicles to exit or increase capacity

#### Issue: "Car not found"
**Cause:** Searching for a vehicle that isn't parked
**Solution:** Check plate number spelling or use display all function

### Performance Issues

#### Slow Response Time
**Possible Causes:**
- Large number of parked vehicles (>1000)
- System memory constraints
- Terminal performance issues

**Solutions:**
- Reduce parking lot size
- Clear unnecessary vehicles
- Use release build (`make release`)

#### Memory Issues
**Symptoms:** Program crashes or becomes unresponsive
**Solutions:**
- Check available system memory
- Restart the program
- Reduce parking capacity

### Input Problems

#### Compilation Errors
```bash
# Ensure C++11 support
g++ --version

# Use correct compilation flags
g++ -std=c++11 -o parking main.cpp
```

#### Character Display Issues
**Problem:** Emojis not displaying correctly
**Solution:** Use a terminal that supports UTF-8 encoding

## 💡 Tips & Best Practices

### Operational Tips

1. **Regular Monitoring:**
   - Check statistics periodically
   - Monitor occupancy rates
   - Track peak usage times

2. **Data Management:**
   - Use clear all function at end of day
   - Maintain consistent plate number formats
   - Keep owner names accurate

3. **Efficiency:**
   - Use search function for quick lookups
   - Display all cars for overview
   - Monitor available spots regularly

### Performance Optimization

1. **Memory Management:**
   - Don't exceed recommended capacity
   - Clear unused data regularly
   - Monitor system resources

2. **User Experience:**
   - Enter complete information accurately
   - Use consistent naming conventions
   - Follow the natural workflow

### Security Considerations

1. **Data Privacy:**
   - System doesn't store sensitive information
   - Data is cleared when program exits
   - No network connections made

2. **Access Control:**
   - Physical access to terminal required
   - No remote access capabilities
   - Local operation only

## 📞 Support Information

### Getting Help

1. **Built-in Help:** Use the menu system for guidance
2. **Documentation:** Refer to README.md and system design docs  
3. **Error Messages:** Read system feedback carefully
4. **Community:** Check project repository for updates

### Reporting Issues

When reporting problems, include:
- Operating system and version
- Compiler used
- Error messages received
- Steps to reproduce the issue
- Expected vs actual behavior

### System Limitations

1. **Capacity:** Recommended maximum 10,000 vehicles
2. **Data Persistence:** Data not saved between sessions
3. **Concurrent Access:** Single-user operation only
4. **Network Features:** No remote management capabilities

This user manual provides comprehensive guidance for operating the Smart Parking Management System efficiently and effectively. For technical details, refer to the System Design documentation.
