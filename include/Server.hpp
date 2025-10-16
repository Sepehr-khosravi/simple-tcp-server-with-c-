#pragma once
#include "asio.hpp"
#include "Session.hpp"

class Server {
public:
    Server(asio::io_context& io, unsigned short port);

private:
    void doAccept();

    asio::ip::tcp::acceptor acceptor_;
};
