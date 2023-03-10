#pragma once

struct Point {
	int x;
	int y;
};

struct Rect {
	int x;
	int y;
	int w;
	int h;
};

namespace render {
	struct FontSize_t {
		int m_width;
		int m_height;
	};

	enum StringFlags_t {
		ALIGN_LEFT = 0,
		ALIGN_RIGHT,
		ALIGN_CENTER
	};

	class Font {
	public:
		HFont      m_handle;
		FontSize_t m_size;

	public:
		__forceinline Font( ) : m_handle{}, m_size{} {};

		// ctor.
		__forceinline Font( const std::string& name, int s, int w, int flags ) {
			m_handle = g_csgo.m_surface->CreateFont( );
			g_csgo.m_surface->SetFontGlyphSet( m_handle, name.data( ), s, w, 0, 0, flags );
			m_size = size( XOR( "A" ) );
		}

		// ctor.
		__forceinline Font( HFont font ) {
			m_handle = font;
			m_size = size( XOR( "A" ) );
		}

		void string( int x, int y, Color color, const std::string& text, StringFlags_t flags = ALIGN_LEFT );
		void string( int x, int y, Color color, const std::stringstream& text, StringFlags_t flags = ALIGN_LEFT );
		void wstring( int x, int y, Color color, const std::wstring& text, StringFlags_t flags = ALIGN_LEFT );
		render::FontSize_t size( const std::string& text );
		FontSize_t wsize( const std::wstring& text );
		void Font::semi_filled_text(int x, int y, Color color, const std::string& text, StringFlags_t flags, float factor);
		void Font::semi_filled_text_v(int x, int y, Color color, const std::string& text, StringFlags_t flags, float factor);
	};

	extern Font menu;
	extern Font menu_shade;
	extern Font esp;
	extern Font esp_small;
	extern Font hud;
	extern Font cs;
	extern Font indicator;
	extern Font logevent;
	extern Font icons;
	extern Font weapon;
	extern Font damage;
	extern Font gw;
	extern Font menu_shade1;

	void init( );
	void Triangle(vec2_t point_one, vec2_t point_two, vec2_t point_three, Color color);
	void circle_outline(int x, int y, int radius, int segments, Color color);
	void WorldCircleOutline(vec3_t origin, float radius, float angle, Color color);
	void textured_polygon(int n, std::vector<Vertex> vertice, Color color);
	void textured_polyline(int n, std::vector<Vertex> vertice, Color color);
	void draw_dynamic_filed_circle(const vec3_t& origin, float radius, Color color, Color color_fill, float points);
	bool world_to_screen_3d(const vec3_t& world, vec3_t& screen);
	bool WorldToScreen( const vec3_t& world, vec2_t& screen );
	void line( vec2_t v0, vec2_t v1, Color color );
	void line( int x0, int y0, int x1, int y1, Color color );
	void gradient1337(int x, int y, int w, int h, Color color1, Color color2, bool horizontal);
	void rect( int x, int y, int w, int h, Color color );
	void rect_filled( int x, int y, int w, int h, Color color );
	void rect_filled_fade( int x, int y, int w, int h, Color color, int a1, int a2 );
	void rect_outlined( int x, int y, int w, int h, Color color, Color color2 );
	void draw_arc( int x, int y, int radius, int start_angle, int percent, int thickness, Color color );
	void arc( int x, int y, int radius, int radius_inner, int start_angle, int end_angle, int segments, Color color );
	void DrawLine(int x0, int y0, int x1, int y1, Color col, bool shadow);
	bool WorldToScreen2(const vec3_t& world, vec3_t& screen);
	void Draw3DFilledCircle( const vec3_t& origin, float radius, Color color );
	void sphere2(vec3_t origin, float radius, float angle, float scale, Color color);
	void sphere1(vec3_t origin, float radius, float angle, float scale, Color color);
	void circle( int x, int y, int radius, int segments, Color color );
	void gradient( int x, int y, int w, int h, Color color1, Color color2, bool sideways = false );
	void round_rect(int x, int y, int w, int h, int r, Color color);
	void sphere( vec3_t origin, float radius, float angle, float scale, Color color );
	void TexturedPolygon( Vertex vertice, Color color );
	Vertex RotateVertex( const vec2_t& p, const Vertex& v, float angle );
}

// nitro du hurensohn