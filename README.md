# Noted
Noted is a wxWidgets application that allows users to interact with a database using a graphical user interface (GUI). It provides functionality to store, retrieve, update, and delete data records from a SQLite database.

## Features

- MainFrame: The main window of the application where users can enter search criteria and view the results.
- AddFrame: A secondary window that allows users to add new data records to the database.
- DeleteFrame: A secondary window that allows users to delete data records from the database.
- SearchFrame: A secondary window that allows users to search data records in the database and display it.

## Prerequisites

- C++ compiler with C++11 support
- wxWidgets library 
- SQLite library 
- CMake  - Optional: only required if you choose to build using CMake

## Getting Started

1. Clone the repository:

```shell
git clone https://github.com/9Neil259/Noted.git

2.Build the application:

a. Using CMake (Recommended):

cd MyApp
mkdir build
cd build
cmake ..
make

b. Using your preferred build system (e.g., Visual Studio, Xcode, etc.)

3.Run the application:

./Noted

#Usage
 Click the "Search" button in the main window (MainFrame) to open a new window (AnotherFrame) where you enter data to display the data from the database.

Click the "Add" button in the main window (MainFrame) to open a new window (AddFrame) where you can enter data to add a new record to the database.

Click the "Delete" button in the main window (MainFrame) to open a new window (DeleteFrame) where you can enter data to delete matching records from the database.

Contributing
Contributions are welcome! If you have any suggestions, bug reports, or feature requests, please open an issue on the GitHub repository.

#License
This project is licensed under the GPL-3.0 license.


Feel free to modify the contents according to your project's specific requirements and details
