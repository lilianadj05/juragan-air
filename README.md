# 💧 Juragan Air C Console Application

## 📌 Project Overview
This project is a C console application for managing a water beverage inventory. The program allows a user to add, edit, and delete two types of products: **mineral water** and **carbonated water**. It uses structures to store product information and provides a simple menu-driven interface for managing the inventory.

## 📊 Data Structure
The program uses two struct types to manage product information:
1. mineralWater: Stores the brand (merk) and size (size) of mineral water.
2. carboWater: Stores the brand (merk), size (size), and carbonated powder type (powder) for carbonated water.
Arrays of these structs are used to store the inventory.

## 🔑 Key Features
1. **Add New Products**: Users can add new mineral or carbonated water products to the inventory.
2. **Input Validation**: The program validates user input to ensure that the brand name is 2 characters long, the size is one of the valid options (240, 600, or 1500 ml), and the carbonated powder name is between 2 and 30 characters.
3. **Duplicate Prevention**: The program checks for existing products with the same brand and size (for mineral water) or brand, size, and powder (for carbonated water) to prevent duplicates.
4. **Manage Products**: Users can edit or delete existing products from the inventory.
5. **View Inventory**: The program can display a list of all products in the inventory.

## 📈 Steps
1. **Initialization**: The program initializes empty arrays to store mineral and carbonated water products.
2. **User Interface**: The main loop presents a menu with options to add new products, manage existing products, or exit.
3. **Product Management**: Functions are called based on the user's menu choice to handle tasks like adding, editing, or deleting products, with built-in validation checks.

## 💡 Conclusion
This C program serves as a functional and straightforward command-line tool for basic inventory management. It demonstrates the use of structs, arrays, and functions to create a simple, interactive application.

## 🔮 Possible Future Works
1. **Persistent Storage**: Implement functionality to save the inventory data to a file (e.g., a .txt or .csv file) so the data is not lost when the program closes.
2. **User Authentication**: Add a login system to restrict access to the inventory management features.
3. **Search Functionality**: Add an option to search for products by brand or size.
4. **Inventory Count**: Add a quantity field to track how many of each product are in stock.
5. **Sorting**: Implement sorting functionality to display the products in a specific order (e.g., by name or size).

## 👨‍💻 Author
**Liliana Djaja Witama** | Undergraduate Data Science Student at BINUS University
