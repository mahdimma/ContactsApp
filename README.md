# Contact Management System

Welcome to the Contact Management System (in Command Line) repository! it a handy tool for personal or small-scale organizational use.

## Overview

The Contact Management Application is a C++ program designed to help users manage their personal contacts efficiently. This application allows users to add, view, edit, delete, and search for contacts, as well as save and load contacts from a file. The program features a text-based menu for easy interaction and utilizes object-oriented programming principles for modularity and scalability.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [File-Structure](#file-structure)
- [Dependencies](#dependencies)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Add Contacts**: Users can add new contacts by providing a first name, last name, and phone number.
- **View Contacts**: Users can view all contacts or search for a specific contact by name or phone number.
- **Edit Contacts**: Users can edit existing contacts by selecting a contact and modifying its details.
- **Delete Contacts**: Users can delete individual contacts or clear the entire contact list.
- **Search Contacts**: Users can search for contacts by first name, last name, or phone number.
- **Save and Load Contacts**: The application saves the contact list to a file when the user exits and loads the contacts from the file when the application starts.

## Installation

To get started with the Contact Management System, follow these steps:

1. **Clone the repository**:

   ```sh
   git clone https://github.com/mahdimma/ContactsApp.git
   cd ContactsApp
   ```

2. **Compile the project**:

   ```sh
   g++ main.cpp Contact.cpp Contacts.cpp Tools.cpp -o contact_manager
   ```

3. **Run the executable**:
   ```sh
   ./contact_manager
   ```

## Usage

Upon running the application, users are presented with a text-based menu where they can select options by entering numbers corresponding to the desired action. The menu includes the following options:

1. **Add a Contact**
2. **Show a Contact**
3. **Delete a Contact**
4. **Find a Contact**
5. **Edit a Contact**
6. **Show All Contacts**
7. **Delete All Contacts**
8. **Exit**

## File-Structure

- `contact.h` and `contact.cpp`: Define the `Contact` class, which encapsulates the details of a single contact.
- `contacts.h` and `contacts.cpp`: Define the `Contacts` class, which manages a vector of `Contact` objects and provides methods for interacting with the collection.
- `tools.h` and `tools.cpp`: Define the `Tools` class, which provides utility functions for the application.
- `main.cpp`: Contains the main function, which initializes the application, handles user input, and coordinates interactions between the `Contacts` and `Tools` classes.

## Dependencies

- Standard C++ libraries
- Windows-specific libraries for directory operations (Windows.h, lmcons.h)

## Contributing

Contributions are welcome! If you have any ideas, suggestions, or bug reports, please open an issue or submit a pull request. Make sure to follow the existing coding style and include appropriate tests for new features.

## License

This project is licensed under the GNU General Public License v3.0 License. See the [LICENSE](LICENSE) file for more details.

---
