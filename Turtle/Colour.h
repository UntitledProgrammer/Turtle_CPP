#pragma once
#ifndef COLOUR_H
#define COLOUR_H

namespace np
{
	template<typename Type> const Type Clamp(Type value, Type min, Type max)
	{
		if (value < min) return min;
		return value > max ? max : value;
	}

	struct Colour
	{
	public:
		//Enum:
		const enum Components{Red, Green, Blue, Alpha, Length};

		//Attributes:
		unsigned int components[Length];

		//Constructors:
		Colour();
		Colour(unsigned int r, unsigned int g, unsigned int b, unsigned int a);

		//Properties:
		void SetRed(unsigned int opacity);
		void SetGreen(unsigned int opacity);
		void SetBlue(unsigned int opacity);
		void SetAlpha(unsigned int opacity);

		unsigned int GetRed();
		unsigned int GetGreen();
		unsigned int GetBlue();
		unsigned int GetAlpha();

		//Operators:
		unsigned int operator[](unsigned int component)
		{
			return components[component];
		}
	};
}

//Defines:
#define COLOUR_RED np::Colour(255,0,0,255)
#define COLOUR_BLUE np::Colour(0,0,255,255)
#define COLOUR_GREEN np::Colour(0,255,0,255)
#define COLOUR_WHITE np::Colour(255,255,255,255)
#define COLOUR_BLACK np::Colour(0,0,0,255)

#endif // COLOUR