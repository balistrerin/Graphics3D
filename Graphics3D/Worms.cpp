#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Example";
	}

	olc::vf2d vSource = { 160.0f, 300.0f };
	olc::vf2d vTarget = { 400.0f, 300.0f };

	float fMuzzleVelocity = 40.0f;
	float vGravity = 40.f;


public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		if (GetMouse(0).bHeld)
		{
			vSource.x = GetMousePos().x;
		}

		if (GetMouse(1).bHeld)
		{
			vTarget.x = GetMousePos().x;
		}

		Clear(olc::VERY_DARK_MAGENTA);

		FillCircle(vSource, 10, olc::CYAN);
		FillCircle(vTarget, 10, olc::YELLOW);

		return true;
	}
};


int main()
{
	Example demo;
	if (demo.Construct(640, 480, 2, 2))
		demo.Start();

	return 0;
}