#pragma once

#include "byteField.hpp"

namespace Rijndael {
    class FourByteVector {
        private: ByteField bytes[4];

        public: FourByteVector(const ByteField (&bytes)[4]);
        public: FourByteVector(const FourByteVector& other);

        public: void operator+=(const FourByteVector& other);
        public: FourByteVector operator+(const FourByteVector& other);

        public: const ByteField& getValue(const unsigned short idx) const;
    };
}

std::ostream& operator<<(std::ostream& out, Rijndael::FourByteVector& field);