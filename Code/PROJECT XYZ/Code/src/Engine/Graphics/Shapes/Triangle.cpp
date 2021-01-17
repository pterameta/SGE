#include "Graphics/Shapes/Triangle.hpp"

namespace Sonar
{
	Triangle::Triangle( GameDataRef data ) : Drawable( data )
	{
		_object = &_shape;
		_texture = new Texture( );

		_shape.setPointCount( 3 );

		SetInsideColor( Color::Black );
		SetPosition( 0, 0 );
		_globalBounds = _shape.getGlobalBounds( );
	}

    Triangle::Triangle( GameDataRef data, const glm::vec2 &point1, const glm::vec2 &point2, const glm::vec2 &point3 ) : Drawable( data )
    {
        _object = &_shape;
		_texture = new Texture( );

		_shape.setPointCount( 3 );

		SetPoints( point1, point2, point3 );

		SetInsideColor( Color::Black );
        SetPosition( 0, 0 );
		_globalBounds = _shape.getGlobalBounds( );
    }

    Triangle::~Triangle( ) { }

	void Triangle::SetPosition( const float &x, const float &y )
	{
		Drawable::SetPosition( x, y );
		_shape.setPosition( x, y );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::SetPositionX( const float &x )
	{
		Drawable::SetPositionX( x );
		_shape.setPosition( x, _shape.getPosition( ).y );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::SetPositionY( const float &y )
	{
		Drawable::SetPositionY( y );
		_shape.setPosition( _shape.getPosition( ).x, y );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::SetSize( const glm::vec2 &point1, const glm::vec2 &point2, const glm::vec2 &point3 )
	{
		float xMin = point1.x, xMax = point1.x;
		float yMin = point1.y, yMax = point1.y;

		if ( point2.x < xMin )
		{ xMin = point2.x; }
		else if ( point2.x > xMax )
		{ xMax = point2.x; }

		if ( point3.x < xMin )
		{ xMin = point3.x; }
		else if ( point3.x > xMax )
		{ xMax = point3.x; }

		if ( point2.y < yMin )
		{ yMin = point2.y; }
		else if ( point2.y > yMax )
		{ yMax = point2.y; }

		if ( point3.y < yMin )
		{ yMin = point3.y; }
		else if ( point3.y > yMax )
		{ yMax = point3.y; }

		float width = xMax - xMin;
		float height = yMax - yMin;

		Drawable::SetSize( width, height );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::SetInsideColor( const Color &color )
	{
		Drawable::SetInsideColor( color );
		_shape.setFillColor( color.GetColor( ) );
	}

	void Triangle::SetBorderColor( const Color &color )
	{
		Drawable::SetBorderColor( color );
		_shape.setOutlineColor( color.GetColor( ) );
	}

	void Triangle::SetBorderThickness( const float &thickness )
	{
		Drawable::SetBorderThickness( thickness );
		_shape.setOutlineThickness( thickness );
	}

	Color Triangle::GetInsideColor( ) const
	{ return Color( _shape.getFillColor( ).r, _shape.getFillColor( ).g, _shape.getFillColor( ).b, _shape.getFillColor( ).a ); }

	Color Triangle::GetBorderColor( ) const
	{ return Color( _shape.getOutlineColor( ).r, _shape.getOutlineColor( ).g, _shape.getOutlineColor( ).b, _shape.getOutlineColor( ).a ); }


	float Triangle::GetBorderThickness( ) const
	{ return _shape.getOutlineThickness( ); }

	void Triangle::Move( const float &x, const float &y )
	{
		Drawable::Move( x, y );
		_shape.move( x, y );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::MoveX( const float &x )
	{
		Drawable::MoveX( x );
		_shape.move( x, 0 );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::MoveY( const float &y )
	{
		Drawable::MoveY( y );
		_shape.move( 0, y );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::SetRotation( const float &angle )
	{
		Drawable::SetRotation( angle );
		_shape.setRotation( angle );
		_globalBounds = _shape.getGlobalBounds( );
	}

	float Triangle::GetRotation( ) const
	{ return _shape.getRotation( ); }

	void Triangle::SetScale( const float &xScale, const float &yScale )
	{
		Drawable::SetScale( xScale, yScale );
		_shape.setScale( xScale, yScale );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::SetScale( const glm::vec2 &scale )
	{
		Drawable::SetScale( scale[0], scale[1] );
		_shape.setScale( scale[0], scale[1] );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::SetScaleX( const float &xScale )
	{
		Drawable::SetScaleX( xScale );
		_shape.setScale( xScale, _shape.getScale( ).y );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::SetScaleY( const float &yScale )
	{
		Drawable::SetScaleX( yScale );
		_shape.setScale( _shape.getScale( ).x, yScale );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::SetPivot( const float &xPoint, const float &yPoint )
	{
		Drawable::SetPivot( xPoint, yPoint );
		_shape.setOrigin( xPoint, yPoint );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::SetPivot( const glm::vec2 &pivot )
	{
		Drawable::SetPivot( pivot );
		_shape.setOrigin( pivot[0], pivot[1] );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::SetPivot( const OBJECT_POINTS &pivot )
	{
		switch ( pivot )
		{
			case OBJECT_POINTS::CENTER:
				Drawable::SetPivot( OBJECT_POINTS::CENTER );
				_shape.setOrigin( _shape.getLocalBounds( ).width * 0.5f, _shape.getLocalBounds( ).height * 0.5f );

				break;

			case OBJECT_POINTS::TOP_LEFT:
				Drawable::SetPivot( OBJECT_POINTS::TOP_LEFT );
				_shape.setOrigin( 0, 0 );

				break;

			case OBJECT_POINTS::TOP_RIGHT:
				Drawable::SetPivot( OBJECT_POINTS::TOP_RIGHT );
				_shape.setOrigin( _shape.getLocalBounds( ).width, 0 );

				break;

			case OBJECT_POINTS::BOTTOM_LEFT:
				Drawable::SetPivot( OBJECT_POINTS::BOTTOM_LEFT );
				_shape.setOrigin( 0, _shape.getLocalBounds( ).height );

				break;

			case OBJECT_POINTS::BOTTOM_RIGHT:
				Drawable::SetPivot( OBJECT_POINTS::BOTTOM_RIGHT );
				_shape.setOrigin( _shape.getLocalBounds( ).width, _shape.getLocalBounds( ).height );

				break;
		}

		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::SetPivotX( const float &xPoint )
	{
		Drawable::SetPivotX( xPoint );
		_shape.setOrigin( xPoint, _shape.getOrigin( ).y );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::SetPivotY( const float &yPoint )
	{
		Drawable::SetPivotY( yPoint );
		_shape.setOrigin( _shape.getOrigin( ).x, yPoint );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Triangle::Update( const float &dt )
	{
		Drawable::Update( dt );

		SetScale( Drawable::GetScale( ) );
	}

	void Triangle::SetPoints( const glm::vec2 &point1, const glm::vec2 &point2, const glm::vec2 &point3 )
	{
		_shape.setPoint( 0, sf::Vector2f( point1.x, point1.y ) );
		_shape.setPoint( 1, sf::Vector2f( point2.x, point2.y ) );
		_shape.setPoint( 2, sf::Vector2f( point3.x, point3.y ) );

		_points.push_back( point1 );
		_points.push_back( point2 );
		_points.push_back( point3 );

		SetSize( point1, point2, point3 );

		_globalBounds = _shape.getGlobalBounds( );
	}

	std::vector<glm::vec2> Triangle::GetPoints( )
	{ return _points; }

	void Triangle::SetTexture( const std::string &filepath, const bool &resetRect )
	{
		_texture->SetTexture( filepath );
		_shape.setTexture( _texture->GetTexture( ), resetRect );

		SetPosition( _shape.getPosition( ).x, _shape.getPosition( ).y );
	}

	void Triangle::SetTexture( Texture *texture, const bool &resetRect )
	{
		_texture = texture;
		_shape.setTexture( _texture->GetTexture( ), resetRect );

		SetPosition( _shape.getPosition( ).x, _shape.getPosition( ).y );
	}

	void Triangle::SetTextureRect( const glm::ivec4 &rectangle )
	{ _shape.setTextureRect( sf::IntRect( rectangle.x, rectangle.y, rectangle.z, rectangle.w ) ); }

	void Triangle::SetTextureRect( const int &left, const int &top, const int &width, const int &height )
	{ _shape.setTextureRect( sf::IntRect( left, top, width, height ) ); }

	Texture *Triangle::GetTexture( ) const
	{ return _texture; }

	glm::ivec4 Triangle::GetTextureRect( ) const
	{ return glm::ivec4( _shape.getTextureRect( ).left, _shape.getTextureRect( ).top, _shape.getTextureRect( ).width, _shape.getTextureRect( ).height ); }

	glm::vec4 Triangle::GetLocalBounds( ) const
	{ return glm::vec4( _shape.getLocalBounds( ).left, _shape.getLocalBounds( ).top, _shape.getLocalBounds( ).width, _shape.getLocalBounds( ).height ); }

	glm::vec4 Triangle::GetGlobalBounds( ) const
	{ return glm::vec4( _shape.getGlobalBounds( ).left, _shape.getGlobalBounds( ).top, _shape.getGlobalBounds( ).width, _shape.getGlobalBounds( ).height ); }

}
