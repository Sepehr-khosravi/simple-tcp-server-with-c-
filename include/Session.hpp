#pragma once
#include "asio.hpp"
#include <memory>
#include <array>

class Session : public std::enable_shared_from_this<Session> {
public:
    explicit Session(asio::ip::tcp::socket socket);
    void start();

private:
    void doRead();
    void doWrite(std::size_t length);

    asio::ip::tcp::socket socket_;
    std::array<char, 1024> buffer_;
};
