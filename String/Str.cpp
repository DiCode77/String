//
//  Str.cpp
//  String
//
//  Created by DiCode77.
//

#include "Str.hpp"

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

void Str::new_str_size(const char *oth_str, ulong &len){
    if (oth_str != nullptr || len){
        char *new_str = new char[this->capacit_y +1]{};
        copy_variable(new_str, oth_str, len);
        delete [] this->str;
        this->str = new_str;
    }
}
