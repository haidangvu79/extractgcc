struct a {
	char a, b;
	short c;
};

int
a1()
{
  printf("g1 ");
	static struct a x = { 1, 2, ~1 }, y = { 65, 2, ~2 };

	return (x.a == (y.a & ~64) && x.b == y.b);
}

int
a2()
{
  printf("g1 ");
	static struct a x = { 1, 66, ~1 }, y = { 1, 2, ~2 };

	return (x.a == y.a && (x.b & ~64) == y.b);
}

int
a3()
{
  printf("g1 ");
	static struct a x = { 9, 66, ~1 }, y = { 33, 18, ~2 };

	return ((x.a & ~8) == (y.a & ~32) && (x.b & ~64) == (y.b & ~16));
}

struct b {
	int c;
	short b, a;
};

int
b1()
{
  printf("g1 ");
	static struct b x = { ~1, 2, 1 }, y = { ~2, 2, 65 };

	return (x.a == (y.a & ~64) && x.b == y.b);
}

int
b2()
{
  printf("g1 ");
	static struct b x = { ~1, 66, 1 }, y = { ~2, 2, 1 };

	return (x.a == y.a && (x.b & ~64) == y.b);
}

int
b3()
{
  printf("g1 ");
	static struct b x = { ~1, 66, 9 }, y = { ~2, 18, 33 };

	return ((x.a & ~8) == (y.a & ~32) && (x.b & ~64) == (y.b & ~16));
}

struct c {
	unsigned int c:4, b:14, a:14;
} __attribute__ ((aligned));

int
c1()
{
  printf("g1 ");
	static struct c x = { ~1, 2, 1 }, y = { ~2, 2, 65 };

	return (x.a == (y.a & ~64) && x.b == y.b);
}

int
c2()
{
  printf("g1 ");
	static struct c x = { ~1, 66, 1 }, y = { ~2, 2, 1 };

	return (x.a == y.a && (x.b & ~64) == y.b);
}

int
c3()
{
  printf("g1 ");
	static struct c x = { ~1, 66, 9 }, y = { ~2, 18, 33 };

	return ((x.a & ~8) == (y.a & ~32) && (x.b & ~64) == (y.b & ~16));
}

struct d {
	unsigned int a:14, b:14, c:4;
} __attribute__ ((aligned));

int
d1()
{
  printf("g1 ");
	static struct d x = { 1, 2, ~1 }, y = { 65, 2, ~2 };

	return (x.a == (y.a & ~64) && x.b == y.b);
}

int
d2()
{
  printf("g1 ");
	static struct d x = { 1, 66, ~1 }, y = { 1, 2, ~2 };

	return (x.a == y.a && (x.b & ~64) == y.b);
}

int
d3()
{
  printf("g1 ");
	static struct d x = { 9, 66, ~1 }, y = { 33, 18, ~2 };

	return ((x.a & ~8) == (y.a & ~32) && (x.b & ~64) == (y.b & ~16));
}

struct e {
	int c:4, b:14, a:14;
} __attribute__ ((aligned));

int
e1()
{
  printf("g1 ");
	static struct e x = { ~1, -2, -65 }, y = { ~2, -2, -1 };

	return (x.a == (y.a & ~64) && x.b == y.b);
}

int
e2()
{
  printf("g1 ");
	static struct e x = { ~1, -2, -1 }, y = { ~2, -66, -1 };

	return (x.a == y.a && (x.b & ~64) == y.b);
}

int
e3()
{
  printf("g1 ");
	static struct e x = { ~1, -18, -33 }, y = { ~2, -66, -9 };

	return ((x.a & ~8) == (y.a & ~32) && (x.b & ~64) == (y.b & ~16));
}

int
e4()
{
  printf("g1 ");
	static struct e x = { -1, -1, 0 };

	return x.a == 0 && x.b & 0x2000;
}

struct f {
	int a:14, b:14, c:4;
} __attribute__ ((aligned));

