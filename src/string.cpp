#include <algorithm>
#include <cstring>
#include <iostream>

#include "my_string.h"

String::String(const char* str)
    : size_(strlen(str)),
      capacity_(2 * size_ + 1),
      char_arr_(new char[capacity_]) {
    std::copy(str, str + size_, char_arr_);
    add_null_char();
}

String::String(size_t n, char c)
    : size_(n), capacity_(2 * size_ + 1), char_arr_(new char[capacity_]) {
    std::fill(char_arr_, char_arr_ + size_, c);
    add_null_char();
}

String::String() : size_(0), capacity_(1), char_arr_(new char[capacity_]) {
    add_null_char();
}

String::String(char ch)
    : size_(1), capacity_(2), char_arr_(new char[capacity_]) {
    char_arr_[0] = ch;
    add_null_char();
}

String::String(const String& str)
    : size_(str.size_),
      capacity_(str.capacity_),
      char_arr_(new char[capacity_]) {
    std::copy(str.char_arr_, str.char_arr_ + capacity_, char_arr_);
}

String::~String() {
    delete[] char_arr_;
}

String& String::operator=(String str) {
    swap(str);
    return *this;
}

String& String::operator+=(const String& str) {
    if (size_ + str.size_ >= capacity_ - 1) {
        resize(2 * (size_ + str.size_) + 1);
    }
    std::copy(str.char_arr_, str.char_arr_ + str.size_, char_arr_ + size_);
    size_ += str.size_;
    add_null_char();
    return *this;
}

String& String::operator+=(char ch) {
    push_back(ch);
    return *this;
}

String operator+(String lhs, const String& rhs) {
    lhs += rhs;
    return lhs;
}

bool operator==(const String& lhs, const String& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    return strcmp(lhs.data(), rhs.data()) == 0;
}

bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs) {
    return strcmp(lhs.data(), rhs.data()) < 0;
}

bool operator>(const String& lhs, const String& rhs) {
    return rhs < lhs;
}

bool operator<=(const String& lhs, const String& rhs) {
    return !(rhs < lhs);
}

bool operator>=(const String& lhs, const String& rhs) {
    return rhs <= lhs;
}

char& String::operator[](size_t pos) {
    return char_arr_[pos];
}

const char& String::operator[](size_t pos) const {
    return char_arr_[pos];
}

char& String::front() {
    return char_arr_[0];
}

const char& String::front() const {
    return char_arr_[0];
}

char& String::back() {
    return char_arr_[size_ - 1];
}

const char& String::back() const {
    return char_arr_[size_ - 1];
}

void String::push_back(char ch) {
    if (size_ == capacity_ - 1) {
        resize(capacity_ * 2 + 2);
    }
    char_arr_[size_++] = ch;
    add_null_char();
}

void String::pop_back() {
    --size_;
    add_null_char();
}

void String::shrink_to_fit() {
    resize(size_ + 1);
}

String String::substr(size_t start, size_t count) const {
    String subs(count, '\0');
    std::copy(char_arr_ + start, char_arr_ + start + count, subs.char_arr_);
    return subs;
}

size_t String::find(const String& subs) const {
    for (size_t i = 0; i <= size_ - subs.size_; ++i) {
        if (strncmp(char_arr_ + i, subs.char_arr_, subs.size_) == 0) {
            return i;
        }
    }
    return length();
}

size_t String::rfind(const String& subs) const {
    for (size_t i = size_ - subs.size(); i > 0; --i) {
        if (strncmp(char_arr_ + i, subs.char_arr_, subs.size_) == 0) {
            return i;
        }
    }
    return size_;
}

char* String::data() {
    return char_arr_;
}

const char* String::data() const {
    return char_arr_;
}

size_t String::size() const {
    return size_;
}

size_t String::length() const {
    return size_;
}

size_t String::capacity() const {
    return capacity_ - 1;
}

bool String::empty() const {
    return size_ == 0;
}

void String::clear() {
    size_ = 0;
    add_null_char();
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    for (size_t i = 0; i < str.size(); ++i) {
        os << str[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, String& str) {
    str.clear();
    char ch;
    while (is.get(ch) && !is.eof() && std::isspace(ch) != 0) {}

    if (is.eof()) {
        return is;
    }

    do {
        str.push_back(ch);
    } while (is.get(ch) && !is.eof() && std::isspace(ch) == 0);
    return is;
}

void String::resize(size_t new_capacity) {
    char* new_char_arr = new char[new_capacity];
    std::copy(char_arr_, char_arr_ + size_, new_char_arr);
    delete[] char_arr_;
    char_arr_ = new_char_arr;
    capacity_ = new_capacity;
    add_null_char();
}

void String::add_null_char() {
    char_arr_[size_] = '\0';
}

void String::swap(String& str) {
    std::swap(size_, str.size_);
    std::swap(capacity_, str.capacity_);
    std::swap(char_arr_, str.char_arr_);
}
