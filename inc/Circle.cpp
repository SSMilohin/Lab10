#include <Circle.hpp>

namespace sm {
	Circle::Circle() {
		m_shape.setFillColor(sf::Color(255, 255, 255, 255));
	}
	Circle::Circle(float x, float y, float R, float vel_y = 0) {
		m_x = x;
		m_y = y;
		m_R = R;
		m_vel_y = vel_y;
		m_shape.setRadius(m_R);
		m_shape.setPosition(m_x, m_y);
		m_shape.setFillColor(sf::Color(255, 255, 255, 255));
	}
	Circle::~Circle() {}
	void Circle::SetPosition(float x, float y) {
		m_x = x;
		m_y = y;
		m_shape.setPosition(m_x, m_y);
	}
	void Circle::SetX(float x) {
		m_x = x;
		m_shape.setPosition(m_x, m_y);
	}
	void Circle::SetY(float y) {
		m_y = y;
		m_shape.setPosition(m_x, m_y);
	}
	void Circle::SetRaduis(float R) {
		m_R = R;
		m_shape.setRadius(m_R);
	}
	void Circle::SetMoveVelocity_Y(float vel_y) {
		m_vel_y = vel_y;
	}
	void Circle::Move_Y() {
		m_y += m_vel_y;
		m_shape.setPosition(m_x, m_y);
	}
	float Circle::GetX() { return m_x; }
	float Circle::GetY() { return m_y; }
	float Circle::GetVelocity_Y() { return m_vel_y; }
	sf::CircleShape Circle::GetShape() { return m_shape; }
}