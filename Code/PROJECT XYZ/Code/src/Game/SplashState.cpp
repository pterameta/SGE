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

	void SplashState::HandleInput( float dt )
	{
		sf::Event event;
        
        player->HandleInput( dt );

		while ( this->_data->window.pollEvent( event ) )
		{
			if ( sf::Event::Closed == event.type )
			{
				this->_data->window.close( );
			}
            
            if ( sf::Event::MouseWheelMoved == event.type )
            {
                physicsWorld->CreateDynamicBody( event.mouseButton.x, event.mouseButton.y, 32, 32 );
                
                //.event.mouseButton.x
                
            }
		}
	}

	void SplashState::Update( float dt )
	{
        player->Update( dt );
        
        
        physicsWorld->Update( dt );
	}

	void SplashState::Draw( float dt )
	{
		this->_data->window.clear(sf::Color::White);

        player->Draw( dt );
        
        //physicsWorld->Draw( dt );
        
        

		this->_data->window.display();
	}

    
}