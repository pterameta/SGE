#include "pch.hpp"

namespace Sonar
{
	void Clock::Reset( )
	{ _clock.restart( ); }

	const Time Clock::GetElapsedTime( ) const
	{ return Time( _clock.getElapsedTime( ).asMicroseconds( ) ); }
}
