
#  Proxy Web Server

A **Multi-Threaded** HTTP Proxy Server written in **C**, designed to efficiently handle multiple simultaneous client requests while improving performance through an integrated **LRU** (Least Recently Used) caching system.



## Features

- 🌐 **HTTP Proxy Server:** Forwards client HTTP requests to target web servers and returns responses.  
- ⚙️ **Multi-threaded Architecture:** Handles multiple client connections simultaneously.  
- 🧠 **LRU Caching System:** Stores frequently accessed web pages to minimize redundant network requests.  
- 🔒 **Thread Synchronization:** Uses semaphores to ensure safe access to shared resources and prevent race conditions.  
- 📜 **Makefile Support:** Simplifies compilation and project management.



## Technologies Used

- **Programming Language:** C  
- **Core Concepts:** Socket Programming, Multi-threading, Synchronization with Semaphores  
- **Data Structures:** LRU Cache  
- **Build Tool:** Makefile  



## How It Works

1. Client sends an HTTP GET request to the proxy server.
2. Proxy checks the cache:
   - If present: sends cached response.
   - If not: forwards the request to the original server, caches the response, and returns it to the client.
3. Handles multiple clients simultaneously using multi-threading.
4. Uses semaphores to ensure mutual exclusion when accessing or modifying shared resources like the cache.



## Author

[**Gagandeep Singh Choudhary**](https://github.com/GagandeepSingh20)

---

⭐ If you like this project, don’t forget to **star the repository**!
