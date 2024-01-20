#pragma once

// Dependencies 
#include "../typedef.hpp"

///////////////////////////////////////////////////////////
/// Function operator<<() will output the components of a 
/// 2d vector. 
/// @param std::ostream& os: Stream to output to. 
/// @param gs::Vec2<Type> vec: Vector to output. 
/// @returns std::ostream&: Updated output stream. 
///////////////////////////////////////////////////////////
template <typename Type>
GLASS_EXPORT std::ostream& operator<<(std::ostream& os, gs::Vec2<Type> vec);
///////////////////////////////////////////////////////////
/// Function operator<<() will output the components of a 
/// 3d vector. 
/// @param std::ostream& os: Stream to output to. 
/// @param gs::Vec3<Type> vec: Vector to output. 
/// @returns std::ostream&: Updated output stream. 
///////////////////////////////////////////////////////////
template <typename Type>
GLASS_EXPORT std::ostream& operator<<(std::ostream& os, gs::Vec3<Type> vec);
///////////////////////////////////////////////////////////
/// Function operator<<() will output the components of a 
/// Color object. 
/// @param std::ostream& os: Stream to output to. 
/// @param gs::Color color: Color to output.  
/// @returns std::ostream&: Updated output stream. 
///////////////////////////////////////////////////////////
GLASS_EXPORT std::ostream& operator<<(std::ostream& os, gs::Color color);

template GLASS_EXPORT std::ostream& operator<<(std::ostream&, gs::Vec2<int>);
template GLASS_EXPORT std::ostream& operator<<(std::ostream&, gs::Vec2<unsigned>);
template GLASS_EXPORT std::ostream& operator<<(std::ostream&, gs::Vec2<float>);
template GLASS_EXPORT std::ostream& operator<<(std::ostream&, gs::Vec2<double>);
template GLASS_EXPORT std::ostream& operator<<(std::ostream&, gs::Vec3<int>);
template GLASS_EXPORT std::ostream& operator<<(std::ostream&, gs::Vec3<unsigned>);
template GLASS_EXPORT std::ostream& operator<<(std::ostream&, gs::Vec3<float>);
template GLASS_EXPORT std::ostream& operator<<(std::ostream&, gs::Vec3<double>);