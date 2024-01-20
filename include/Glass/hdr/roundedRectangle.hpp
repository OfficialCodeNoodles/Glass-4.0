#pragma once

// Dependencies 
#include "util/math.hpp"
#include "component.hpp"

namespace gs {
    namespace priv {
        ///////////////////////////////////////////////////////////
        /// class RoundedRectangleShape inherits from the sfml
        /// Shape class and represents a rectangle with round 
        /// corners. 
        /////////////////////////////////////////////////////////// 
        class GLASS_EXPORT RoundedRectangleShape final : public sf::Shape{
        public:
            ///////////////////////////////////////////////////////////
            /// @param Vec2f size: Size of RoundedRectangleShape. 
            /// @param float radius: Radius of corner in pixels. 
            /// @param unsigned int cornerPointCount: Vertex count. 
            /////////////////////////////////////////////////////////// 
            RoundedRectangleShape(
                Vec2f size = Vec2f(0.0f, 0.0f),
                float radius = 0.0f,
                unsigned int cornerPointCount = 0
            );

            ///////////////////////////////////////////////////////////
            /// Method setSize() will change the size of rectangle. 
            /// @param Vec2f size: New size of RoundedRectangleShape. 
            /////////////////////////////////////////////////////////// 
            void setSize(Vec2f size);
            ///////////////////////////////////////////////////////////
            /// Method setCornersRadius() will set the arc radius of the 
            /// corners of the rectangle in pixels. 
            /// @param float radius: Arc size in pixels. 
            /////////////////////////////////////////////////////////// 
            void setCornersRadius(float radius);
            ///////////////////////////////////////////////////////////
            /// Method setCornerPointCount() will set the number of 
            /// verticies at the corner of each corner. 
            /// @param unsigned int count: Number of vertices.
            /////////////////////////////////////////////////////////// 
            void setCornerPointCount(unsigned int count);

            ///////////////////////////////////////////////////////////
            /// @return size_t: Number of points in shape. 
            /////////////////////////////////////////////////////////// 
            size_t getPointCount() const override;
            ///////////////////////////////////////////////////////////
            /// @param size_t index: Index in point array. 
            /// @returns sf::Vector2f: Gets point along edge of shape. 
            /////////////////////////////////////////////////////////// 
            sf::Vector2f getPoint(size_t index) const override;

            ///////////////////////////////////////////////////////////
            /// @returns Vec2f: Size of RoundedRectangleShape. 
            /////////////////////////////////////////////////////////// 
            Vec2f getSize() const;
            ///////////////////////////////////////////////////////////
            /// @returns float: Radius of corners in pixels. 
            /////////////////////////////////////////////////////////// 
            float getCornersRadius() const;
        private:
            /// Internal size. 
            Vec2f rrSize;
            /// Internal corner radius. 
            float rrRadius;
            /// Count of verticies on each corner. 
            unsigned int cornerPointCount;
        };
    }

    ///////////////////////////////////////////////////////////
    /// class RoundedRectangle is a class that represents a 
    /// new shape that has rounded corners. 
    /////////////////////////////////////////////////////////// 
    class GLASS_EXPORT RoundedRectangle : public Component {
    public:
        RoundedRectangle();
        ~RoundedRectangle();

