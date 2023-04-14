//
// Created by zilae on 23-4-13.
//

#ifndef PBRT_LY_PBRT_H
#define PBRT_LY_PBRT_H

#include <iostream>
#include <type_traits>
#include <cmath>
#include <algorithm>
#include <glog/logging.h>

#ifdef PBRT_FLOAT_AS_DOUBLE
typedef double Float;
#else
typedef float Float;
#endif

#define PBRT_CONSTEXPR constexpr

static PBRT_CONSTEXPR Float MaxFloat = std::numeric_limits<Float>::max();
static PBRT_CONSTEXPR Float Infinity = std::numeric_limits<Float>::infinity();


template<typename T>
class Vector2;
template<typename T>
class Vector3;
template<typename T>
class Point2;
template<typename T>
class Point3;
template<typename T>
class Normal3;
class Ray;
class RayDifferential;
class Medium;
template <typename T>
class Bounds2;
template <typename T>
class Bounds3;
#endif //PBRT_LY_PBRT_H
