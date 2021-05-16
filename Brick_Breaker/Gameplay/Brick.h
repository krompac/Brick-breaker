#pragma once
#include <vector>
#include <string>

#include "Rect_Object.h"
#include "Side.h"

class Brick : public Rect_Object
{
	private: 
		static int numberOfActiveBricks;

		Brick *upperBrick;
		Brick *lowerBrick;
		Brick *leftBrick;
		Brick *rightBrick;

		std::string id;

		bool checkNeighbour(Brick *brick);

	public:
		Brick();
		Brick(int x, int y, int width, int height, Color color, int id);

		bool IsDisabled();
		bool IsBreakable();

		void DisableMe();
		std::vector<Brick*> GetNeighbourBreakableBricks();

		void SetBrick(Side side, Brick *brick);

		static int GetNumberOfActiveBricks();

		~Brick();

		bool operator == (Brick const &other)
		{
			return x == other.x && y == other.y;
		}
};