        ///////////////////////////////////////////////////////////
        /// Method update() is an overriden Component method that 
        /// is used to update elements of the Component every time 
        /// a frame passes. Although this method can be called in 
        /// the case of this class it doesn't do anything so it 
        /// shouldn't be worried about. 
        ///////////////////////////////////////////////////////////
        virtual void update() override;
        ///////////////////////////////////////////////////////////
        /// Method render() will render the RoundedRectangle object 
        /// to a sf::RenderTarget. Note: You can also render this 
        /// object by calling gs::draw() aswell. 
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
        /// left corner of the RoundedRectangle object. 
        /// @param Vec2f position: New position of
        ///  RoundedRectangle. 
        ///////////////////////////////////////////////////////////     
        virtual void setPosition(Vec2f position) override;
        ///////////////////////////////////////////////////////////
        /// Method setPosition() will set the position of the top 
        /// left corner of the RoundedRectangle object. 
        /// @param float xpos: New xpos of RoundedRectangle. 
        /// @param float ypos: New ypos of RoundedRectangle. 
        ///////////////////////////////////////////////////////////     
        virtual void setPosition(float xpos, float ypos) override;
        ///////////////////////////////////////////////////////////
        /// Method setCenter() will set the position of the 
        /// RoundedRectangle to be centered at the position given. 
        /// @param Vec2f position: Center of RoundedRectangle. 
        ///////////////////////////////////////////////////////////  
        virtual void setCenter(Vec2f position) override;
        ///////////////////////////////////////////////////////////
        /// Method setCenter() will set the position of the 
        /// RoundedRectangle to be centered at the position given. 
        /// @param float xpos: Center xpos of RoundedRectangle. 
        /// @param float ypos: Center ypos of RoundedRectangle. 
        ///////////////////////////////////////////////////////////  
        virtual void setCenter(float xpos, float ypos) override;
        ///////////////////////////////////////////////////////////
        /// Method move() will add an offset to the position of the 
        /// RoundedRectangle object. 
        /// @param Vec2f offset: Positional offset of
        ///  RoundedRectangle. 
        ///////////////////////////////////////////////////////////  
        virtual void move(Vec2f offset) override;
        ///////////////////////////////////////////////////////////
        /// Method move() will add an offset to the position of the 
        /// RoundedRectangle object. 
        /// @param float offsetx: Xpos offset. 
        /// @param float offsety: Ypos offset. 
        ///////////////////////////////////////////////////////////  
        virtual void move(float offsetx, float offsety) override;
        ///////////////////////////////////////////////////////////
        /// Method applyStyle() will change the visual 
        /// representation of the roundedRectangle by changing it's 
        /// style. 
        /// @param const Style& style: Style to apply to 
        ///  roundedRectangle. 
        ///////////////////////////////////////////////////////////  
        virtual void applyStyle(const Style& style) override;
        ///////////////////////////////////////////////////////////
        /// Method lock() will disable updates to the
        /// RoundedRectangle. This doesn't effect this class in any 
        /// way and shoudn't be worried about. 
        ///////////////////////////////////////////////////////////  
        virtual void lock() override;
        ///////////////////////////////////////////////////////////
        /// Method unlock() will enable updates to the
        /// RoundedRectangle. This doesn't effect this class in any 
        /// way and shoudn't be worried about. 
        /////////////////////////////////////////////////////////// 
        virtual void unlock() override;

        ///////////////////////////////////////////////////////////
        /// Method setSize() will change the size of rectangle. 
        /// @param Vec2f size: New size of RoundedRectangle. 
        /////////////////////////////////////////////////////////// 
        virtual void setSize(Vec2f size);
        ///////////////////////////////////////////////////////////
        /// Method setSize() will change the size of rectangle. 
        /// @param float width: New RoundedRectangle width. 
        /// @param float height: New RoundedRectangle height. 
        /////////////////////////////////////////////////////////// 
        virtual void setSize(float width, float height);
        ///////////////////////////////////////////////////////////
        /// Method setCornerRadius() will set the arc radius of the 
        /// corners of the rectangle in pixels. 
        /// @param float radius: Arc size in pixels. 
        /////////////////////////////////////////////////////////// 
        virtual void setCornerRadius(float radius);
        ///////////////////////////////////////////////////////////
        /// Method setCornerPointCount() will set the number of 
        /// verticies at the corner of each corner. 
        /// @param unsigned int count: Number of vertices.
        /////////////////////////////////////////////////////////// 
        virtual void setCornerPointCount(unsigned int count);
        ///////////////////////////////////////////////////////////
        /// Method setFillColor() will set the inside color of the 
        /// RoundedRectangle. 
        /// @param Color color: Fill color. 
        /////////////////////////////////////////////////////////// 
        virtual void setFillColor(Color color);
        ///////////////////////////////////////////////////////////
        /// Method setOutlineThickness() will set the thickness of 
        /// the outline in pixels. 
        /// @param float thickness: Thickness in pixels. 
        /////////////////////////////////////////////////////////// 
        virtual void setOutlineThickness(float thickness);
        ///////////////////////////////////////////////////////////
        /// Method setOutlineColor() will set the color of the 
        /// outline. 
        /// @param Color color: New outline color. 
        /////////////////////////////////////////////////////////// 
        virtual void setOutlineColor(Color color);

