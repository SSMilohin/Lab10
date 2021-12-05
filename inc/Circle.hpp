#pragma once
#include <SFML/Graphics.hpp>

namespace sm {
	class Circle {
	public:
		Circle();
		Circle(float x, float y, float R, float vel_y);
		~Circle();
		void Move_Y();
		void SetPosition(float x, float y);
		void SetX(float x);
		void SetY(float y);
		void SetRaduis(float R);
		void SetMoveVelocity_Y(float velocity_y);
		float GetX();
		float GetY();
		float GetVelocity_Y();
		sf::CircleShape GetShape();
	private:
		float m_x, m_y, m_R, m_vel_y;
		sf::CircleShape m_shape;
	};

}