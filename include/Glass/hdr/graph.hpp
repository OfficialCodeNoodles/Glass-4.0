#pragma once

// Dependencies 
#include "sprite.hpp"

namespace gs {
	namespace priv {
		///////////////////////////////////////////////////////////
		/// Function renderLine() will render a thin line between 
		/// two points. 
		/// @param sf::RenderTarget* target: Where to render to. 
		/// @param Vec2f p1: First point. 
		/// @param Vec2f p2: Second point. 
		/// @param Color color: Line color. 
		/////////////////////////////////////////////////////////// 
		GLASS_EXPORT void renderLine(
			sf::RenderTarget* target,
			Vec2f p1, Vec2f p2, Color color
		);
	}

	///////////////////////////////////////////////////////////
	/// class Graph is a class used for displaying height data. 
	/// It is highly customizable. 
	/////////////////////////////////////////////////////////// 
	class GLASS_EXPORT Graph : public Component {
	public:
		Graph();
		~Graph();

		///////////////////////////////////////////////////////////
		/// Method update() is an overriden Component method that 
		/// is used to update the Graph every time a frame passes.
		///////////////////////////////////////////////////////////
		virtual void update() override;
		///////////////////////////////////////////////////////////
		/// Method render() will render the Graph object to a 
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
		/// Method graph() will graph the next point on the Graph. 
		/// @param float value: Height value of next point. 
		///////////////////////////////////////////////////////////
		virtual void graph(float value);
		///////////////////////////////////////////////////////////
		/// Method clear() will erase all of the points from the 
		/// point vector.  
		///////////////////////////////////////////////////////////
		virtual void clear();

		///////////////////////////////////////////////////////////
		/// Method setPosition() will set the position of the top 
		/// left corner of the Graph object. 
		/// @param Vec2f position: New position of Graph. 
		///////////////////////////////////////////////////////////   
		virtual void setPosition(Vec2f position) override;
		///////////////////////////////////////////////////////////
		/// Method setPosition() will set the position of the top 
		/// left corner of the Graph object. 
		/// @param float xpos: New xpos of Graph. 
		/// @param float ypos: New ypos of Graph. 
		///////////////////////////////////////////////////////////   
		virtual void setPosition(float xpos, float ypos) override;
		///////////////////////////////////////////////////////////
		/// Method setCenter() will set the position of the Graph 
		/// to be centered at the position given.
		/// @param Vec2f position: Center of Graph. 
		///////////////////////////////////////////////////////////  
		virtual void setCenter(Vec2f position) override;
		///////////////////////////////////////////////////////////
		/// Method setCenter() will set the position of the Graph 
		/// to be centered at the position given.
		/// @param float xpos: Xpos of center. 
		/// @param float ypos: Ypos of center. 
		///////////////////////////////////////////////////////////  
		virtual void setCenter(float xpos, float ypos) override;
		///////////////////////////////////////////////////////////
		/// Method move() will add an offset to the position of the 
		/// Graph object. 
		/// @param Vec2f offset: Positional offset of Graph. 
		///////////////////////////////////////////////////////////  
		virtual void move(Vec2f offset) override;
		///////////////////////////////////////////////////////////
		/// Method move() will add an offset to the position of the 
		/// Graph object. 
		/// @param float offsetx: X distance to offset. 
		/// @param float offsety: Y distance to offset. 
		///////////////////////////////////////////////////////////  
		virtual void move(float offsetx, float offsety) override;
		///////////////////////////////////////////////////////////
		/// Method applyStyle() will change the visual 
		/// representation of the graph by changing it's style. 
		/// @param const Style& style: Style to apply to graph. 
		///////////////////////////////////////////////////////////  
		virtual void applyStyle(const Style& style) override;
		///////////////////////////////////////////////////////////
		/// Method lock() will disable updates to the Graph object.
		/////////////////////////////////////////////////////////// 
		virtual void lock() override;
		///////////////////////////////////////////////////////////
		/// Method unlock() will enable updates to the Graph 
		/// object.
		/////////////////////////////////////////////////////////// 
		virtual void unlock() override;

