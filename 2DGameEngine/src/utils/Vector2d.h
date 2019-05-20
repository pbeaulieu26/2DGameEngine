#pragma once

#include <cmath>


namespace Engine {

    template <class T>
    class Vector2d 
    {

    public:

        T x, y;

        Vector2d() :x(0), y(0) {}
        Vector2d(T x, T y) : x(x), y(y) {}
        Vector2d(const Vector2d& v) : x(v.x), y(v.y) {}

        Vector2d& operator=(const Vector2d& v) 
        {
            x = v.x;
            y = v.y;
            return *this;
        }

        Vector2d operator+(Vector2d& v) 
        {
            return Vector2d(x + v.x, y + v.y);
        }
        Vector2d operator-(Vector2d& v) 
        {
            return Vector2d(x - v.x, y - v.y);
        }

        Vector2d& operator+=(Vector2d& v) 
        {
            x += v.x;
            y += v.y;
            return *this;
        }
        Vector2d& operator-=(Vector2d& v) 
        {
            x -= v.x;
            y -= v.y;
            return *this;
        }

        Vector2d operator+(double s) 
        { 
            return Vector2d(x + s, y + s); 
        
        }
        Vector2d operator-(double s) 
        {
            return Vector2d(x - s, y - s); 
        
        }

        Vector2d operator*(double s) 
        { 
            return Vector2d(x * s, y * s);
        }

        Vector2d operator/(double s) 
        { 
            return Vector2d(x / s, y / s); 
        }

        Vector2d& operator+=(double s) 
        {
            x += s;
            y += s;
            return *this;
        }
        Vector2d& operator-=(double s) 
        {
            x -= s;
            y -= s;
            return *this;
        }
        Vector2d& operator*=(double s) 
        {
            x *= s;
            y *= s;
            return *this;
        }
        Vector2d& operator/=(double s) 
        {
            x /= s;
            y /= s;
            return *this;
        }

        void setValues(T x, T y) 
        {
            this->x = x;
            this->y = y;
        }

        void rotate(double rad) 
        {
            double c = cos(rad);
            double s = sin(rad);
            double tx = x * c - y * s;
            double ty = x * s + y * c;
            x = tx;
            y = ty;
        }

        Vector2d& normalize() 
        {
            if (euclideanNorm() == 0) return *this;
            *this *= (1.0 / euclideanNorm());
            return *this;
        }

        float distance(Vector2d v) const 
        {
            Vector2d d(v.x - x, v.y - y);
            return d.euclideanNorm();
        }

        float euclideanNorm() const 
        {
            return std::sqrt(x * x + y * y);
        }

        Vector2d ortho() const 
        {
            return Vector2d(y, -x);
        }

        static float dot(Vector2d v1, Vector2d v2) 
        {
            return v1.x * v2.x + v1.y * v2.y;
        }

        static float cross(Vector2d v1, Vector2d v2) 
        {
            return (v1.x * v2.y) - (v1.y * v2.x);
        }

    };
}