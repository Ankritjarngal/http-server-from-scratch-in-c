# C HTTP Server

## Overview
This project is a simple HTTP server written in C that supports **GET, POST, PUT, and DELETE** requests. The server listens on port **8080** and logs each request to `index.html` for visualization.

## Why This Project?
This project was created as part of learning network programming and understanding how web servers work.
 By implementing an HTTP server from scratch in C, the goal is to gain hands-on experience with socket programming, HTTP request handling, and response generation.
 It serves as an educational tool to explore how real-world web servers process client requests and manage data.
## Features
- Handles **GET, POST, PUT, and DELETE** requests.
- Logs requests to `index.html` for visualization.
- Implements basic HTTP response handling.

## Requirements
- **Windows OS** (uses Winsock2 for socket programming)
- **MinGW or MSVC** compiler
- **Postman** (or any API testing tool)

## Setup and Installation
1. **Clone the Repository**
   ```sh
   git clone https://github.com/Ankritjarngal/http-server-from-scratch-in-c.git
   cd http-server-from-scratch-in-c

   ```
2. **Compile the Code**
   ```sh
   gcc server.c -o server.exe -lws2_32
   ```
3. **Run the Server**
   ```sh
   ./server.exe
   ```
4. **Test with Postman( you can  use any other testing tool or method too)**
   - **GET Request:**
     ```
     URL: http://localhost:8080/test
     Method: GET
     ```
   - **POST Request:**
     ```
     URL: http://localhost:8080/test
     Method: POST
     Body: {"message": "Hello World"}
     ```
   - **PUT Request:**
     ```
     URL: http://localhost:8080/test
     Method: PUT
     Body: {"message": "Updated Data"}
     ```
   - **DELETE Request:**
     ```
     URL: http://localhost:8080/test
     Method: DELETE
     ```

## How `index.html` Works
- The server logs incoming requests to `index.html`.
- Each method (GET, POST, PUT, DELETE) updates `index.html` dynamically.
- You can open `index.html` in a browser to see the latest request details.