		///////////////////////////////////////////////////////////
		/// Method setSize() will set the size of the Graph. 
		/// @param Vec2f size: New size. 
		/////////////////////////////////////////////////////////// 
		virtual void setSize(Vec2f size);
		///////////////////////////////////////////////////////////
		/// Method setSize() will set the size of the Graph. 
		/// @param float width: New width. 
		/// @param float height New height. 
		/////////////////////////////////////////////////////////// 
		virtual void setSize(float width, float height);
		///////////////////////////////////////////////////////////
		/// Method setLowerBound() will set the minimum yvalue that 
		/// can be viewed on the Graph. Note: To automatically 
		/// adjust it call setLowerBoundAutoAdjust(). 
		/// @param float height: Height value. 
		/////////////////////////////////////////////////////////// 
		virtual void setLowerBound(float height);
		///////////////////////////////////////////////////////////
		/// Method setUpperBound() will set the maximum yvalue that 
		/// can be viewed on the Graph. Note: To automatically 
		/// adjust it call setUpperBoundAutoAdjust(). 
		/// @param float height: Height value. 
		/////////////////////////////////////////////////////////// 
		virtual void setUpperBound(float height);
		///////////////////////////////////////////////////////////
		/// Method setLowerBoundAutoAdjust() will set if the Graph 
		/// should automatically adjust its viewing window. 
		/// @param bool enabled: True to enable, false to disable. 
		/////////////////////////////////////////////////////////// 
		virtual void setLowerBoundAutoAdjust(bool enabled);
		///////////////////////////////////////////////////////////
		/// Method setUpperBoundAutoAdjust() will set if the Graph 
		/// should automatically adjust its viewing window. 
		/// @param bool enabled: True to enable, false to disable. 
		///////////////////////////////////////////////////////////  
		virtual void setUpperBoundAutoAdjust(bool enabled);
		///////////////////////////////////////////////////////////
		/// Method setPointCount() will set the number of points at 
		/// one time that can be on the graph before it scrolls. 
		/// @param size_t numOfPoints: Point count. 
		/////////////////////////////////////////////////////////// 
		virtual void setPointCount(size_t numOfPoints);
		///////////////////////////////////////////////////////////
		/// Method setFillColor() will set the background color of 
		/// the Graph. 
		/// @param Color color: New color. 
		/////////////////////////////////////////////////////////// 
		virtual void setFillColor(Color color);
		///////////////////////////////////////////////////////////  
		/// Method setLineColor() will set the color of the lines 
		/// connecting the points together. 
		/// @param Color color: New color. 
		/////////////////////////////////////////////////////////// 
		virtual void setLineColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setOutlineThickness() will set the thickness of 
		/// the outline surrounding the Graph. 
		/// @param float thickness: Thickness in pixels. 
		/////////////////////////////////////////////////////////// 
		virtual void setOutlineThickness(float thickness);
		///////////////////////////////////////////////////////////
		/// Method setPointThickness() will set the radius of the
		/// points on the Graph. Note: To disable it set the 
		/// thickness to 0.0.
		/// @param float thickness: New radius of points in pixels.
		/////////////////////////////////////////////////////////// 
		virtual void setPointThickness(float thickness);
		///////////////////////////////////////////////////////////
		/// Method setOutlineColor() will change the color of the 
		/// Graphs boarder outline. 
		/// @param Color color: New color. 
		/////////////////////////////////////////////////////////// 
		virtual void setOutlineColor(Color color);
		///////////////////////////////////////////////////////////
		/// Method setPointColor() will change the color of the 
		/// points on the graph. 
		/// @param Color color: New color. 
		/////////////////////////////////////////////////////////// 
		virtual void setPointColor(Color color);

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Position of Graph. 
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getPosition() const override;
		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Center position of Graph.
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getCenter() const override;
		///////////////////////////////////////////////////////////
		/// @returns const Hitbox&: Reference to internal Hitbox. 
		/////////////////////////////////////////////////////////// 
		virtual const Hitbox& getHitbox() const override;
		///////////////////////////////////////////////////////////
		/// Method getStyle() will return the Style object of the 
		/// graph object. 
		/// @returns const Style&: Style of graph. 
		///////////////////////////////////////////////////////////  
		virtual const Style& getStyle();
		///////////////////////////////////////////////////////////
		/// @returns bool: True if locked. 
		/////////////////////////////////////////////////////////// 
		virtual bool isLocked() const override;

