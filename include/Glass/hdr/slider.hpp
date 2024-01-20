#pragma once

// Dependencies 
#include "button.hpp"

namespace gs {
	///////////////////////////////////////////////////////////
	/// class Slider is a class that represents sliders in many
	/// applications. It is essentially a moveable Button that
	/// stores a percentage that it has been pulled. 
	///////////////////////////////////////////////////////////  
	class GLASS_EXPORT Slider : public Component {
	public:
		/// Direction that the Slider points. By default it is set to
		/// Horizontal. 
		enum class Direction { Horizontal, Vertical }
			direction = Direction::Horizontal;

		/// Internal Button of Slider. Note: You can directly access this to 
		/// modify the Button as it is public. 
		Button button;

		/// True if Slider's Button is selected. 
		bool isSelected;
		/// True if Slider's Button is clicked on. 
		bool isClickedOn;

		Slider();
		~Slider();

		///////////////////////////////////////////////////////////
		/// Method update() will update the internal Button and
		/// color and size of the Slider. Make sure to call this
		/// method() every frame or in a Menu object. 
		///////////////////////////////////////////////////////////
		virtual void update() override;
		///////////////////////////////////////////////////////////
		/// Method render() will render the Slider object to a 
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
		/// left corner of the Slider object. Note: It will
		/// automatically move the Button accordingly unless the 
		/// percentage needs to be retained. 
		/// @param Vec2f position: New position of Slider. 
		///////////////////////////////////////////////////////////  
		virtual void setPosition(Vec2f position) override;
		///////////////////////////////////////////////////////////
		/// Method setPosition() will set the position of the top 
		/// left corner of the Slider object. Note: It will
		/// automatically move the Button accordingly unless the 
		/// percentage needs to be retained. 
		/// @param float xpos: New xpos of Slider. 
		/// @param float ypos: New ypos of Slider. 
		///////////////////////////////////////////////////////////  
		virtual void setPosition(float xpos, float ypos) override;
		///////////////////////////////////////////////////////////
		/// Method setCenter() will set the position of the Slider 
		/// to be centered at the position given.
		/// @param Vec2f position: Center of Slider. 
		///////////////////////////////////////////////////////////  
		virtual void setCenter(Vec2f position) override;
		///////////////////////////////////////////////////////////
		/// Method setCenter() will set the position of the Slider 
		/// to be centered at the position given.
		/// @param float xpos: Xpos of center. 
		/// @param float ypos: Ypos of center. 
		///////////////////////////////////////////////////////////  
		virtual void setCenter(float xpos, float ypos) override;
		///////////////////////////////////////////////////////////
		/// Method move() will add an offset to the position of the 
		/// Slider object. 
		/// @param Vec2f offset: Positional offset of Slider. 
		///////////////////////////////////////////////////////////  
		virtual void move(Vec2f offset) override;
		///////////////////////////////////////////////////////////
		/// Method move() will add an offset to the position of the 
		/// Slider object. 
		/// @param float offsetx: X distance to offset. 
		/// @param float offsety: Y distance to offset. 
		///////////////////////////////////////////////////////////  
		virtual void move(float offsetx, float offsety) override;
		///////////////////////////////////////////////////////////
		/// Method applyStyle() will change the visual 
		/// representation of the slider by changing it's style. 
		/// @param const Style& style: Style to apply to slider. 
		///////////////////////////////////////////////////////////  
		virtual void applyStyle(const Style& style) override;
		///////////////////////////////////////////////////////////
		/// Method lock() will disable updates to the Slider 
		/// object.
		///////////////////////////////////////////////////////////  
		virtual void lock() override;
		///////////////////////////////////////////////////////////
		/// Method unlock() will enable updates to the Slider 
		/// object.
		/////////////////////////////////////////////////////////// 
		virtual void unlock() override;

