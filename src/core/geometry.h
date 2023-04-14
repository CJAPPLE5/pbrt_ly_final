//
// Created by zilae on 23-4-13.
//

#ifndef PBRT_LY_GEOMETRY_H
#define PBRT_LY_GEOMETRY_H

#include "pbrt.h"

template <typename T>
inline bool isNaN(const T x) {
    return std::isnan(x);
}

template <>
inline bool isNaN(const int x) {
    return false;
}

typedef Vector2<Float> Vector2f;
typedef Vector2<int>   Vector2i;
typedef Vector3<Float> Vector3f;
typedef Vector3<int>   Vector3i;

typedef Point2<Float> Point2f;
typedef Point2<int>   Point2i;
typedef Point3<Float> Point3f;
typedef Point3<int>   Point3i;

typedef Normal3<Float> Normal3f;

typedef Bounds2<Float> Bounds2f;
typedef Bounds2<int> Bounds2i;
typedef Bounds3<Float> Bounds3f;
typedef Bounds3<int> Bounds3i;

template <typename T>
class Vector2{
public:
    T x,y;
public:
    Vector2() {x = y =0;}
    Vector2(T xx, T yy):x(xx), y(yy) { DCHECK(!HasNaNs());}
    bool HasNaNs() const {return isNaN(x) || isNaN(y);}
    explicit Vector2(const Point2<T>&p): x(p.x), y(p.y) {DCHECK(!HasNaNs());}
    explicit Vector2(const Point3<T>&p): x(p.x), y(p.y) {DCHECK(!HasNaNs());}
#ifndef NDEBUG
    // The default versions of these are fine for release builds; for debug
    // we define them so that we can add the DCHECK checks.
    Vector2(const Vector2<T> &v) {
        DCHECK(!v.HasNaNs());
        x = v.x;
        y = v.y;
    }
    Vector2<T> &operator=(const Vector2<T> &v) {
        DCHECK(!v.HasNaNs());
        x = v.x;
        y = v.y;
        return *this;
    }
#endif  // !NDEBUG
    friend std::ostream& operator<<(std::ostream& os, const Vector2<T> &v) {
        os << "[" << v.x << ", " << v.y << "]";
        return os;
    }
    Vector2<T> operator+(const Vector2<T> &v) const {
        DCHECK(!v.HasNaNs());
        return Vector2<T>(x + v.x , y + v.y);
    }

    Vector2<T>& operator+=(const Vector2<T> &v) const {
        DCHECK(!v.HasNaNs());
        x += v.x;
        y += v.y;
        return *this;
    }

    Vector2<T> operator-(const Vector2<T> &v) const {
        DCHECK(!v.HasNaNs());
        return Vector2<T>(x - v.x , y - v.y);
    }

    Vector2<T>& operator-=(const Vector2<T> &v) const {
        DCHECK(!v.HasNaNs());
        x += v.x;
        y += v.y;
        return *this;
    }

    bool operator==(const Vector2<T>& v) const {return x == v.x && y == v.y;}
    bool operator!=(const Vector2<T>& v) const {return x != v.x || y != v.y;}

    template<typename U>
    Vector2<T> operator*(U f) {
        return Vector2<T>(f * x, f * y);
    }

    template<typename U>
    Vector2<T>& operator*=(U f) {
        x *= f;
        y *= f;
        return *this;
    }

    template<typename U>
    Vector2<T> operator/(U f) {
        CHECK_NE(f, 0);
        Float inv = (Float) 1 / f;
        return Vector2<T>(x * inv, y * inv);
    }

    template<typename U>
    Vector2<T>& operator/=(U f) {
        CHECK_NE(f, 0);
        Float inv = (Float) 1 / f;
        x *= inv;
        y *= inv;
        return *this;
    }

    Vector2<T> operator-() const {return Vector2<T>(-x,-y);}

    T operator[](int i) const {
        DCHECK(i >=0 && i <= 1);
        if(i == 0) return x;
        else return y;
    }

    T& operator[](int i) {
        DCHECK(i >= 0 && i <= 1);
        if(i == 0) return x;
        else return y;
    }

    Float LengthSquared() const { return x * x + y * y;}
    Float Length() const { return std::sqrt(LengthSquared());}

};


