#pragma once

// Dependencies 
#include "typedef.hpp"

namespace gs {
	///////////////////////////////////////////////////////////
	/// class Transition is a class that can be used to add a
	/// smooth transition to an application. This works well 
	/// with the State class. 
	///////////////////////////////////////////////////////////  
	class GLASS_EXPORT Transition { 
	public:
		/// The style of the Transition. By default it is set to Fade. 
		enum class Type { Fade, Scope }
		type = Type::Fade;
		struct {
			/// Current percentage of the transitions completion.
			float percentage;
			/// Lowest percentage value. It is typicaly 0. 
			float min;
			/// Highest percentage value. If using fade set to 255 to fully darken. 
			float max;
			// /Change of percentage every update() call. 
			float inc;
			/// The state represents 0 = Nuetral, 1 = Increasing, -1 = Decreasing. 
			int state;
			/// Use this bool to detect when to switch game states. 
			bool switchedState;
			/// Color of transition. 
			Color color;
		};

		Transition();
		~Transition();

		///////////////////////////////////////////////////////////
		/// Method update() will update the Transition object 
		/// values. This should be called every frame. 
		///////////////////////////////////////////////////////////  
		virtual void update();
		///////////////////////////////////////////////////////////
		/// Method start() will start the Transition. If called 
		/// during motion it won't effect the current transition. 
		///////////////////////////////////////////////////////////  
		virtual void start();
		///////////////////////////////////////////////////////////
		/// Method setType() will change the Type of the Transition 
		/// and initialize some of the value in the object to match 
		/// the Type. 
		/// @param Type type: Type of Transition style. 
		///////////////////////////////////////////////////////////  
		virtual void setType(Type type);
		///////////////////////////////////////////////////////////
		/// Method apply() will render the transitio to a target. 
		/// @param sf::RenderTarget& target: Target to render at. 
		///////////////////////////////////////////////////////////  
		virtual void apply(sf::RenderTarget& target);

		///////////////////////////////////////////////////////////
		/// Method setPosition() will change the position of the 
		/// Transition for some of the styles ex. Scope. 
		/// @param Vec2f position: New position of Transition. 
		///////////////////////////////////////////////////////////  
		virtual void setPosition(Vec2f position);
		///////////////////////////////////////////////////////////
		/// Method setPosition() will change the position of the 
		/// Transition for some of the styles ex. Scope. 
		/// @param float xpos: New xpos of Transition. 
		/// @param float ypos: New ypos of Transition. 
		///////////////////////////////////////////////////////////  
		virtual void setPosition(float xpos, float ypos);

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Position of Transition. 
		///////////////////////////////////////////////////////////  
		virtual Vec2f getPosition() const;
	protected:
		/// Internal position of Transition. 
		Vec2f position;
	};
}