		///////////////////////////////////////////////////////////
		/// Method setSize() will change the size of the bar that
		/// the Slider Button is on. Note: To change the Button 
		/// size access the Button directly and call setSize() ex. 
		/// slider.button.setSize(). 
		/// @param Vec2f size: New size of Slider bar. 
		/////////////////////////////////////////////////////////// 
		virtual void setSize(Vec2f size);
		///////////////////////////////////////////////////////////
		/// Method setSize() will change the size of the bar that
		/// the Slider Button is on. Note: To change the Button 
		/// size access the Button directly and call setSize() ex. 
		/// slider.button.setSize(). 
		/// @param float width: Bar width.
		/// @param float height: Bar height. 
		/////////////////////////////////////////////////////////// 
		virtual void setSize(float width, float height);
		///////////////////////////////////////////////////////////
		/// Method setOnColor will set the fill color of the side
		/// of the bar that is on. 
		/// @param Color color: On fill color. 
		/////////////////////////////////////////////////////////// 
		virtual void setOnColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setOffColor will set the fill color of the side
		/// of the bar that is off. 
		/// @param Color color: Off fill color. 
		/////////////////////////////////////////////////////////// 
		virtual void setOffColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setOnOutlineColor() will set the outline color 
		/// of the on side. 
		/// @param Color color: On outline color. 
		/////////////////////////////////////////////////////////// 
		virtual void setOnOutlineColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setOffOutlineColor() will set the outline color 
		/// of the off side. 
		/// @param Color color: Off outline color. 
		/////////////////////////////////////////////////////////// 
		virtual void setOffOutlineColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setOnOutlineThickness() will set the thickness 
		/// of the colored outline on the on side. 
		/// @param float thickness: Thickness of on side in pixels. 
		/////////////////////////////////////////////////////////// 
		virtual void setOnOutlineThickness(float thickness);
		///////////////////////////////////////////////////////////
		/// Method setOffOutlineThickness() will set the thickness 
		/// of the colored outline on the off side. 
		/// @param float thickness: Thickness of off side in
		///  pixels. 
		/////////////////////////////////////////////////////////// 
		virtual void setOffOutlineThickness(float thickness);
		///////////////////////////////////////////////////////////
		/// Method setClampedToEdge() will enable or disable if the
		/// Button's edge should clamp to the bars edge. If 
		/// disabled it will clamp to the middle instead of the 
		/// edge. 
		/// @param bool clamped: True if clamp to edge.
		/////////////////////////////////////////////////////////// 
		virtual void setClampedToEdge(bool clamped);
		///////////////////////////////////////////////////////////
		/// Method setPercentage() will set the percentage along 
		/// the bar that the Button should be. 
		/// @param float percentage: Value between 0.0 and 100.0. 
		/////////////////////////////////////////////////////////// 
		virtual void setPercentage(float percentage);
		///////////////////////////////////////////////////////////
		/// Method setPercentage() will set the percentage along 
		/// the bar that the Button should be. 
		/// @param float percentage: Value between 0.0 and max. 
		/// @param float max: Max value instead of 100.0.
		/////////////////////////////////////////////////////////// 
		virtual void setPercentage(float percentage, float max);

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Position of Slider bar. 
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getPosition() const override;
		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Position of Slider center. 
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getCenter() const override;
		///////////////////////////////////////////////////////////
		/// @returns const Hitbox&: Reference to Slider Hitbox. 
		/////////////////////////////////////////////////////////// 
		virtual const Hitbox& getHitbox() const override;
		///////////////////////////////////////////////////////////
		/// Method getStyle() will return the Style object of the 
		/// Slider object. 
		/// @returns const Style&: Style of Slider. 
		///////////////////////////////////////////////////////////  
		virtual const Style& getStyle();
		///////////////////////////////////////////////////////////
		/// @returns bool: True if locked false if unlocked. 
		/////////////////////////////////////////////////////////// 
		virtual bool isLocked() const override;

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Size of Slider bar. 
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getSize() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Fill color of on area. 
		/////////////////////////////////////////////////////////// 
		virtual Color getOnColor() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Fill color of off area. 
		/////////////////////////////////////////////////////////// 
		virtual Color getOffColor() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Color of on outline. 
		/////////////////////////////////////////////////////////// 
		virtual Color getOnOutlineColor() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Color of off outline. 
		/////////////////////////////////////////////////////////// 
		virtual Color getOffOutlineColor() const;
		///////////////////////////////////////////////////////////
		/// @returns float: On outline thickness in pixels. 
		/////////////////////////////////////////////////////////// 
		virtual float getOnOutlineThickness() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Off outline thickness in pixels. 
		/////////////////////////////////////////////////////////// 
		virtual float getOffOutlineThickness() const;
		///////////////////////////////////////////////////////////
		/// @returns bool: True if Button clamps to bar edge. 
		/////////////////////////////////////////////////////////// 
		virtual bool getClampedToEdge() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Percentage the Button is along the bar.  
		/////////////////////////////////////////////////////////// 
		virtual float getPercentage() const;
		///////////////////////////////////////////////////////////
		/// @param float max: Max percentage value.  
		///	@returns float: Percentage the Button is along the bar
		///  between 0 and max. 
		/////////////////////////////////////////////////////////// 
		virtual float getPercentage(float max) const;
	protected:
		/// Internal Slider colors. 
		Color onColor, onOutlineColor,
			offColor, offOutlineColor;
		/// Thicknesses. 
		float onOutlineThickness, offOutlineThickness;
		/// The percentage along the rail that the Button is. 
		float percentage = 0.0f;
		/// The modified percentage used for rendering. 
		float renderPercentage = 0.0f;
		/// True if Button should clamp edge to edge with rail. If false then
		/// the Button will center at the edge instead. 
		bool clampToEdge = true;
		/// Internal flag used in update method. 
		bool disableMovement = false;