template <typename T>
class Vector3{
public:
    T x,y,z;
public:
    Vector3() {x = y = z =0;}
    Vector3(T xx, T yy, T zz):x(xx), y(yy), z(zz) { DCHECK(!HasNaNs());}
    bool HasNaNs() const {return isNaN(x) || isNaN(y) || isNaN(z);}
    explicit Vector3(const Point2<T>&p): x(p.x), y(p.y), z(0) {DCHECK(!HasNaNs());}
    explicit Vector3(const Point3<T>&p): x(p.x), y(p.y), z(p.z) {DCHECK(!HasNaNs());}
    explicit Vector3(const Normal3<T>&p): x(p.x), y(p.y), z(p.z) {DCHECK(!HasNaNs());}
#ifndef NDEBUG
    // The default versions of these are fine for release builds; for debug
    // we define them so that we can add the DCHECK checks.
    Vector3(const Vector3<T> &v) {
        DCHECK(!v.HasNaNs());
        x = v.x;
        y = v.y;
        z = v.z;
    }
    Vector3<T> &operator=(const Vector3<T> &v) {
        DCHECK(!v.HasNaNs());
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
#endif  // !NDEBUG
    friend std::ostream& operator<<(std::ostream& os, const Vector3<T> &v) {
        os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
        return os;
    }
    Vector3<T> operator+(const Vector3<T> &v) const {
        DCHECK(!v.HasNaNs());
        return Vector3<T>(x + v.x , y + v.y, z + v.z);
    }

    Vector3<T>& operator+=(const Vector3<T> &v) const {
        DCHECK(!v.HasNaNs());
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector3<T> operator-(const Vector3<T> &v) const {
        DCHECK(!v.HasNaNs());
        return Vector3<T>(x - v.x , y - v.y, z - v.z);
    }

    Vector3<T>& operator-=(const Vector3<T> &v) const {
        DCHECK(!v.HasNaNs());
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    bool operator==(const Vector3<T>& v) const {return x == v.x && y == v.y && z == v.z;}
    bool operator!=(const Vector3<T>& v) const {return x != v.x || y != v.y || z != v.z;}

    template<typename U>
    Vector3<T> operator*(U f) {
        return Vector3<T>(f * x, f * y, f*z);
    }

    template<typename U>
    Vector3<T>& operator*=(U f) {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }

    template<typename U>
    Vector3<T> operator/(U f) {
        CHECK_NE(f, 0);
        Float inv = (Float) 1 / f;
        return Vector3<T>(x * inv, y * inv, z*inv);
    }

    template<typename U>
    Vector3<T>& operator/=(U f) {
        CHECK_NE(f, 0);
        Float inv = (Float) 1 / f;
        x *= inv;
        y *= inv;
        z *= inv;
        return *this;
    }

    Vector3<T> operator-() const {return Vector3<T>(-x,-y,-z);}

    T operator[](int i) const {
        DCHECK(i >=0 && i <= 2);
        if(i == 0) return x;
        else if(i==1) return y;
        else return z;
    }

    T& operator[](int i) {
        DCHECK(i >= 0 && i <= 2);
        if(i == 0) return x;
        else if(i==1) return y;
        else return z;
    }

    Float LengthSquared() const { return x * x + y * y + z * z;}
    Float Length() const { return std::sqrt(LengthSquared());}

};

template <typename T> inline T
Dot(const Vector3<T> &v1, const Vector3<T> &v2) {
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}
template <typename T> inline T
Dot(const Vector2<T> &v1, const Vector2<T> &v2) {
    return v1.x*v2.x + v1.y*v2.y;
}

template <typename T> inline T
AbsDot(const Vector3<T> &v1, const Vector3<T> &v2) {
    return std::abs(Dot(v1,v2));
}
template <typename T> inline T
AbsDot(const Vector2<T> &v1, const Vector2<T> &v2) {
    return std::abs(Dot(v1,v2));
}

template <typename T> inline Vector3<T>
Cross(const Vector3<T> &v1, const Vector3<T> &v2) {
    double v1x = v1.x, v1y = v1.y, v1z = v1.z;
    double v2x = v2.x, v2y = v2.y, v2z = v2.z;
    return Vector3<T>((v1y * v2z) - (v1z * v2y),
                      (v1z * v2x) - (v1x * v2z),
                      (v1x * v2y) - (v1y * v2x));
}

template <typename T> inline Vector3<T>
Normalize(const Vector3<T> &v) { return v / v.Length(); }

template <typename T> inline Vector2<T>
Normalize(const Vector2<T> &v) { return v / v.Length(); }

template <typename T> T
MinComponent(const Vector3<T> &v) {
    return std::min(v.x, std::min(v.y, v.z));
}
template <typename T> T
MaxComponent(const Vector3<T> &v) {
    return std::max(v.x, std::max(v.y, v.z));
}

template <typename T> T
MinComponent(const Vector2<T> &v) {
    return std::min(v.x, v.y);
}
template <typename T> T
MaxComponent(const Vector2<T> &v) {
    return std::max(v.x, v.y);
}

template <typename T> int
MaxDimension(const Vector3<T> &v) {
    return (v.x > v.y) ? ((v.x > v.z) ? 0 : 2) :
           ((v.y > v.z) ? 1 : 2);
}

template <typename T> int
MinDimension(const Vector3<T> &v) {
    return (v.x < v.y) ? ((v.x < v.z) ? 0 : 2) :
           ((v.y < v.z) ? 1 : 2);
}

template <typename T> int
MaxDimension(const Vector2<T> &v) {
    return (v.x > v.y) ? 0 : 1;
}

template <typename T> int
MinDimension(const Vector2<T> &v) {
    return (v.x < v.y) ? 0 : 1;
}

template <typename T> Vector3<T>
Min(const Vector3<T> &p1, const Vector3<T> &p2) {
    return Vector3<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y),
                      std::min(p1.z, p2.z));
}
template <typename T> Vector3<T>
Max(const Vector3<T> &p1, const Vector3<T> &p2) {
    return Vector3<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y),
                      std::max(p1.z, p2.z));
}

