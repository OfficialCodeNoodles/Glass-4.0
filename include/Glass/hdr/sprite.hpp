#pragma once

// Dependencies 
#include "component.hpp"

namespace gs {
	///////////////////////////////////////////////////////////
	/// class Sprite is an sfml Sprite wrapper class. It can
	/// be used to render a texture to the screen and has other
	/// special functionalities. It can also be added to a 
	/// Menu. 
	///////////////////////////////////////////////////////////
	class GLASS_EXPORT Sprite : public Component {
	public:
		Sprite();
		~Sprite();

		///////////////////////////////////////////////////////////
		/// Method update() is an overriden Component method that 
		/// is used to update elements of the Component every time 
		/// a frame passes. Although this method can be called in 
		/// the case of this class it doesn't do anything so it 
		/// shouldn't be worried about. 
		///////////////////////////////////////////////////////////
		virtual void update() override;
		///////////////////////////////////////////////////////////
		/// Method render() will render the Sprite object to a 
		/// sf::RenderTarget. Note: You can also render this object 
		/// by calling gs::draw() aswell. 
		/// @param sf::RenderTarget* target: Pointer to the target
		///  you want to render. Example: &window. 
		/// @param sf::RenderStates: Used for advanced blending and
		///  custom shaders. By default it is set to 
		///  sf::RenderStates::Default. 
		///////////////////////////////////////////////////////////
		virtual void render(
			sf::RenderTarget* target,
			sf::RenderStates renderStates = sf::RenderStates::Default
		) override;

		///////////////////////////////////////////////////////////
		/// Method setPosition() will set the position of the top 
		/// left corner of the Sprite object. 
		/// @param Vec2f position: New position of Sprite. 
		///////////////////////////////////////////////////////////   
		virtual void setPosition(Vec2f position) override;
		///////////////////////////////////////////////////////////
		/// Method setPosition() will set the position of the top 
		/// left corner of the Sprite object. 
		/// @param float xpos: New xpos of Sprite. 
		/// @param float ypos: New ypos of Sprite. 
		///////////////////////////////////////////////////////////  
		virtual void setPosition(float xpos, float ypos) override;
		///////////////////////////////////////////////////////////
		/// Method setCenter() will set the position of the Sprite 
		/// to be centered at the position given.
		/// @param Vec2f position: Center position of Sprite. 
		///////////////////////////////////////////////////////////  
		virtual void setCenter(Vec2f position) override;
		///////////////////////////////////////////////////////////
		/// Method setCenter() will set the position of the Sprite 
		/// to be centered at the position given.
		/// @param float xpos: Center xpos. 
		/// @param float ypos: Center ypos. 
		///////////////////////////////////////////////////////////  
		virtual void setCenter(float xpos, float ypos) override;
		///////////////////////////////////////////////////////////
		/// Method move() will add an offset to the position of the 
		/// Sprite object. 
		/// @param Vec2f offset: Positional offset of Sprite. 
		///////////////////////////////////////////////////////////  
		virtual void move(Vec2f offset) override;
		///////////////////////////////////////////////////////////
		/// Method move() will add an offset to the position of the 
		/// Sprite object. 
		/// @param float offsetx: X distance to offset. 
		/// @param float offsety: Y distance to offset. 
		///////////////////////////////////////////////////////////  
		virtual void move(float offsetx, float offsety) override;
		///////////////////////////////////////////////////////////
		/// Method applyStyle() will change the visual 
		/// representation of the sprite by changing it's style. 
		/// @param const Style& style: Style to apply to sprite. 
		///////////////////////////////////////////////////////////  
		virtual void applyStyle(const Style& style) override;
		///////////////////////////////////////////////////////////
		/// Method lock() will disable updates to the Sprite 
		/// object. This doesn't effect this class in any way and 
		/// shoudn't be worried about. 
		///////////////////////////////////////////////////////////  
		virtual void lock() override;
		///////////////////////////////////////////////////////////
		/// Method unlock() will enable updates to the Sprite object.
		/// This doesn't effect this class in any way and shoudn't
		/// be worried about. 
		///////////////////////////////////////////////////////////  
		virtual void unlock() override;

