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

		int codepoints[256];
		int count = 0;

		// Кирилица (основен диапазон)
		for (int i = 0x0400; i <= 0x04FF; i++) {
			codepoints[count++] = i;
		}

		this->textFont = LoadFontEx("resources/fonts/Roboto-Regular.ttf", 32, codepoints, count);


	}

	Button()
	{
		this->box = { 0, 0, 0, 0 };
		this->buttonText = "";
		this->normalbuttonColor = { 0, 0, 0, 255 };
		this->text = "";
	}

	void draw()
	{
		DrawRectangleRec(box, Fade(currentbuttonColor, 0.5f));
		DrawRectangleLinesEx(box, 4, BLACK);
		DrawTextEx(textFont, buttonText.c_str(), { box.x + 45, box.y + 10 }, 20, 1, BLACK);
	}

	void run()
	{
		if (CheckCollisionPointRec(GetMousePosition(),box)) {
			this->currentbuttonColor = WHITE;
		}
		else {
			currentbuttonColor = normalbuttonColor;
		}

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), box)) {
			DrawTextEx(textFont, text.c_str(), { 300, 50 }, 10, 2, BLACK);
		}
		
	}


};