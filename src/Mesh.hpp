#pragma once
#include "Map.hpp"
#include "HalfEdge.hpp"
#include <SFML/Graphics.hpp>

class Mesh {

    protected:
        Map<Vertex *, Stack<Vertex *>> _map;
    
    public:

        Mesh() = default;
        ~Mesh() {
            for (auto &&pair : _map) {
                pair.value.erase();
                delete pair.key;
            }
        }

        Map<Vertex *, Stack<Vertex *>> &map() {return _map;}
        Map<Vertex *, Stack<Vertex *>> map() const {return _map;}

};