#pragma once
#include <cmath>
#include <cstddef>
#include "def.h"
namespace linalg
{

    

    template<typename _Ty> struct Vec2;
    template<typename _Ty> struct Vec3;
    template<typename _Ty> struct Quaternion;

    

    // template<typename _Ty> struct Ray
    // {
    //     Vec3<_Ty> origin, direction;
    //     Vec3<_Ty> operator()(const _Ty t) {return origin + t * direction;}
    // };





    template<typename _Ty> struct Mat2
    {
        _Ty i00, i01,
            i10, i11;
        




        constexpr Mat2 T() const
        {
            return {
                i00, i10,
                i01, i11
            };
        }
        
        Mat2& operator=(const Mat2& rhs)
        {
            i00 = rhs.i00;  i01 = rhs.i01;
            i10 = rhs.i10;  i11 = rhs.i11;
            return *this;
        }
    };

    // MAT3

    template<typename _Ty> struct Mat3
    {
        _Ty i00, i01, i02,
            i10, i11, i12,
            i20, i21, i22;

        
        constexpr Mat3 T() const
        {
            return {
                i00, i10, i20,
                i01, i11, i21,
                i02, i12, i22
            };
        }
        
        Mat3& operator=(const Mat3& rhs)
        {
            i00 = rhs.i00;  i01 = rhs.i01;  i02 = rhs.i02;
            i10 = rhs.i10;  i11 = rhs.i11;  i12 = rhs.i12;
            i20 = rhs.i20;  i21 = rhs.i21;  i22 = rhs.i22;
            return *this;
        }
    };




    template<typename _Ty> constexpr Mat3<_Ty> mat3RotationX(const _Ty _Theta)
    {
        _Ty cos_theta = static_cast<_Ty>(cos(_Theta));
        _Ty sin_theta = static_cast<_Ty>(sin(_Theta));

        return {
            1,          0,          0,
            0,          cos_theta,  -sin_theta,
            0,          sin_theta,  cos_theta,
        };
    }

    template<typename _Ty> constexpr Mat3<_Ty> mat3RotationY(const _Ty _Theta)
    {
        _Ty cos_theta = static_cast<_Ty>(cos(_Theta));
        _Ty sin_theta = static_cast<_Ty>(sin(_Theta));

        return {
            cos_theta,  0,          sin_theta,
            0,          1,          0,
            -sin_theta, 0,          cos_theta
        };
    }

    template<typename _Ty> constexpr Mat3<_Ty> mat3RotationZ(const _Ty _Theta)
    {
        _Ty cos_theta = static_cast<_Ty>(cos(_Theta));
        _Ty sin_theta = static_cast<_Ty>(sin(_Theta));

        return {
            cos_theta,  -sin_theta, 0,
            sin_theta,  cos_theta,  0,
            0,          0,          1
        };
    }






    // MAT4

    template<typename _Ty> struct Mat4
    {
        _Ty i00, i01, i02, i03,
            i10, i11, i12, i13,
            i20, i21, i22, i23,
            i30, i31, i32, i33;


        constexpr Mat4 transposed() const
        {
            return {
                i00, i10, i20, i30,
                i01, i11, i21, i31,
                i02, i12, i22, i32,
                i03, i13, i23, i33
            };
        }

        // Mat4& transpose()
        // {
        //                 i01 = i10;  i02 = i20;  i03 = i30;
        //     i10 = i01;              i12 = i21;  i13 = i31;
        //     i20 = i02;  i21 = i12;              i23 = i32;
        //     i30 = i03;  i31 = i13;  i32 = i23;

        //     return *this;
        // }

        constexpr Mat4 T() const
        {
            return transposed();
        }
        
        Mat4& operator=(const Mat4& rhs)
        {
            i00 = rhs.i00;  i01 = rhs.i01;  i02 = rhs.i02;  i03 = rhs.i03;
            i10 = rhs.i10;  i11 = rhs.i11;  i12 = rhs.i12;  i13 = rhs.i13;
            i20 = rhs.i20;  i21 = rhs.i21;  i22 = rhs.i22;  i23 = rhs.i23;
            i30 = rhs.i30;  i31 = rhs.i31;  i32 = rhs.i32;  i33 = rhs.i33;
            return *this;
        }
    };