template <typename T> Vector2<T>
Min(const Vector2<T> &p1, const Vector2<T> &p2) {
    return Vector2<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y));
}
template <typename T> Vector2<T>
Max(const Vector2<T> &p1, const Vector2<T> &p2) {
    return Vector2<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y));
}

template <typename T> Vector3<T>
Permute(const Vector3<T> &v, int x, int y, int z) {
    return Vector3<T>(v[x], v[y], v[z]);
}

template <typename T> Vector2<T>
Permute(const Vector2<T> &v, int x, int y) {
    return Vector2<T>(v[x], v[y]);
}

template <typename T> inline void
CoordinateSystem(const Vector3<T> &v1, Vector3<T> *v2, Vector3<T> *v3) {
    if (std::abs(v1.x) > std::abs(v1.y))
        *v2 = Vector3<T>(-v1.z, 0, v1.x) /
              std::sqrt(v1.x * v1.x + v1.z * v1.z);
    else
        *v2 = Vector3<T>(0, v1.z, -v1.y) /
              std::sqrt(v1.y * v1.y + v1.z * v1.z);
    *v3 = Cross(v1, *v2);
}

template <typename T>
class Point2{
public:
        T x,y;
public:
        explicit Point2(const Point3<T> &p) : x(p.x), y(p.y) {
            DCHECK(!HasNaNs());
        }
        Point2() : x(0), y(0) {}
        Point2(T xx, T yy) : x(xx), y(yy){
            DCHECK(!HasNaNs());
        }

        template <typename U> explicit Point2(const Point2<U> &p) {
            x = (T)p.x;
            y = (T)p.y;
            DCHECK(!HasNaNs());
        }

        template <typename U> explicit Point2(const Vector2<U> &p) {
            x = (T)p.x;
            y = (T)p.y;
            DCHECK(!HasNaNs());
        }

        template <typename U> explicit operator Vector2<U>() const {
            return Vector2<U>(x, y);
        }

        #ifndef NDEBUG
            Point2(const Point2<T> &p) {
                   DCHECK(!p.HasNaNs());
                   x = p.x; y = p.y;
               }

               Point2<T> &operator=(const Point2<T> &p) {
                   DCHECK(!p.HasNaNs());
                   x = p.x; y = p.y;
                   return *this;
               }
        #endif // !NDEBUG

        friend std::ostream& operator<<(std::ostream& os, const Point2<T> &p) {
            os << "[" << p.x << ", " << p.y << "]";
            return os;
        }

        Point2<T> operator+(const Vector2<T> &v) const {
            DCHECK(!v.HasNaNs());
            return Point2<T>(x + v.x, y + v.y);
        }

        Point2<T> &operator+=(const Vector2<T> &v) {
            DCHECK(!v.HasNaNs());
            x += v.x; y += v.y;
            return *this;
        }
        Vector2<T> operator-(const Point2<T> &p) const {
            DCHECK(!p.HasNaNs());
            return Vector2<T>(x - p.x, y - p.y);
        }

