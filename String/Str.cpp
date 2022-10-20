//
//  Str.cpp
//  String
//
//  Created by DiCode77.
//

#include "Str.hpp"

void Str::new_str(const uint &size){
    if (this->str == nullptr){
        this->str = new char[size]{};
    }
}

void Str::copy_variable(char *str, const char *in_str, const uint &len){
    if (!str || !in_str || !len){
        return;
    }
    else{
        for (uint i = 0; i < len; i++){
            str[i] = in_str[i];
        }
    }
}

void Str::copy_variable_position(const uint &pos, char *str, const char *in_str, const uint &len){
    if (!str || !in_str || !len){
        return;
    }
    else{
        for (uint i = pos; i < len; i++){
            str[i] = in_str[i - this->length];
        }
    }
}

bool Str::maxsize(const uint &len){
    return this->capacit_y > len;
}

bool Str::minsize(const uint &len){
    return (len + STR_CAPACITY) < this->capacit_y;
}

void Str::reall_size(const uint &len){
    if (!maxsize(len)){
        this->capacit_y += (len - this->capacit_y) + STR_CAPACITY;
    }
    else if (minsize(len)){
        this->capacit_y = len + STR_CAPACITY;
    }

}

void Str::new_str_size(const char *oth_str, const uint &len){
    if (this->str != nullptr){
        char *new_str = new char[this->capacit_y +1]{};
        copy_variable(new_str, oth_str, len +1);
        delete [] this->str;
        this->str = new_str;
    }
    else{
        this->str = new char[this->capacit_y +1]{};
        copy_variable(this->str, oth_str, len +1);
    }
}


Str &Str::operator= (const Str &oth){
    if (oth.str != nullptr){
        this->length = oth.length;
        reall_size(this->length);
        new_str_size(oth.str, this->length);
    }
    return *this;
}

Str &Str::operator= (const char oth){
    char str[2] = {oth, '\0'};
    this->length = 1;
    reall_size(this->length);
    new_str_size(str, this->length);
    return *this;
}

Str &Str::operator+= (const Str &oth){
    reall_size(this->length + oth.length);
    new_str_size(this->str, this->length);
    copy_variable_position(this->length, this->str, oth.str, (this->length + oth.length) +1);
    this->length = this->length + oth.length;
    return *this;
}

Str &Str::operator+= (const char oth){
    char str[2] = {oth, '\0'};
    reall_size(this->length + 1);
    new_str_size(this->str, this->length);
    copy_variable_position(this->length, this->str, str, (this->length + 1) +1);
    this->length = this->length + 1;
    return *this;
}

Str Str::operator+ (const Str &oth){
    NewVariable cont;
    reall_size(this->length + oth.length);
    cont.new_str = new char[capacit_y +1]{};
    copy_variable(cont.new_str, this->str, this->length);
    copy_variable_position(this->length, cont.new_str, oth.str, (this->length + oth.length) +1);
    return cont.new_str;
}

Str Str::operator+ (const char oth){
    char str[2] = {oth, '\0'};
    NewVariable cont;
    reall_size(this->length + 1);
    cont.new_str = new char[capacit_y +1]{};
    copy_variable(cont.new_str, this->str, this->length);
    copy_variable_position(this->length, cont.new_str, str, (this->length + 1) +1);
    return cont.new_str;
}

bool Str::operator< (const Str &oth) const{
    uint size_str = 0;
    uint size_str_oth = 0;
    
    for (uint i = 0; i < this->length; i++){
        size_str += this->str[i];
    }
    
    for (uint i = 0; i < oth.length; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str < size_str_oth);
}

bool Str::operator> (const Str &oth) const{
    uint size_str = 0;
    uint size_str_oth = 0;
    
    for (uint i = 0; i < this->length; i++){
        size_str += this->str[i];
    }
    
    for (uint i = 0; i < oth.length; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str > size_str_oth);
}

bool Str::operator<= (const Str &oth) const{
    uint size_str = 0;
    uint size_str_oth = 0;
    
    for (uint i = 0; i < this->length; i++){
        size_str += this->str[i];
    }
    
    for (uint i = 0; i < oth.length; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str <= size_str_oth);
}

bool Str::operator>= (const Str &oth) const{
    uint size_str = 0;
    uint size_str_oth = 0;
    
    for (uint i = 0; i < this->length; i++){
        size_str += this->str[i];
    }
    
    for (uint i = 0; i < oth.length; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str < size_str_oth);
}

