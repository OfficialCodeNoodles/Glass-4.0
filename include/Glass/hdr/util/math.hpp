#pragma once

// Dependencies 
#include "../typedef.hpp"

///////////////////////////////////////////////////////////
/// Function operator*() will perform the dot product 
/// operation on two given vectors. 
/// @param gs::Vec2<Type> p1: First vector. 
/// @param gs::Vec2<Type> p2: Second vector. 
/// @returns Type: Result of dot product. 
///////////////////////////////////////////////////////////
template <typename Type>
GLASS_EXPORT Type operator*(gs::Vec2<Type> p1, gs::Vec2<Type> p2);
///////////////////////////////////////////////////////////
/// Function operator*() will perform the dot product 
/// operation on two given vectors. 
/// @param gs::Vec3<Type> p1: First vector. 
/// @param gs::Vec3<Type> p2: Second vector. 
/// @returns Type: Result of dot product. 
///////////////////////////////////////////////////////////
template <typename Type>
GLASS_EXPORT Type operator*(gs::Vec3<Type> p1, gs::Vec3<Type> p2);

template GLASS_EXPORT int operator*(gs::Vec2<int>, gs::Vec2<int>);
template GLASS_EXPORT float operator*(gs::Vec2<float>, gs::Vec2<float>);
template GLASS_EXPORT double operator*(gs::Vec2<double>, gs::Vec2<double>);
template GLASS_EXPORT int operator*(gs::Vec3<int>, gs::Vec3<int>);
template GLASS_EXPORT float operator*(gs::Vec3<float>, gs::Vec3<float>);
template GLASS_EXPORT double operator*(gs::Vec3<double>, gs::Vec3<double>);

namespace gs {
	namespace util {
		/// Constant for pi. 
		GLASS_EXPORT extern const float PI;
		/// Constant for tau or 2pi. 
		GLASS_EXPORT extern const float TAU;

		///////////////////////////////////////////////////////////
		/// Function clamp() will constrain a value between two 
		/// bounds. 
		/// @param Type value: Value to constrain. 
		/// @param Type min: Minimum bound. 
		/// @param Type max: Maximum bound. 
		/// @returns Type: Constrained value. 
		///////////////////////////////////////////////////////////
		template <typename Type>
		GLASS_EXPORT Type clamp(Type value, Type min, Type max);
		///////////////////////////////////////////////////////////
		/// Function clamp() will constrain a value between two 
		/// bounds. 
		/// @param Type* value: Pointer to value to constrain. 
		/// @param Type min: Minimum bound. 
		/// @param Type max: Maximum bound. 
		///////////////////////////////////////////////////////////
		template <typename Type>
		GLASS_EXPORT void clamp(Type* value, Type min, Type max);

		template GLASS_EXPORT int clamp<int>(int, int, int);
		template GLASS_EXPORT float clamp<float>(float, float, float);
		template GLASS_EXPORT double clamp<double>(double, double, double);
		template GLASS_EXPORT void clamp<int>(int*, int, int);
		template GLASS_EXPORT void clamp<float>(float*, float, float);
		template GLASS_EXPORT void clamp<double>(double*, double, double);

		///////////////////////////////////////////////////////////
		/// Function distance() will perform the distance formula
		/// to calculate the distance between two points given. 
		/// @param Vec2<Type> p1: First point. 
		/// @param Vec2<Type> p2: Second point. 
		/// @returns Type: Total distance between both points. 
		///////////////////////////////////////////////////////////
		template <typename Type>
		GLASS_EXPORT Type distance(Vec2<Type> p1, Vec2<Type> p2);
		///////////////////////////////////////////////////////////
		/// Function distance() will perform the distance formula
		/// to calculate the distance between two points given. 
		/// @param Vec3<Type> p1: First point. 
		/// @param Vec3<Type> p2: Second point. 
		/// @returns Type: Total distance between both points. 
		///////////////////////////////////////////////////////////
		template <typename Type>
		GLASS_EXPORT Type distance(Vec3<Type> p1, Vec3<Type> p2);

