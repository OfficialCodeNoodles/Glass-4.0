#pragma once

// Dependencies 
#include "component.hpp"

namespace gs {
	namespace priv {
		/// Determines weither or not to add new Components to the defaultMenu. 
		GLASS_EXPORT extern bool defaultMenuEnabled; 
	}

	///////////////////////////////////////////////////////////
	/// class Menu is a multipurpose Component class that can
	/// be used to store and manipulate other Components. 
	///////////////////////////////////////////////////////////  
	class GLASS_EXPORT Menu : public Component {
	public:
		Menu();
		~Menu();

		///////////////////////////////////////////////////////////
		/// Method update() will update all of the Components that
		/// have been added to this Menu. Note: To add Components
		/// call add(). 
		///////////////////////////////////////////////////////////
		virtual void update() override;
		///////////////////////////////////////////////////////////
		/// Method render() will render the Menu object to a 
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
		/// Method add() will add a Component to the components 
		/// vector.
		/// @param Component* component: Pointer to component. 
		/// @param const std::string& name: Name of component. 
		///////////////////////////////////////////////////////////
		virtual void add(Component* component, const std::string& name);
		///////////////////////////////////////////////////////////
		/// Method add() will add a Component to the components 
		/// vector.
		/// @param Component* component: Pointer to component. 
		///////////////////////////////////////////////////////////
		virtual void add(Component* component);
		///////////////////////////////////////////////////////////
		/// Method remove() will remove a Component from the vector 
		/// if it finds a Component of the same address. 
		/// @param Component* component: Address of Component to
		///  remove. 
		///////////////////////////////////////////////////////////
		virtual void remove(Component* component); 
		///////////////////////////////////////////////////////////
		/// Method remove() will remove a Component from the vector 
		/// if it finds a Component of the same name. 
		/// @param Component* component: Address of Component to
		///  remove. 
		///////////////////////////////////////////////////////////
		virtual void remove(const std::string& name);  

		///////////////////////////////////////////////////////////
		/// Method setPosition() will set the offset of all of the
		/// components inside of the menu. 
		/// @param Vec2f position: New menu offset. 
		///////////////////////////////////////////////////////////
		virtual void setPosition(Vec2f position) override;
		///////////////////////////////////////////////////////////
		/// Method setPosition() will set the offset of all of the
		/// components inside of the menu. 
		/// @param float xpos: New menu xoffset. 
		/// @param float ypos: New menu yoffset. 
		///////////////////////////////////////////////////////////
		virtual void setPosition(float xpos, float ypos) override;
		///////////////////////////////////////////////////////////
		/// Method setCenter() won't do anything in this class and 
		/// shouldn't be worried about. Call setPosition() instead. 
		/// @param Vec2f position: Center of Menu. 
		///////////////////////////////////////////////////////////  
		virtual void setCenter(Vec2f position) override;
		///////////////////////////////////////////////////////////
		/// Method setCenter() won't do anything in this class and 
		/// shouldn't be worried about. Call setPosition() instead. 
		/// @param float xpos: Center xpos. 
		/// @param float ypos: Center ypos. 
		///////////////////////////////////////////////////////////  
		virtual void setCenter(float xpos, float ypos) override;
		///////////////////////////////////////////////////////////
		/// Method move() will move all of the components in the 
		/// Menu a given offset.
		/// @param Vec2f offset: Menu components offset. 
		///////////////////////////////////////////////////////////
		virtual void move(Vec2f offset) override;
		///////////////////////////////////////////////////////////
		/// Method move() will move all of the components in the 
		/// Menu a given offset.
		/// @param float offsetx: Menu components xpos offset. 
		/// @param float offsety: Menu components ypos offset. 
		///////////////////////////////////////////////////////////
		virtual void move(float offsetx, float offsety) override;
		///////////////////////////////////////////////////////////
		/// Method applyStyle() will change the visual 
		/// representation of all of the components within the Menu 
		/// by calling their applyStyle() methods. 
		/// @param const Style& style: Style to apply to 
		///  components. 
		///////////////////////////////////////////////////////////  
		virtual void applyStyle(const Style& style) override;
		///////////////////////////////////////////////////////////
		/// Method lock() will disable updates to the Menu. 
		///////////////////////////////////////////////////////////
		virtual void lock() override;
		///////////////////////////////////////////////////////////
		/// Method unlock() will enable updates to the Menu. 
		///////////////////////////////////////////////////////////
		virtual void unlock() override;

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Position of Menu. 
		///////////////////////////////////////////////////////////
		virtual Vec2f getPosition() const override;
		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Position of Menu. No center. 
		///////////////////////////////////////////////////////////
		virtual Vec2f getCenter() const override;
		///////////////////////////////////////////////////////////
		/// @returns const Hitbox&: Reference to internal Hitbox. 
		///////////////////////////////////////////////////////////
		virtual const Hitbox& getHitbox() const override;
		///////////////////////////////////////////////////////////
		/// Method getStyle() will return the Style object of the 
		/// Menu class. 
		/// @returns const Style&: Style of Menu. 
		///////////////////////////////////////////////////////////  
		virtual const Style& getStyle();
		///////////////////////////////////////////////////////////
		/// @returns bool: True if Menu is locked. 
		///////////////////////////////////////////////////////////
		virtual bool isLocked() const override;

