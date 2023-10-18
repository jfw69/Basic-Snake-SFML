#ifndef TEXTBOX_H_INCLUDED
#define TEXTBOX_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using MessageContainer = std::vector<std::string>;

class Textbox{
public:
	Textbox();
	Textbox(int visible, int charSize, int width, sf::Vector2f screenPos);
	~Textbox();

	void Setup(int visible, int charSize, int width, sf::Vector2f screenPos);
	void Add(std::string message);
	void Clear();
	void Render(sf::RenderWindow& wind);

private:
	MessageContainer m_messages;
	int m_numVisible;
	sf::RectangleShape m_backDrop;
	sf::Font m_font;
	sf::Text m_content;
};
#endif // !TEXTBOX_H_INCLUDED