        Point2<T> operator-(const Vector2<T> &v) const {
            DCHECK(!v.HasNaNs());
            return Point2<T>(x - v.x, y - v.y);
        }
        Point2<T> operator-() const { return Point2<T>(-x, -y); }
        Point2<T> &operator-=(const Vector2<T> &v) {
            DCHECK(!v.HasNaNs());
            x -= v.x; y -= v.y;
            return *this;
        }
        Point2<T> &operator+=(const Point2<T> &p) {
            DCHECK(!p.HasNaNs());
            x += p.x; y += p.y;
            return *this;
        }
        Point2<T> operator+(const Point2<T> &p) const {
            DCHECK(!p.HasNaNs());
            return Point2<T>(x + p.x, y + p.y);
        }
        Point2<T> operator* (T f) const {
            return Point2<T>(f*x, f*y);
        }
        Point2<T> &operator*=(T f) {
            x *= f; y *= f;
            return *this;
        }
        Point2<T> operator/ (T f) const {
            Float inv = (Float)1 / f;
            return Point2<T>(inv*x, inv*y);
        }
        Point2<T> &operator/=(T f) {
            Float inv = (Float)1 / f;
            x *= inv; y *= inv;
            return *this;
        }
        T operator[](int i) const {
            DCHECK(i >= 0 && i <= 1);
            if (i == 0) return x;
            return y;
        }

        T &operator[](int i) {
            DCHECK(i >= 0 && i <= 1);
            if (i == 0) return x;
            return y;
        }
        bool operator==(const Point2<T> &p) const {
            return x == p.x && y == p.y;
        }
        bool operator!=(const Point2<T> &p) const {
            return x != p.x || y != p.y;
        }
        bool HasNaNs() const {
            return std::isnan(x) || std::isnan(y);
        }

};

template <typename T>
class Point3{
public:
    T x,y,z;
    Point3() { x = y = z = 0; }
    Point3(T x, T y, T z) : x(x), y(y), z(z) {
        DCHECK(!HasNaNs());
    }
    template <typename U> explicit Point3(const Point3<U> &p)
            : x((T)p.x), y((T)p.y), z((T)p.z) {
        DCHECK(!HasNaNs());
    }
    template <typename U> explicit operator Vector3<U>() const {
        return Vector3<U>(x, y, z);
    }
#ifndef NDEBUG
    Point3(const Point3<T> &p) {
           DCHECK(!p.HasNaNs());
           x = p.x; y = p.y; z = p.z;
       }
       
       Point3<T> &operator=(const Point3<T> &p) {
           DCHECK(!p.HasNaNs());
           x = p.x; y = p.y; z = p.z;
           return *this;
       }
#endif // !NDEBUG
    friend std::ostream& operator<<(std::ostream& os, const Point3<T> &p) {
        os << "[" << p.x << ", " << p.y << ", " << p.z << "]";
        return os;
    }
    Point3<T> operator+(const Vector3<T> &v) const {
        return Point3<T>(x + v.x, y + v.y, z + v.z);
    }
    Point3<T> &operator+=(const Vector3<T> &v) {
        x += v.x; y += v.y; z += v.z;
        return *this;
    }
    Vector3<T> operator-(const Point3<T> &p) const {
        return Vector3<T>(x - p.x, y - p.y, z - p.z);
    }
    Point3<T> operator-(const Vector3<T> &v) const {
        return Point3<T>(x - v.x, y - v.y, z - v.z);
    }
    Point3<T> &operator-=(const Vector3<T> &v) {
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }
    Point3<T> &operator+=(const Point3<T> &p) {
        x += p.x; y += p.y; z += p.z;
        return *this;
    }
    Point3<T> operator+(const Point3<T> &p) const {
        return Point3<T>(x + p.x, y + p.y, z + p.z);
    }
    Point3<T> operator*(T f) const {
        return Point3<T>(f*x, f*y, f*z);
    }
    Point3<T> &operator*=(T f) {
        x *= f; y *= f; z *= f;
        return *this;
    }
    Point3<T> operator/(T f) const {
        Float inv = (Float)1 / f;
        return Point3<T>(inv*x, inv*y, inv*z);
    }
    Point3<T> &operator/=(T f) {
        Float inv = (Float)1 / f;
        x *= inv; y *= inv; z *= inv;
        return *this;
    }
    T operator[](int i) const {
        DCHECK(i >= 0 && i <= 2);
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }

