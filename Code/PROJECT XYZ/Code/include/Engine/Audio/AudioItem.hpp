/*
* EVERY CLASS INHERITING AUDIOITEM
* Music
* Sound
*/

#pragma once

namespace Sonar
{
    /**
    * \brief Status of the audio
    */
    enum AUDIO_STATUS
    {
        STOPPED = 0,
        PAUSED,
        PLAYING
    };

    enum AUDIO_TYPE
    {
        MUSIC = 0,
        SOUND
    };

    class AudioItem
    {
    public:
        /**
        * \brief Set audio file
        *
        * \param filepath Filepath of the file
        */
        void LoadFile( const std::string &filepath );

        /**
        * \brief Get the filepath of the currently loaded audio file
        *
        * \return Output returns the audio filepath
        */
        [[nodiscard]] const std::string &GetFilepath( ) const;

        /**
        * \brief Play the audio item
        */
        void Play( );

        /**
        * \brief Pause the audio item
        */
        void Pause( );

        /**
        * \brief Stop the audio item
        */
        void Stop( );

        /**
        * \brief Restart audio item
        */
        void Restart( );

        /**
        * \brief Set volume (0 - 100)
        *
        * \param volume Audio item's volume
        */
        void SetVolume( const float &volume );

        /**
        * \brief Get volume
        */
        [[nodiscard]] const float GetVolume( ) const;

        /**
        * \brief Set pitch
        * 
         * \param pitch Pitch of the audio item
        */
        void SetPitch( const float &pitch );

        /**
        * \brief Get pitch
        *
        * \return Output returns the pitch
        */
        [[nodiscard]] const float &GetPitch( ) const;

        /**
        * \brief Get the status of the audio item
        */
        [[nodiscard]] const AUDIO_STATUS &GetStatus( ) const;

        /**
        * \brief Set attenuation
        *
        * \param attenuation Attenuation for sound item
        */
        void SetAttenuation( const float &attenuation );

        /**
        * \brief Get the attenuation
        *
        * \return Output returns the attenuation
        */
        [[nodiscard]] const float &GetAttenuation( ) const;

        /**
        * \brief Set x, y and z position
        *
        * \param position X, Y and Z position
        */
        void SetPosition( const glm::vec3 &position );

        /**
		* \brief Set x, y and z position
        *
        * \param x X position
		* \param y Y position
		* \param z Z position
        */
        void SetPosition( const float &x, const float &y, const float &z );

        /**
        * \brief Set x position
        *
        * \param x X position
        */
        void SetPositionX( const float &x );

        /**
        * \brief Set y position
        *
        * \param y Y position
        */
        void SetPositionY( const float &y );

        /**
        * \brief Set z position
        *
        * \param z Z position
        */
        void SetPositionZ( const float &z );

        /**
		* \brief Get the x position
		*
        * \return Output returns the x position
        */
        [[nodiscard]] const float &GetPositionX( ) const;

        /**
		* \brief Get the y position
        *
        * \return Output returns the y position
        */
        [[nodiscard]] const float &GetPositionY( ) const;

        /**
        * \brief Get the z position
        *
        * \return Output returns the z position
        */
        [[nodiscard]] const float &GetPositionZ( ) const;

        /**
        * \brief Get the position vector
        *
        * \return Output returns the position vector
        */
        [[nodiscard]] const glm::vec3 &GetPosition( ) const;

        /**
        * \brief Move the object relative to it's current position in the x, y and z axis
        *
        * \param offset Offset in x, y and z axis
        */
        void Move( const glm::vec3 &offset );

        /**
		* \brief Move the object relative to it's current position in the x, y and z axis
        *
        * \param x Offset in x axis
		* \param y Offset in y axis
		* \param z Offset in z axis
        */
        void Move( const float &x, const float &y, const float &z );

        /**
        * \brief Move the object relative to it's current position in the x axis
        *
        * \param x Offset in x axis
        */
        void MoveX( const float &x );

        /**
        * \brief Move the object relative to it's current position in the y axis
        *
        * \param y Offset in y axis
        */
        void MoveY( const float &y );

        /**
        * \brief Move the object relative to it's current position in the z axis
        *
        * \param z Offset in z axis
        */
        void MoveZ( const float &z );

    protected:
        /**
        * \brief Class constructor
        */
        AudioItem( const AUDIO_TYPE &audioType );

        /**
        * \brief Class destructor
        */
        ~AudioItem( );

        /**
        * \brief Object to be listened to
        */
        sf::SoundStream *_musicObject;
        sf::SoundSource *_soundObject;

    private:
        /**
        * \brief Filepath of the music file
        */
        std::string _filepath;

        /**
        * \brief Is the audio item a music or sound item (true for music, false for sound)
        */
        bool _isMusic;

    };
}

