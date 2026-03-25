#include "raylib.h"
#include "Button.h"

class QvorovMainFrame
{
	Image backgroundImage;
	Texture2D backgroundTexture;
	Image peioImage;
	Texture2D peioTexture;

	Rectangle optionsBox;
	Rectangle peioMessageBox;

	bool start;
	float startTime;
	Font textFont;
	float howBlack;


	public:
		QvorovMainFrame();

		void runVisuals();

		void runMath();
};