    T &operator[](int i) {
        DCHECK(i >= 0 && i <= 2);
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }
    bool operator==(const Point3<T> &p) const {
        return x == p.x && y == p.y && z == p.z;
    }
    bool operator!=(const Point3<T> &p) const {
        return x != p.x || y != p.y || z != p.z;
    }
    bool HasNaNs() const {
        return std::isnan(x) || std::isnan(y) || std::isnan(z);
    }
    Point3<T> operator-() const { return Point3<T>(-x, -y, -z); }
};

template <typename T> inline Float
Distance(const Point3<T>& p1, const Point3<T>& p2) {
    return (p1-p2).Length();
}

template <typename T> inline Float
DistanceSquared(const Point3<T> &p1, const Point3<T> &p2) {
    return (p1 - p2).LengthSquared();
}

template <typename T> Point3<T>
Lerp(Float t, const Point3<T>& p0, const Point3<T>& p1) {
    return p0 * (1-t) + p1 * t;
}

template <typename T> Point3<T>
Min(const Point3<T> &p1, const Point3<T> &p2) {
    return Point3<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y),
                     std::min(p1.z, p2.z));
}
template <typename T> Point3<T>
Max(const Point3<T> &p1, const Point3<T> &p2) {
    return Point3<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y),
                     std::max(p1.z, p2.z));
}

template <typename T> Point3<T> Floor(const Point3<T> &p) {
    return Point3<T>(std::floor(p.x), std::floor(p.y), std::floor(p.z));
}
template <typename T> Point3<T> Ceil(const Point3<T> &p) {
    return Point3<T>(std::ceil(p.x), std::ceil(p.y), std::ceil(p.z));
}
template <typename T> Point3<T> Abs(const Point3<T> &p) {
    return Point3<T>(std::abs(p.x), std::abs(p.y), std::abs(p.z));
}

template <typename T> Point3<T>
Permute(const Point3<T> &p, int x, int y, int z) {
    return Point3<T>(p[x], p[y], p[z]);
}

template <typename T>
class Normal3 {
    public:
        T x, y, z;
    Normal3() { x = y = z = 0; }
    Normal3(T xx, T yy, T zz)
            : x(xx), y(yy), z(zz) {
    }
    Normal3<T> operator-() const {
        return Normal3(-x, -y, -z);
    }
    Normal3<T> operator+(const Normal3<T> &n) const {
        return Normal3<T>(x + n.x, y + n.y, z + n.z);
    }

    Normal3<T>& operator+=(const Normal3<T> &n) {
        x += n.x; y += n.y; z += n.z;
        return *this;
    }
    Normal3<T> operator- (const Normal3<T> &n) const {
        return Normal3<T>(x - n.x, y - n.y, z - n.z);
    }

    Normal3<T>& operator-=(const Normal3<T> &n) {
        x -= n.x; y -= n.y; z -= n.z;
        return *this;
    }
    bool HasNaNs() const {
        return std::isnan(x) || std::isnan(y) || std::isnan(z);
    }
    Normal3<T> operator*(T f) const {
        return Normal3<T>(f*x, f*y, f*z);
    }

    Normal3<T> &operator*=(T f) {
        x *= f; y *= f; z *= f;
        return *this;
    }
    Normal3<T> operator/(T f) const {
        DCHECK(f != 0);
        Float inv = (Float)1 / f;
        return Normal3<T>(x * inv, y * inv, z * inv);
    }

    Normal3<T> &operator/=(T f) {
        DCHECK(f != 0);
        Float inv = (Float)1 / f;
        x *= inv; y *= inv; z *= inv;
        return *this;
    }
    Float LengthSquared() const { return x*x + y*y + z*z; }
    Float Length() const        { return std::sqrt(LengthSquared()); }

#ifndef NDEBUG
    Normal3<T>(const Normal3<T> &n) {
           DCHECK(!n.HasNaNs());
           x = n.x; y = n.y; z = n.z;
       }

       Normal3<T> &operator=(const Normal3<T> &n) {
           DCHECK(!n.HasNaNs());
           x = n.x; y = n.y; z = n.z;
           return *this;
       }
#endif // !NDEBUG
    friend std::ostream& operator<<(std::ostream& os, const Normal3<T> &v) {
        os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
        return os;
    }
    explicit Normal3<T>(const Vector3<T> &v) : x(v.x), y(v.y), z(v.z) {
        DCHECK(!v.HasNaNs());
    }
    bool operator==(const Normal3<T> &n) const {
        return x == n.x && y == n.y && z == n.z;
    }
    bool operator!=(const Normal3<T> &n) const {
        return x != n.x || y != n.y || z != n.z;
    }

