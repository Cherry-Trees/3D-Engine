#include "Mesh.hpp"

class Cube : public Mesh {

    public:

        Cube() {
            

            Vertex *vertex1 = make_vertex({0, 0, 0});
            Vertex *vertex2 = make_vertex({1, 0, 0});
            Vertex *vertex3 = make_vertex({1, 1, 0});
            Vertex *vertex4 = make_vertex({0, 1, 0});
            Vertex *vertex5 = make_vertex({0, 0, 1});
            Vertex *vertex6 = make_vertex({1, 0, 1});
            Vertex *vertex7 = make_vertex({1, 1, 1});
            Vertex *vertex8 = make_vertex({0, 1, 1});

            this->_map
                .insert(Entry<Vertex *, Stack<Vertex *>>(vertex1, {vertex2, vertex4, vertex5}))
                .insert(Entry<Vertex *, Stack<Vertex *>>(vertex2, {vertex1, vertex3, vertex6}))
                .insert(Entry<Vertex *, Stack<Vertex *>>(vertex3, {vertex4, vertex2, vertex7}))
                .insert(Entry<Vertex *, Stack<Vertex *>>(vertex4, {vertex3, vertex1, vertex8}))
                .insert(Entry<Vertex *, Stack<Vertex *>>(vertex5, {vertex6, vertex8, vertex1}))
                .insert(Entry<Vertex *, Stack<Vertex *>>(vertex6, {vertex5, vertex7, vertex2}))
                .insert(Entry<Vertex *, Stack<Vertex *>>(vertex7, {vertex8, vertex6, vertex3}))
                .insert(Entry<Vertex *, Stack<Vertex *>>(vertex8, {vertex7, vertex5, vertex4}));
        }
};