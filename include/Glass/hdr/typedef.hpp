#pragma once

// Dependencies 
#include "macros.hpp"

///////////////////////////////////////////////////////////
/// namespace gs is the main namespace Glass uses for 
/// storing it's classes/functions. 
///////////////////////////////////////////////////////////
namespace gs {
	using std::vector;

	///////////////////////////////////////////////////////////
	/// namespace priv is used for storing private classes/
	/// functions that Glass uses. Only use this namespace if
	/// something in it is not implemented on the surface layer
	/// of Glass. 
	///////////////////////////////////////////////////////////
	namespace priv {
	}
	///////////////////////////////////////////////////////////
	/// namespace input is the namespace input related things
	/// such as mouse and keyboard things are located. 
	///////////////////////////////////////////////////////////
	namespace input {
		///////////////////////////////////////////////////////////
		/// namespace priv is used for storing private classes/
		/// functions that Glass uses. Only use this namespace if
		/// something in it is not implemented on the surface layer
		/// of Glass. 
		///////////////////////////////////////////////////////////
		namespace priv {
		}
	}
	///////////////////////////////////////////////////////////
	/// namespace util is a multipurpose namespace used for 
	/// storing utility items from Glass. This is where most of
	/// the mathematical functions are located. 
	///////////////////////////////////////////////////////////
	namespace util {
	}

	/// Alias for sf::Color.
	GLASS_EXPORT typedef sf::Color Color;

	/// Alias for sf::Vector2<>.
	template <typename Type>
	using Vec2 = sf::Vector2<Type>;
	/// Alias for sf::Vector3<>.
	template <typename Type>
	using Vec3 = sf::Vector3<Type>;

	/// Alias for Vec2<int>.
	GLASS_EXPORT typedef Vec2<int> Vec2i;
	/// Alias for Vec2<unsigned>. 
	GLASS_EXPORT typedef Vec2<unsigned> Vec2u;
	/// Alias for Vec2<float>. 
	GLASS_EXPORT typedef Vec2<float> Vec2f;
	/// Alias for Vec2<double>. 
	GLASS_EXPORT typedef Vec2<double> Vec2d;

	/// Alias for Vec3<int>. 
	GLASS_EXPORT typedef Vec3<int> Vec3i;
	/// Alias for Vec3<unsigned>.
	GLASS_EXPORT typedef Vec3<unsigned> Vec3u;
	/// Alias for Vec3<float>.
	GLASS_EXPORT typedef Vec3<float> Vec3f;
	/// Alias for Vec3<double>. 
	GLASS_EXPORT typedef Vec3<double> Vec3d;
}