		///////////////////////////////////////////////////////////
		/// @returns Vec2f: Size of Graph. 
		/////////////////////////////////////////////////////////// 
		virtual Vec2f getSize() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Minimum value on graph. 
		/////////////////////////////////////////////////////////// 
		virtual float getLowerBound() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Maximum value on graph. 
		/////////////////////////////////////////////////////////// 
		virtual float getUpperBound() const;
		///////////////////////////////////////////////////////////
		/// @returns bool: True if lower bound automatically
		///  adjusts. 
		/////////////////////////////////////////////////////////// 
		virtual bool getLowerBoundAutoAdjust() const;
		///////////////////////////////////////////////////////////
		/// @returns bool: True if upper bound automatically
		///  adjusts. 
		/////////////////////////////////////////////////////////// 
		virtual bool getUpperBoundAutoAdjust() const;
		///////////////////////////////////////////////////////////
		/// @returns size_t: Number of viewable points. 
		/////////////////////////////////////////////////////////// 
		virtual size_t getPointCount() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Fill color of Gragh background. 
		/////////////////////////////////////////////////////////// 
		virtual Color getFillColor() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Color of line segments. 
		/////////////////////////////////////////////////////////// 
		virtual Color getLineColor() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Thickness of Graph outline.
		/////////////////////////////////////////////////////////// 
		virtual float getOutlineThickness() const;
		///////////////////////////////////////////////////////////
		/// @returns float: Radius of points. 
		///////////////////////////////////////////////////////////  
		virtual float getPointThickness() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Color of Graph outline. 
		/////////////////////////////////////////////////////////// 
		virtual Color getOutlineColor() const;
		///////////////////////////////////////////////////////////
		/// @returns Color: Color of points. 
		/////////////////////////////////////////////////////////// 
		virtual Color getPointColor() const;
	protected:
		/// Points that make up the Graph. 
		vector<float> points;
		/// Maximum number of points allowed on Graphs x axis.
		size_t numOfPoints = 20;
		/// Viewing bounds. 
		float lowerBound = 0.0f, upperBound = 0.0f;
		/// Automatically adjust bounds?
		bool autoAdjustLower = false, autoAdjustUpper = false;
		/// Color of the background of the Graph. 
		Color backGroundColor;
		/// Color of line segments. 
		Color lineColor;
		/// Color of Graph outline. 
		Color outlineColor;
		/// Color of Graph points. 
		Color pointColor;
		/// Thickness of Graph outline. 
		float outlineThickness;
		/// Thickness of Graph points. 
		float pointThickness;
		/// Texture used to render Graph onto. 
		sf::RenderTexture graphTexture;
		/// Sprite used to move Graph. 
		Sprite graphSprite;

		///////////////////////////////////////////////////////////
		/// Method generateHitbox() is a private method that will 
		/// update the internal Hitbox to match the current object. 
		/////////////////////////////////////////////////////////// 
		virtual void generateHitbox() override;
	};

	///////////////////////////////////////////////////////////
	/// Function draw() will render the Graph object to a 
	/// sf::RenderTarget. 
	/// @param sf::RenderTarget* target: Pointer to the target
	///  you want to render. Example: &window. 
	/// @param Graph& graph: Graph object reference. 
	/// @param sf::RenderStates: Used for advanced blending and
	///  custom shaders. By default it is set to 
	///  sf::RenderStates::Default. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT void draw(
		sf::RenderTarget* target,
		Graph& graph,
		sf::RenderStates renderStates = sf::RenderStates::Default
	);

	///////////////////////////////////////////////////////////
	/// Function operator<<() will output basic information 
	/// about the Graph object to the given std::ostream. 
	/// @param std::ostream& os: Base output stream. 
	/// @param const Graph& graph: Reference to Graph object. 
	/// @returns std::ostream&: The modified output stream. 
	///////////////////////////////////////////////////////////
	GLASS_EXPORT std::ostream& operator<<(std::ostream& os, const Graph& graph);
}