#pragma once

#include <iostream>

struct Vector2f
{
	Vector2f()
	:x(0.0f), y(0.0f)
	{}

	Vector2f(float p_x, float p_y)
	:x(p_x), y(p_y)
	{}

	Vector2f operator+(const Vector2f& v) const
	{
		return Vector2f(x+v.x, y+v.y);
	}

	Vector2f operator-(const Vector2f& v) const
	{
		return Vector2f(x-v.x, y-v.y);
	}

	Vector2f operator*(float s) const
	{
		return Vector2f(x*s, y*s);
	}

	Vector2f operator/(float s) const
	{
		return Vector2f(x/s, y/s);
	}

	void print()
	{
		std::cout << x << ", " << y << std::endl;
	}

	float x, y;
};

