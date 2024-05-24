#pragma once
#include <cstddef>
template<typename T> class Stack {
    
    private:
        struct Node {
            T key;
            Node *next;
        };

        class Iterator {

            private:
                Node *_iterable;
            
            public:
                constexpr Iterator() : _iterable(0) {}
                constexpr Iterator(Node *iterable) : _iterable(iterable) {}

                Iterator &operator++() {
                    _iterable = _iterable->next;
                    return *this;
                }

                T &operator*() {return _iterable->key;}
                T operator*() const {return _iterable->key;}

                bool operator==(const Iterator &rhs) {return _iterable == rhs._iterable;}
                bool operator!=(const Iterator &rhs) {return _iterable != rhs._iterable;}
        };

        template<typename E> void _push_param_pack(const E &arg) {
            push(arg);
        }

        template<typename E, typename ...Es> void _push_param_pack(const E &arg, const Es &...args) {
            push(arg);
            _push_param_pack(args...);
        }

        

        Node *_head;
        unsigned long long _size;
    
    public:
        constexpr Stack() : _head(0), _size(0) {}

        // template<typename ...Ts, std::enable_if_t<(std::is_same_v<T, Ts> && ...)> * = nullptr>
        // Stack(Ts ...args) : _head(0) {_push_param_pack(args...);}

        template<typename ...Ts, std::enable_if_t<(std::is_same_v<T, Ts> && ...)> * = nullptr>
        Stack(Ts &...args) : _head(0), _size(0) {_push_param_pack(args...);}

        

        // ~Stack() {
        //     if (_head) {
        //         _erased = true;
                 
        //         Node *curr = _head;
        //         Node *prev = _head;
                
        //         while(curr) {
        //             curr = curr->next;
        //             delete prev;
        //             std::cout << __FUNCTION__ << std::endl;
        //             prev = curr;
        //         }
        //         _head = 0;
                
        //     }
        // }

        void erase() {
            Node *curr = _head;
            Node *prev = _head;
            
            while(curr) {
                curr = curr->next;
                delete prev;
                // std::cout << __FUNCTION__ << std::endl;
                prev = curr;
            }
            _head = 0;
            _size = 0;
        }



        Stack &push(const T &value) {
            ++_size;
            if (!_head) {
                _head = new Node;
                _head->key = value;
                _head->next = 0;
            } else {
                Node *node = new Node;
                node->key = value;
                node->next = _head;
                _head = node;
            } return *this;
        }

        T pop() {
            --_size;
            Node *temp = _head;
            T value = temp->key;
            _head = _head->next;
            delete temp;
            temp = 0;
            return value;
        }

        T &top() {return _head->key;}
        T top() const {return _head->key;}

        bool empty() const {
            return !_head;
        }  

        unsigned long long size() const {
            return _size;
        }  

        Iterator begin() const {
            return _head;
        }

        Iterator end() const {
            return 0;
        }       
};