int
f1()
{
  printf("g1 ");
	static struct f x = { -65, -2, ~1 }, y = { -1, -2, ~2 };

	return (x.a == (y.a & ~64) && x.b == y.b);
}

int
f2()
{
  printf("g1 ");
	static struct f x = { -1, -2, ~1 }, y = { -1, -66, ~2 };

	return (x.a == y.a && (x.b & ~64) == y.b);
}

int
f3()
{
  printf("g1 ");
	static struct f x = { -33, -18, ~1 }, y = { -9, -66, ~2 };

	return ((x.a & ~8) == (y.a & ~32) && (x.b & ~64) == (y.b & ~16));
}

int
f4()
{
  printf("g1 ");
	static struct f x = { 0, -1, -1 };

	return x.a == 0 && x.b & 0x2000;
}

struct gx {
	int c:4, b:14, a:14;
} __attribute__ ((aligned));
struct gy {
	int b:14, a:14, c:4;
} __attribute__ ((aligned));

int
g1()
{
  printf("g1 ");
	static struct gx x = { ~1, -2, -65 };
	static struct gy y = { -2, -1, ~2 };

	return (x.a == (y.a & ~64) && x.b == y.b);
}

int
g2()
{
  printf("g1 ");
	static struct gx x = { ~1, -2, -1 };
	static struct gy y = { -66, -1, ~2 };

	return (x.a == y.a && (x.b & ~64) == y.b);
}

int
g3()
{
  printf("g1 ");
	static struct gx x = { ~1, -18, -33 };
	static struct gy y = { -66, -9, ~2 };

	return ((x.a & ~8) == (y.a & ~32) && (x.b & ~64) == (y.b & ~16));
}

int
g4()
{
  printf("g1 ");
	static struct gx x = { ~1, 0x0020, 0x0010 };
	static struct gy y = { 0x0200, 0x0100, ~2 };

	return ((x.a & 0x00f0) == (y.a & 0x0f00) &&
		(x.b & 0x00f0) == (y.b & 0x0f00));
}

int
g5()
{
  printf("g1 ");
	static struct gx x = { ~1, 0x0200, 0x0100 };
	static struct gy y = { 0x0020, 0x0010, ~2 };

	return ((x.a & 0x0f00) == (y.a & 0x00f0) &&
		(x.b & 0x0f00) == (y.b & 0x00f0));
}

int
g6()
{
  printf("g1 ");
	static struct gx x = { ~1, 0xfe20, 0xfd10 };
	static struct gy y = { 0xc22f, 0xc11f, ~2 };

	return ((x.a & 0x03ff) == (y.a & 0x3ff0) &&
		(x.b & 0x03ff) == (y.b & 0x3ff0));
}

int
g7()
{
  printf("g1 ");
	static struct gx x = { ~1, 0xc22f, 0xc11f };
	static struct gy y = { 0xfe20, 0xfd10, ~2 };

	return ((x.a & 0x3ff0) == (y.a & 0x03ff) &&
		(x.b & 0x3ff0) == (y.b & 0x03ff));
}

struct hx {
	int a:14, b:14, c:4;
} __attribute__ ((aligned));
struct hy {
	int c:4, a:14, b:14;
} __attribute__ ((aligned));

int
h1()
{
  printf("g1 ");
	static struct hx x = { -65, -2, ~1 };
	static struct hy y = { ~2, -1, -2 };

	return (x.a == (y.a & ~64) && x.b == y.b);
}

int
h2()
{
  printf("g1 ");
	static struct hx x = { -1, -2, ~1 };
	static struct hy y = { ~2, -1, -66 };

	return (x.a == y.a && (x.b & ~64) == y.b);
}

int
h3()
{
  printf("g1 ");
	static struct hx x = { -33, -18, ~1 };
	static struct hy y = { ~2, -9, -66 };

	return ((x.a & ~8) == (y.a & ~32) && (x.b & ~64) == (y.b & ~16));
}

