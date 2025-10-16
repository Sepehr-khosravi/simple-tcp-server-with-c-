#include "Server.hpp"
#include <iostream>

Server::Server(asio::io_context& io, unsigned short port)
    : acceptor_(io, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)) {
    doAccept();
}

void Server::doAccept() {
    acceptor_.async_accept(
        [this](std::error_code ec, asio::ip::tcp::socket socket) {
            if (!ec) {
                std::make_shared<Session>(std::move(socket))->start();
            }
            doAccept();
        });
}