		///////////////////////////////////////////////////////////
		/// Method operator[]() will return a pointer to the 
		/// Component of a given index. 
		/// @param size_t index: Index of Component. 
		/// @returns Component*: Pointer to Component. 
		///////////////////////////////////////////////////////////
		Component* operator[](size_t index);
		///////////////////////////////////////////////////////////
		/// Method operator[]() will return a pointer to the 
		/// Component of a given name. 
		/// @oaram const std::string& name: Name of Component. 
		/// @returns Component*: Pointer to Component. Note: If no 
		///  Component of the name given is found it will return a 
		///  nullptr instead. 
		///////////////////////////////////////////////////////////
		Component* operator[](const std::string& name);
		
		///////////////////////////////////////////////////////////
		/// struct ComponentContainer is a private struct used to 
		/// store a Component in the Menu. It has a pointer to the
		/// Component and an optional name. 
		///////////////////////////////////////////////////////////
		struct ComponentContainer {
			/// Pointer of Component object. 
			Component* ptr = nullptr;
			/// Optional name of Component. 
			std::string name;
		}; 
		/// Vector of the Components in the Menu. 
		vector<ComponentContainer> components;
	protected:

		///////////////////////////////////////////////////////////
		/// Method generateHitbox() is a private method that will 
		/// update the internal Hitbox to match the current object. 
		///////////////////////////////////////////////////////////  
		virtual void generateHitbox() override;

		///////////////////////////////////////////////////////////
		/// Method updateInternalComponents() will update the 
		/// position of the Components offset to match the Menu
		/// position. 
		///////////////////////////////////////////////////////////  
		virtual void updateInternalComponents();
	};

	///////////////////////////////////////////////////////////
	/// Function draw() will render the Menu object to a 
	/// sf::RenderTarget. 
	/// @param sf::RenderTarget* target: Pointer to the target
	///  you want to render. Example: &window. 
	/// @param Menu& menu: Menu object reference. 
	/// @param sf::RenderStates: Used for advanced blending and
	///  custom shaders. By default it is set to 
	///  sf::RenderStates::Default. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT void draw(
		sf::RenderTarget* target,
		Menu& menu,
		sf::RenderStates renderStates = sf::RenderStates::Default
	);

	///////////////////////////////////////////////////////////
	/// Function operator<<() will output basic information 
	/// about the Menu object to the given std::ostream. 
	/// @param std::ostream& os: Base output stream. 
	/// @param const Menu& menu: Reference to Menu object. 
	/// @returns std::ostream&: The modified output stream. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT std::ostream& operator<<(std::ostream& os, const Menu& menu);
	
	/// The default Menu used by a Component if not attached to another Menu.
	GLASS_EXPORT extern Menu defaultMenu; 

	///////////////////////////////////////////////////////////
	/// Function enableDefaultMenu() will enable new Components
	/// to be added to the defaultMenu object. To turn this off
	/// call disableDefaultMenu(). 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT void enableDefaultMenu(); 
	///////////////////////////////////////////////////////////
	/// Function disableDefaultMenu() will disable new 
	/// Components from being added to the defaultMenu object. 
	/// To turn this on call enableDefaultMenu(). 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT void disableDefaultMenu(); 
	///////////////////////////////////////////////////////////
	/// Function updateDefaultMenu() will call the update() 
	/// method of all of the components that were added to the
	/// default Menu object. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT void updateDefaultMenu();
	///////////////////////////////////////////////////////////
	/// Function updateDefaultMenu() will draw all of the 
	/// components that were added to the default Menu object. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT void drawDefaultMenu(
		sf::RenderTarget* target,
		sf::RenderStates renderStates = sf::RenderStates::Default
	);
}