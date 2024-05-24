#include "Hash.hpp"
template<typename KeyType, typename ValueType> class Entry
{

    private:
        
    
    public:
        Hash::hash_t hash;
        KeyType key;
        ValueType value;

        constexpr Entry() = default;
        constexpr Entry(const Entry &entry) : 
            key(entry.key), 
            value(entry.value), 
            hash(Hash::generate(&entry.key, sizeof(entry.key)))
            {}
        constexpr explicit Entry(const KeyType &key, const ValueType &value) : 
            key(key), 
            value(value), 
            hash(Hash::generate(&key, sizeof(key))) 
            {}

        constexpr Entry &operator=(const Entry &rhs) {
            key = rhs.key;
            value = rhs.value;
            hash = Hash::generate(&rhs.key, sizeof(rhs.key));
            return *this;
        }

        // for the lookup, hash the key and then search in the bst for that hash

        constexpr bool operator==(const Entry &rhs) const {return hash == rhs.hash;};
        constexpr bool operator!=(const Entry &rhs) const {return hash != rhs.hash;};
        constexpr bool operator<=(const Entry &rhs) const {return hash <= rhs.hash;};
        constexpr bool operator>=(const Entry &rhs) const {return hash >= rhs.hash;};
        constexpr bool operator< (const Entry &rhs) const {return hash < rhs.hash;};
        constexpr bool operator> (const Entry &rhs) const {return hash > rhs.hash;};
};
