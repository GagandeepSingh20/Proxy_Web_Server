
# 🧰 Proxy Web Server

A **Multi-Threaded HTTP Proxy Server** written in **C**, designed to efficiently handle multiple simultaneous client requests while improving performance through an integrated **LRU (Least Recently Used) caching system**. This project demonstrates key concepts in networking, concurrency, and caching, making it an excellent learning resource for systems programming.

---

## 🧠 Overview

The **Proxy Web Server** acts as an intermediary between clients and target web servers. It listens for HTTP requests, forwards them to the appropriate destination, and relays responses back to the clients.  
By integrating a **multi-threaded architecture** and an **LRU caching system**, the server achieves high concurrency and improved response times, significantly reducing repetitive network requests.

---

## ✨ Features

- 🌐 **HTTP Proxy Server:** Forwards client HTTP requests to target web servers and returns responses.  
- ⚙️ **Multi-threaded Architecture:** Handles multiple client connections simultaneously.  
- 🧠 **LRU Caching System:** Stores frequently accessed web pages to minimize redundant network requests.  
- 🔒 **Thread Synchronization:** Uses semaphores to ensure safe access to shared resources and prevent race conditions.  
- 📜 **Makefile Support:** Simplifies compilation and project management.

---

## 🛠️ Technologies Used

- **Programming Language:** C  
- **Core Concepts:** Socket Programming, Multi-threading, Synchronization with Semaphores  
- **Data Structures:** LRU Cache  
- **Build Tool:** Makefile  

---

## 📁 Project Structure



.
├── proxy\_server\_with\_cache.c    # Main proxy server implementation (multi-threaded + caching)
├── proxy\_parse.c                # HTTP request parsing logic
├── proxy\_parse.h                # Header file for parsing functions
├── Makefile                     # Automates compilation
└── README.md                    # Project documentation



## ⚙️ Installation & Setup

### 1. Clone the Repository
git clone https://github.com/GagandeepSingh20/Proxy_Web_Server.git
cd Proxy_Web_Server


### 2. Build the Project

Compile using the provided Makefile:
make

This will generate an executable named `proxy_server`.

---

## ▶️ Usage

Run the proxy server by specifying a port number:


./proxy_server <port_number>


Now configure your browser or HTTP client (like `curl`) to use `localhost:8080` as the proxy.


If the requested page is already in the cache, the proxy will serve it directly from memory without fetching it from the remote server again.

---

## 🔧 How It Works

1. **Client Connection:** The server listens on the specified port and accepts multiple client connections concurrently using threads.
2. **Request Parsing:** Incoming HTTP requests are parsed to extract the target server and resource.
3. **Forwarding & Response:** The proxy forwards the request to the destination server and relays the response back to the client.
4. **LRU Caching:** Frequently accessed responses are stored in memory using an LRU caching mechanism. Cached responses are served instantly if available.
5. **Thread Synchronization:** Semaphores manage concurrent access to shared data structures, ensuring thread safety and preventing race conditions.

---

## 🚀 Future Enhancements

* 🔐 Add support for **HTTPS** using the CONNECT method.
* 📁 Implement **persistent disk-based caching** for long-term storage.
* 📊 Add detailed **logging and monitoring** features.
* 🧪 Include **automated unit testing** and performance benchmarking.
* ⚙️ Add configuration options (e.g., cache size, logging level) via command-line or config files.

---

## 🤝 Contributing

Contributions are welcome!
Follow these steps to contribute:

1. Fork the repository
2. Create a feature branch

   ```bash
   git checkout -b feature/your-feature-name
   ```
3. Commit your changes

   ```bash
   git commit -m "Add your feature"
   ```
4. Push to the branch

   ```bash
   git push origin feature/your-feature-name
   ```
5. Open a Pull Request describing your changes.

---

## 📝 License

This project is licensed under the **MIT License** – you are free to use, modify, and distribute it.

---

## 👨‍💻 Author

[**Gagandeep Singh Choudhary**](https://github.com/GagandeepSingh20)

---

⭐ If you like this project, don’t forget to **star the repository**!
