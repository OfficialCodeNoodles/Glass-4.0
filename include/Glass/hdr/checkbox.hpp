#pragma once

// Dependencies 
#include "button.hpp"

namespace gs {
	///////////////////////////////////////////////////////////
	/// class Checkbox is a Button class that makes the Button
	/// class act as a switch. It can be turned on and off by
	/// clicking on it. Other than that it follows all other 
	/// rules of a Button. 
	///////////////////////////////////////////////////////////   
	class GLASS_EXPORT Checkbox : public Button {
	public:
		Checkbox();
		~Checkbox();

		///////////////////////////////////////////////////////////
		/// Method update() will update the Checkbox. Call this 
		/// method every frame. Note: It calls the overriden 
		/// Button::update() method aswell. 
		///////////////////////////////////////////////////////////
		virtual void update() override;
	protected:
		/// On when mouse is clicked and is within bounds of Checkbox. 
		bool click = false;
		/// Clicked state from previous update() call. 
		bool prvsClick = false;
		/// Flag that is turned on when Checkbox is on. Note: You can use
		/// isClickedOn instead as it is a public attribute. 
		bool on = false;
	};
}