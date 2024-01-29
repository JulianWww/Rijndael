#pragma once

#include <iostream>
#include "../utils.hpp"

namespace Rijndael {
    class ByteField {
        private: unsigned char value;

        public: ByteField(const unsigned char& value);
        public: ByteField();
        public: ByteField(const ByteField& value);
        public: ByteField(const ByteField* value);

        public: ByteField operator+(const ByteField& other) const;
        public: void operator+=(const ByteField& other);
        public: ByteField operator-(const ByteField& other) const;
        public: void operator-=(const ByteField& other);

        private: void xtimes();
        private: bool getBit(const short& idx) const;
        public: void operator*=(const ByteField& other);
        public: ByteField operator*(const ByteField& other);

        public: const unsigned char& getValue() const;
        public: void setValue(const unsigned char& other);
        public: void setValue(const ByteField& other);
    };
}

std::ostream& operator<<(std::ostream& out, const Rijndael::ByteField& field);