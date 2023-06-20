#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <iostream>
#include <vector>

template<typename KeyType, typename ValueType>
class Dictionary {
private:
    struct KeyValuePair {
        KeyType key;
        ValueType value;
        KeyValuePair* next;
    };

    int size;
    std::vector<KeyValuePair*> table;
    int (*hashFunc)(KeyType, int);

public:
    Dictionary(int m, int (*h)(KeyType, int));
    ~Dictionary();

    void INSERT(KeyType key, ValueType value);
    bool MEMBER(KeyType key);
    ValueType* FIND(KeyType key);
    void DELETE(KeyType key);

    friend void PRINT(Dictionary& dict);

    int hash_function(std::string key, int m);
};

#endif 
