#pragma once

// Dependencies 
#include "util/math.hpp"
#include "input/key.hpp"
#include "text.hpp"
#include "sprite.hpp"

namespace gs {
	///////////////////////////////////////////////////////////
	/// class Button is a class that describes an interactable 
	/// button. The Button can be different sizes and shapes. 
	/// Many other classes in Glass inherit from this class. 
	///////////////////////////////////////////////////////////
	class GLASS_EXPORT Button : public Component {
	public:
		/// The shape of the Button. By default it is set to be a Rectangle. 
		enum class Shape { Rectangle, Circle }
			shape = Shape::Rectangle;
		/// The way the Button should be rendered aka. Textured or Basic. By 
		/// default it is set to Basic. 
		enum class RenderMethod { Basic, Textured }
			renderMethod = RenderMethod::Basic;
		/// What should interact with the Button. By default it is set to a
		/// MouseClick. 
		enum class EventTriggerer { None, MouseClick, ActiveMouse }
			eventTriggerer = EventTriggerer::MouseClick;
		/// If there is Text where should the text orient. By default it is set 
		/// to be Center. 
		enum class TextOrigin { Left, Center, Right }
			textOrigin = TextOrigin::Center;
		/// What should happen if the Button is selected. By default it is set 
		/// to ChangeColorAndSize. 
		enum class EventSelected {
			None = 0,
			ChangeColor = 1 << 0,
			ChangeSize = 1 << 1,
			ChangeColorAndSize = ChangeColor | ChangeSize,
			Hide = 1 << 2
		} eventSelected = EventSelected::ChangeColorAndSize;
		/// What should happen if the Button is clicked. By default it is set 
		/// to ChangeColorAndSize. 
		enum class EventClicked {
			None = 0,
			ChangeColor = 1 << 0,
			ChangeSize = 1 << 1,
			ChangeColorAndSize = ChangeColor | ChangeSize,
			Hide = 1 << 2
		} eventClicked = EventClicked::ChangeColorAndSize;

		/// Set to true when Button is selected. 
		bool isSelected;
		/// Set to true when Button is clicked on. 
		bool isClickedOn;

		Button();
		~Button();

		///////////////////////////////////////////////////////////
		/// Method update() is an overriden Component method that 
		/// is used to update elements of the Component every time 
		/// a frame passes. Make sure to call this method every 
		/// frame directly or from the Menu class. 
		///////////////////////////////////////////////////////////
		virtual void update() override;
		///////////////////////////////////////////////////////////
		/// Method render() will render the Button object to a 
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
		/// Method clearShapeColors() will set all of the color 
		/// values of the Button shape to white. This is useful if 
		/// making a textured Button. 
		///////////////////////////////////////////////////////////  
		virtual void clearShapeColors();
		///////////////////////////////////////////////////////////
		/// Method clearShapeScaleModifiers() will set all of the 
		/// Button shape scale modifiers to 1.0. 
		///////////////////////////////////////////////////////////  
		virtual void clearShapeScaleModifiers();
		///////////////////////////////////////////////////////////
		/// Method clearTextColors() will set all of the color 
		/// values of the text to white. 
		///////////////////////////////////////////////////////////  
		virtual void clearTextColors(); 
		///////////////////////////////////////////////////////////
		/// Method clearTextScaleModifiers() will set all of the 
		/// text scale modifiers to 1.0. 
		///////////////////////////////////////////////////////////  
		virtual void clearTextScaleModifiers(); 
		///////////////////////////////////////////////////////////
		/// Method clearColors() will set all of the color values 
		/// to white. This is useful if making a textured Button. 
		///////////////////////////////////////////////////////////  
		virtual void clearColors(); 
		///////////////////////////////////////////////////////////
		/// Method clearScaleModifiers() will set all of the scale 
		/// modifiers to 1.0. 
		///////////////////////////////////////////////////////////  
		virtual void clearScaleModifiers(); 
		///////////////////////////////////////////////////////////
		/// Method clear() will set all of the color values to 
		/// white and set the scale modifiers to 1.0. This is 
		/// useful if making a textured Button. 
		///////////////////////////////////////////////////////////  
		virtual void clear();

