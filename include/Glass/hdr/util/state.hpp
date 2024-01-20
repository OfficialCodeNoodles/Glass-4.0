#pragma once

// Dependencies 
#include "../typedef.hpp"
 
namespace gs {
	namespace util {
		///////////////////////////////////////////////////////////
		/// class State is a utility class for managing a state
		/// system in a game. It can be used to switch menus. 
		///////////////////////////////////////////////////////////  
		class GLASS_EXPORT State {
		public:
			State();
			~State();
			 
			///////////////////////////////////////////////////////////
			/// Method changeState() will set the current state to the
			/// next state updating the state. 
			///////////////////////////////////////////////////////////
			virtual void changeState();

			///////////////////////////////////////////////////////////
			/// Method setState() will change the current state of the
			/// State object. 
			/// @param int state: New state of class. 
			///////////////////////////////////////////////////////////
			virtual void setState(int state);
			///////////////////////////////////////////////////////////
			/// Method setNextState() will change the next state of the
			/// object. Note: To change the state call changeState(). 
			/// @param int state: New next state class. 
			///////////////////////////////////////////////////////////
			virtual void setNextState(int state); 

			///////////////////////////////////////////////////////////
			/// @returns int: Current state of object. 
			///////////////////////////////////////////////////////////
			virtual int getState() const;
			///////////////////////////////////////////////////////////
			/// @returns int: Next state of object. 
			///////////////////////////////////////////////////////////
			virtual int getNextState() const;
		protected:
			/// State of object. 
			int currentState;
			/// State of next use. 
			int nextState; 
		};
	}
}