    T operator[](int i) const {
        DCHECK(i >= 0 && i <= 2);
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }

    T &operator[](int i) {
        DCHECK(i >= 0 && i <= 2);
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }
};

template <typename T> inline Normal3<T>
Normalize(const Normal3<T> &n)
{
    return n / n.Length();
}

template <typename T>
inline T Dot(const Normal3<T> &n1, const Vector3<T> &v2) {
    DCHECK(!n1.HasNaNs() && !v2.HasNaNs());
    return n1.x * v2.x + n1.y * v2.y + n1.z * v2.z;
}

template <typename T>
inline T Dot(const Vector3<T> &v1, const Normal3<T> &n2) {
    DCHECK(!v1.HasNaNs() && !n2.HasNaNs());
    return v1.x * n2.x + v1.y * n2.y + v1.z * n2.z;
}

template <typename T>
inline T Dot(const Normal3<T> &n1, const Normal3<T> &n2) {
    DCHECK(!n1.HasNaNs() && !n2.HasNaNs());
    return n1.x * n2.x + n1.y * n2.y + n1.z * n2.z;
}

template <typename T>
inline T AbsDot(const Normal3<T> &n1, const Vector3<T> &v2) {
    DCHECK(!n1.HasNaNs() && !v2.HasNaNs());
    return std::abs(n1.x * v2.x + n1.y * v2.y + n1.z * v2.z);
}

template <typename T>
inline T AbsDot(const Vector3<T> &v1, const Normal3<T> &n2) {
    DCHECK(!v1.HasNaNs() && !n2.HasNaNs());
    return std::abs(v1.x * n2.x + v1.y * n2.y + v1.z * n2.z);
}

template <typename T>
inline T AbsDot(const Normal3<T> &n1, const Normal3<T> &n2) {
    DCHECK(!n1.HasNaNs() && !n2.HasNaNs());
    return std::abs(n1.x * n2.x + n1.y * n2.y + n1.z * n2.z);
}

template <typename T> inline Normal3<T>
Faceforward(const Normal3<T> &n, const Vector3<T> &v) {
    return (Dot(n, v) < 0.f) ? -n : n;
}

class Ray{
public:
        Ray(): tMax(Infinity), time(0.f), medium(nullptr) {}
        Ray(const Point3f &o, const Vector3f &d, Float tMax = Infinity,
            Float time=0.f, const Medium* medium= nullptr):
            o(o), d(o), tMax(tMax), time(time), medium(medium) {}

    Point3f operator()(Float t) {return o + d * t;}
    bool HasNaNs() const {
        return (o.HasNaNs() || d.HasNaNs() || std::isnan(tMax));
    }
    friend std::ostream& operator<<(std::ostream& os, const Ray &r) {
        os << "[o=" << r.o << ", d=" << r.d << ", tMax="
           << r.tMax << ", time=" << r.time << "]";
        return os;
    }
public:
    Point3f o;
    Vector3f d;
    mutable Float tMax;
    Float time;
    const Medium* medium;
};

class RayDifferential : public Ray {
public:
    RayDifferential() { hasDifferentials = false; }
    RayDifferential(const Point3f &o, const Vector3f &d,
                    Float tMax = Infinity, Float time = 0.f,
                    const Medium *medium = nullptr)
            : Ray(o, d, tMax, time, medium) {
        hasDifferentials = false;
    }
    RayDifferential(const Ray &ray) : Ray(ray) {
        hasDifferentials = false;
    }
    bool HasNaNs() const {
        return Ray::HasNaNs() ||
               (hasDifferentials && (rxOrigin.HasNaNs() || ryOrigin.HasNaNs() ||
                                     rxDirection.HasNaNs() || ryDirection.HasNaNs()));
    }
    void ScaleDifferentials(Float s) {
        rxOrigin = o + (rxOrigin - o) * s;
        ryOrigin = o + (ryOrigin - o) * s;
        rxDirection = d + (rxDirection - d) * s;
        ryDirection = d + (ryDirection - d) * s;
    }

    bool hasDifferentials;
    Point3f rxOrigin, ryOrigin;
    Vector3f rxDirection, ryDirection;

};

