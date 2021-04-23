#include "Graphics/ButtonGroup.hpp"

namespace Sonar
{
	ButtonGroup::ButtonGroup( GameDataRef data ) : _data( data )
	{
		_currentIndex = 0;

		_isKeyboardEnabled = DEFAULT_BUTTON_GROUP_KEYBOARD_ENABLED;

		_isCurrentButtonClicked = false;
		_hasButtonGroupLoaded = false;

		_currentMouseState = Button::MOUSE_STATE::NOT_INTERACTING;
	}

	ButtonGroup::~ButtonGroup( ) { }

	void ButtonGroup::Draw( )
	{
		if ( !_hasButtonGroupLoaded )
		{
			_hasButtonGroupLoaded = true;
			UpdateButtons( );
		}

		for ( auto &button : _buttons )
		{ button->Draw( ); }
	}

	void ButtonGroup::Update( const float &dt )
	{
		for ( int i = 0; i < _buttons.size( ); i++ )
		{
			Button::MOUSE_STATE mouseState = _buttons.at( i )->UpdateForButtonGroup( dt, !_isKeyboardEnabled );

			switch ( mouseState )
			{
				case Button::MOUSE_STATE::NOT_INTERACTING:
					if ( i == _currentIndex )
					{
						_isCurrentButtonClicked = false;

						if ( Button::MOUSE_STATE::NOT_INTERACTING != _currentMouseState )
						{
							_currentMouseState = Button::MOUSE_STATE::NOT_INTERACTING;

							UpdateButtons( );
						}
					}

					break;

				case Button::MOUSE_STATE::CLICKED:
					if ( i == _currentIndex )
					{
						_isCurrentButtonClicked = true;
					

						if ( Button::MOUSE_STATE::CLICKED != _currentMouseState )
						{
							_currentMouseState = Button::MOUSE_STATE::CLICKED;

							UpdateButtons( );
						}
					}

					break;

				case Button::MOUSE_STATE::HOVER:
					_currentIndex = i;

					if ( i == _currentIndex )
					{
						_isCurrentButtonClicked = false;

						if ( Button::MOUSE_STATE::HOVER != _currentMouseState )
						{
							_currentMouseState = Button::MOUSE_STATE::HOVER;

							UpdateButtons( );
						}
					}

					break;
			}
		}
	}

	void ButtonGroup::PollInput( const float &dt, const Event &event )
	{
		for ( auto &button : _buttons )
		{ button->PollInput( dt, event ); }

		if ( Event::KeyReleased == event.type )
		{
			if ( Keyboard::Up == event.key.code )
			{ MoveUp( ); }
			else if ( Keyboard::Down == event.key.code )
			{ MoveDown( ); }
		}
	}

	void ButtonGroup::AddButton( Button *button, const bool &overrideStyle )
	{
		if ( overrideStyle )
		{ button->SetTheme( _theme ); }

		_buttons.push_back( button );

		UpdateButtons( );
	}

	void ButtonGroup::RemoveButton( Button *button )
	{
		std::vector<Button *> newMenuComponentsVector( _buttons.size( ) );

		std::remove_copy( _buttons.begin( ), _buttons.end( ), newMenuComponentsVector.begin( ), button );

		if ( newMenuComponentsVector.at( newMenuComponentsVector.size( ) - 1 ) == NULL )
		{
			newMenuComponentsVector.pop_back( );

			_buttons = newMenuComponentsVector;

			UpdateButtons( );
		}
	}

	void ButtonGroup::RemoveButton( const int &index )
	{
		if ( index < _buttons.size( ) )
		{
			_buttons.erase( _buttons.begin( ) + index );

			if ( _buttons.size( ) <= _currentIndex )
			{
				_currentIndex = _buttons.size( ) - 1;

				if ( 0 > _currentIndex )
				{ _currentIndex = 0; }
			}

			UpdateButtons( );
		}
	}

	void ButtonGroup::RemoveFirstButton( )
	{
		if ( 0 < _buttons.size( ) )
		{
			_buttons.erase( _buttons.begin( ) );

			if ( _buttons.size( ) <= _currentIndex )
			{
				_currentIndex = _buttons.size( ) - 1;

				if ( 0 > _currentIndex )
				{ _currentIndex = 0; }
			}

			UpdateButtons( );
		}
	}

	void ButtonGroup::RemoveLastButton( )
	{
		if ( _buttons.size( ) > 0 )
		{
			_buttons.erase( _buttons.end( ) - 1 );

			if ( _buttons.size( ) <= _currentIndex )
			{
				_currentIndex = _buttons.size( ) - 1;

				if ( 0 > _currentIndex )
				{ _currentIndex = 0; }
			}

			UpdateButtons( );
		}
	}

	unsigned int ButtonGroup::GetSize( ) const
	{ return _buttons.size( ); }

	void ButtonGroup::SetTheme( const MenuComponent::Theme &theme )
	{
		_theme = theme;

		for ( auto &button : _buttons )
		{ button->SetTheme( theme ); }
	}

	void ButtonGroup::MoveUp( const bool &cycleDown, const unsigned int &moveAmount )
	{
		if ( _currentIndex - ( int )moveAmount >= 0 )
		{ _currentIndex -= moveAmount; }
		else if ( cycleDown && _buttons.size( ) > 0 )
		{ _currentIndex = _buttons.size( ) - 1; }
			
		UpdateButtons( );
	}

	void ButtonGroup::MoveDown( const bool &cycleUp, const unsigned int &moveAmount )
	{
		if ( _currentIndex + moveAmount < _buttons.size( ) )
		{ _currentIndex += moveAmount; }
		else if ( cycleUp && _buttons.size( ) > 0 )
		{ _currentIndex = 0; }
		
		UpdateButtons( );
	}

	void ButtonGroup::JumpToIndex( const unsigned int &index )
	{
		if ( index < _buttons.size( ) )
		{ _currentIndex = index; }

		UpdateButtons( );
	}

	unsigned int ButtonGroup::GetCurrentIndex( ) const
	{ return _currentIndex; }

	void ButtonGroup::SetKeyboadEnabled( const bool &isEnabled )
	{ _isKeyboardEnabled = isEnabled; }

	void ButtonGroup::EnableKeyboard( )
	{ _isKeyboardEnabled = true; }

	void ButtonGroup::DisableKeyboard( )
	{ _isKeyboardEnabled = false; }

	void ButtonGroup::ToggleKeyboard( )
	{ _isKeyboardEnabled = !_isKeyboardEnabled; }

	const bool &ButtonGroup::IsKeyboardEnabled( )
	{ return _isKeyboardEnabled; }

	void ButtonGroup::UpdateButtons( )
	{
		spdlog::error( "NONNONONONONO" );

		for ( int i = 0; i < _buttons.size( ); i++ )
		{
			if ( i == _currentIndex )
			{ 
				auto button = _buttons.at( i );

				if ( _isCurrentButtonClicked )
				{ button->SetButtonStyle( button->GetClickedButtonStyle( ), false ); }
				else
				{ button->SetButtonStyle( button->GetHighlightedButtonStyle( ), false ); }
			}
			else
			{
				auto button = _buttons.at( i );
				button->SetButtonStyle( button->GetDefaultButtonStyle( ), false );
			}
		}
	}
}
