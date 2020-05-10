#include <sstream>
#include "SplashState.hpp"
#include <iostream>

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );
	}

	void SplashState::Init( )
	{
        
	}

	void SplashState::PollInput( const float &dt, const Event &event )
	{
        player->HandleInput( dt );
        
        if ( Event::MouseWheelMoved == event.type )
        {
            physicsWorld->CreateDynamicBody( event.mouseButton.x, event.mouseButton.y, 32, 32 );
        }        
	}

	void SplashState::Update( const float &dt )
	{
        player->Update( dt );
        
        if ( Keyboard::ChordPressed( { Keyboard::Key::LSystem, Keyboard::Key::LShift, Keyboard::Key::A } ) )
        {
            Debug::Print( "YAY" );
        }
        
        if ( Mouse::ChordPressed( { Mouse::Button::Left, Mouse::Button::Right, Mouse::Button::Middle } ) )
        {
            Debug::Print( "OH YES" );
        }
        
        physicsWorld->Update( dt );
	}

	void SplashState::Draw( const float &dt )
	{
		this->_data->window.clear( sf::Color::White );

        player->Draw( dt );
        
        physicsWorld->Draw( dt );
	}

    
}