template <typename T>
class Bounds2{
public:
    Bounds2(){
        T minNum = std::numeric_limits<T>::lowest();
        T maxNum = std::numeric_limits<T>::max();
        pMin = Point2<T>(maxNum, maxNum);
        pMax = Point2<T>(minNum, minNum);
    }
    Bounds2(const Point2<T> &p) : pMin(p), pMax(p) {}
    Bounds2(const Point2<T> &p1, const Point2<T> &p2) {
        pMin = Point2<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y));
        pMax = Point2<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y));
    }
    template <typename U> explicit operator Bounds2<U>() const {
        return Bounds2<U>((Point2<U>)pMin, (Point2<U>)pMax);
    }

    Vector2<T> Diagonal() const {
        return pMax - pMin;
    }
    T Area() const {
        Vector2<T> d = pMax - pMin;
        return (d.x * d.y);
    }
    int MaximumExtent() const {
        Vector2<T> diag = Diagonal();
        if (diag.x > diag.y)
            return 0;
        else
            return 1;
    }
    inline const Point2<T> & operator[](int i) const {
        DCHECK(i == 0 || i == 1);
        return (i == 0) ? pMin : pMax;
    }
    inline Point2<T> &operator[](int i) {
        DCHECK(i == 0 || i == 1);
        return (i == 0) ? pMin : pMax;
    }
    bool operator==(const Bounds2<T> &b) const {
        return b.pMin == pMin && b.pMax == pMax;
    }
    bool operator!=(const Bounds2<T> &b) const {
        return b.pMin != pMin || b.pMax != pMax;
    }
    Point2<T> Lerp(const Point2f &t) const {
        return Point2<T>(::Lerp(t.x, pMin.x, pMax.x), ::Lerp(t.y, pMin.y, pMax.y));
    }
    Vector2<T> Offset(const Point2<T> &p) const {
        Vector2<T> o = p - pMin;
        if (pMax.x > pMin.x) o.x /= pMax.x - pMin.x;
        if (pMax.y > pMin.y) o.y /= pMax.y - pMin.y;
        return o;
    }
    void BoundingSphere(Point2<T> *c, Float *rad) const {
        *c = (pMin + pMax) / 2;
        *rad = Inside(*c, *this) ? Distance(*c, pMax) : 0;
    }

public:
    Point2<T> pMin, pMax;
};

template <typename T> class Bounds3 {
public:
    Bounds3() {
        T minNum = std::numeric_limits<T>::lowest();
        T maxNum = std::numeric_limits<T>::max();
        pMin = Point3<T>(maxNum, maxNum, maxNum);
        pMax = Point3<T>(minNum, minNum, minNum);
    }
    Bounds3(const Point3<T> &p) : pMin(p), pMax(p) { }
    Bounds3(const Point3<T> &p1, const Point3<T> &p2)
            : pMin(std::min(p1.x, p2.x), std::min(p1.y, p2.y),
                   std::min(p1.z, p2.z)),
              pMax(std::max(p1.x, p2.x), std::max(p1.y, p2.y),
                   std::max(p1.z, p2.z)) {
    }
    const Point3<T> &operator[](int i) const {
        CHECK(i >= 0 && i <= 1);
        if(i == 0) return pMin;
        else return pMax;
    };
    Point3<T> &operator[](int i) {
        CHECK(i >= 0 && i <= 1);
        if(i == 0) return pMin;
        else return pMax;
    }
    bool operator==(const Bounds3<T> &b) const {
        return b.pMin == pMin && b.pMax == pMax;
    }
    bool operator!=(const Bounds3<T> &b) const {
        return b.pMin != pMin || b.pMax != pMax;
    }
    Point3<T> Corner(int corner) const {
        return Point3<T>((*this)[(corner & 1)].x,
                         (*this)[(corner & 2) ? 1 : 0].y,
                         (*this)[(corner & 4) ? 1 : 0].z);
    }
    Vector3<T> Diagonal() const { return pMax - pMin; }
    T SurfaceArea() const {
        Vector3<T> d = Diagonal();
        return 2 * (d.x * d.y + d.x * d.z + d.y * d.z);
    }
    T Volume() const {
        Vector3<T> d = Diagonal();
        return d.x * d.y * d.z;
    }
    int MaximumExtent() const {
        Vector3<T> d = Diagonal();
        if (d.x > d.y && d.x > d.z)
            return 0;
        else if (d.y > d.z)
            return 1;
        else
            return 2;
    }
    Point3<T> Lerp(const Point3f &t) const {
        return Point3<T>(::Lerp(t.x, pMin.x, pMax.x),
                         ::Lerp(t.y, pMin.y, pMax.y),
                         ::Lerp(t.z, pMin.z, pMax.z));
    }
    Vector3<T> Offset(const Point3<T> &p) const {
        Vector3<T> o = p - pMin;
        if (pMax.x > pMin.x) o.x /= pMax.x - pMin.x;
        if (pMax.y > pMin.y) o.y /= pMax.y - pMin.y;
        if (pMax.z > pMin.z) o.z /= pMax.z - pMin.z;
        return o;
    }
    void BoundingSphere(Point3<T> *center, Float *radius) const {
        *center = (pMin + pMax) / 2;
        *radius = Inside(*center, *this) ? Distance(*center, pMax) : 0;
    }
    template <typename U> explicit operator Bounds3<U>() const {
        return Bounds3<U>((Point3<U>)pMin, (Point3<U>)pMax);
    }
    bool IntersectP(const Ray &ray, Float *hitt0 = nullptr, Float *hitt1 = nullptr) const;
    inline bool IntersectP(const Ray &ray, const Vector3f &invDir,
                           const int dirIsNeg[3]) const;

    Point3<T> pMin, pMax;

};

