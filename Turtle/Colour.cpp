#include "Colour.h"

np::Colour::Colour()
{
	for (int i = 0; i < Length; i++) components[i] = 0;
}

np::Colour::Colour(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
	components[Red] = r;
	components[Blue] = b;
	components[Green] = g;
	components[Alpha] = a;
}

void np::Colour::SetRed(unsigned int opacity)
{
	components[Red] = Clamp<unsigned int>(opacity, 0, 255);
}

void np::Colour::SetGreen(unsigned int opacity)
{
	components[Green] = Clamp<unsigned int>(opacity, 0, 255);
}

void np::Colour::SetBlue(unsigned int opacity)
{
	components[Blue] = Clamp<unsigned int>(opacity, 0, 255);
}

void np::Colour::SetAlpha(unsigned int opacity)
{
	components[Alpha] = Clamp<unsigned int>(opacity, 0, 255);
}

unsigned int np::Colour::GetRed()
{
	return components[Red];
}

unsigned int np::Colour::GetGreen()
{
	return components[Green];
}

unsigned int np::Colour::GetBlue()
{
	return components[Blue];
}

unsigned int np::Colour::GetAlpha()
{
	return components[Alpha];
}
