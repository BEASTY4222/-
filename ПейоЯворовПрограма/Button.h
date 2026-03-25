#include "raylib.h"
#include "string"

struct Button
{
	Font textFont;
	Rectangle box;
	std::string buttonText;
	Color normalbuttonColor;
	Color currentbuttonColor;
	std::string text;

	Button(Rectangle box, std::string buttonText, Color buttonColor, std::string text)
	{
		this->box = box;
		this->buttonText = buttonText;
		this->normalbuttonColor = buttonColor;
		this->currentbuttonColor = buttonColor;
		this->text = text;

		// Create codepoint array for Cyrillic characters
		int codepoints[512];
		int count = 0;

		// Cyrillic basic range (А-Я, а-я) - U+0400 to U+04FF
		for (int i = 0x0400; i <= 0x04FF; i++) {
			codepoints[count++] = i;
		}

		this->textFont = LoadFontEx("resources/Fonts/2596-font.ttf", 32, codepoints, count);
	}

	Button()
	{
		this->box = { 0, 0, 0, 0 };
		this->buttonText = "";
		this->normalbuttonColor = { 0, 0, 0, 255 };
		this->text = "";
		this->textFont = GetFontDefault();
	}

	void draw()
	{
		DrawRectangleRec(box, Fade(currentbuttonColor, 0.5f));
		DrawRectangleLinesEx(box, 4, BLACK);
		DrawTextEx(textFont, buttonText.c_str(), { box.x + 45, box.y + 10 }, 20, 1, BLACK);
	}

	void run()
	{
		
	}


};