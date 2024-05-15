#include "../include/Ball.hpp"

Ball::Ball(Coordinate coordinates, int radius, float speed, float angle) : Object(coordinates), m_radius(radius), m_speed(speed), m_angle(angle) {}

void Ball::move() {
    m_coordinates.setX(m_coordinates.getX() + int(m_speed * cos(m_angle*3.14159265/180)));
    m_coordinates.setY(m_coordinates.getY() + int(m_speed * sin(m_angle*3.14159265/180)));
}

bool Ball::ballCollide(Ball const& ball) const   {
    return (m_coordinates.getX() - ball.getCoordinates().getX()) * (m_coordinates.getX() - ball.getCoordinates().getX()) +
           (m_coordinates.getY() - ball.getCoordinates().getY()) * (m_coordinates.getY() - ball.getCoordinates().getY()) <=
           (m_radius + ball.getRadius()) * (m_radius + ball.getRadius());
}

void Ball::bounceOnSlider(Slider const& slider) {
    if (m_can_bounce){ 
        float slider_center = slider.getCoordinates().getX() + slider.getWidth() / 2;
        float hit_position = m_coordinates.getX() - slider_center;
        float ratio = hit_position / (slider.getWidth() / 2);

        m_angle = -m_angle + 50 * ratio;

        if (m_angle < 0) {
            m_angle += 360;
        } else if (m_angle > 360) {
            m_angle -= 360;
        }

        move();
        move();
    }
}

void Ball::bounce(Coordinate normal) {
    if (m_can_bounce){ // pour éviter les rebonds multiples sur un même objet
        Coordinate new_speed = Coordinate(m_speed * cos(m_angle*3.14159265/180), m_speed * sin(m_angle*3.14159265/180)) - normal * 2 * (Coordinate(m_speed * cos(m_angle*3.14159265/180), m_speed * sin(m_angle*3.14159265/180)).dot(normal));
        m_angle = atan2(new_speed.getY(), new_speed.getX()) * 180 / 3.14159265;
    }
}
