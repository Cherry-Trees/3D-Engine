#pragma once
#include "linalg.hpp"
using namespace linalg;

struct Vertex;
struct Edge;
struct HalfEdge;
struct Face;

struct Vertex {
    Vec3f coordinate;
    HalfEdge *halfedge;
};

struct Edge {
    Vertex *vertex1, *vertex2;
    HalfEdge *halfedge1, *halfedge2;
};

struct HalfEdge {
    Vertex *vertex;
    Edge *edge;
    HalfEdge *next, *adj;
    Face *face;
};

struct Face {
    HalfEdge *halfedge;
};


Vertex *make_vertex(const Vec3f &coordinate, HalfEdge *halfedge = 0) {
    Vertex *new_vertex = new Vertex;
    new_vertex->coordinate = coordinate;
    new_vertex->halfedge = halfedge;
    return new_vertex;
}


HalfEdge *make_halfedge(Vertex *&vertex_prev, Vertex *&vertex_next, Face *&face) {
    HalfEdge *new_halfedge = new HalfEdge;
    new_halfedge->next = 0;
    new_halfedge->adj = 0;
    new_halfedge->vertex = vertex_next;
    vertex_prev->halfedge = new_halfedge;
    new_halfedge->face = face;
    face->halfedge = new_halfedge;
    return new_halfedge;
}



void link_halfedge_inline(HalfEdge *&halfedge_prev, HalfEdge *&halfedge_next) {
    halfedge_prev->next = halfedge_next;
}

void link_halfedge_adj(HalfEdge *&halfedge1, HalfEdge *&halfedge2) {
    halfedge1->adj = halfedge2;
    halfedge2->adj = halfedge1;
}


Face *make_face_tri_from_halfedge(HalfEdge *&halfedge1, HalfEdge *&halfedge2, HalfEdge *&halfedge3) {

    link_halfedge_inline(halfedge1, halfedge2);
    link_halfedge_inline(halfedge2, halfedge3);
    link_halfedge_inline(halfedge3, halfedge1);

    Face *new_face = new Face;
    new_face->halfedge = halfedge1;
    halfedge1->face = new_face;
    halfedge2->face = new_face;
    halfedge3->face = new_face;
    return new_face;
}

Face *make_face_tri(Vertex *&vertex1, Vertex *&vertex2, Vertex *&vertex3) {

    Face *face = new Face;
    HalfEdge *halfedge12 = make_halfedge(vertex1, vertex2, face);
    HalfEdge *halfedge23 = make_halfedge(vertex2, vertex3, face);
    HalfEdge *halfedge31 = make_halfedge(vertex3, vertex1, face);

    link_halfedge_inline(halfedge12, halfedge23);
    link_halfedge_inline(halfedge23, halfedge31);
    link_halfedge_inline(halfedge31, halfedge12);
    return face;
}

// Face *make_face_tri(const Vec3f &coordinate1, const Vec3 &coordinate2, const Vec3 &coordinate3) {
//     Vertex *vertex1 = make_vertex(coordinate1);
//     Vertex *vertex2 = make_vertex(coordinate2);
//     Vertex *vertex3 = make_vertex(coordinate3);
//     return make_face_tri_from_vertex(vertex1, vertex2, vertex3);
// }