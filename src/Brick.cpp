#include "../include/Brick.hpp"

Brick::Brick(int health, Coordinate coordinates, int width, int height) 
    : Object(coordinates), m_health(health), m_width(width), m_height(height) {}

bool Brick::ballCollide(Ball const& ball) {
    return  (m_coordinates.getX() < ball.getCoordinates().getX() + ball.getRadius() &&
             m_coordinates.getX() + m_width > ball.getCoordinates().getX() &&
             m_coordinates.getY() < ball.getCoordinates().getY() + ball.getRadius() &&
             m_coordinates.getY() + m_height > ball.getCoordinates().getY());
}


bool Brick::hit() {
    if (m_health <= 1){
        m_health--;
        return true;
    }
    m_health--;
    return false;
}

bool Brick::operator==(const Brick &brick) const {
    return m_coordinates == brick.getCoordinates();
}

Coordinate Brick::closeBorderPoint(Coordinate const& point) const {
    auto projectOntoSegment = [](Coordinate const& p, Coordinate const& a, Coordinate const& b) -> Coordinate { // project point p onto segment ab
        Coordinate ab = b - a;
        Coordinate ap = p - a;
        float ab2 = ab.dot(ab);
        float ap_ab = ap.dot(ab);
        float t = ap_ab / ab2;
        t = std::max(0.0f, std::min(1.0f, t));
        return a + ab * t;
    };

    // Define the four corners of the brick
    Coordinate topLeft(m_coordinates.getX(), m_coordinates.getY());
    Coordinate topRight(m_coordinates.getX() + m_width, m_coordinates.getY());
    Coordinate bottomLeft(m_coordinates.getX(), m_coordinates.getY() + m_height);
    Coordinate bottomRight(m_coordinates.getX() + m_width, m_coordinates.getY() + m_height);
    std::cout << "le point est : " << point.getX() << " " << point.getY() << std::endl;
    std::cout << "les 4 coins de la brick sont : " << topLeft.getX() << " " << topLeft.getY() << " " << topRight.getX() << " " << topRight.getY() << " " << bottomLeft.getX() << " " << bottomLeft.getY() << " " << bottomRight.getX() << " " << bottomRight.getY() << std::endl;

    // Project the point onto each border segment
    Coordinate closestPointTop = projectOntoSegment(point, topLeft, topRight);
    Coordinate closestPointBottom = projectOntoSegment(point, bottomLeft, bottomRight);
    Coordinate closestPointLeft = projectOntoSegment(point, topLeft, bottomLeft);
    Coordinate closestPointRight = projectOntoSegment(point, topRight, bottomRight);

    // Calculate the distances to each projected point
    auto distance = [](Coordinate const& a, Coordinate const& b) {
        return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY() - b.getY()) * (a.getY() - b.getY()));
    };

    float distanceTop = distance(point, closestPointTop);
    float distanceBottom = distance(point, closestPointBottom);
    float distanceLeft = distance(point, closestPointLeft);
    float distanceRight = distance(point, closestPointRight);

    // Find the minimum distance and return the corresponding point
    float minDistance = std::min(distanceTop, distanceBottom);
    minDistance = std::min(minDistance, distanceLeft);
    minDistance = std::min(minDistance, distanceRight);

    if (minDistance == distanceTop) {
        std::cout << "le point le plus proche est : " << closestPointTop.getX() << " " << closestPointTop.getY() << std::endl;
        return closestPointTop;
    } else if (minDistance == distanceBottom) {
        std::cout << "le point le plus proche est : " << closestPointBottom.getX() << " " << closestPointBottom.getY() << std::endl;
        return closestPointBottom;
    } else if (minDistance == distanceLeft) {
        std::cout << "le point le plus proche est : " << closestPointLeft.getX() << " " << closestPointLeft.getY() << std::endl;
        return closestPointLeft;
    } else {
        std::cout << "le point le plus proche est : " << closestPointRight.getX() << " " << closestPointRight.getY() << std::endl;
        return closestPointRight;
    }
}

Coordinate Brick::getNormal(Coordinate const& point) const {
    Coordinate closestPoint = closeBorderPoint(point);

    if (closestPoint.getY() == m_coordinates.getY()) {
        // Top border
        return Coordinate(0, 1);
    } else if (closestPoint.getY() == m_coordinates.getY() + m_height) {
        // Bottom border
        return Coordinate(0, -1);
    } else if (closestPoint.getX() == m_coordinates.getX()) {
        // Left border
        return Coordinate(-1, 0);
    } else if (closestPoint.getX() == m_coordinates.getX() + m_width) {
        // Right border
        return Coordinate(1, 0);
    }
    return Coordinate(0, 0);
}

