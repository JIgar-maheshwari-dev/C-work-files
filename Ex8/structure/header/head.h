struct point{
	int x;
	int y;
};

//nested structure
struct rect{
	struct point pt1;
	struct point pt2;
	struct point pt3;
	struct point pt4;
};


struct point makept(int x,int y);
struct rect make_rect(struct point p1,struct point p2,struct point p3,struct point p4);