bool Str::operator== (const Str &oth) const{
    if (this->length != oth.length){
        return false;
    }
    else{
        for (uint i = 0; i < this->length; i++){
            if (this->str[i] != oth.str[i]){
                return false;
            }
        }
    }
    return true;
}

bool Str::operator!= (const Str &oth) const{
    if (this->length != oth.length){
        return true;
    }
    else{
        for (uint i = 0; i < this->length; i++){
            if (this->str[i] != oth.str[i]){
                return true;
            }
        }
    }
    return false;
}

char &Str::operator[] (const uint &in) const{
    return this->str[in];
}


Str operator+ (Str in, Str &oth){
    in.reall_size(in.length + oth.length);
    in.new_str_size(in.str, in.length);
    in.copy_variable_position(in.length, in.str, oth.str, (in.length + oth.length) +1);
    in.length = in.length + oth.length;
    return in;
}

bool operator< (const Str in, const Str &oth) {
    uint size_str = 0;
    uint size_str_oth = 0;
    
    for (uint i = 0; i < in.length; i++){
        size_str += in.str[i];
    }
    
    for (uint i = 0; i < oth.length; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str < size_str_oth);
}

bool operator> (const Str in, const Str &oth) {
    uint size_str = 0;
    uint size_str_oth = 0;
    
    for (uint i = 0; i < in.length; i++){
        size_str += in.str[i];
    }
    
    for (uint i = 0; i < oth.length; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str > size_str_oth);
}

bool operator<= (const Str in, const Str &oth) {
    uint size_str = 0;
    uint size_str_oth = 0;
    
    for (uint i = 0; i < in.length; i++){
        size_str += in.str[i];
    }
    
    for (uint i = 0; i < oth.length; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str <= size_str_oth);
}

bool operator>= (const Str in, const Str &oth) {
    uint size_str = 0;
    uint size_str_oth = 0;
    
    for (uint i = 0; i < in.length; i++){
        size_str += in.str[i];
    }
    
    for (uint i = 0; i < oth.length; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str >= size_str_oth);
}

bool operator== (const Str in, const Str &oth) {
    uint size_str = 0;
    uint size_str_oth = 0;
    
    for (uint i = 0; i < in.length; i++){
        size_str += in.str[i];
    }
    
    for (uint i = 0; i < oth.length; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str == size_str_oth);
}

std::ostream &operator << (std::ostream &out, const Str &other){
    return (out << other.str);
}

std::istream &operator >> (std::istream &stream, Str &other){
    char *new_str = new char[]{};
    stream.getline(new_str, UINT_MAX);
    
    if (other.length != 0){
        other.length = 0;
    }
    
    while (new_str[other.length] != '\0') {
        other.length++;
    }
    
    if (other.str != nullptr){
        delete [] other.str;
        other.str = nullptr;
    }

    other.reall_size(other.length);
    other.new_str(other.capacit_y);
    other.copy_variable(other.str, new_str, other.length +1);
    delete [] new_str;
    return stream;
}


long Str::findr(const char *in){
    uint size = 0;
    while (in[size] != '\0'){
        size++;
    }
    for (uint i = 0; i < this->length; i++){
        if (this->str[i] == in[0]){
            if (this->str[i + (size -1)] == in[size -1]){
                for (long l = 0; l < size; l++){
                    if (this->str[i + l] == in[l]){
                        if (l == (size -1)){
                            return i;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    return -1;
}


long Str::findr(const char *in, const uint &where){
    uint size = 0;
    while (in[size] != '\0'){
        size++;
    }
    for (uint i = where; i < this->length; i++){
        if (this->str[i] == in[0]){
            if (this->str[i + (size -1)] == in[size -1]){
                for (long l = 0; l < size; l++){
                    if (this->str[i + l] == in[l]){
                        if (l == (size -1)){
                            return i;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    return -1;
}


long Str::rfindr(const char *in){
    uint size = 0;
    while (in[size] != '\0'){
        size++;
    }
    for (long i = this->length; i >= 0; i--){
        if (this->str[i] == in[0]){
            if (this->str[i + (size -1)] == in[size -1]){
                for (long l = 0; l < size; l++){
                    if (this->str[i + l] == in[l]){
                        if (l == (size -1)){
                            return i;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    return -1;
}


long Str::rfindr(const char *in, const uint &where){
    uint size = 0;
    while (in[size] != '\0'){
        size++;
    }
    for (long i = where; i >= 0; i--){
        if (this->str[i] == in[0]){
            if (this->str[i + (size -1)] == in[size -1]){
                for (long l = 0; l < size; l++){
                    if (this->str[i + l] == in[l]){
                        if (l == (size -1)){
                            return i;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    return -1;
}