    template<typename _Ty> constexpr Mat4<_Ty> mat4Zeros() {
        return {0, 0, 0, 0, 
                0, 0, 0, 0, 
                0, 0, 0, 0, 
                0, 0, 0, 0};
    }

    template<typename _Ty> constexpr Mat4<_Ty> mat4Ones() {
        return {1, 1, 1, 1, 
                1, 1, 1, 1, 
                1, 1, 1, 1, 
                1, 1, 1, 1};
    }

    template<typename _Ty> constexpr Mat4<_Ty> mat4Identity() {
        return {1, 0, 0, 0, 
                0, 1, 0, 0, 
                0, 0, 1, 0, 
                0, 0, 0, 1};
    }



    template<typename _Ty> constexpr Mat4<_Ty> mat4RotationX(const _Ty _Theta)
    {
        _Ty cos_theta = static_cast<_Ty>(cos(_Theta));
        _Ty sin_theta = static_cast<_Ty>(sin(_Theta));

        return {
            1,          0,          0,          0,
            0,          cos_theta,  -sin_theta, 0,
            0,          sin_theta,  cos_theta,  0,
            0,          0,          0,          1
        };
    }

    template<typename _Ty> constexpr Mat4<_Ty> mat4RotationY(const _Ty _Theta)
    {
        _Ty cos_theta = static_cast<_Ty>(cos(_Theta));
        _Ty sin_theta = static_cast<_Ty>(sin(_Theta));

        return {
            cos_theta,  0,          sin_theta,  0,
            0,          1,          0,          0,
            -sin_theta, 0,          cos_theta,  0,
            0,          0,          0,          1
        };
    }

    template<typename _Ty> constexpr Mat4<_Ty> mat4RotationZ(const _Ty _Theta)
    {
        _Ty cos_theta = static_cast<_Ty>(cos(_Theta));
        _Ty sin_theta = static_cast<_Ty>(sin(_Theta));

        return {
            cos_theta,  -sin_theta, 0,          0,
            sin_theta,  cos_theta,  0,          0,
            0,          0,          1,          0,
            0,          0,          0,          1
        };
    }

    template<typename _Ty> constexpr Mat4<_Ty> mat4Translation(const _Ty tx, const _Ty ty, const _Ty tz)
    {
        return {
            1,          0,          0,          0,
            0,          1,          0,          0,
            0,          0,          1,          0,
            tx,         ty,         tz,         1       
        };
        // Mat4<_Ty> m;
        // m.i00 = 1;
        // m.i01 = 0;
        // m.i02 = 0;
        // m.i03 = tx;
        // m.i10 = 0;
        // m.i11 = 1;
        // m.i12 = 0;
        // m.i13 = ty;
        // m.i20 = 0;
        // m.i21 = 0;
        // m.i22 = 1;
        // m.i23 = tz;
        // m.i30 = 0;
        // m.i31 = 0;
        // m.i32 = 0;
        // m.i33 = 1;
        // return m;
    }

    template<typename _Ty> constexpr Mat4<_Ty> mat4Translation(const Vec3<_Ty>& t)
    {
        return {
            1,          0,          0,          0,
            0,          1,          0,          0,
            0,          0,          1,          0,
            t.x,        t.y,        t.z,        1       
        };
    }


    template<typename _Ty> constexpr Mat4<_Ty> mat4Scale(const _Ty sx, const _Ty sy, const _Ty sz)
    {
        return {
            sx,         0,          0,          0,
            0,          sy,         0,          0,
            0,          0,          sz,         0,
            0,          0,          0,          1       
        };
    }

    template<typename _Ty> constexpr Mat4<_Ty> mat4Scale(const Vec3<_Ty>& s)
    {
        return {
            s.x,        0,          0,          0,
            0,          s.y,        0,          0,
            0,          0,          s.z,        0,
            0,          0,          0,          1       
        };
    }




