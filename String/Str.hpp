//
//  Str.hpp
//  String
//
//  Created by DiCode77.
//
#include <iostream>

#define STR_VERSION "0.0.1"
#define STR_CAPACITY 22
typedef unsigned long ulong;

class Str{
    char *str;
    ulong lenght;
    ulong capacit_y;
    
public:
    Str(){
        this->str = nullptr;
        this->lenght = 0;
        this->capacit_y = STR_CAPACITY;
    }
    
    Str(const char *in_str) : Str(){
        if (in_str == nullptr){
            return;
        }
        else{
            while (in_str[this->lenght] != '\0'){
                this->lenght++;
            }
            this->str = new char[this->lenght +1]{};
            copy_variable(this->str, in_str, this->lenght +1);
            reall_size(this->lenght);
        }
    }
    
    
public:
    
    Str &operator= (const Str &oth){
        if (oth.str != nullptr){
            this->lenght = oth.lenght;
            reall_size(this->lenght);
            new_str_size(oth.str, this->lenght);
        }
        return *this;
    }
    
    
    friend std::ostream& operator << (std::ostream &out, const Str &other){
        return (out << other.str);
    }
    
    ulong size(){
        return this->lenght;
    }
    
    ulong capacity(){
        return this->capacit_y;
    }
    
    const char *c_str(){
        return this->str;
    }
    
private:
    bool maxsize(const ulong&);
    bool minsize(const ulong&);
    void reall_size(const ulong&);
    void new_str_size(const char*, ulong&);
    void copy_variable(char*, const char*, const ulong&);
    
public:
    ~Str(){
        delete [] this->str;
    }
};
