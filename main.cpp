#include "Dictionary.hpp"

int main() {
    const int m = 15;

    // Creating a dictionary with the given size and hash function
    Dictionary<std::string, std::string> dict(m, Dictionary<std::string, std::string>::hash_function);

    dict.INSERT("Gabriella", "Devoted to God");
    dict.INSERT("Grace", "Goodness, generosity");
    dict.INSERT("Hannah", "Favor, grace of God");
    dict.INSERT("Jocelyn", "Happy, joyful");
    dict.INSERT("Kaitlyn", "Pure");
    dict.INSERT("Kalila", "Heap of love");
    dict.INSERT("Layla", "Dark beauty");
    dict.INSERT("Alice", "Noble, kind");
    dict.INSERT("Amelia", "Industrious, striving");
    dict.INSERT("Diana", "Moon goddess");
    dict.INSERT("Ella", "Light, beautiful fairy woman");
    dict.INSERT("Stella", "A star");
    dict.INSERT("Zoe", "Life");
    dict.INSERT("Zahra", "Flower");
    dict.INSERT("Anastasia", "Resurrection");

    std::cout << "Is 'Anastasia' a member? " << (dict.MEMBER("Anastasia") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'Sophia' a member? " << (dict.MEMBER("Sophia") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'Amelia' a member? " << (dict.MEMBER("Amelia") ? "Yes" : "No") << std::endl;

    std::string* value = dict.FIND("Amelia");
    if (value != nullptr) {
        std::cout << "Meaning of 'Amelia': " << *value << std::endl;
    }

    dict.DELETE("Anastasia");

    std::cout << "Is 'Anastasia' a member after deletion? " << (dict.MEMBER("Anastasia") ? "Yes" : "No") << std::endl;
    std::cout << "____________________________________" << std::endl << std::endl;

    PRINT(dict);

    return 0;
}
