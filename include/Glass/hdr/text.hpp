#pragma once

// Dependencies 
#include "component.hpp"

namespace gs {
	///////////////////////////////////////////////////////////
	/// class Text is an sfml Text wrapper class. It is used 
	/// for rendering text to the screen and can be added to a
	/// Menu. 
	///////////////////////////////////////////////////////////               
	class GLASS_EXPORT Text : public Component { 
	public:
		Text();
		~Text();

		///////////////////////////////////////////////////////////
		/// Method update() is an overriden Component method that 
		/// is used to update elements of the Component every time 
		/// a frame passes. Although this method can be called in 
		/// the case of this class it doesn't do anything so it 
		/// shouldn't be worried about. 
		///////////////////////////////////////////////////////////
		virtual void update() override;
		///////////////////////////////////////////////////////////
		/// Method render() will render the Text object to a 
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
		/// left corner of the Text object. 
		/// @param Vec2f position: New position of Text. 
		///////////////////////////////////////////////////////////               
		virtual void setPosition(Vec2f position) override;
		///////////////////////////////////////////////////////////
		/// Method setPosition() will set the position of the top 
		/// left corner of the Text object. 
		/// @param float xpos: New xpos of Text. 
		/// @param float ypos: New ypos of Text. 
		///////////////////////////////////////////////////////////  
		virtual void setPosition(float xpos, float ypos) override;
		///////////////////////////////////////////////////////////
		/// Method setCenter() will set the position of the Text to
		/// be centered at the position given. Note: The ypos is 
		/// slightly inaccurate depending on the font so adjust 
		/// accordingly. 
		/// @param Vec2f position: Center of Text. 
		///////////////////////////////////////////////////////////  
		virtual void setCenter(Vec2f position) override;
		///////////////////////////////////////////////////////////
		/// Method setCenter() will set the position of the Text to
		/// be centered at the position given. Note: The ypos is 
		/// slightly inaccurate depending on the font so adjust 
		/// accordingly. 
		/// @param float xpos: Xpos of center. 
		/// @param float ypos: Ypos of center. 
		///////////////////////////////////////////////////////////  
		virtual void setCenter(float xpos, float ypos) override;
		///////////////////////////////////////////////////////////
		/// Method move() will add an offset to the position of the 
		/// Text object. 
		/// @param Vec2f offset: Positional offset of Text. 
		///////////////////////////////////////////////////////////  
		virtual void move(Vec2f offset) override;
		///////////////////////////////////////////////////////////
		/// Method move() will add an offset to the position of the 
		/// Text object. 
		/// @param float offsetx: X distance to offset. 
		/// @param float offsety: Y distance to offset. 
		///////////////////////////////////////////////////////////  
		virtual void move(float offsetx, float offsety) override;
		///////////////////////////////////////////////////////////
		/// Method applyStyle() will change the visual 
		/// representation of the text by changing it's style. 
		/// @param const Style& style: Style to apply to text. 
		///////////////////////////////////////////////////////////  
		virtual void applyStyle(const Style& style) override;
		///////////////////////////////////////////////////////////
		/// Method lock() will disable updates to the Text object.
		/// This doesn't effect this class in any way and shoudn't
		/// be worried about. 
		///////////////////////////////////////////////////////////  
		virtual void lock() override;
		///////////////////////////////////////////////////////////
		/// Method unlock() will enable updates to the Text object.
		/// This doesn't effect this class in any way and shoudn't
		/// be worried about. 
		///////////////////////////////////////////////////////////  
		virtual void unlock() override;

