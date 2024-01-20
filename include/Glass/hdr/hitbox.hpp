#pragma once

// Dependencies 
#include "typedef.hpp"

namespace gs {
	///////////////////////////////////////////////////////////
	/// class Hitbox is a general class for defining a shape 
	/// for other classes in Glass. It can be used by itself 
	/// and can check if a 2d point is inside of the shape. 
	///////////////////////////////////////////////////////////  
	class GLASS_EXPORT Hitbox {
	public:
		/// enum class Shape describes shape of Hitbox. Is rectangle by default.
		enum class Shape { Rectangle, Circle }
		shape = Shape::Rectangle;

		Hitbox();
		///////////////////////////////////////////////////////////
		/// @param Shape shape: Shape of Hitbox. 
		///////////////////////////////////////////////////////////   
		Hitbox(Shape shape);
		~Hitbox() = default;

		///////////////////////////////////////////////////////////
		/// Method intersects() will see if a point is inside of 
		/// the current Hitbox object. 
		/// @param Vec2f point: The 2d cordinate of the point. 
		/// @returns bool: Returns true if point intersects. 
		///////////////////////////////////////////////////////////               
		bool intersects(Vec2f point) const;
		///////////////////////////////////////////////////////////
		/// Method intersects() will see if a point is inside of 
		/// the current Hitbox object. 
		/// @param float xpos: xpos of the point. 
		/// @param float ypos: ypos of the point. 
		/// @returns bool: Returns true if point intersects. 
		///////////////////////////////////////////////////////////     
		bool intersects(float xpos, float ypos) const;

		///////////////////////////////////////////////////////////
		/// Method setPosition() willset the position of the 
		/// Hitbox. If the Hitbox shape is Rectangle it will set 
		/// the position of the top left corner. If Circle then it 
		/// will set the position of the center of the circle. 
		/// @param Vec2f position: The cordinate of the position.
		///////////////////////////////////////////////////////////  
		void setPosition(Vec2f position);
		///////////////////////////////////////////////////////////
		/// Method setPosition() willset the position of the 
		/// Hitbox. If the Hitbox shape is Rectangle it will set 
		/// the position of the top left corner. If Circle then it 
		/// will set the position of the center of the circle. 
		/// @param float xpos: X coordinate of position. 
		/// @param float ypos: Y coordinate of position. 
		///////////////////////////////////////////////////////////  
		void setPosition(float xpos, float ypos);
		///////////////////////////////////////////////////////////
		/// Method setSize() will size the Hitbox to a 2d size. If 
		/// using a Circle shape call setRadius() instead. 
		/// @param Vec2f size: Size of Hitbox. 
		///////////////////////////////////////////////////////////  
		void setSize(Vec2f size);
		///////////////////////////////////////////////////////////
		/// Method setSize() will size the Hitbox to a 2d size. If 
		/// using a Circle shape call setRadius() instead. 
		/// @param float xpos: Width of Hitbox. 
		/// @param float ypos: Height of Hitbox. 
		///////////////////////////////////////////////////////////  
		void setSize(float xpos, float ypos);
		///////////////////////////////////////////////////////////
		/// Method setRadius() will set the radius of Hitbox. If 
		/// using a Rectangle shape call setSize() instead. 
		/// @param float radius: Radius. 
		///////////////////////////////////////////////////////////
		void setRadius(float radius);
		///////////////////////////////////////////////////////////
		/// Method setCenter() will set the position so that the 
		/// center of the Hitbox will be at the position given. 
		/// @param Vec2f position: The center position. 
		///////////////////////////////////////////////////////////
		void setCenter(Vec2f position);
		///////////////////////////////////////////////////////////
		/// Method setCenter() will set the position so that the 
		/// center of the Hitbox will be at the position given. 
		/// @param float xpos: Xpos of center. 
		/// @param float ypos: Ypos of center. 
		///////////////////////////////////////////////////////////
		void setCenter(float xpos, float ypos);
		///////////////////////////////////////////////////////////
		/// Method move() will add an offset to the current 
		/// position moving the Hitbox. 
		/// @param Vec2f offset: Positional offset of Hitbox. 
		///////////////////////////////////////////////////////////
		void move(Vec2f offset);
		///////////////////////////////////////////////////////////
		/// Method move() will add an offset to the current 
		/// position moving the Hitbox. 
		/// @param float offsetx: X distance to offset. 
		/// @param float offsety: Y distance to offset. 
		///////////////////////////////////////////////////////////
		void move(float offsetx, float offsety);

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Position of Hitbox. 
		///////////////////////////////////////////////////////////
		Vec2f getPosition() const;
		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Size of Hitbox. If using Circle shape 
		///	 call getRadius() instead. 
		///////////////////////////////////////////////////////////
		Vec2f getSize() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Radius of Hitbox. If using Rectangle
		/// shape call getSize() instead. 
		///////////////////////////////////////////////////////////
		float getRadius() const;
		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Center position of shape. 
		///////////////////////////////////////////////////////////
		Vec2f getCenter() const;

		friend GLASS_EXPORT void draw(
			sf::RenderTarget* target,
			const Hitbox& hitbox,
			sf::RenderStates renderStates = sf::RenderStates::Default
		);
	private:
		/// Position of the Hitbox as a 2d coordinate. 
		Vec2f position;
		/// Size of Hitbox when used as a Rectangle. 
		Vec2f size;
		/// Radius of Hitbox when used as a Circle. 
		float radius;
		/// Set to true when an intersection happens. Can change the color of 
		/// the Hitbox if rendered for debugging purposes. 
		mutable bool intersectFlag;
	};

	///////////////////////////////////////////////////////////
	/// Function draw() will render a basic shape to show the 
	/// position and size of the Hitbox given. Note this is 
	/// meant purely for debugging and use Button for a more 
	/// advanced solution. 
	/// @param sf::RenderTarget* target: Pointer to the target
	///  you want to render. Example: &window. 
	/// @param const Hitbox& hitbox: Reference of Hitbox. 
	/// @param sf::RenderStates: Used for advanced blending and
	///  custom shaders. By default it is set to 
	///  sf::RenderStates::Default. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT void draw(
		sf::RenderTarget* target,
		const Hitbox& hitbox,
		sf::RenderStates renderStates
	);

	///////////////////////////////////////////////////////////
	/// Function operator<<() will output basic information 
	/// about the Hitbox to the given std::ostream. 
	/// @param std::ostream& os: Base output stream. 
	/// @param const Hitbox& hitbox: Reference to Hitbox. 
	/// @returns std::ostream&: The modified output stream. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT std::ostream& operator<<(std::ostream& os, const Hitbox& hitbox);
}