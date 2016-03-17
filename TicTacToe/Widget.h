#ifndef WIDGET_H
#define WIDGET_H

#include <SFML/Graphics.hpp>
#include <memory>

class Widget : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
public:
	using Ptr = std::shared_ptr<Widget>; // typedef std::shared_ptr<Widget> Ptr;

	explicit Widget(sf::RenderWindow &window);
	virtual ~Widget() = default;

	virtual bool isSelectable() const = 0;

	virtual void select();
	virtual void deselect();

	virtual void activate();
	virtual void deactivate();

	bool isSelected() const;
	bool isActive() const;

private:
	bool selected;
	bool active;

	sf::RenderWindow &window;
};

#endif