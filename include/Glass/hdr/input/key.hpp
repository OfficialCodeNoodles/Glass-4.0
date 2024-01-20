#pragma once

// Dependencies 
#include "mouse.hpp"

namespace gs {
	namespace input {
		namespace priv {
			/// Internal sf::RenderWindow*. 
			GLASS_EXPORT extern sf::RenderWindow* internalWindow;
			/// Window size of internalWindow when created. 
			GLASS_EXPORT extern Vec2f defaultWindowSize;
			/// Number of frames updated since creation.  
			GLASS_EXPORT extern int ticks;

			/// Space bar bool. 
			GLASS_EXPORT extern bool space;
			/// Backspace bool. 
			GLASS_EXPORT extern bool backSpace;
			/// Enter bool. 
			GLASS_EXPORT extern bool enter;

		}

		/// Unicode value of last inputed character from keyboard. 
		GLASS_EXPORT extern int textUnicode;

		///////////////////////////////////////////////////////////         
		/// Function setWindow() will give a window to Glass for 
		/// updation. Make sure to call this function and call
		/// updateInputs() and updateEvents() every frame. 
		/// @param sf::RenderWindow* window: Window pointer. 
		///////////////////////////////////////////////////////////
		GLASS_EXPORT void setWindow(sf::RenderWindow* window);

		///////////////////////////////////////////////////////////
		/// Function updateInputs() will update the internal values
		/// of Glass. Call this every frame. Note: If you get an 
		/// error make sure to call setWindow() first. 
		///////////////////////////////////////////////////////////
		GLASS_EXPORT void updateInputs();
		///////////////////////////////////////////////////////////
		/// Function updateEvents() will update internal Glass 
		/// states. Call this inside your event loop. Note: If you
		/// get an error make sure to call setWindow() first. 
		/// @param sf::Event& event: sf::Event to use. 
		///////////////////////////////////////////////////////////
		GLASS_EXPORT void updateEvents(sf::Event& event);
	}
}