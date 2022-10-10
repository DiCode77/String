//
//  Str.cpp
//  String
//
//  Created by DiCode77.
//

#include "Str.hpp"

void Str::new_str(const ulong &size){
    if (this->str == nullptr){
        this->str = new char[size]{};
    }
}

void Str::copy_variable(char *str, const char *in_str, const ulong &len){
    if (!str || !in_str || !len){
        return;
    }
    else{
        for (ulong i = 0; i < len; i++){
            str[i] = in_str[i];
        }
    }
}

void Str::copy_variable_position(const ulong &pos, char *str, const char *in_str, const ulong &len){
    if (!str || !in_str || !len){
        return;
    }
    else{
        for (ulong i = pos; i < len; i++){
            str[i] = in_str[i - this->lenght];
        }
    }
}

bool Str::maxsize(const ulong &len){
    return this->capacit_y > len;
}

bool Str::minsize(const ulong &len){
    return (len + STR_CAPACITY) < this->capacit_y;
}

void Str::reall_size(const ulong &len){
    if (!maxsize(len)){
        this->capacit_y += (len - this->capacit_y) + STR_CAPACITY;
    }
    else if (minsize(len)){
        this->capacit_y = len + STR_CAPACITY;
    }

}

void Str::new_str_size(const char *oth_str, const ulong &len){
    if (oth_str != nullptr){
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
        this->lenght = oth.lenght;
        reall_size(this->lenght);
        new_str_size(oth.str, this->lenght);
    }
    return *this;
}

Str &Str::operator+= (const Str &oth){
    reall_size(this->lenght + oth.lenght);
    new_str_size(this->str, this->lenght);
    copy_variable_position(this->lenght, this->str, oth.str, (this->lenght + oth.lenght) +1);
    this->lenght = this->lenght + oth.lenght;
    return *this;
}

Str Str::operator+ (const Str &oth){
    NewVariable cont;
    reall_size(this->lenght + oth.lenght);
    cont.new_str = new char[capacit_y +1]{};
    copy_variable(cont.new_str, this->str, this->lenght);
    copy_variable_position(this->lenght, cont.new_str, oth.str, (this->lenght + oth.lenght) +1);
    return cont.new_str;
}

bool Str::operator< (const Str &oth) const{
    ulong size_str = 0;
    ulong size_str_oth = 0;
    
    for (ulong i = 0; i < this->lenght; i++){
        size_str += this->str[i];
    }
    
    for (ulong i = 0; i < oth.lenght; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str < size_str_oth);
}

bool Str::operator> (const Str &oth) const{
    ulong size_str = 0;
    ulong size_str_oth = 0;
    
    for (ulong i = 0; i < this->lenght; i++){
        size_str += this->str[i];
    }
    
    for (ulong i = 0; i < oth.lenght; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str > size_str_oth);
}

bool Str::operator<= (const Str &oth) const{
    ulong size_str = 0;
    ulong size_str_oth = 0;
    
    for (ulong i = 0; i < this->lenght; i++){
        size_str += this->str[i];
    }
    
    for (ulong i = 0; i < oth.lenght; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str <= size_str_oth);
}

bool Str::operator>= (const Str &oth) const{
    ulong size_str = 0;
    ulong size_str_oth = 0;
    
    for (ulong i = 0; i < this->lenght; i++){
        size_str += this->str[i];
    }
    
    for (ulong i = 0; i < oth.lenght; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str < size_str_oth);
}

bool Str::operator== (const Str &oth) const{
    if (this->lenght != oth.lenght){
        return false;
    }
    else{
        for (ulong i = 0; i < this->lenght; i++){
            if (this->str[i] != oth.str[i]){
                return false;
            }
        }
    }
    return true;
}

bool Str::operator!= (const Str &oth) const{
    if (this->lenght != oth.lenght){
        return true;
    }
    else{
        for (ulong i = 0; i < this->lenght; i++){
            if (this->str[i] != oth.str[i]){
                return true;
            }
        }
    }
    return false;
}

char &Str::operator[] (const ulong &in) const{
    return this->str[in];
}


Str operator+ (Str in, const Str &oth){
    in.reall_size(in.lenght + oth.lenght);
    in.new_str_size(in.str, in.lenght);
    in.copy_variable_position(in.lenght, in.str, oth.str, (in.lenght + oth.lenght) +1);
    in.lenght = in.lenght + oth.lenght;
    return in;
}

bool operator< (const Str in, const Str &oth) {
    ulong size_str = 0;
    ulong size_str_oth = 0;
    
    for (ulong i = 0; i < in.lenght; i++){
        size_str += in.str[i];
    }
    
    for (ulong i = 0; i < oth.lenght; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str < size_str_oth);
}

bool operator> (const Str in, const Str &oth) {
    ulong size_str = 0;
    ulong size_str_oth = 0;
    
    for (ulong i = 0; i < in.lenght; i++){
        size_str += in.str[i];
    }
    
    for (ulong i = 0; i < oth.lenght; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str > size_str_oth);
}

bool operator<= (const Str in, const Str &oth) {
    ulong size_str = 0;
    ulong size_str_oth = 0;
    
    for (ulong i = 0; i < in.lenght; i++){
        size_str += in.str[i];
    }
    
    for (ulong i = 0; i < oth.lenght; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str <= size_str_oth);
}

bool operator>= (const Str in, const Str &oth) {
    ulong size_str = 0;
    ulong size_str_oth = 0;
    
    for (ulong i = 0; i < in.lenght; i++){
        size_str += in.str[i];
    }
    
    for (ulong i = 0; i < oth.lenght; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str >= size_str_oth);
}

bool operator== (const Str in, const Str &oth) {
    ulong size_str = 0;
    ulong size_str_oth = 0;
    
    for (ulong i = 0; i < in.lenght; i++){
        size_str += in.str[i];
    }
    
    for (ulong i = 0; i < oth.lenght; i++){
        size_str_oth += oth.str[i];
    }
    return (size_str == size_str_oth);
}