		///////////////////////////////////////////////////////////
		/// Method setPosition() will set the position of the top 
		/// left corner of the Button object. 
		/// @param Vec2f position: New position of Button. 
		///////////////////////////////////////////////////////////   
		virtual void setPosition(Vec2f position) override;
		///////////////////////////////////////////////////////////
		/// Method setPosition() will set the position of the top 
		/// left corner of the Button object. 
		/// @param float xpos: New xpos of Button. 
		/// @param float ypos: New ypos of Button. 
		///////////////////////////////////////////////////////////  
		virtual void setPosition(float xpos, float ypos) override;
		///////////////////////////////////////////////////////////
		/// Method setCenter() will set the position of the Button 
		/// to be centered at the position given.
		/// @param Vec2f position: Center position of Button. 
		///////////////////////////////////////////////////////////  
		virtual void setCenter(Vec2f position) override;
		///////////////////////////////////////////////////////////
		/// Method setCenter() will set the position of the Button 
		/// to be centered at the position given.
		/// @param float xpos: Center xpos. 
		/// @param float ypos: Center ypos. 
		///////////////////////////////////////////////////////////  
		virtual void setCenter(float xpos, float ypos) override;
		///////////////////////////////////////////////////////////
		/// Method move() will add an offset to the position of the 
		/// Button object. 
		/// @param Vec2f offset: Positional offset of Button. 
		///////////////////////////////////////////////////////////  
		virtual void move(Vec2f offset) override;
		///////////////////////////////////////////////////////////
		/// Method move() will add an offset to the position of the 
		/// Button object. 
		/// @param float offsetx: X distance to offset. 
		/// @param float offsety: Y distance to offset. 
		///////////////////////////////////////////////////////////  
		virtual void move(float offsetx, float offsety) override;
		///////////////////////////////////////////////////////////
		/// Method applyStyle() will change the visual 
		/// representation of the button by changing it's style. 
		/// @param const Style& style: Style to apply to button. 
		///////////////////////////////////////////////////////////  
		virtual void applyStyle(const Style& style) override;
		///////////////////////////////////////////////////////////
		/// Method lock() will disable updates to the Button
		/// object.
		///////////////////////////////////////////////////////////  
		virtual void lock() override;
		///////////////////////////////////////////////////////////
		/// Method unlock() will enable updates to the Button 
		/// object.
		///////////////////////////////////////////////////////////  
		virtual void unlock() override;