		///////////////////////////////////////////////////////////
		/// Method generateHitbox() is a private method that will 
		/// update the internal Hitbox to match the current object. 
		///////////////////////////////////////////////////////////  
		virtual void generateHitbox() override;

		///////////////////////////////////////////////////////////
		/// Method setButtonPosition() will update the Button 
		/// position regardless of Button shape. 
		/// @param Vec2f position: New position of Button. 
		///////////////////////////////////////////////////////////  
		virtual void setButtonPosition(Vec2f position);
		///////////////////////////////////////////////////////////
		/// Method setButtonPosition() will update the Button 
		/// position regardless of Button shape. 
		/// @param float xpos: New xpos of Button. 
		/// @param float ypos: New ypos of Button. 
		///////////////////////////////////////////////////////////  
		virtual void setButtonPosition(float xpos, float ypos);

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Position of Button regardless of Shape. 
		///////////////////////////////////////////////////////////  
		virtual Vec2f getButtonPosition();
		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Size of Button regardless of Shape. 
		///////////////////////////////////////////////////////////  
		virtual Vec2f getButtonSize();
	};

	///////////////////////////////////////////////////////////
	/// Function draw() will render the Slider object to a 
	/// sf::RenderTarget. 
	/// @param sf::RenderTarget* target: Pointer to the target
	///  you want to render. Example: &window. 
	/// @param Slider& slider: Slider object reference. 
	/// @param sf::RenderStates: Used for advanced blending and
	///  custom shaders. By default it is set to 
	///  sf::RenderStates::Default. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT void draw(
		sf::RenderTarget* target,
		Slider& slider,
		sf::RenderStates renderStates = sf::RenderStates::Default
	); 

	///////////////////////////////////////////////////////////
	/// Function operator<<() will output basic information 
	/// about the Slider object to the given std::ostream. 
	/// @param std::ostream& os: Base output stream. 
	/// @param const Slider& slider: Reference to Slider object. 
	/// @returns std::ostream&: The modified output stream. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT std::ostream& operator<<(std::ostream& os, const Slider& slider);
}