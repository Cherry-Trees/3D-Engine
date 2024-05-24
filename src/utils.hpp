#pragma once
#include <SFML/Graphics.hpp>
#include "linalg.hpp"

template<typename T> sf::Vector2<T> to_SFML_Vector2(const linalg::Vec2<T> &linalg_vec2) {
    return sf::Vector2<T>{linalg_vec2.x, linalg_vec2.y};
}

template<typename T> sf::Vector2<T> to_SFML_Vector2(const linalg::Vec3<T> &linalg_vec3) {
    return sf::Vector2<T>{linalg_vec3.x, linalg_vec3.y};
}