		///////////////////////////////////////////////////////////
		/// Method setSize() will resize the Button to the size 
		/// given. Note: If using a circular Button make sure to 
		/// call setRadius() instead. 
		/// @param Vec2f size: New size of the Button in pixels. 
		///////////////////////////////////////////////////////////  
		virtual void setSize(Vec2f size);
		///////////////////////////////////////////////////////////
		/// Method setSize() will resize the Button to the size 
		/// given. Note: If using a circular Button make sure to 
		/// call setRadius() instead. 
		/// @param float sizex: The width of the Button.
		/// @param float sizey: The height of the Button. 
		///////////////////////////////////////////////////////////  
		virtual void setSize(float sizex, float sizey);
		///////////////////////////////////////////////////////////
		/// Method setRadius() will change the radius to the given
		/// length. Note: If using a rectangular Button call 
		/// setSize() instead. 
		/// @param float radius: The length of the radius. 
		///////////////////////////////////////////////////////////  
		virtual void setRadius(float radius);
		///////////////////////////////////////////////////////////
		/// Method setTexture() will give a texture to the Button. 
		/// It will also set the renderMethod to Textured aswell. 
		/// @param const sf::Texture& texture: Texture reference. 
		///////////////////////////////////////////////////////////  
		virtual void setTexture(const sf::Texture& texture);
		///////////////////////////////////////////////////////////
		/// Method setInactiveFillColor() will set the Color of the
		/// Button when no event is happening. 
		/// @param Color color: FillColor of Button. 
		///////////////////////////////////////////////////////////  
		virtual void setInactiveFillColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setSelectedFillColor() will set the Color of the 
		/// Button when it is selected. 
		/// @param Color color: FillColor of Button. 
		///////////////////////////////////////////////////////////  
		virtual void setSelectedFillColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setClickedFillColor() will set the Color of the 
		/// Button when it is clicked 
		/// @param Color color: FillColor of Button. 
		///////////////////////////////////////////////////////////  
		virtual void setClickedFillColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setOutlineThickness() will change the outline 
		/// thickness of the Button. Note: The default thickness is 
		/// 0.0. 
		/// @param float thickness: The new thickness of the
		///  outline of the Button. 
		///////////////////////////////////////////////////////////  
		virtual void setOutlineThickness(float thickness);
		///////////////////////////////////////////////////////////
		/// Method setOutlineColor() will change the Color of the 
		/// Button outline. Note: Make sure to call 
		/// setOutlineThickness() first to have an outline appear. 
		/// @param Color color: Outline color. 
		///////////////////////////////////////////////////////////  
		virtual void setOutlineColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setFont() is used when wanting text on the 
		/// Button. Note: Call setString() aswell to have text 
		/// appear over the Button. 
		/// @param const sf::Font& font: Reference to sf::Font. 
		///////////////////////////////////////////////////////////  
		virtual void setFont(const sf::Font& font);
		///////////////////////////////////////////////////////////
		/// Method setString() will give the internal Text object a
		/// string to render. Note: Call setFont() aswell to see
		/// the text on the Button. 
		/// @param const std::string& string: String reference. 
		///////////////////////////////////////////////////////////  
		virtual void setString(const std::string& string);
		///////////////////////////////////////////////////////////
		/// Method setTextOffset() will change the position of the 
		/// Text from its origin. Note: By default it is set to 
		/// (0, 0) meaning it wont offset the text. 
		/// @param Vec2f offset: The offset from the Text origin. 
		///////////////////////////////////////////////////////////  
		virtual void setTextOffset(Vec2f offset);
		///////////////////////////////////////////////////////////
		/// Method setTextOffset() will change the position of the 
		/// Text from its origin. Note: By default it is set to 
		/// (0, 0) meaning it wont offset the text. 
		/// @param float offsetx: Offset on x axis. 
		/// @param float offsety: Offset on y axis. 
		///////////////////////////////////////////////////////////  
		virtual void setTextOffset(float offsetx, float offsety);
		///////////////////////////////////////////////////////////
		/// Method setTextScale() will modify the scale of the 
		/// internal Text objects text. Note: It is (1.0, 1.0) by 
		/// default. 
		/// @param Vec2f scalar: Scale factors on both axies. 
		///////////////////////////////////////////////////////////  
		virtual void setTextScale(Vec2f scalar);
		///////////////////////////////////////////////////////////
		/// Method setTextScale() will modify the scale of the 
		/// internal Text objects text. Note: It is (1.0, 1.0) by 
		/// default. 
		/// @param float scalex: X axis scale factor.
		/// @param float scaley: Y axis scale factor. 
		/////////////////////////////////////////////////////////// 
		virtual void setTextScale(float scalex, float scaley);
		///////////////////////////////////////////////////////////
		/// Method setInactiveTextFillColor() will set the
		/// fillColor of the text when no event is currently 
		/// happening.
		/// @param Color color: New fillColor. 
		/////////////////////////////////////////////////////////// 
		virtual void setInactiveTextFillColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setSelectedTextFillColor() will set the 
		/// fillColor of the text when the Button is selected. 
		/// @param Color color: New fillColor. 
		/////////////////////////////////////////////////////////// 
		virtual void setSelectedTextFillColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setTextScale() will modify the scale of the 
		/// internal Text objects text. Note: It is (1.0, 1.0) by 
		/// default. 
		/// @param Vec2f scalar: Scale factors on both axies. 
		/////////////////////////////////////////////////////////// 
		virtual void setClickedTextFillColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setTextOutlineThickness() will set the thickness 
		/// of the Text objects outline. 
		/// @param float thickness: Thickness of Text outline in
		///  pixels. 
		/////////////////////////////////////////////////////////// 
		virtual void setTextOutlineThickness(float thickness);
		///////////////////////////////////////////////////////////
		/// Method setTextOutlineColor() will change the color of 
		/// the Text objects outline. Note: Make sure to call
		/// setTextOutlineThickness() aswell to set a thickness. 
		/// @param Color color: Color of Text outline. 
		/////////////////////////////////////////////////////////// 
		virtual void setTextOutlineColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setTextShadow() will enable or disable a shadow 
		/// for the Text object. 
		/// @param bool hasShadow: Set true for shadow, false to 
		///  disable it. 
		/////////////////////////////////////////////////////////// 
		virtual void setTextShadow(bool hasShadow);
		///////////////////////////////////////////////////////////
		/// Method setTextShadowOffset() will set the offset of the 
		/// shadow from the position of the Text. Note: Setting the 
		/// offset to (0, 0) will cause the shadow to not be seen
		/// as the text will be drawn above it. 
		/// @param Vec2f offset: Shadow offset from Text position. 
		/////////////////////////////////////////////////////////// 
		virtual void setTextShadowOffset(Vec2f offset);
		///////////////////////////////////////////////////////////
		/// Method setTextShadowOffset() will set the offset of the 
		/// shadow from the position of the Text. Note: Setting the 
		/// offset to (0, 0) will cause the shadow to not be seen
		/// as the text will be drawn above it. 
		/// @param float offsetx: Shadow offset on x axis. 
		/// @param float offsety: Shadow offset on y axis. 
		/////////////////////////////////////////////////////////// 
		virtual void setTextShadowOffset(float offsetx, float offsety);
		///////////////////////////////////////////////////////////
		/// Method setTextShadowColor() will change the Color of 
		/// the Text shadow. Note: Be sure to call setTextShadow()
		/// aswell to enable it. 
		/// @param Color shadowColor: Color of Text Shadow. 
		/////////////////////////////////////////////////////////// 
		virtual void setTextShadowColor(Color shadowColor);
		///////////////////////////////////////////////////////////
		/// Method setSelectedScaleModifier() will change the scale 
		/// of the Button when it is selected. Note: A scale of 1.0 
		/// keeps the Button size the same. 
		/// @param float scale: Scale of selected modifier. 
		/////////////////////////////////////////////////////////// 
		virtual void setSelectedScaleModifier(float scale);
		///////////////////////////////////////////////////////////
		/// Method setSClickedScaleModifier() will change the scale 
		/// of the Button when it is clicked. Note: A scale of 1.0 
		/// keeps the Button size the same. 
		/// @param float scale: Scale of clicked modifier. 
		/////////////////////////////////////////////////////////// 
		virtual void setClickedScaleModifier(float scale);
		///////////////////////////////////////////////////////////
		/// Method setSelectedTextScaleModifier() will change the 
		/// scale of the Button text when it is selected. Note: A 
		/// scale of 1.0 keeps the Button text size the same. 
		/// @param float scale: Scale of selected text modifier.
		/////////////////////////////////////////////////////////// 
		virtual void setSelectedTextScaleModifier(float scale);
		///////////////////////////////////////////////////////////
		/// Method setClickedTextScaleModifier() will change the 
		/// scale of the Button text when it is clicked. Note: A 
		/// scale of 1.0 keeps the Button text size the same. 
		/// @param float scale: Scale of clicked text modifier.
		/////////////////////////////////////////////////////////// 
		virtual void setClickedTextScaleModifier(float scale);
		///////////////////////////////////////////////////////////
		/// Method setSizeAdjustSpeed() will set the percentage 
		/// speed that the Button's size will change. Note a value 
		/// of 100.0 will immediately change the size. 
		/// @param float percentage: Percentage up to 100.0. 
		/////////////////////////////////////////////////////////// 
		virtual void setSizeAdjustSpeed(float percentage);
		///////////////////////////////////////////////////////////
		/// Method setColorAdjustSpeed() will set the percentage 
		/// speed that the Button's color will change. Note a value 
		/// of 100.0 will immediately change the color. 
		/// @param float percentage: Percentage up to 100.0. 
		/////////////////////////////////////////////////////////// 
		virtual void setColorAdjustSpeed(float percentage);
		///////////////////////////////////////////////////////////
		/// Method setShapeColors() will change all of the Button
		/// shape colors to a given color. 
		/// @param gs::Color color: New color of shape. 
		/////////////////////////////////////////////////////////// 
		virtual void setShapeColors(gs::Color color);
		///////////////////////////////////////////////////////////
		/// Method setShapeScaleModifiers() will set all of the 
		/// Button shape scale modifiers to a given value. 
		/// @param float scale: New shape scale modifier. 
		/////////////////////////////////////////////////////////// 
		virtual void setShapeScaleModifiers(float scale);
		///////////////////////////////////////////////////////////
		/// Method setTextColors() will change all of the text
		/// colors to a given color. 
		/// @param gs::Color color: New color of text. 
		/////////////////////////////////////////////////////////// 
		virtual void setTextColors(gs::Color color); 
		///////////////////////////////////////////////////////////
		/// Method setTextScaleModifiers() will set all of the text 
		/// scale modifiers to a given value. 
		/// @param float scale: New text scale modifier. 
		/////////////////////////////////////////////////////////// 
		virtual void setTextScaleModifiers(float scale);  
		///////////////////////////////////////////////////////////
		/// Method setColors() will set all of the primary colors 
		/// of the Button to a given color. 
		/// @param gs::Color color: New color. 
		/////////////////////////////////////////////////////////// 
		virtual void setColors(gs::Color color); 
		///////////////////////////////////////////////////////////
		/// Method setScaleModifiers() will set all of the primary 
		/// scale modifiers to a given value. 
		/// @param float scale: New scale modifer. 
		/////////////////////////////////////////////////////////// 
		virtual void setScaleModifiers(float scale); 

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Position of Button.
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getPosition() const override;
		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Center position of Button. 
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getCenter() const override;
		///////////////////////////////////////////////////////////
		/// @returns const Hitbox&: Reference to internal Button
		///  Hitbox. 
		/////////////////////////////////////////////////////////// 
		virtual const Hitbox& getHitbox() const override;
		///////////////////////////////////////////////////////////
		/// Method getStyle() will return the Style object of the 
		/// Button object. 
		/// @returns const Style&: Style of Button. 
		///////////////////////////////////////////////////////////  
		virtual const Style& getStyle();
		///////////////////////////////////////////////////////////
		/// @returns bool: Returns if Button is locked or not. 
		/////////////////////////////////////////////////////////// 
		virtual bool isLocked() const override;

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Size of Button. Note: If using a
		///  circular Button call getRadius() instead. 
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getSize() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Radius of Button. Note: If using a 
		///  rectangular Button call getSize() instead. 
		/////////////////////////////////////////////////////////// 
		virtual float getRadius() const;
		///////////////////////////////////////////////////////////
		/// @returns const sf::Texture&: Reference to internal
		///  sf::Texture if set. 
		/////////////////////////////////////////////////////////// 
		virtual const sf::Texture& getTexture() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Color when Button is not selected. 
		/////////////////////////////////////////////////////////// 
		virtual Color getInactiveFillColor() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Color when Button is selected. 
		/////////////////////////////////////////////////////////// 
		virtual Color getSelectedFillColor() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Color when Button is clicked. 
		/////////////////////////////////////////////////////////// 
		virtual Color getClickedFillColor() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Thickness of Button outline. 
		/////////////////////////////////////////////////////////// 
		virtual float getOutlineThickness() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Color of Button outline. 
		/////////////////////////////////////////////////////////// 
		virtual Color getOutlineColor() const;
		///////////////////////////////////////////////////////////
		/// @returns const sf::Font&: Reference to internal Text
		///  sf::Font. 
		/////////////////////////////////////////////////////////// 
		virtual const sf::Font& getFont() const;
		///////////////////////////////////////////////////////////
		/// @returns const std::string&: Reference to internal Text
		///  string. 
		/////////////////////////////////////////////////////////// 
		virtual const std::string& getString() const;
		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Internal Text offset from origin. 
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getTextOffset() const;
		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Internal Text scale.  
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getTextScale() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Internal Text fillColor when Button is
		///  not selected. 
		/////////////////////////////////////////////////////////// 
		virtual Color getInactiveTextFillColor() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Internal Text fillColor when Button is
		///  selected. 
		/////////////////////////////////////////////////////////// 
		virtual Color getSelectedTextFillColor() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Internal Text fillColor when Button is
		///  clicked on. 
		/////////////////////////////////////////////////////////// 
		virtual Color getClickedTextFillColor() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Internal Text outline thickness. 
		/////////////////////////////////////////////////////////// 
		virtual float getTextOutlineThickness() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Internal Text outline Color. 
		/////////////////////////////////////////////////////////// 
		virtual Color getTextOutlineColor() const;
		///////////////////////////////////////////////////////////
		/// @returns bool: True if internal Text shadow is enabled.  
		/////////////////////////////////////////////////////////// 
		virtual bool textHasShadow() const;
		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Internal Text shadow offset.  
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getTextShadowOffset() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Internal Text shadow Color. 
		/////////////////////////////////////////////////////////// 
		virtual Color getTextShadowColor() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Button scale modifier when selected. 
		/////////////////////////////////////////////////////////// 
		virtual float getSelectedScaleModifier() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Button scale modifier when clicked on. 
		///////////////////////////////////////////////////////////  
		virtual float getClickedScaleModifier() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Button Text scale modifier when
		///  selected.
		/////////////////////////////////////////////////////////// 
		virtual float getSelectedTextScaleModifier() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Button Text scale modifier when
		///  clicked on.
		/////////////////////////////////////////////////////////// 
		virtual float getClickedTextScaleModifier() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Button size speed adjustment in
		///  percentage. 
		/////////////////////////////////////////////////////////// 
		virtual float getSizeAdjustSpeed() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Button color speed adjustment in
		///  percentage. 
		/////////////////////////////////////////////////////////// 
		virtual float getColorAdjustSpeed() const;
	protected:
		/// Internal Hitbox used for scaling. 
		Hitbox virtualHitbox;
		/// Internal Button colors. 
		Color currentColor, currentTextColor,
			inActiveFillColor, inActiveTextFillColor,
			selectedFillColor, selectedTextFillColor,
			clickedFillColor, clickedTextFillColor,
			outlineColor, outlineTextColor;
		/// Thicknesses
		float outlineThickness, textOutlineThickness;
		/// Internal Button scale modifiers. 
		float currentScaleModifier, currentTextScaleModifier,
			selectedScaleModifier, selectedTextScaleModifier,
			clickedScaleModifier, clickedTextScaleModifier;
		/// Flag used for other Glass classes. 
		bool disableInternalUpdate = false;
		/// Speed of size adjustment in percentage. 
		float sizeAdjustSpeed = 25.0f;
		/// Speed of color adjustment in percentage. 
		float colorAdjustSpeed = 25.0f;
		/// Scale of Text. 
		Vec2f textScale = Vec2f(1.0f, 1.0f);
		/// Offset of the Text position. 
		Vec2f textOffset;
		/// Internal Text object. 
		Text text;
		/// Internal Sprite object. 
		Sprite sprite;

