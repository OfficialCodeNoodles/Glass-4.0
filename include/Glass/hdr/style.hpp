#pragma once

// Dependencies
#include "typedef.hpp"

namespace gs {
	struct Style {
		Style() = default; 
		~Style() = default; 

		/// Main color of Component. 
		gs::Color fillColor = gs::Color::White;
		/// Thickness of outline if the Component has one. 
		float outlineThickness = 0.0f;
		/// Color of outline. 
		gs::Color outlineColor = gs::Color::Black;

		/// Shadow boolean. Set to false by default. 
		bool shadow = false;
		/// Shadow offset from position of Text. 
		Vec2f shadowOffset = Vec2f(5.0f, 5.0f);
		/// Color of shadow. Translucent by default. 
		Color shadowColor = Color(0, 0, 0, 200);

		/// Internal Button colors. 
		Color inActiveFillColor = Color(60, 65, 70), inActiveTextFillColor = Color(130, 130, 140),
			selectedFillColor = Color(0, 120, 250), selectedTextFillColor = Color::White,
			clickedFillColor = Color(60, 65, 70), clickedTextFillColor = Color(130, 130, 140), 
			outlineTextColor = Color::Black;
		/// Thicknesses
		float textOutlineThickness = 0.0f;
		/// Internal Button scale modifiers. 
		float selectedScaleModifier = 1.1f, selectedTextScaleModifier = 1.1f,
			clickedScaleModifier = 1.1f, clickedTextScaleModifier = 1.1f;

		// Internal Slider colors. 
		Color onColor = Color(10, 150, 250), onOutlineColor = Color(0, 0, 0),
			offColor = Color(127, 127, 137, 230), offOutlineColor = Color(0, 0, 0);
		/// Thicknesses. 
		float onOutlineThickness = 1.0f, offOutlineThickness = 1.0f;

		/// Color of the background of the Graph. 
		Color backGroundColor = Color(40, 45, 65, 220);
		/// Color of line segments. 
		Color lineColor = Color(10, 200, 230);
		/// Color of Graph points. 
		Color pointColor = Color(8, 190, 220);
		/// Thickness of Graph points. 
		float pointThickness = 3.0f;
	};

	/// Built in rendering information for Components. 
	GLASS_EXPORT extern Style defaultStyle; 
}