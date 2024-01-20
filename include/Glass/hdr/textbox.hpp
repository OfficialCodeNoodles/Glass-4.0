#pragma once

// Dependencies 
#include "button.hpp"

namespace gs {
	///////////////////////////////////////////////////////////
	/// class Textbox is a Button class is used for inputing 
	/// data from the keyboard. 
	///////////////////////////////////////////////////////////
	class GLASS_EXPORT Textbox : public Button {
	public:
		/// Method of input. By default it is set to Keyboard. 
		enum class InputMethod { None, Keyboard }
			inputMethod = InputMethod::Keyboard;
		/// What inputs should be valid. By default it is set to AlphaNumeric.
		enum class ValidInputs { Alpha, Numeric, AlphaNumeric }
			validInputs = ValidInputs::AlphaNumeric;
		/// In what way should the Text object display a string. By default it
		/// is set to MessageAndStoredValue. 
		enum class TextRenderMethod {
			None, Message, StoredValue,
			MessageAndStoredValue
		} textRenderMethod = TextRenderMethod::MessageAndStoredValue;

		Textbox();
		~Textbox();

		///////////////////////////////////////////////////////////
		/// Method update() will update the Textbox class. Also 
		/// make sure to call updateInputs() and updateEvents() in
		/// the input namespace. 
		///////////////////////////////////////////////////////////
		virtual void update() override;

		///////////////////////////////////////////////////////////
		/// Method setStoredString() will update the internal 
		/// string that is stored inside the Textbox. Note: To 
		/// modify the message string call setMessageString(). 
		/// @param const std::string& string: New stored string. 
		///////////////////////////////////////////////////////////
		virtual void setStoredString(const std::string& string);
		///////////////////////////////////////////////////////////
		/// Method setMessageString() will update the internal 
		/// message string that can be displayed. Note: To  
		/// modify the stored string call setStoredString(). 
		/// @param const std::string& string: New message string. 
		///////////////////////////////////////////////////////////
		virtual void setMessageString(const std::string& string);
		///////////////////////////////////////////////////////////
		/// Method setMaxInputLength() will set a maximum input 
		/// size when inputing into the Textbox. 
		/// @param size_t length: Max length in characters. Note:
		///  Spaces are included. 
		///////////////////////////////////////////////////////////
		virtual void setMaxInputLength(size_t length);
		///////////////////////////////////////////////////////////
		/// Method setCursoreTickSpeed() sets the rate of speed 
		/// that the cursor should blink when the Textbox is active. 
		/// @param int speed: Speed in frames inbetween flickers.
		///  Note: Lower is faster bigger is slower. 
		///////////////////////////////////////////////////////////
		virtual void setCursorTickSpeed(int speed);
		///////////////////////////////////////////////////////////
		/// Method setActive() will enable the Textbox for typing 
		/// or disable it. Note: This is the same as clicking the
		/// Textbox. 
		/// @param bool isActive: Set true to enable the Textbox
		///  false to disable. 
		///////////////////////////////////////////////////////////
		virtual void setActive(bool isActive);

		///////////////////////////////////////////////////////////
		/// @returns const::string&: Reference to stored string. 
		///////////////////////////////////////////////////////////
		virtual const std::string& getStoredString() const;
		///////////////////////////////////////////////////////////
		/// @returns const::string&: Reference to message string. 
		///////////////////////////////////////////////////////////
		virtual const std::string& getMessageString() const;
		///////////////////////////////////////////////////////////
		/// @returns size_t: Maximum size of inputed string. 
		///////////////////////////////////////////////////////////
		virtual size_t getMaxInputLength() const;
		///////////////////////////////////////////////////////////
		/// @returns int: Ticks between cursor flickers.  
		///////////////////////////////////////////////////////////
		virtual int getCursorTickSpeed() const;
		///////////////////////////////////////////////////////////
		/// @returns bool: True if Textbox is able to have strings
		///  inputed. 
		///////////////////////////////////////////////////////////
		virtual bool getActive() const;
	protected:
		/// String used for inputs. 
		std::string storedString = "";
		/// String used for parsing purposes.  
		std::string parsingString = "";
		/// String used as display message.  
		std::string defaultMessage = "Click to Type";
		/// Maximum inputed string size in characters. 
		size_t maxLength = 10;
		/// Ticks between cursor flickers. 
		int cursorTickSpeed = 50;
		/// True if Textbox can have strings entered. 
		bool isActive = false;
	};
}