template <typename T> Bounds3 <T>
Union(const Bounds3<T> &b, const Point3<T> &p) {
    return Bounds3<T>(Point3<T>(std::min(b.pMin.x, p.x),
                                std::min(b.pMin.y, p.y),
                                std::min(b.pMin.z, p.z)),
                      Point3<T>(std::max(b.pMax.x, p.x),
                                std::max(b.pMax.y, p.y),
                                std::max(b.pMax.z, p.z)));
}

template <typename T> Bounds3<T>
Union(const Bounds3<T> &b1, const Bounds3<T> &b2) {
    return Bounds3<T>(Point3<T>(std::min(b1.pMin.x, b2.pMin.x),
                                std::min(b1.pMin.y, b2.pMin.y),
                                std::min(b1.pMin.z, b2.pMin.z)),
                      Point3<T>(std::max(b1.pMax.x, b2.pMax.x),
                                std::max(b1.pMax.y, b2.pMax.y),
                                std::max(b1.pMax.z, b2.pMax.z)));
}

template <typename T> Bounds3<T>
Intersect(const Bounds3<T> &b1, const Bounds3<T> &b2) {
    return Bounds3<T>(Point3<T>(std::max(b1.pMin.x, b2.pMin.x),
                                std::max(b1.pMin.y, b2.pMin.y),
                                std::max(b1.pMin.z, b2.pMin.z)),
                      Point3<T>(std::min(b1.pMax.x, b2.pMax.x),
                                std::min(b1.pMax.y, b2.pMax.y),
                                std::min(b1.pMax.z, b2.pMax.z)));
}

template <typename T>
bool Overlaps(const Bounds3<T> &b1, const Bounds3<T> &b2) {
    bool x = (b1.pMax.x >= b2.pMin.x) && (b1.pMin.x <= b2.pMax.x);
    bool y = (b1.pMax.y >= b2.pMin.y) && (b1.pMin.y <= b2.pMax.y);
    bool z = (b1.pMax.z >= b2.pMin.z) && (b1.pMin.z <= b2.pMax.z);
    return (x && y && z);
}

template <typename T>
bool Inside(const Point3<T> &p, const Bounds3<T> &b) {
    return (p.x >= b.pMin.x && p.x <= b.pMax.x &&
            p.y >= b.pMin.y && p.y <= b.pMax.y &&
            p.z >= b.pMin.z && p.z <= b.pMax.z);
}

template <typename T>
bool InsideExclusive(const Point3<T> &p, const Bounds3<T> &b) {
    return (p.x >= b.pMin.x && p.x < b.pMax.x &&
            p.y >= b.pMin.y && p.y < b.pMax.y &&
            p.z >= b.pMin.z && p.z < b.pMax.z);
}

template <typename T, typename U> inline Bounds3<T>
Expand(const Bounds3<T> &b, U delta) {
    return Bounds3<T>(b.pMin - Vector3<T>(delta, delta, delta),
                      b.pMax + Vector3<T>(delta, delta, delta));
}

#endif //PBRT_LY_GEOMETRY_H
