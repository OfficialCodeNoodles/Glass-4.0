#pragma once

// Dependencies 
#include "../typedef.hpp"

namespace gs {
	namespace input {
		namespace priv {
			/// Mouse position from last frame. 
			GLASS_EXPORT extern Vec2f prvsMousePosition;
		}

		/// Current position of mouse.  
		GLASS_EXPORT extern Vec2f mousePosition;
		/// Change in mouse position between current and last frame. 
		GLASS_EXPORT extern Vec2f mouseChange;
		/// Active mouse click. 
		GLASS_EXPORT extern bool activeMouseClickL,
			activeMouseClickM, activeMouseClickR;
		/// Single mouse click. 
		GLASS_EXPORT extern bool mouseClickL,
			mouseClickM, mouseClickR;
	}
}