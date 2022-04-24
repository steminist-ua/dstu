#pragma once

using namespace System::Drawing;

class Geom_figura
{
public:
	virtual void draw ( Graphics ^ g )=0;
};

class triangle : Geom_figura   //треугольник
{
public:
	void setxy ( int a, int b )
	{
		x = a;
		y = b;
	}
	void setxxyy ( int a, int b )
	{
		xx = a;
		yy = b;
	}
	void draw ( Graphics ^ g ){};
protected:
	int x, y; // координата первой точки;
	int xx, yy; // координата второй точки;
};


class isosceles_triangle : public triangle //равнобедренный треугольник
{
public:
	void setxy ( int a, int b )
	{
		triangle::setxy (a,b);
	}
	void setxxyy ( int a1, int b1 )
	{
		triangle::setxxyy (a1,b1);
	}
	void draw ( Graphics ^ g)
	{
		Color^ h = gcnew Color();
		g -> Clear(h->White);
		int k;
		k = (xx - x ) / 2;		
		g -> DrawLine ( Pens::Black, x, yy, xx, yy );
		g -> DrawLine ( Pens::Black, x, yy, x + k, y );
		g -> DrawLine ( Pens::Black, x + k, y, xx, yy );
		
	};
};

class equilateral_triangle : public triangle //равносторонний треугольник
{
public:
	void setxy ( int a, int b )
	{
		triangle::setxy (a,b);
	}
	void setxxyy ( int a1, int b1 )
	{
		triangle::setxxyy (a1,b1);
	}
	void draw ( Graphics ^ g )
	{
		Color^ h = gcnew Color();
		g -> Clear(h->White);
		int k;
		k = ( yy - y ) * 1,7;
		g -> DrawLine ( Pens::Red, x, y, x + k, yy );
		g -> DrawLine ( Pens::Red, x, y, x - k, yy );
		g -> DrawLine ( Pens::Red, x - k, yy, x + k, yy );
	};

};


class pr_triangle: public triangle
{
public:
	void setxy ( int a, int b )
	{
		triangle::setxy (a,b);
	}
	void setxxyy ( int a1, int b1 )
	{
		triangle::setxxyy (a1,b1);
	}
	void draw ( Graphics ^ g )
	{
					Color^ h = gcnew Color();
				 	g -> Clear(h->White);
					if ( xx > x )
					{
						if ( yy < y )
						{
							g -> DrawLine ( Pens::Blue, x, yy, x, y );
							g -> DrawLine ( Pens::Blue, x, yy, xx, y );
							g -> DrawLine ( Pens::Blue, x,y, xx, y );
						}
						else
						{

						 g -> DrawLine ( Pens::Blue, x, y, x, yy );
						 g -> DrawLine ( Pens::Blue, x, yy, xx, yy );
						 g -> DrawLine ( Pens::Blue, x,y, xx, yy );
						 }
					}
					else
					{
						if ( xx < x )
						{
							if ( yy < y )
							{
								g -> DrawLine ( Pens::Blue, xx, yy, xx, y );
								g -> DrawLine ( Pens::Blue,  x, y,xx, yy );
								g -> DrawLine ( Pens::Blue, x,y, xx, y );
							}
							else
							{
								g -> DrawLine ( Pens::Blue, xx, y, xx, yy );
								g -> DrawLine ( Pens::Blue, xx, yy, x, yy );
								g -> DrawLine ( Pens::Blue, xx, y, x, yy );
							}
						}
					}
	}
};

class rectangle : public Geom_figura
{
	public:
	void setxy ( int a, int b )
	{
		x = a;
		y = b;
	}
	void setxxyy ( int a, int b )
	{
		xx = a;
		yy = b;
	}
	void draw ( Graphics ^ g )
	{
		Color^ h = gcnew Color();
		g -> Clear(h->White);
		g -> DrawRectangle ( Pens::Chocolate, x, y, xx - x, yy - y );
	}
protected:
	int x, y; // координата первой точки;
	int xx, yy; // координата второй точки;
};

class square : public rectangle
{
	public:
		void setxy ( int a, int b )
	{
		rectangle::setxy ( a, b );
	}
	void setxxyy ( int a, int b )
	{
		rectangle::setxxyy ( a, b );
	}
	void draw ( Graphics ^ g )
	{
		Color^ h = gcnew Color();
		g -> Clear(h->White);
		g -> DrawRectangle ( Pens::Chocolate, x, y, xx - x, xx - x );
	}

};