		///////////////////////////////////////////////////////////
		/// Method setScale() will change the size of the Text on
		/// both axies. 
		/// @param Vec2f scalar: The scale on the x and y axis. 
		///  Note: a scale of 1.0 is default. 
		///////////////////////////////////////////////////////////  
		virtual void setScale(Vec2f scalar);
		///////////////////////////////////////////////////////////
		/// Method setScale() will change the size of the Text on
		/// both axies. 
		/// @param float scalex: Scale on the x axis. 
		/// @param float scaley: Scale on the y axis. 
		///////////////////////////////////////////////////////////  
		virtual void setScale(float scalex, float scaley);
		///////////////////////////////////////////////////////////
		/// Method setFont() will give the Text object a reference 
		/// to a sf::Font object so make sure the lifetime of the 
		/// sf::Font is long enough. Note: A font must be provided
		/// to see text on the screen. 
		/// @param const sf::Font& font: Reference to sf::Font
		///  object. 
		///////////////////////////////////////////////////////////  
		virtual void setFont(const sf::Font& font);
		///////////////////////////////////////////////////////////
		/// Method setString() will set what text to be displayed 
		/// by the Text object. Note: By default it wont show 
		/// anything as the std::string is empty and it needs a 
		/// font so call setFont(). 
		/// @param const std::string& string: Reference to
		///  std::string. 
		///////////////////////////////////////////////////////////  
		virtual void setString(const std::string& string);
		///////////////////////////////////////////////////////////
		/// Method setFillColor() will set the center color of the 
		/// Text object. Note: To get a boarder first call 
		/// setOutlineThickness() and the setOutlineColor() to 
		/// change the boarder color. 
		/// @param Color color: The new color of the Text. Note:
		///  It can be made fully transparent. 
		///////////////////////////////////////////////////////////  
		virtual void setFillColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setOutlineThickness() will change the boarder
		/// size of the Text object. Note: A thickness of 0.0 will
		/// disable the boarder and it is 0.0 by default. 
		/// @param float thickness: The new thickness as a float. 
		///////////////////////////////////////////////////////////  
		virtual void setOutlineThickness(float thickness);
		///////////////////////////////////////////////////////////
		/// Method setOutlineColor() will change the color of the 
		/// outline. Note: The thickness must be greater than zero
		/// to appear so call setOutlineThickness aswell. 
		/// @param Color outlineColor: Color of outline. 
		///////////////////////////////////////////////////////////  
		virtual void setOutlineColor(Color outlineColor);
		///////////////////////////////////////////////////////////
		/// Method setShadow() will enable a shadow at the back of 
		/// the Text object. 
		/// @param bool hasShadow: Set to true to enable shadow. It
		///  is disabled by default. 
		///////////////////////////////////////////////////////////  
		virtual void setShadow(bool hasShadow);
		///////////////////////////////////////////////////////////
		/// Method setShadowOffset() will set the offset from the 
		/// position of the Text to render the shadow. Note: If the 
		/// shadows offset is (0, 0) no shadow will appear as it 
		/// will be rendered over. The offset is not (0, 0) by 
		/// default so if no shadow is shown call setShadow() to 
		/// enable it. 
		/// @param Vec2f offset: Offset from position of Text. 
		///////////////////////////////////////////////////////////  
		virtual void setShadowOffset(Vec2f offset);
		///////////////////////////////////////////////////////////
		/// Method setShadowOffset() will set the offset from the 
		/// position of the Text to render the shadow. Note: If the 
		/// shadows offset is (0, 0) no shadow will appear as it 
		/// will be rendered over. The offset is not (0, 0) by 
		/// default so if no shadow is shown call setShadow() to 
		/// enable it. 
		/// @param float offsetx: X offset from Text xpos. 
		/// @param float offsety: Y offset from Text ypos.  
		///////////////////////////////////////////////////////////  
		virtual void setShadowOffset(float offsetx, float offsety);
		///////////////////////////////////////////////////////////
		/// Method setShadowColor() will change the color of the 
		/// shadow. Note: If the shadow still isn't appearing then 
		/// call setShadow() to enable it first. 
		/// @param Color shadowColor: The new color of the shadow. 
		///////////////////////////////////////////////////////////  
		virtual void setShadowColor(Color shadowColor);

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Position of Text. 
		///////////////////////////////////////////////////////////  
		virtual Vec2f getPosition() const override;
		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Center position of the Text. 
		///////////////////////////////////////////////////////////  
		virtual Vec2f getCenter() const override;
		///////////////////////////////////////////////////////////
		/// Method getHitbox() will return a reference to the 
		/// underlying Hitbox object. This can be used to call the
		/// intersect() method for example since it is a const 
		/// method. 
		/// @returns const Hitbox&: Const reference to Hitbox. 
		///////////////////////////////////////////////////////////  
		virtual const Hitbox& getHitbox() const override;
		///////////////////////////////////////////////////////////
		/// Method getStyle() will return the Style object of the 
		/// Text object. 
		/// @returns const Style&: Style of Text. 
		///////////////////////////////////////////////////////////  
		virtual const Style& getStyle();
		///////////////////////////////////////////////////////////
		/// @returns bool: Returns if Text is locked or not. 
		///////////////////////////////////////////////////////////  
		virtual bool isLocked() const override;

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Center position of the Text. 
		///////////////////////////////////////////////////////////  
		virtual Vec2f getScale() const;
		///////////////////////////////////////////////////////////
		/// @returns const sf::Font&: Font reference. 
		///////////////////////////////////////////////////////////  
		virtual const sf::Font& getFont() const;
		///////////////////////////////////////////////////////////
		/// @returns const std::string&: Reference to string. 
		///////////////////////////////////////////////////////////  
		virtual const std::string& getString() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Color of the inside of Text. 
		///////////////////////////////////////////////////////////  
		virtual Color getFillColor() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Thickness of Text outline. 
		///////////////////////////////////////////////////////////  
		virtual float getOutlineThickness() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Outline color. 
		///////////////////////////////////////////////////////////  
		virtual Color getOutlineColor() const;
		///////////////////////////////////////////////////////////
		/// @returns bool: True if shadow is enabled. 
		///////////////////////////////////////////////////////////  
		virtual bool hasShadow() const;
		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Shadow offset.
		///////////////////////////////////////////////////////////  
		virtual Vec2f getShadowOffset() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Color of shadow. 
		///////////////////////////////////////////////////////////  
		virtual Color getShadowColor() const;
		///////////////////////////////////////////////////////////
		/// @returns sf::Text: Non-const reference of underlying
		///  sf::Text object. Note: This can be used if a behaviour
		///  is not implemented. 
		///////////////////////////////////////////////////////////  
		virtual sf::Text& getText();
	protected:
		/// Underlying sf::Text object. 
		sf::Text text;
		/// Shadow boolean. Set to false by default. 
		bool shadow;
		/// Shadow offset from position of Text. 
		Vec2f shadowOffset;
		/// Color of shadow. Translucent by default. 
		Color shadowColor;

		///////////////////////////////////////////////////////////
		/// Method generateHitbox() is a private method that will 
		/// update the internal Hitbox to match the current object. 
		///////////////////////////////////////////////////////////  
		virtual void generateHitbox() override;
	};

	///////////////////////////////////////////////////////////
	/// Function draw() will render the Text object to a 
	/// sf::RenderTarget. 
	/// @param sf::RenderTarget* target: Pointer to the target
	///  you want to render. Example: &window. 
	/// @param Text& text: Text object reference. 
	/// @param sf::RenderStates: Used for advanced blending and
	///  custom shaders. By default it is set to 
	///  sf::RenderStates::Default. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT void draw(
		sf::RenderTarget* target,
		Text& text,
		sf::RenderStates renderStates = sf::RenderStates::Default
	);

	///////////////////////////////////////////////////////////
	/// Function operator<<() will output basic information 
	/// about the Text object to the given std::ostream. 
	/// @param std::ostream& os: Base output stream. 
	/// @param const Text& text: Reference to Text object. 
	/// @returns std::ostream&: The modified output stream. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT std::ostream& operator<<(std::ostream& os, const Text& text);
}