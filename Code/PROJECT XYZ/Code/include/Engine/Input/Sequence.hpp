#pragma once

#include "Joystick.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Clock.hpp"
#include "Debug.hpp"

#include <iostream>

namespace Sonar
{
	/**
	 * \brief enum for tick direction
	 */
	enum DIRECTION { UP, DOWN };
	
    class Sequence
    {
    public:
		/**
		 * \brief Class constructor
		 */
        Sequence( );
		
		/**
		 * \brief Class destructor
		 */
        ~Sequence( ) { };
        
		/**
		 * \brief Tick up the sequence counter
		 *
		 * \param amount Interval jump for the counter
		 * \param canGoOver Can the counter go above its max
		 *
		 */
        void TickUp( const float &amount = 1, const bool &canGoOver = false );
        
		/**
		 * \brief Tick down the sequence counter
		 *
		 * \param amount Interval jump for the counter
		 * \param canGoOver Can the counter go below its max
		 *
		 */
        void TickDown( const float &amount = 1, const bool &canGoUnder = false );
        
        void MousePress( const Mouse::Button &button, const float &amount = 1, const DIRECTION &direction = DIRECTION::UP );
        
        void KeyboardPress( const Keyboard::Key &key, const float &amount = 1, const DIRECTION &direction = DIRECTION::UP  );
        
        void JoystickPress( const unsigned int joystickID, const unsigned int &button, const float &amount = 1, const DIRECTION &direction = DIRECTION::UP );
        
        void SetCount( const float &count );
        
        void SetMin( const float &min );
        
        void SetMax( const float &max );
        
        const float &GetCount( ) const;
        
        const float &GetMin( ) const;
        
        const float &GetMax( ) const;
        
		const Time &KeyboardPressedTimer( const Keyboard::Key &key );
		const Time &MousePressedTimer( const Mouse::Button &button );
		const Time &JoystickPressedTimer( const unsigned int &joystick, const unsigned int &button );
		
    private:
        float _count;
        
        float _min;
        
        float _max;
		
		Clock _clock;
        
    };
}
