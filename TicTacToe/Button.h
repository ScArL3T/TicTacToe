#ifndef BUTTON_H
#define BUTTON_H

#include <functional>

#include "Widget.h"
#include "State.h"

class Button final : public Widget
{
private:
	using Function = std::function<void()>;

	enum class Type
	{
		None = 0,
		Selected,
		Pressed
	};

public:
	explicit Button(sf::RenderWindow &window);
	~Button();

	bool isSelectable() const override;

	void select() override;
	void deselect() override;

	void activate() override;
	void deactivate() override;

	void setFunction(Function function);
	void setText(const std::string &text);
	


private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	void changeTexture(Type texture);

	Function   function;

	sf::Sprite sprite;
	sf::Text   text;
};

#endif