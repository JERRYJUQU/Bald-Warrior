#ifndef POSITION_H
#define POSITION_H

struct Position {
	int x;
	int y;

	bool operator== (Position other) {
		return (other.x == x) && (other.y == y);
	}
};

#endif