    template<typename _Ty> constexpr Mat4<_Ty> mat4Projection(const _Ty W, const _Ty H, const _Ty FOV = PI / 2.f, const _Ty near = 0.01, const _Ty far = 100)
    {
        const _Ty aspect_ratio = W / H;
        const _Ty focal_length = 1.f / tan(FOV / 2.f);

        const _Ty i00 = focal_length * aspect_ratio;
        const _Ty i11 = focal_length;
        // const _Ty i22 = (far + near) / (far - near);
        const _Ty i22 = far / (far - near);
        // const _Ty i32 = -2 * far * near / (far - near);
        const _Ty i32 = (-far * near) / (far - near);
        
        return {
            i00,    0,      0,      0,
            0,      i11,    0,      0,
            0,      0,      i22,    1.f,
            0,      0,      i32,    0,
        };
    }

    

    

    
    


    
    template<typename _Ty> struct Vec2
    {
        _Ty x, y;



        Vec2 reflected(const Vec2& _Surface_Normal_Vec)
        {
            return *this - (2 * dot(_Surface_Normal_Vec, *this) * _Surface_Normal_Vec);
        }

        Vec2& reflect(const Vec2& _Surface_Normal_Vec)
        {
            return *this = *this - (2 * dot(_Surface_Normal_Vec, *this) * _Surface_Normal_Vec);
        }


        Vec2<_Ty> operator+(const Vec2<_Ty>& rhs) const
        {
            return {x + rhs.x, y + rhs.y};
        }

        Vec2<_Ty> operator-(const Vec2<_Ty>& rhs) const 
        {
            return {x - rhs.x, y - rhs.y};
        }

        Vec2<_Ty> operator-() const
        {
            return {-x, -y};
        }

        Vec2<_Ty> operator*(const _Ty& rhs) const 
        {
            return {x * rhs, y * rhs};
        }

        Vec2<_Ty> operator/(const _Ty& rhs) const 
        {
            return {x / rhs, y / rhs};
        }

        Vec2<_Ty>& operator+=(const Vec2<_Ty>& rhs) 
        {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        Vec2<_Ty>& operator-=(const Vec2<_Ty>& rhs) 
        {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }

        Vec2<_Ty>& operator*=(const _Ty& rhs) 
        {
            x *= rhs;
            y *= rhs;
            return *this;
        }

        Vec2<_Ty>& operator/=(const _Ty& rhs) 
        {
            x /= rhs;
            y /= rhs;
            return *this;
        }

        Vec2<_Ty>& operator=(const Vec2<_Ty>& rhs)
        {
            x = rhs.x;
            y = rhs.y;
            return *this;
        }
        
    };


    template<typename _Ty> Vec2<_Ty> operator*(const _Ty& _Scalar, const Vec2<_Ty>& _Vec) 
    {
        return {
            _Vec.x * _Scalar, 
            _Vec.y * _Scalar
        };
    }

    template<typename _Ty> Vec2<_Ty> operator/(const _Ty& _Scalar, const Vec2<_Ty>& _Vec) 
    {
        return {
            _Scalar / _Vec.x, 
            _Scalar / _Vec.y
        };
    }

    template<typename _Ty> _Ty dot(const Vec2<_Ty>& _Vec_A, const Vec2<_Ty>& _Vec_B) 
    {
        return _Vec_A.x * _Vec_B.x + 
                _Vec_A.y * _Vec_B.y;
    }

    template<typename _Ty> _Ty cross(const Vec2<_Ty>& _Vec_A, const Vec2<_Ty>& _Vec_B) 
    {
        return _Vec_A.x * _Vec_B.y -
                _Vec_A.y * _Vec_B.x;
    }

    template<typename _Ty> _Ty norm(const Vec2<_Ty>& _Vec) 
    {
        return sqrt(
            _Vec.x * _Vec.x +
            _Vec.y * _Vec.y
        );
    }

    template<typename _Ty> _Ty norm(const Vec2<_Ty>& _Vec_A, const Vec2<_Ty>& _Vec_B) 
    {
        return sqrt(
            (_Vec_A.x - _Vec_B.x) * (_Vec_A.x - _Vec_B.x) +
            (_Vec_A.y - _Vec_B.y) * (_Vec_A.y - _Vec_B.y)
        );
    }

    // template<typename _Ty> _Ty normFast(const Vec2<_Ty>& _Vec) 
    // {
    //     return fastSqrt(
    //         _Vec.x * _Vec.x +
    //         _Vec.y * _Vec.y
    //     );
    // }

    // template<typename _Ty> _Ty normFast(const Vec2<_Ty>& _Vec_A, const Vec2<_Ty>& _Vec_B) 
    // {
    //     return fastSqrt(
    //         (_Vec_A.x - _Vec_B.x) * (_Vec_A.x - _Vec_B.x) +
    //         (_Vec_A.y - _Vec_B.y) * (_Vec_A.y - _Vec_B.y)
    //     );
    // }

    template<typename _Ty> _Ty normSquare(const Vec2<_Ty>& _Vec) 
    {
        return (
            _Vec.x * _Vec.x +
            _Vec.y * _Vec.y
        );
    }

    template<typename _Ty> _Ty normSquare(const Vec2<_Ty>& _Vec_A, const Vec2<_Ty>& _Vec_B) 
    {
        return (
            (_Vec_A.x - _Vec_B.x) * (_Vec_A.x - _Vec_B.x) +
            (_Vec_A.y - _Vec_B.y) * (_Vec_A.y - _Vec_B.y)
        );
    }

    template<typename _Ty> Vec2<_Ty> unit(const Vec2<_Ty>& _Vec) 
    {
        return _Vec / norm(_Vec);
    }

    // template<typename _Ty> Vec2<_Ty> unitFast(const Vec2<_Ty>& _Vec) 
    // {
    //     return _Vec / normFast(_Vec);
    // }






    template<typename _Ty> struct Vec3
    {
        _Ty x, y, z;


        constexpr Vec3() = default;
        constexpr Vec3(const _Ty x, const _Ty y, const _Ty z) : x(x), y(y), z(z) {}


        constexpr Vec2<_Ty> toVec2() const
        {
            return {x, y};
        }


        constexpr _Ty norm() const
        {
            return sqrt(
                x * x +
                y * y +
                z * z
            );
        }

        // constexpr _Ty normFast() const
        // {
        //     return fastSqrt(
        //         x * x +
        //         y * y +
        //         z * z
        //     );
        // }

        constexpr _Ty normSquare() const
        {
            return x * x + y * y + z * z;
        }

        constexpr Vec3 unit() const
        {
            return *this / norm();
        }

        // constexpr Vec3 unitFast() const
        // {
        //     return *this / normFast();
        // }

        constexpr Vec3 normalize()
        {
            return *this = *this / norm();
        }

        // constexpr Vec3 normalizeFast()
        // {
        //     return *this = *this / normFast();
        // }


        _Ty dot(const Vec3& _Vec) const
        {
            return x * _Vec.x + 
                    y * _Vec.y + 
                    z * _Vec.z;
        }

        Vec3 cross(const Vec3& _Vec) const
        {
            return {
                y * _Vec.z - z * _Vec.y,
                z * _Vec.x - x * _Vec.z,
                x * _Vec.y - y * _Vec.x
            };
        }


        Vec3 reflected(const Vec3& _Surface_Normal_Vec)
        {
            return *this - (2 * dot(_Surface_Normal_Vec, *this) * _Surface_Normal_Vec);
        }

        Vec3& reflect(const Vec3& _Surface_Normal_Vec)
        {
            return *this = *this - (2 * dot(_Surface_Normal_Vec, *this) * _Surface_Normal_Vec);
        }

        Vec3 rotated(const _Ty _Theta, const Vec3& _Axis)
        {
            return Quaternion<_Ty>{_Theta, _Axis}
                    .rotated({_Theta, _Axis})
                    .vector();
        }

        Vec3& rotate(const _Ty _Theta, const Vec3& _Axis) {
            return *this = rotated(_Theta, _Axis);
        }

        Vec3 rotatedX(const _Ty _Theta) const
        {
            return *this * mat4RotationX<_Ty>(_Theta);
        }

        Vec3 rotatedY(const _Ty _Theta) const
        {
            return *this * mat4RotationY<_Ty>(_Theta);
        }

        Vec3 rotatedZ(const _Ty _Theta) const
        {
            return *this * mat4RotationZ<_Ty>(_Theta);
        }

        Vec3& rotateX(const _Ty _Theta)
        {
            return *this *= mat4RotationX<_Ty>(_Theta);
        }

        Vec3& rotateY(const _Ty _Theta)
        {
            return *this *= mat4RotationY<_Ty>(_Theta);
        }

        Vec3& rotateZ(const _Ty _Theta)
        {
            return *this *= mat4RotationZ<_Ty>(_Theta);
        }

        Vec3 translated(const _Ty tx, const _Ty ty, const _Ty tz) const
        {
            return *this * mat4Translation<_Ty>(tx, ty, tz);
        }

        Vec3 translated(const Vec3<_Ty>& t) const
        {
            return *this * mat4Translation<_Ty>(t);
        }

        Vec3& translate(const _Ty tx, const _Ty ty, const _Ty tz)
        {
            return *this *= mat4Translation<_Ty>(tx, ty, tz);
        }

        Vec3& translate(const Vec3<_Ty>& t)
        {
            return *this *= mat4Translation<_Ty>(t);
        }

        Vec3 scaled(const _Ty sx, const _Ty sy, const _Ty sz) const
        {
            return *this * mat4Scale<_Ty>(sx, sy, sz);
        }

        Vec3 scaled(const Vec3<_Ty>& s) const
        {
            return *this * mat4Scale<_Ty>(s);
        }

        Vec3& scale(const _Ty sx, const _Ty sy, const _Ty sz)
        {
            return *this *= mat4Scale<_Ty>(sx, sy, sz);
        }

        Vec3& scale(const Vec3<_Ty>& s)
        {
            return *this *= mat4Scale<_Ty>(s);
        }

        Vec3 projected(const _Ty W, const _Ty H, const _Ty FOV = PI / 2.f, const _Ty near = 0.01, const _Ty far = 100) const
        {
            return *this * mat4Projection(W, H, FOV, near, far);
        }

        Vec3& project(const _Ty W, const _Ty H, const _Ty FOV = PI / 2.f, const _Ty near = 0.01, const _Ty far = 100)
        {
            *this *= mat4Projection(W, H, FOV, near, far);
            // x += 1.f;
            // y += 1.f;

            // x *= 0.5f * W;
            // y *= 0.5f * H;
            return *this;


        }





        /* OPERATORS */

        Vec3<_Ty> operator*(const Mat4<_Ty>& rhs) const
        {
            Vec3<_Ty> result = {
                x * rhs.i00 + y * rhs.i10 + z * rhs.i20 + rhs.i30,
                x * rhs.i01 + y * rhs.i11 + z * rhs.i21 + rhs.i31,
                x * rhs.i02 + y * rhs.i12 + z * rhs.i22 + rhs.i32
            };

            _Ty w = x * rhs.i03 + y * rhs.i13 + z * rhs.i23 + rhs.i33;

            if (w != 0.0f ) {
                // result /= w;
                result.x /= w;
                result.y /= w;
                result.z /= w;

            }
            return result;




            // out.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + m.m[3][0];
            // out.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + m.m[3][1];
            // out.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + m.m[3][2];
            // float w = v.x * m.m[0][3] + v.y * m.m[1][3] + v.z * m.m[2][3] + m.m[3][3];

            // if (w != 0.0f)
            // {
            //     out.x /= w;
            //     out.y /= w;
            //     out.z /= w;
            // }
        }

        Vec3<_Ty>& operator*=(const Mat4<_Ty>& rhs)
        {
            return *this = *this * rhs;
        }

        Vec3<_Ty> operator+(const Vec3<_Ty>& rhs) const 
        {
            return {x + rhs.x, y + rhs.y, z + rhs.z};
        }

        Vec3<_Ty> operator-(const Vec3<_Ty>& rhs) const 
        {
            return {x - rhs.x, y - rhs.y, z - rhs.z};
        }

        Vec3<_Ty> operator*(const Mat3<_Ty>& rhs)
        {
            return {
                x * rhs.i00 + y * rhs.i01 + z * rhs.i02,
                x * rhs.i01 + y * rhs.i11 + z * rhs.i21,
                x * rhs.i02 + y * rhs.i12 + z * rhs.i22
            };
        }

        Vec3<_Ty> operator-() const
        {
            return {-x, -y, -z};
        }

        Vec3<_Ty> operator*(const _Ty& rhs) const 
        {
            return {x * rhs, y * rhs, z * rhs};
        }

        Vec3<_Ty> operator/(const _Ty& rhs) const 
        {
            return {x / rhs, y / rhs, z / rhs};
        }

        Vec3<_Ty>& operator+=(const Vec3<_Ty>& rhs) 
        {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            return *this;
        }

        Vec3<_Ty>& operator-=(const Vec3<_Ty>& rhs) 
        {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            return *this;
        }

        Vec3<_Ty>& operator*=(const _Ty& rhs) 
        {
            x *= rhs;
            y *= rhs;
            z *= rhs;
            return *this;
        }

        Vec3<_Ty>& operator/=(const _Ty& rhs) 
        {
            x /= rhs;
            y /= rhs;
            z /= rhs;
            return *this;
        }

        Vec3<_Ty>& operator=(const Vec3<_Ty>& rhs)
        {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;
            return *this;
        }

        // Vec3<_Ty>& operator*=(const Matrix<_Ty, 3, 3>& _Matrix)
        // {

        //     *this = *this * _Matrix;
        //     return *this;
        // }

        // Vec3<_Ty>& rotateX(const _Ty& _Theta)
        // {
        //     _Ty cos_theta = static_cast<_Ty>(cos(_Theta));
        //     _Ty sin_theta = static_cast<_Ty>(sin(_Theta));

        //     return *this *= {{
        //         {       1,          0,          0           },
        //         {       0,          cos_theta,  -sin_theta  },
        //         {       0,          sin_theta,  cos_theta   }
        //     }};
        // }

    //     Vec3<_Ty>& rotateY(const _Ty& _Theta)
    //     {
    //         _Ty cos_theta = static_cast<_Ty>(cos(_Theta));
    //         _Ty sin_theta = static_cast<_Ty>(sin(_Theta));

    //         return *this *= {{
    //             {       cos_theta,  0,          sin_theta   },
    //             {       0,          1,          0           },
    //             {       -sin_theta, 0,          cos_theta   }
    //         }};
    //     }

    //     Vec3<_Ty>& rotateZ(const _Ty& _Theta)
    //     {
    //         _Ty cos_theta = static_cast<_Ty>(cos(_Theta));
    //         _Ty sin_theta = static_cast<_Ty>(sin(_Theta));

    //         return *this *= {{
    //             {       cos_theta,  -sin_theta, 0           },
    //             {       sin_theta,  cos_theta,  0           },
    //             {       0,          0,          1           }
    //         }};
    //     }
        
    };

    template<typename _Ty> Vec3<_Ty> operator*(const _Ty& _Scalar, const Vec3<_Ty>& _Vec) 
    {
        return {
            _Vec.x * _Scalar, 
            _Vec.y * _Scalar, 
            _Vec.z * _Scalar
        };
    }

    template<typename _Ty> Vec3<_Ty> operator/(const _Ty& _Scalar, const Vec3<_Ty>& _Vec) 
    {
        return {
            _Scalar / _Vec.x, 
            _Scalar / _Vec.y, 
            _Scalar / _Vec.z
        };
    }

    template<typename _Ty> _Ty dot(const Vec3<_Ty>& _Vec_A, const Vec3<_Ty>& _Vec_B) 
    {
        return _Vec_A.x * _Vec_B.x + 
                _Vec_A.y * _Vec_B.y + 
                _Vec_A.z * _Vec_B.z;
    }

    template<typename _Ty> Vec3<_Ty> cross(const Vec3<_Ty>& _Vec_A, const Vec3<_Ty>& _Vec_B) 
    {
        return {
            _Vec_A.y * _Vec_B.z - _Vec_A.z * _Vec_B.y,
            _Vec_A.z * _Vec_B.x - _Vec_A.x * _Vec_B.z,
            _Vec_A.x * _Vec_B.y - _Vec_A.y * _Vec_B.x
        };
    }

    template<typename _Ty> _Ty norm(const Vec3<_Ty>& _Vec) 
    {
        return sqrt(
            _Vec.x * _Vec.x +
            _Vec.y * _Vec.y +
            _Vec.z * _Vec.z
        );
    }

    template<typename _Ty> _Ty norm(const Vec3<_Ty>& _Vec_A, const Vec3<_Ty>& _Vec_B) 
    {
        return sqrt(
            (_Vec_A.x - _Vec_B.x) * (_Vec_A.x - _Vec_B.x) +
            (_Vec_A.y - _Vec_B.y) * (_Vec_A.y - _Vec_B.y) +
            (_Vec_A.z - _Vec_B.z) * (_Vec_A.z - _Vec_B.z)
        );
    }

    // template<typename _Ty> _Ty normFast(const Vec3<_Ty>& _Vec) 
    // {
    //     return fastSqrt(
    //         _Vec.x * _Vec.x +
    //         _Vec.y * _Vec.y +
    //         _Vec.z * _Vec.z
    //     );
    // }

    // template<typename _Ty> _Ty normFast(const Vec3<_Ty>& _Vec_A, const Vec3<_Ty>& _Vec_B) 
    // {
    //     return fastSqrt(
    //         (_Vec_A.x - _Vec_B.x) * (_Vec_A.x - _Vec_B.x) +
    //         (_Vec_A.y - _Vec_B.y) * (_Vec_A.y - _Vec_B.y) +
    //         (_Vec_A.z - _Vec_B.z) * (_Vec_A.z - _Vec_B.z)
    //     );
    // }

    template<typename _Ty> _Ty normSquare(const Vec3<_Ty>& _Vec) 
    {
        return (
            _Vec.x * _Vec.x +
            _Vec.y * _Vec.y +
            _Vec.z * _Vec.z
        );
    }

    template<typename _Ty> _Ty normSquare(const Vec3<_Ty>& _Vec_A, const Vec3<_Ty>& _Vec_B) 
    {
        return (
            (_Vec_A.x - _Vec_B.x) * (_Vec_A.x - _Vec_B.x) +
            (_Vec_A.y - _Vec_B.y) * (_Vec_A.y - _Vec_B.y) +
            (_Vec_A.z - _Vec_B.z) * (_Vec_A.z - _Vec_B.z)
        );
    }

    template<typename _Ty> Vec3<_Ty> unit(const Vec3<_Ty>& _Vec) 
    {
        return _Vec / norm(_Vec);
    }

    // template<typename _Ty> Vec3<_Ty> unitFast(const Vec3<_Ty>& _Vec) 
    // {
    //     return _Vec / normFast(_Vec);
    // }


    






    template<typename _Ty> struct Quaternion
    {
        _Ty s;
        Vec3<_Ty> v;

        constexpr Quaternion() = default;
        constexpr Quaternion(const Vec3<_Ty>& _Vec, const _Ty _Scalar)                    : s(_Scalar), v(_Vec)       {}
        constexpr Quaternion(const _Ty _Scalar, const Vec3<_Ty>& _Vec)                    : s(_Scalar), v(_Vec)       {}
        constexpr Quaternion(const _Ty _Scalar, const _Ty i, const _Ty j, const _Ty k)    : s(_Scalar), v{i, j, k}    {}

        constexpr Quaternion& operator=(const Quaternion& rhs)
        {
            s = rhs.s;
            v = rhs.v;
            return *this;
        }



        constexpr Quaternion operator-() {return {-s, -v};}

        constexpr Quaternion operator+(const Quaternion& rhs) const {return {s + rhs.s, v + rhs.v};}
        constexpr Quaternion operator-(const Quaternion& rhs) const {return {s - rhs.s, v - rhs.v};}
        constexpr Quaternion operator*(const _Ty rhs) const         {return {s * rhs, v * rhs};}
        constexpr Quaternion operator/(const _Ty rhs) const         {return {s / rhs, v / rhs};}
        constexpr Quaternion operator*(const Quaternion& rhs) const
        {
            return {
                s * rhs.s - v.dot(rhs.v),
                rhs.v * s + v * rhs.s + v.cross(rhs.v)
            };
        }

        constexpr Quaternion& operator+=(const Quaternion& rhs) const {return *this = *this + rhs;}
        constexpr Quaternion& operator-=(const Quaternion& rhs) const {return *this = *this - rhs;}
        constexpr Quaternion& operator*=(const _Ty rhs) const         {return *this = *this * rhs;}
        constexpr Quaternion& operator/=(const _Ty rhs) const         {return *this = *this / rhs;}
        constexpr Quaternion& operator*=(const Quaternion& rhs) const {return *this = *this * rhs;}

        constexpr Quaternion operator*() const   {return {s, -v};}
        constexpr Quaternion conj() const        {return {s, -v};}

        constexpr _Ty norm() const        {return std::sqrt(s * s + v.x * v.x + v.y * v.y + v.z * v.z);}
        // constexpr _Ty normFast() const    {return mathutil::fastSqrt(s * s + v.x * v.x + v.y * v.y + v.z * v.z);}
        constexpr _Ty normSquare() const  {return s * s + v.x * v.x + v.y * v.y + v.z * v.z;}

        constexpr Quaternion unit() const             {return *this / norm();}
        // constexpr Quaternion unitFast() const         {return *this / normFast();}
        constexpr Quaternion unitRotation() const     {return {static_cast<_Ty>(cos(s * 0.5)), static_cast<_Ty>(sin(s * 0.5)) * v.unit()};}
        // constexpr Quaternion unitRotationFast() const {return {cos(s * 0.5), sin(s * 0.5) * v.unitFast()};}

        constexpr Quaternion inv() const {return conj() / normSquare();}


        constexpr _Ty scalar() const              {return s;}
        constexpr Vec3<_Ty> vector() const        {return v;}
        constexpr Quaternion scalarQuat() const   {return {s, 0, 0, 0};}
        constexpr Quaternion vectorQuat() const   {return {0, v};}

        constexpr Quaternion rotated(const Quaternion& _Q) const
        {
            const Quaternion _Q_unit_rotation = _Q.unitRotation();
            return _Q_unit_rotation * vectorQuat() * _Q_unit_rotation.inv();
        }

        constexpr Quaternion rotated(const _Ty _Theta, const Vec3<_Ty>& _Axis) const
        {
            return rotated({_Theta, _Axis});
        }


        Quaternion& scalarize() {v = {0, 0, 0}; return *this;}
        Quaternion& vectorize() {s = 0; return *this;}

        Quaternion& rotate(const Quaternion& _Q)
        {
            return *this = rotated(_Q);
        }

        Quaternion& rotate(const _Ty _Theta, const Vec3<_Ty>& _Axis)
        {
            return *this = rotated({_Theta, _Axis});
        }
        

    };




    using Vec3f = Vec3<float>;
    using Vec3i = Vec3<int>;
    using Vec3u = Vec3<unsigned>;

} // namespace linalg