        ///////////////////////////////////////////////////////////
        /// @returns Vec2f: Position of RoundedRectangle. 
        /////////////////////////////////////////////////////////// 
        virtual Vec2f getPosition() const override;
        ///////////////////////////////////////////////////////////
        /// @returns Vec2f: Position of center. 
        /////////////////////////////////////////////////////////// 
        virtual Vec2f getCenter() const override;
        ///////////////////////////////////////////////////////////
        /// @returns const Hitbox&: Internal Hitbox reference. 
        /////////////////////////////////////////////////////////// 
        virtual const Hitbox& getHitbox() const override;
        ///////////////////////////////////////////////////////////
        /// Method getStyle() will return the Style object of the 
        /// RoundedRectangle object. 
        /// @returns const Style&: Style of RoundedRectangle. 
        ///////////////////////////////////////////////////////////  
        virtual const Style& getStyle();
        ///////////////////////////////////////////////////////////
        /// @returns bool: True if locked. 
        /////////////////////////////////////////////////////////// 
        virtual bool isLocked() const override;

        ///////////////////////////////////////////////////////////
        /// @returns Vec2f: Size of RoundedRectangle. 
        /////////////////////////////////////////////////////////// 
        virtual Vec2f getSize() const;
        ///////////////////////////////////////////////////////////
        /// @returns float: Radius of corner in pixels. 
        /////////////////////////////////////////////////////////// 
        virtual float getCornerRadius() const;
        ///////////////////////////////////////////////////////////
        /// @returns unsigned int: Number of verticies per corner. 
        /////////////////////////////////////////////////////////// 
        virtual unsigned int getCornerPointCount() const;
        ///////////////////////////////////////////////////////////
        /// @returns Color: Fill color of RoundedRectangle. 
        /////////////////////////////////////////////////////////// 
        virtual Color getFillColor() const;
        ///////////////////////////////////////////////////////////
        /// @returns float: Outline of rectangle in pixels. 
        /////////////////////////////////////////////////////////// 
        virtual float getOutlineThickness() const;
        ///////////////////////////////////////////////////////////
        /// @returns Color: Color of outline. 
        /////////////////////////////////////////////////////////// 
        virtual Color getOutlineColor() const;
        ///////////////////////////////////////////////////////////
        /// @returns priv::RoundedRectangleShape&: Internal shape
        ///  reference. 
        /////////////////////////////////////////////////////////// 
        virtual priv::RoundedRectangleShape& getInternalShape();
    protected:
        /// Inernal shape used for rendering. 
        priv::RoundedRectangleShape internalShape;

        ///////////////////////////////////////////////////////////
        /// Method generateHitbox() is a private method that will 
        /// update the internal Hitbox to match the current object. 
        /////////////////////////////////////////////////////////// 
        virtual void generateHitbox() override;
    };

    ///////////////////////////////////////////////////////////
    /// Function draw() will render the RoundedRectangle object 
    /// to a sf::RenderTarget. 
    /// @param sf::RenderTarget* target: Pointer to the target
    ///  you want to render. Example: &window. 
    /// @param RoundedRectangle& rect: RoundedRectangle object
    ///  reference. 
    ///  custom shaders. By default it is set to 
    ///  sf::RenderStates::Default. 
    /// @param sf::RenderStates: Used for advanced blending and
    ///////////////////////////////////////////////////////////
    GLASS_EXPORT void draw(
        sf::RenderTarget* target,
        RoundedRectangle& rect,
        sf::RenderStates renderStates = sf::RenderStates::Default
    );

    ///////////////////////////////////////////////////////////
    /// Function operator<<() will output basic information 
    /// about the RoundedRectangle object to the given 
    /// std::ostream. 
    /// @param std::ostream& os: Base output stream.  
    /// @param  const RoundedRectangle& rect: Reference to
    ///  RoundedRectangle object. 
    /// @returns std::ostream&: The modified output stream. 
    ///////////////////////////////////////////////////////////
    GLASS_EXPORT std::ostream& operator<<(
        std::ostream& os,
        const RoundedRectangle& rect
    );
}