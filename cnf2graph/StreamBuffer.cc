// Copyright 2017 Hakan Metin - LIP6

#include "cnf2graph/StreamBuffer.h"

namespace cnf2graph {

StreamBuffer::StreamBuffer(const std::string& filename) :
    StreamBuffer(filename.c_str()) {
}

StreamBuffer::StreamBuffer(const char* filename) :
        _filename(filename),
        _in(nullptr),
        _index(0),
        _size(0) {
    _in = gzopen(filename, "rb");
    if (_in == nullptr)
        LOG(FATAL) << "Cannot open file " << filename;
    read();
}

StreamBuffer::~StreamBuffer() {
    if (_in != nullptr) {
        gzclose(_in);
    }
}


int StreamBuffer::readInt() {
    bool negative = false;
    int value = 0;

    skipWhiteSpaces();

    unsigned char c = read();
    if (c == '-') {
        negative = true;
        ++(*this);
    } else if (c == '+') {
        negative = false;
        ++(*this);
    }

    while ((c = read()) != '\0' &&  c >= '0' && c <= '9') {
        value = (value * 10) + (_buffer[_index] - '0');
        ++(*this);
    }

    return negative ? -value : value;
}

void StreamBuffer::skipWhiteSpaces() {
    unsigned char c;

    while ((c = read()) != '\0' && std::isspace(c)) {
        _index++;
    }
}

void StreamBuffer::skipLine() {
    unsigned char c;

    while ((c = read()) != '\0' && c != '\n') {
        _index++;
    }
    ++(*this);
}


int StreamBuffer::operator*() {
    return static_cast<int>(read());
}

void StreamBuffer::operator++() {
    _index++;
    read();
}

unsigned char StreamBuffer::read() {
    if (_index >= _size) {
        _size = gzread(_in, _buffer, sizeof(_buffer));
        _index = 0;
    }
    return (_index >= _size) ? '\0' : _buffer[_index];
}

}  // namespace cnf2graph

/*
 * Local Variables:
 * mode: c++
 * indent-tabs-mode: nil
 * End:
 */