		///////////////////////////////////////////////////////////
		/// Method generateHitbox() is a private method that will 
		/// update the internal Hitbox to match the current object. 
		///////////////////////////////////////////////////////////  
		virtual void generateHitbox() override;

		///////////////////////////////////////////////////////////
		/// Method updateColorAndScale() is a private method thats
		/// sole purpose is to update the color and scaled size of 
		/// the Button. 
		/// @param bool customButton: Used for other Glass classes. 
		///////////////////////////////////////////////////////////  
		virtual void updateColorAndScale(bool customButton = false);
	};

	///////////////////////////////////////////////////////////
	/// Function draw() will render the Button object to a 
	/// sf::RenderTarget. 
	/// @param sf::RenderTarget* target: Pointer to the target
	///  you want to render. Example: &window. 
	/// @param Button& button: Button object reference. 
	/// @param sf::RenderStates: Used for advanced blending and
	///  custom shaders. By default it is set to 
	///  sf::RenderStates::Default. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT void draw(
		sf::RenderTarget* target,
		Button& button,
		sf::RenderStates renderStates = sf::RenderStates::Default
	);

	/////////////////////////////////////////////////////////// 
	/// Function operator<<() will output basic information 
	/// about the Button object to the given std::ostream. 
	/// @param std::ostream& os: Base output stream. 
	/// @param const Button& button: Reference to Button object. 
	/// @returns std::ostream&: The modified output stream. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT std::ostream& operator<<(std::ostream& os, const Button& button);
}