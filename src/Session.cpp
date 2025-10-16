#include "Session.hpp"
#include <iostream>

Session::Session(asio::ip::tcp::socket socket)
    : socket_(std::move(socket)) {}

void Session::start() {
    doRead();
}

void Session::doRead() {
    auto self(shared_from_this());
    socket_.async_read_some(asio::buffer(buffer_),
        [this, self](std::error_code ec, std::size_t length) {
            if (!ec) {
                doWrite(length);
            }
        });
}

void Session::doWrite(std::size_t length) {
    auto self(shared_from_this());
    asio::async_write(socket_, asio::buffer(buffer_, length),
        [this, self](std::error_code ec, std::size_t /*length*/) {
            if (!ec) {
                doRead();
            }
        });
}
