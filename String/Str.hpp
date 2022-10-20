//
//  Str.hpp
//  String
//
//  Created by DiCode77.
//
#include <iostream>

#define STR_VERSION "0.0.3"
#define STR_CAPACITY 22
typedef unsigned int uint;

class Str{
    char *str;
    uint length;
    uint capacit_y;
public:
    Str(){
        this->str = nullptr;
        this->length = 0;
        this->capacit_y = STR_CAPACITY;
    }
    
    Str(Str &str) : Str(){
        this->length = str.length;
        reall_size(this->length);
        new_str(this->capacit_y +1);
        copy_variable(this->str, str.str, this->length +1);
    }
    
    Str(const char *in_str) : Str(){
        if (in_str == nullptr){
            return;
        }
        else{
            while (in_str[this->length] != '\0'){
                this->length++;
            }
            reall_size(this->length);
            new_str(this->capacit_y +1);
            copy_variable(this->str, in_str, this->length +1);
        }
    }
    
    
public:
    Str &operator= (const Str &oth);
    
    Str &operator= (const char oth);
    
    Str &operator+= (const Str &oth);
    
    Str &operator+= (const char oth);
    
    Str operator+ (const Str &oth);
    
    Str operator+ (const char oth);
    
    bool operator< (const Str &oth) const;
    
    bool operator> (const Str &oth) const;
    
    bool operator<= (const Str &oth) const;
    
    bool operator>= (const Str &oth) const;
    
    bool operator== (const Str &oth) const;
    
    bool operator!= (const Str &oth) const;
    
    char &operator[] (const uint &in) const;
    
    friend Str operator+ (Str in, Str &oth);
    friend bool operator< (const Str in, const Str &oth);
    friend bool operator> (const Str in, const Str &oth);
    friend bool operator<= (const Str in, const Str &oth);
    friend bool operator>= (const Str in, const Str &oth);
    friend bool operator== (const Str in, const Str &oth);
    
    friend std::ostream &operator << (std::ostream &out, const Str &other);
    
    friend std::istream &operator >> (std::istream &stream, Str &other);
    
    uint size(){
        return this->length;
    }
    
    uint capacity(){
        return this->capacit_y;
    }
    
    const char *c_str(){
        return this->str;
    }
    
    long find(const char *in){
        return findr(in);
    }
    
    long find(const Str &in){
        return findr(in.str);
    }
    
    long find(const char *in, const uint where){
        return findr(in, where);
    }
    
    long find(const Str &in, const uint where){
        return findr(in.str, where);
    }
    
    long rfind(const char *in){
        return rfindr(in);
    }
    
    long rfind(const Str &in){
        return rfindr(in.str);
    }
    
    long rfind(const char *in, const uint where){
        return rfindr(in, where);
    }
    
    long rfind(const Str &in, const uint where){
        return rfindr(in.str, where);
    }
    
    
    
private:
    void new_str(const uint&);
    bool maxsize(const uint&);
    bool minsize(const uint&);
    void reall_size(const uint&);
    void new_str_size(const char*, const uint&);
    void copy_variable(char*, const char*, const uint&);
    void copy_variable_position(const uint&, char*, const char*, const uint&);
    
private:
    
    long findr(const char*);
    long findr(const char*, const uint&);
    long rfindr(const char*);
    long rfindr(const char*, const uint&);

    
    
public:
    ~Str(){
        delete [] this->str;
    }
};

class NewVariable{
private:
    char *new_str;
public:
    NewVariable(){
        this->new_str = nullptr;
    }
    ~NewVariable(){
        delete [] this->new_str;
    }
    friend class Str;
};
