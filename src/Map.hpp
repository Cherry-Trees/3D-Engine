#include "Entry.hpp"
#include "Stack.hpp"
#include <iostream>
template<typename KeyType, typename ValueType> class Map {

    private:
        using EntryType = Entry<KeyType, ValueType>;

        


        struct EntryNode {
            EntryType entry;
            EntryNode *right, *left;  

            constexpr EntryNode() : entry(), right(0), left(0) {} 
            constexpr EntryNode(const EntryType &entry) : entry(entry), right(0), left(0) {} 
        };



        class Iterator {

            private:

                EntryNode *_iterable;
                Stack<EntryNode *> _stack;

                

            
            public:
                Iterator() : _iterable(0), _stack() {}
                Iterator(EntryNode *root) {
                    _iterable = root;

                    while (_iterable) { 
                        _stack.push(_iterable);
                        
                        _iterable = _iterable->left;
                    }
                    
                    if (!_stack.empty())
                        _iterable = _stack.top();
                    
                }

                ~Iterator() {_stack.erase();}

                Iterator &operator++() {
                    
                        _iterable = _stack.pop()->right;
                                           
                        while (_iterable) {
                            _stack.push(_iterable); 
                            _iterable = _iterable->left;
                        }
                        if (_stack.empty()) {_iterable = 0; return *this;}
                        _iterable = _stack.top();
                                   

                    return *this;
                }

                EntryType &operator*()       {return _iterable->entry;}
                EntryType  operator*() const {return _iterable->entry;}

                bool operator==(const Iterator &rhs) const {return _iterable == rhs._iterable;}
                bool operator!=(const Iterator &rhs) const {return _iterable != rhs._iterable;}
        };



        
        static void _h_insert(EntryNode *&root, const EntryType &entry) {
            if (!root) {
                root = new EntryNode(entry);
                return;
            }

            if (entry < root->entry)
                _h_insert(root->left, entry);
            
            if (entry > root->entry)
                _h_insert(root->right, entry);
        }

        static void _h_print(EntryNode *&root) {
            if (!root) return;

            _h_print(root->left);
            std::cout << root->entry.hash << " : " << root->entry.key << " : " << root->entry.value << std::endl;
            _h_print(root->right);
        }

        static void _h_erase(EntryNode *&root) {
            if (!root) return;

            _h_erase(root->left);
            _h_erase(root->right);

            delete root;
            root = 0;
        }

        static EntryNode *_h_get(EntryNode *&root, const Hash::hash_t hash) {
            if (!root) return 0;

            if (hash < root->entry.hash)
                return _h_get(root->left, hash);
            
            if (hash > root->entry.hash)
                return _h_get(root->right, hash);
            
            return root;
        }


        static void _h_remove(EntryNode *&root, const Hash::hash_t hash) {

            EntryNode *curr = root;
            EntryNode *prev = root;

            while (curr && curr->entry.hash != hash) {
                prev = curr;
                
                if (hash < curr->entry.hash) curr = curr->left;
                if (hash > curr->entry.hash) curr = curr->right;
            }

            if (!curr->left && !curr->right) {
                if      (prev == curr)        {delete root; root = 0; return;}
                else if (prev->left == curr)  {prev->left = 0;}
                else if (prev->right == curr) {prev->right = 0;}

                delete curr;
                return;
            }

            // If the node doesn't have a left child, set the prev to the node's right child.
            if (!curr->left)
            {
                if      (prev == curr)        {root = root->right;}
                else if (prev->left == curr)  {prev->left = curr->right;}
                else if (prev->right == curr) {prev->right = curr->right;}

                delete curr;
                return;
            }

            // If the node doesn't have a right child, set the prev to the node's left child.
            if (!curr->right)
            {
                if      (prev == curr)        {root = root->left;}
                else if (prev->left == curr)  {prev->left = curr->left;}
                else if (prev->right == curr) {prev->right = curr->left;}

                delete curr;
                return;
            }  



            // Get the successor.
            // Keep track of successor prev (parent)
            EntryNode *sauce_curr = curr->right;
            EntryNode *sauce_prev = curr;

            // Iterate until we find the successor.
            for (; sauce_curr->left; sauce_prev = sauce_curr, sauce_curr = sauce_curr->left);
            
            // Set the node to replace's key to the successor's key and delete the successor.
            curr->entry = sauce_curr->entry;
            delete sauce_curr;

            if (sauce_prev == curr)  {sauce_prev->right = sauce_curr->right;}
            else                     {sauce_prev->left = sauce_curr->right;}

            return;
        }




        EntryNode *_root;


        template<typename E> void _insert_param_pack(const E &arg) {
            insert(arg);
        }

        template<typename E, typename ...Es> void _insert_param_pack(const E &arg, const Es &...args) {
            insert(arg);
            _insert_param_pack(args...);
        }
            
        

    public:
        constexpr Map() : _root(0) {}

        template<typename ...EntryTypes, std::enable_if_t<(std::is_same_v<EntryType, EntryTypes> && ...)> * = nullptr>
        Map(EntryTypes &&...args) : _root(0) {_insert_param_pack(args...);}

        ~Map() {std::cout << __FUNCTION__ << std::endl; _h_erase(_root);}

        Map &insert(const EntryType &entry) {
            _h_insert(_root, entry);
            return *this;
        }

        Map &insert(const KeyType &key, const ValueType &value) {
            _h_insert(_root, Entry<KeyType, ValueType>(key, value));
            return *this;
        }

        Map &remove(const KeyType &key) {
            _h_remove(_root, Hash::generate(&key, sizeof(key)));
            return *this;
        }

        Map &print() {
            _h_print(_root);
            return *this;
        }

        ValueType &get(const KeyType &key) {
            return _h_get(_root, Hash::generate(&key, sizeof(key)))->entry.value;
        }

        ValueType get(const KeyType &key) const {
            return _h_get(_root, Hash::generate(&key, sizeof(key)))->entry.value;
        }

        ValueType &operator[](const KeyType &key)       {return get(key);}
        ValueType  operator[](const KeyType &key) const {return get(key);}


        Iterator begin() const {
            return _root;
        }

        Iterator end() const {
            return {};
        }
};



