#pragma once
#include <iostream>

class String {
  public:
    String();
    String(char ch);
    String(const char* str);
    String(size_t n, char c);
    String(const String& str);
    ~String();

    String& operator=(String str);
    char& operator[](size_t pos);
    const char& operator[](size_t pos) const;
    String& operator+=(const String& str);
    String& operator+=(char ch);

    char& front();
    const char& front() const;
    char& back();
    const char& back() const;

    void push_back(char ch);
    void pop_back();
    void shrink_to_fit();

    String substr(size_t start, size_t count) const;
    size_t find(const String& subs) const;
    size_t rfind(const String& subs) const;

    char* data();
    const char* data() const;
    size_t size() const;
    size_t length() const;
    size_t capacity() const;
    bool empty() const;
    void clear();

  private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    char* char_arr_ = nullptr;

    void resize(size_t new_capacity);
    void add_null_char();
    void swap(String& str);
};

std::ostream& operator<<(std::ostream& os, const String& str);
std::istream& operator>>(std::istream& is, String& str);
String operator+(String lhs, const String& rhs);
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);
