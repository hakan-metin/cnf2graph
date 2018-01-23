// Copyright 2017 Hakan Metin - LIP6

#ifndef INCLUDE_CNF2GRAPH_STREAMBUFFER_H_
#define INCLUDE_CNF2GRAPH_STREAMBUFFER_H_

#include <zlib.h>

#include <cctype>
#include <string>

#include "cnf2graph/Logging.h"
#include "cnf2graph/Literal.h"

static const int kBufferSize = 4096;

namespace cnf2graph {

class StreamBuffer {
 public:
    explicit StreamBuffer(const std::string& filename);
    explicit StreamBuffer(const char * filename);
    ~StreamBuffer();

    int readInt();
    void skipWhiteSpaces();
    void skipLine();

    int operator*();
    void operator++();

 private:
    const std::string _filename;
    gzFile _in;
    unsigned char _buffer[kBufferSize];
    unsigned int _index;
    unsigned int _size;

    unsigned char read();
};

}  // namespace cnf2graph


#endif  // INCLUDE_CNF2GRAPH_STREAMBUFFER_H_

/*
 * Local Variables:
 * mode: c++
 * indent-tabs-mode: nil
 * End:
 */