		///////////////////////////////////////////////////////////
		/// Method setScale() will change the size of the Sprite on
		/// both axies. 
		/// @param Vec2f scalar: The scale on the x and y axis. 
		///  Note: a scale of 1.0 is default. 
		///////////////////////////////////////////////////////////  
		virtual void setScale(Vec2f scalar);
		///////////////////////////////////////////////////////////
		/// Method setScale() will change the size of the Sprite on 
		/// both axies. 
		/// @param float scalex: Scale on the x axis. 
		/// @param float scaley: Scale on the y axis. 
		///////////////////////////////////////////////////////////  
		virtual void setScale(float scalex, float scaley);
		///////////////////////////////////////////////////////////
		/// Method setRotation() will set the angle of the sprite 
		/// for when it is rotated. Note: If using the intersect() 
		/// method on the Sprite Hitbox it won't work as intended 
		/// as the Hitbox is an AABB. 
		/// @param float angle: Angle of rotation 0.0 is default. 
		///////////////////////////////////////////////////////////  
		virtual void setRotation(float angle);
		///////////////////////////////////////////////////////////
		/// Method rotate() will change the rotation value by a
		/// given amount. Note: To set rotation call setRotation() 
		/// instead. 
		/// @param float angle: Angle to be added to current
		///  rotation value. Note: Value will be mod equaled by
		///  360 degrees. 
		///////////////////////////////////////////////////////////  
		virtual void rotate(float angle);
		///////////////////////////////////////////////////////////
		/// Method setTexture() will give the Sprite a texture to 
		/// render from. 
		/// @param const sf::Texture& texture: Reference to
		///  sf::Texture object. 
		/// @param bool resetRect: True if you want the internal
		///  texture rect to be reset. Note: It's set to false by
		///  default. 
		///////////////////////////////////////////////////////////  
		virtual void setTexture(const sf::Texture& texture, bool resetRect = false);
		///////////////////////////////////////////////////////////
		/// Method setTextueRect() will give a location on the 
		/// texture for the Sprite to render. 
		/// @param const sf::IntRect& bounds: The location and area
		///  of the space needed to be rendered. 
		///////////////////////////////////////////////////////////  
		virtual void setTextureRect(const sf::IntRect& bounds);
		///////////////////////////////////////////////////////////
		/// Method setColor() will give the Sprite a Color to be 
		/// multiplied by. Note: It is white by default preserving 
		/// the original color of the Sprite. 
		/// @param Color color: Color of the Sprite. 
		///////////////////////////////////////////////////////////  
		virtual void setColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setOutlineThickness() will set the thickness of 
		/// the boarder around the Sprite object. Note: It is set 
		/// to 0.0 by default. 
		///////////////////////////////////////////////////////////  
		virtual void setOutlineThickness(float thickness);
		///////////////////////////////////////////////////////////
		/// Method setOutlineColor() will change the color of the 
		/// outline of the Sprite. Note: Call setOutlineThickness()
		/// first. 
		/// @param Color color: Color of outline. 
		/////////////////////////////////////////////////////////// 
		virtual void setOutlineColor(Color color);

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Position of Sprite. 
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getPosition() const override;
		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Center position of Sprite. 
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getCenter() const override;
		///////////////////////////////////////////////////////////
		/// @returns const Hitbox&: Reference to internal Hitbox
		///  object. 
		/////////////////////////////////////////////////////////// 
		virtual const Hitbox& getHitbox() const override;
		///////////////////////////////////////////////////////////
		/// Method getStyle() will return the Style object of the 
		/// Sprite object. 
		/// @returns const Style&: Style of Sprite. 
		///////////////////////////////////////////////////////////  
		virtual const Style& getStyle();
		///////////////////////////////////////////////////////////
		/// @returns bool: Tells if Sprite is locked or not. 
		/////////////////////////////////////////////////////////// 
		virtual bool isLocked() const override;

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: The scale of the Sprite. 
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getScale() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Current rotation value of Sprite in
		///  degrees. 
		/////////////////////////////////////////////////////////// 
		virtual float getRotation() const;
		///////////////////////////////////////////////////////////
		/// @returns const sf::Texture&: Reference to texture.  
		/////////////////////////////////////////////////////////// 
		virtual const sf::Texture& getTexture() const;
		///////////////////////////////////////////////////////////
		/// @returns sf::IntRect: Rectangle of bounds of the
		///  rendering area on the texture. 
		/////////////////////////////////////////////////////////// 
		virtual sf::IntRect getTextureRect() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Color of Sprite. Note: It is white by
		///  default. 
		/////////////////////////////////////////////////////////// 
		virtual Color getColor() const;
		///////////////////////////////////////////////////////////
		/// @returns float: The thickness of the Sprite's
		///  outline. 
		/////////////////////////////////////////////////////////// 
		virtual float getOutlineThickness() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Color of the outline of the Sprite. 
		/////////////////////////////////////////////////////////// 
		virtual Color getOutlineColor() const;
		///////////////////////////////////////////////////////////
		/// @returns sf::Sprite: Reference to the internal
		///  sf::Sprite. 
		/////////////////////////////////////////////////////////// 
		virtual sf::Sprite& getSprite();
	protected:
		/// Internal sf::Sprite object used in class. 
		sf::Sprite sprite;
		/// Color of the outline. Set to white by default.  
		Color outlineColor;
		/// Thickness of the outline. Set to 0.0 by default. 
		float outlineThickness;

		///////////////////////////////////////////////////////////
		/// Method generateHitbox() is a private method that will 
		/// update the internal Hitbox to match the current object. 
		///////////////////////////////////////////////////////////  
		virtual void generateHitbox() override;
	};

	///////////////////////////////////////////////////////////
	/// Function mapSpriteToSize() will modify the Sprite scale
	/// to give it the same size as the size given in pixels. 
	/// @param Sprite& sprite: Sprite reference. 
	/// @param Vec2f size: Size in pixels to set the scale to
	///  match. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT void mapSpriteToSize(Sprite& sprite, Vec2f size);
	///////////////////////////////////////////////////////////
	/// Function mapSpriteToSize() will modify the sf::Sprite 
	/// scale to give it the same size as the size given in 
	/// pixels.
	/// @param sf::Sprite& sprite: sf::Sprite reference. 
	/// @param Vec2f size: Size in pixels to set the scale to
	///  match. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT void mapSpriteToSize(sf::Sprite& sprite, Vec2f size);

	///////////////////////////////////////////////////////////
	/// Function draw() will render the Sprite object to a 
	/// sf::RenderTarget. 
	/// @param sf::RenderTarget* target: Pointer to the target
	///  you want to render. Example: &window. 
	/// @param Sprite& sprite: Sprite object reference. 
	/// @param sf::RenderStates: Used for advanced blending and
	///  custom shaders. By default it is set to 
	///  sf::RenderStates::Default. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT void draw(
		sf::RenderTarget* target,
		Sprite& sprite,
		sf::RenderStates renderStates = sf::RenderStates::Default
	);
	 
	///////////////////////////////////////////////////////////
	/// Function operator<<() will output basic information 
	/// about the Sprite object to the given std::ostream. 
	/// @param std::ostream& os: Base output stream. 
	/// @param const Sprite& sprite: Reference to Sprite object. 
	/// @returns std::ostream&: The modified output stream. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT std::ostream& operator<<(std::ostream& os, const Sprite& sprite);
}