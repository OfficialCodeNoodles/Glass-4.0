#pragma once

// Dependencies 
#include <iostream>
#include <vector>
#include <chrono>

#include <SFML/Graphics.hpp>

#ifdef GLASS_UI_API_4_EXPORTS
	/// Used to export functions/classes to the Glass dll. 
	#define GLASS_EXPORT __declspec(dllexport)
#else
	/// Used to import functions/classes from the Glass dll. 
	#define GLASS_EXPORT __declspec(dllimport)
#endif

/// Basic output function used by Glass. 
#define GLASS_LOG(expr) std::cout << expr << std::endl; 
/// Basic error function used by Glass.
#define GLASS_ERROR(msg, number) std::cout << "Glass Error: " << msg << " : " \
	<< number << std::endl