#include "Dictionary.hpp"

template<typename KeyType, typename ValueType>
Dictionary<KeyType, ValueType>::Dictionary(int m, int (*h)(KeyType, int)) {
    size = m;
    table.resize(m, nullptr);
    hashFunc = h;
}

template<typename KeyType, typename ValueType>
Dictionary<KeyType, ValueType>::~Dictionary() {
    for (int i = 0; i < size; i++) {
        KeyValuePair* current = table[i];
        while (current != nullptr) {
            KeyValuePair* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

template<typename KeyType, typename ValueType>
void Dictionary<KeyType, ValueType>::INSERT(KeyType key, ValueType value) {
    int bucket = hashFunc(key, size);
    KeyValuePair* oldheader = table[bucket];
    table[bucket] = new KeyValuePair;
    table[bucket]->key = key;
    table[bucket]->value = value;
    table[bucket]->next = oldheader;
}

template<typename KeyType, typename ValueType>
bool Dictionary<KeyType, ValueType>::MEMBER(KeyType key) {
    int bucket = hashFunc(key, size);
    KeyValuePair* current = table[bucket];
    while (current != nullptr) {
        if (current->key == key)
            return true;
        else
            current = current->next;
    }
    return false;
}

template<typename KeyType, typename ValueType>
ValueType* Dictionary<KeyType, ValueType>::FIND(KeyType key) {
    int bucket = hashFunc(key, size);
    KeyValuePair* current = table[bucket];
    while (current != nullptr) {
        if (current->key == key)
            return &(current->value);
        else
            current = current->next;
    }
    return nullptr;
}

template<typename KeyType, typename ValueType>
void Dictionary<KeyType, ValueType>::DELETE(KeyType key) {
    int bucket = hashFunc(key, size);
    KeyValuePair* current = table[bucket];
    KeyValuePair* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                table[bucket] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

template<typename KeyType, typename ValueType>
void PRINT(Dictionary<KeyType, ValueType>& dict) {
    for (int i = 0; i < dict.size; i++) {
        std::cout << "[" << i << "] ";
        KeyValuePair* current = dict.table[i];
        while (current != nullptr) {
            std::cout << current->key << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

template<typename KeyType, typename ValueType>
int Dictionary<KeyType, ValueType>::hash_function(std::string key, int m) {
    int sum = 0;
    for (char c : key) {
        sum += c;
    }
    return sum % m;
}