int
h4()
{
  printf("g1 ");
	static struct hx x = { 0x0010, 0x0020, ~1 };
	static struct hy y = { ~2, 0x0100, 0x0200 };

	return ((x.a & 0x00f0) == (y.a & 0x0f00) &&
		(x.b & 0x00f0) == (y.b & 0x0f00));
}

int
h5()
{
  printf("g1 ");
	static struct hx x = { 0x0100, 0x0200, ~1 };
	static struct hy y = { ~2, 0x0010, 0x0020 };

	return ((x.a & 0x0f00) == (y.a & 0x00f0) &&
		(x.b & 0x0f00) == (y.b & 0x00f0));
}

int
h6()
{
  printf("g1 ");
	static struct hx x = { 0xfd10, 0xfe20, ~1 };
	static struct hy y = { ~2, 0xc11f, 0xc22f };

	return ((x.a & 0x03ff) == (y.a & 0x3ff0) &&
		(x.b & 0x03ff) == (y.b & 0x3ff0));
}

int
h7()
{
  printf("g1 ");
	static struct hx x = { 0xc11f, 0xc22f, ~1 };
	static struct hy y = { ~2, 0xfd10, 0xfe20 };

	return ((x.a & 0x3ff0) == (y.a & 0x03ff) &&
		(x.b & 0x3ff0) == (y.b & 0x03ff));
}

int
main()
{
  if (!a1 ())
   { printf("abort_main "); 		abort (); }
  if (!a2 ())
   { printf("abort_main "); 		abort (); }
  if (!a3 ())
   { printf("abort_main "); 		abort (); }
  if (!b1 ())
   { printf("abort_main "); 		abort (); }
  if (!b2 ())
   { printf("abort_main "); 		abort (); }
  if (!b3 ())
   { printf("abort_main "); 		abort (); }
  if (!c1 ())
   { printf("abort_main "); 		abort (); }
  if (!c2 ())
   { printf("abort_main "); 		abort (); }
  if (!c3 ())
   { printf("abort_main "); 		abort (); }
  if (!d1 ())
   { printf("abort_main "); 		abort (); }
  if (!d2 ())
   { printf("abort_main "); 		abort (); }
  if (!d3 ())
   { printf("abort_main "); 		abort (); }
  if (!e1 ())
   { printf("abort_main "); 		abort (); }
  if (!e2 ())
   { printf("abort_main "); 		abort (); }
  if (!e3 ())
   { printf("abort_main "); 		abort (); }
  if (!e4 ())
   { printf("abort_main "); 		abort (); }
  if (!f1 ())
   { printf("abort_main "); 		abort (); }
  if (!f2 ())
   { printf("abort_main "); 		abort (); }
  if (!f3 ())
   { printf("abort_main "); 		abort (); }
  if (!f4 ())
   { printf("abort_main "); 		abort (); }
  if (!g1 ())
   { printf("abort_main "); 		abort (); }
  if (!g2 ())
   { printf("abort_main "); 		abort (); }
  if (!g3 ())
   { printf("abort_main "); 		abort (); }
  if (g4 ())
   { printf("abort_main "); 		abort (); }
  if (g5 ())
   { printf("abort_main "); 		abort (); }
  if (!g6 ())
   { printf("abort_main "); 		abort (); }
  if (!g7 ())
   { printf("abort_main "); 		abort (); }
  if (!h1 ())
   { printf("abort_main "); 		abort (); }
  if (!h2 ())
   { printf("abort_main "); 		abort (); }
  if (!h3 ())
   { printf("abort_main "); 		abort (); }
  if (h4 ())
   { printf("abort_main "); 		abort (); }
  if (h5 ())
   { printf("abort_main "); 		abort (); }
  if (!h6 ())
   { printf("abort_main "); 		abort (); }
  if (!h7 ())
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

