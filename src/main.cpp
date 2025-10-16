#include <iostream>
#include "Server.hpp"

int main() {
    try {
        asio::io_context io;
        Server server(io, 8080);
        std::cout << "🚀 Server running on port 8080...\n";
        io.run();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
