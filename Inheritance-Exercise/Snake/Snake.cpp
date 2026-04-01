#include "Snake.h"

#include <algorithm>

Snake::Snake(const int     fieldRows,
             const int     fieldCols,
             const Point & startPos)
    : _FIELD_ROWS(fieldRows),
      _FIELD_COLS(fieldCols),
      _currPos(startPos)
{
    _snakeNodes.push_back(startPos);
}

Snake::~Snake()
{
}

StatusCode Snake::move(const Direction            dir,
                       const std::vector<Point> & obstacles,
                       std::vector<Point> &       powerUps)
{
    Point newHead = _snakeNodes.front();

    switch (dir)
    {
        case Direction::UP:    newHead.row -= 1; break;
        case Direction::DOWN:  newHead.row += 1; break;
        case Direction::LEFT:  newHead.col -= 1; break;
        case Direction::RIGHT: newHead.col += 1; break;
    }

    if (newHead.row < 0 || newHead.row >= _FIELD_ROWS ||
        newHead.col < 0 || newHead.col >= _FIELD_COLS)
    {
        return StatusCode::SNAKE_DEAD;
    }

    for (const Point & obs : obstacles)
    {
        if (newHead == obs)
        {
            return StatusCode::SNAKE_DEAD;
        }
    }

    const size_t SNAKE_SIZE = _snakeNodes.size();
    for (size_t i = 1; i < SNAKE_SIZE; ++i)
    {
        if (newHead == _snakeNodes[i])
        {
            return StatusCode::SNAKE_DEAD;
        }
    }

    auto powerUpIt = std::find(powerUps.begin(), powerUps.end(), newHead);
    if (powerUpIt != powerUps.end())
    {
        _snakeNodes.push_front(newHead);
        powerUps.erase(powerUpIt);
        return StatusCode::SNAKE_GROWING;
    }

    _snakeNodes.push_front(newHead);
    _snakeNodes.pop_back();

    return StatusCode::SNAKE_MOVING;
}

std::deque<Point> & Snake::getSnakeNodes()
{
    return _snakeNodes;
}
