#pragma once

// Dependencies 
#include "hitbox.hpp"
#include "style.hpp"

namespace gs {
	///////////////////////////////////////////////////////////
	/// class Component is an abstract class for defining basic
	/// UI elements in Glass. Alot of classes in Glass inherit
	/// from this class. Note: Custom Component's can be made
	/// by inheriting from this class and overriding all of its
	/// methods. 
	///////////////////////////////////////////////////////////
	class GLASS_EXPORT Component {
	public: 
		/// Offset of subclass from the Menu when using the Menu class. 
		Vec2f menuOffset;

		Component() = default; 
		~Component() = default;

		///////////////////////////////////////////////////////////
		/// Method update() is intended to be called every frame to 
		/// update elements within a subclass. 
		///////////////////////////////////////////////////////////
		virtual void update() = 0;
		///////////////////////////////////////////////////////////
		/// Method render() will render the subclass object to a 
		/// sf::RenderTarget. Note: You can also render this object 
		/// by calling gs::draw() aswell; if implemented. 
		/// @param sf::RenderTarget* target: Pointer to the target
		///  you want to render. Example: &window. 
		/// @param sf::RenderStates: Used for advanced blending and
		///  custom shaders. By default it is set to 
		///  sf::RenderStates::Default. 
		///////////////////////////////////////////////////////////
		virtual void render(
			sf::RenderTarget* target,
			sf::RenderStates renderStates = sf::RenderStates::Default
		) = 0;

		///////////////////////////////////////////////////////////
		/// Method setPosition() will set the position of the 
		/// subclass.
		/// @param Vec2f position: New position of subclass. 
		///////////////////////////////////////////////////////////    
		virtual void setPosition(Vec2f position) = 0;
		///////////////////////////////////////////////////////////
		/// Method setPosition() will set the position of the 
		/// subclass.
		/// @param float xpos: New xpos of subclass. 
		/// @param float ypos: New ypos of subclass. 
		///////////////////////////////////////////////////////////  
		virtual void setPosition(float xpos, float ypos) = 0;
		///////////////////////////////////////////////////////////
		/// Method setCenter() will set the position of the subclass 
		/// to be centered at the position given. 
		/// @param Vec2f position: Center of subclass object. 
		///////////////////////////////////////////////////////////  
		virtual void setCenter(Vec2f position) = 0;
		///////////////////////////////////////////////////////////
		/// Method setCenter() will set the position of the subclass 
		/// to be centered at the position given. 
		/// @param float xpos: Xpos of center. 
		/// @param float ypos: Ypos of center. 
		///////////////////////////////////////////////////////////  
		virtual void setCenter(float xpos, float ypos) = 0;
		///////////////////////////////////////////////////////////
		/// Method move() will add an offset to the position of the 
		/// subclass. 
		/// @param Vec2f offset: Positional offset of subclass. 
		///////////////////////////////////////////////////////////  
		virtual void move(Vec2f offset) = 0;
		///////////////////////////////////////////////////////////
		/// Method move() will add an offset to the position of the 
		/// subclass. 
		/// @param float offsetx: X distance to offset. 
		/// @param float offsety: Y distance to offset. 
		///////////////////////////////////////////////////////////  
		virtual void move(float offsetx, float offsety) = 0;
		///////////////////////////////////////////////////////////
		/// Method applyStyle() will change the visual 
		/// representation of a subclass by changing it's style. 
		/// @param const Style& style: Style to apply to subclass. 
		///////////////////////////////////////////////////////////  
		virtual void applyStyle(const Style& style) = 0; 
		///////////////////////////////////////////////////////////
		/// Method lock() will disable updates to the subclass.
		///////////////////////////////////////////////////////////  
		virtual void lock() = 0;
		///////////////////////////////////////////////////////////
		/// Method unlock() will enable updates to the subclass.
		///////////////////////////////////////////////////////////  
		virtual void unlock() = 0;

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Position of subclass. 
		///////////////////////////////////////////////////////////  
		virtual Vec2f getPosition() const = 0;
		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Center position of the subclass. 
		///////////////////////////////////////////////////////////  
		virtual Vec2f getCenter() const = 0;
		///////////////////////////////////////////////////////////
		/// Method getHitbox() will return a reference to the 
		/// underlying subclass object. This can be used to call 
		/// the intersect() method for example since it is a const 
		/// method. 
		/// @returns const Hitbox&: Const reference to Hitbox. 
		///////////////////////////////////////////////////////////  
		virtual const Hitbox& getHitbox() const = 0;
		///////////////////////////////////////////////////////////
		/// Method getStyle() will return the Style object of the 
		/// subclass. 
		/// @returns const Style&: Style of subclass. 
		///////////////////////////////////////////////////////////  
		virtual const Style& getStyle() = 0; 
		///////////////////////////////////////////////////////////
		/// @returns bool: Returns if subclass is locked or not. 
		///////////////////////////////////////////////////////////            
		virtual bool isLocked() const = 0;
	protected:
		/// Underlying general shape of subclass. 
		Hitbox hitbox;
		/// Visual representation of subclass. 
		Style style; 
		/// Is true when object shouldn't update. 
		bool locked;

		///////////////////////////////////////////////////////////
		/// Method generateHitbox() is a private method that will 
		/// update the internal Hitbox to match the current object. 
		///////////////////////////////////////////////////////////  
		virtual void generateHitbox() = 0;
	};
}