		template GLASS_EXPORT int distance<int>(Vec2<int>, Vec2<int>);
		template GLASS_EXPORT float distance<float>(Vec2<float>, Vec2<float>);
		template GLASS_EXPORT double distance<double>(Vec2<double>, 
			Vec2<double>);
		template GLASS_EXPORT int distance<int>(Vec3<int>, Vec3<int>);
		template GLASS_EXPORT float distance<float>(Vec3<float>, Vec3<float>);
		template GLASS_EXPORT double distance<double>(Vec3<double>, 
			Vec3<double>);

		///////////////////////////////////////////////////////////
		/// Function approach() will move a value in the direction 
		/// of another value a given percentage. 
		/// @param Type base: Base value. 
		/// @param Type destination: Final value. 
		/// @param Type percentage: Distance to cover between
		///  values. 
		/// @returns Type: New value. 
		///////////////////////////////////////////////////////////
		template <typename Type>
		GLASS_EXPORT Type approach(Type base, Type destination, 
			Type percentage);
		///////////////////////////////////////////////////////////
		/// Function approach() will move a color in the direction 
		/// of another color a given percentage. 
		/// @param Color base: Base color. 
		/// @param Color destination: Final color. 
		/// @param float percentage: Distance to cover between
		///  color values. 
		/// @returns Color: New color. 
		///////////////////////////////////////////////////////////
		GLASS_EXPORT Color approach(Color base, Color destination, 
			float percentage);
		///////////////////////////////////////////////////////////
		/// Function approach() will move a value in the direction 
		/// of another value a given percentage. 
		/// @param Type* base: Pointer to value needing to be 
		///  modified. 
		/// @param Type destination: Final value. 
		/// @param Type percentage: Distance to cover between
		///  values. 
		/// @returns Type: New value. 
		///////////////////////////////////////////////////////////
		template <typename Type>
		GLASS_EXPORT void approach(Type* base, Type destination, 
			Type percentage); 
		///////////////////////////////////////////////////////////
		/// Function approach() will move a color in the direction 
		/// of another color a given percentage. 
		/// @param Color* base: Pointer to color needing to be
		///  modified. 
		/// @param Color destination: Final color. 
		/// @param float percentage: Distance to cover between
		///  color values. 
		/// @returns Color: New color. 
		///////////////////////////////////////////////////////////
		GLASS_EXPORT void approach(Color* base, Color destination, 
			float percentage); 

		template GLASS_EXPORT float approach<float>(float, float, float);
		template GLASS_EXPORT double approach<double>(double, double, double);
		template GLASS_EXPORT void approach<float>(float*, float, float);
		template GLASS_EXPORT void approach<double>(double*, double, double);

		///////////////////////////////////////////////////////////
		/// Function sign() will return the value sign of a given
		/// value. 
		/// @param Type value: Value to find sign of. 
		/// @returns Type: -1 if negative, 0 if zero, 1, if
		///  positive. 
		///////////////////////////////////////////////////////////
		template <typename Type> 
		GLASS_EXPORT Type sign(Type value); 

		template GLASS_EXPORT int sign(int); 
		template GLASS_EXPORT float sign(float);
		template GLASS_EXPORT double sign(double);

		///////////////////////////////////////////////////////////
		/// Function inBound() will return true if a value is 
		/// between 2 given bouns. 
		/// @param Type value: Value to check bounds of. 
		/// @param Type upperBound: Maximum value. 
		/// @param Type lowerBound: Minimum value.
		/// @returns bool: True if value is between the given 
		///  bounds. 
		///////////////////////////////////////////////////////////
		template <typename Type>
		GLASS_EXPORT bool inBound(Type value, Type upperBound, Type lowerBound);

		template GLASS_EXPORT bool inBound(int, int, int); 
		template GLASS_EXPORT bool inBound(unsigned, unsigned, unsigned);
		template GLASS_EXPORT bool inBound(float, float, float);
		template GLASS_EXPORT bool inBound(double, double, double);

