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
    
    Str(Str &str) : Str(){
        this->lenght = str.lenght;
        reall_size(this->lenght);
        new_str(this->capacit_y +1);
        copy_variable(this->str, str.str, this->lenght +1);
    }
    
    Str(const char *in_str) : Str(){
        if (in_str == nullptr){
            return;
        }
        else{
            while (in_str[this->lenght] != '\0'){
                this->lenght++;
            }
            reall_size(this->lenght);
            new_str(this->capacit_y +1);
            copy_variable(this->str, in_str, this->lenght +1);
        }
    }
    
    
public:
    Str &operator= (const Str &oth);
    
    Str &operator+= (const Str &oth);
    
    Str &operator+ (const Str &oth);
    
    char &operator[] (const ulong &in){
        return this->str[in];
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
    void new_str(const ulong&);
    bool maxsize(const ulong&);
    bool minsize(const ulong&);
    void reall_size(const ulong&);
    void new_str_size(const char*, const ulong&);
    void copy_variable(char*, const char*, const ulong&);
    void copy_variable_position(const ulong&, char*, const char*, const ulong&);
    
public:
    ~Str(){
        delete [] this->str;
    }
};
