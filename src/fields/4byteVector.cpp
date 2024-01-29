#include <rijndael/fields/4byteVector.hpp>
#include <rijndael/fields/byteField.hpp>
#include <cassert>

Rijndael::FourByteVector::FourByteVector(const ByteField (&_bytes)[4]) {
    for (short idx = 0; idx < 4; idx++) {
        this->bytes[idx].setValue(_bytes[idx]);
    }
}
Rijndael::FourByteVector::FourByteVector(const FourByteVector& other) : FourByteVector(other.bytes) {};

const Rijndael::ByteField& Rijndael::FourByteVector::getValue(const unsigned short idx) const {
    assert(idx < 4);
    return this->bytes[idx];
}

void Rijndael::FourByteVector::operator+=(const FourByteVector& other) {

}
Rijndael::FourByteVector Rijndael::FourByteVector::operator+(const FourByteVector& other) {
    FourByteVector res = FourByteVector(*this);
    res += other;
    return res;
}

std::ostream& operator<<(std::ostream& out, Rijndael::FourByteVector& field) {
    return (out << "[ " << field.getValue(0) << ", " << field.getValue(1) << ", " << field.getValue(2) << ", " << field.getValue(3) << "]");
}