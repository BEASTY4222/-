#include "QvorovMainFrame.h"

QvorovMainFrame::QvorovMainFrame() :
	backgroundImage(LoadImage("resources/pics/peioKushtajpg.jpg")),
	backgroundTexture(LoadTextureFromImage(backgroundImage)),

	peioImage(LoadImage("resources/pics/peioQvorov.png")),
	peioTexture(LoadTextureFromImage(peioImage)),

	start(true), startTime(0.0f), howBlack(1.0f), 
	optionsBox({ 550, 50, 200, 50 }), 
	peioMessageBox({ 50, 150, 400, 200 })

{
	int codepoints[512];
	int count = 0;

	for (int i = 0x0400; i <= 0x04FF; i++) {
		codepoints[count++] = i;
	}

	this->textFont = LoadFontEx("resources/Fonts/2596-font.ttf", 32, codepoints, count);
}

void QvorovMainFrame::runVisuals(){
	DrawTexture(backgroundTexture, 0, 0, WHITE);
	DrawTexture(peioTexture, 0, 270, WHITE);

	DrawRectangle();
	
	
	if (start) {
		DrawRectangle(0, 0, 950, 750, Fade(BLACK, howBlack));
		DrawTextEx(textFont, "Интервю с Пейо Яворов", { 310, 300 }, 40, 5, WHITE);

		startTime += GetFrameTime();
		if (startTime >= 2.5f) {
			howBlack -= 0.25f * GetFrameTime();
			if (howBlack <= 0.0f) {
				start = false;
			}
		}
	}


	
}

void QvorovMainFrame::runMath() {

}