		///////////////////////////////////////////////////////////
		/// Function mod() performs the modulus operation on a 
		/// number including negative numbers meaning any number 
		/// lower than zero will roll over. 
		/// @param Type value: Value to perform modulus on. 
		/// @param Type divisor: What do divide the value by. 
		/// @returns Type: Remainder after performing modulus. 
		///////////////////////////////////////////////////////////
		template <typename Type>
		GLASS_EXPORT Type mod(Type value, Type divisor);

		template GLASS_EXPORT int mod(int, int);
		template GLASS_EXPORT float mod(float, float);
		template GLASS_EXPORT double mod(double, double); 

		///////////////////////////////////////////////////////////
		/// Function toDegrees() will convert a radian value to 
		/// degrees. 
		/// @param Type radians: Number of radians. 
		/// @returns Type: Degrees. 
		///////////////////////////////////////////////////////////
		template <typename Type>
		GLASS_EXPORT Type toDegrees(Type radians);

		template GLASS_EXPORT float toDegrees<float>(float);
		template GLASS_EXPORT double toDegrees<double>(double);

		///////////////////////////////////////////////////////////
		/// Function toRadians() will convert a degree value to 
		/// radians. 
		/// @param Type degrees: Number of degrees. 
		/// @returns Type: Radians. 
		///////////////////////////////////////////////////////////
		template <typename Type>
		GLASS_EXPORT Type toRadians(Type degrees);

		template GLASS_EXPORT float toRadians<float>(float);
		template GLASS_EXPORT double toRadians<double>(double);

		///////////////////////////////////////////////////////////
		/// Function angleBetween() will get the angle between two
		/// points using atan2. 
		/// @param Vec2<Type> p1: First point. 
		/// @param Vec2<Type> p2: Second point. 
		/// @param bool inDegrees: True if output angle is needed
		///  in degrees, false for radians. 
		/// @returns Type: Angle of two points given. 
		///////////////////////////////////////////////////////////
		template <typename Type>
		GLASS_EXPORT Type angleBetween(
			Vec2<Type> p1, Vec2<Type> p2, bool inDegrees = true);

		template GLASS_EXPORT float angleBetween(Vec2<float>, Vec2<float>, bool);
		template GLASS_EXPORT double angleBetween(Vec2<double>, Vec2<double>, bool);

		///////////////////////////////////////////////////////////
		/// Function polarToCartesian() will convert a given polar
		/// coordinate to a 2d cartesian coordinate. 
		/// @param Vec2<Type> polarCoordinate: Polar coordinate of
		///  point ordered (radius, angle). 
		/// @param bool inDegrees: True if polarCoodinate stores 
		///  angle in degrees, false if it's stored in radians. 
		/// @returns Vec2<Type>: Cartesian coordinate of polar
		///  coordinate given. 
		///////////////////////////////////////////////////////////
		template <typename Type>
		GLASS_EXPORT Vec2<Type> polarToCartesian(
			Vec2<Type> polarCoordinate, bool inDegrees = true); 

		template GLASS_EXPORT Vec2<float> polarToCartesian(Vec2<float>, bool);
		template GLASS_EXPORT Vec2<double> polarToCartesian(Vec2<double>, bool);

		///////////////////////////////////////////////////////////
		/// Function cartesianToPolar() will convert a given 2d
		/// cartesian coordinate to a polar coordinate. 
		/// @param Vec2<Type> cartesianCoordinate: 2d cartesian 
		///  coordinate of point. 
		/// @param bool inDegrees: True to store angle in polar 
		///  coordinate in degrees, false for radians. 
		/// @returns Vec2<Type>: Polar coordinate of cartesian 
		///  coordinate given. 
		///////////////////////////////////////////////////////////
		template <typename Type>
		GLASS_EXPORT Vec2<Type> cartesianToPolar(
			Vec2<Type> cartesianCoordinate, bool inDegrees = true); 

		template GLASS_EXPORT Vec2<float> cartesianToPolar(Vec2<float>, bool); 
		template GLASS_EXPORT Vec2<double> cartesianToPolar(Vec2<double>, bool); 
	}
}