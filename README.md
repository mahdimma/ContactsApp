# Contact Management System

Welcome to the Contact Management System (in Command Line) repository! This project is a simple C++ application designed to manage contacts efficiently. It provides functionalities to add, delete, and view contacts, making it a handy tool for personal or small-scale organizational use.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Add Contacts**: Easily add new contacts with details such as name, phone number, and email.
- **Delete Contacts**: Remove contacts that are no longer needed.
- **View Contacts**: List all contacts stored in the system.
- **Search Contacts**: Quickly find specific contacts using search functionality.

## Installation

To get started with the Contact Management System, follow these steps:

1. **Clone the repository**:

   ```sh
   git clone https://github.com/mahdimma/contactsApp.git
   cd contactsApp
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

Upon running the application, you will be presented with a menu to perform various operations:

- **Add Contact**: Enter the details of the new contact.
- **Edit Contact**: edit the details of the exist contact.

- **Delete Contact**: Provide the name or ID of the contact to delete.
- **Delete All Contact**: Provide delete of all contact.
- **View Contacts**: Displays all the contacts currently stored.
- **Search Contact**: Enter a name or part of the name to search for a contact.
- **Exit**: Closes the application.
- **Save To File**: save contact in file.

## Contributing

Contributions are welcome! If you have any ideas, suggestions, or bug reports, please open an issue or submit a pull request. Make sure to follow the existing coding style and include appropriate tests for new features.

## License

This project is licensed under the GNU General Public License v3.0 License. See the [LICENSE](LICENSE) file for more details.

---
