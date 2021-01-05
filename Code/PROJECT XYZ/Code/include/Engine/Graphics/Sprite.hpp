#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <External/glm/glm.hpp>

#include "Graphics/Drawable.hpp"
#include "Graphics/Texture.hpp"

namespace Sonar
{
    class Sprite : public Drawable
    {
    public:
        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        Sprite( GameDataRef data );

        /**
        * \brief Class constructor
        *
        * \param data Game data object
        * \param filePath Texture file path
        */
        Sprite( GameDataRef data, const std::string &filepath );

        /**
        * \brief Class constructor
        *
        * \param data Game data object
        * \param texture Another texture to be copied onto the local texture
        */
        Sprite( GameDataRef data, Texture *texture );

        /**
        * \brief Class destructor
        */
        ~Sprite( );

        /**
        * \brief Set the position (x and y)
        *
        * \param x X position
        * \param y Y position
        */
        void SetPosition( const float &x, const float &y );

        /**
        * \brief Set the x position
        *
        * \param x X position
        */
        void SetPositionX( const float &x );

        /**
        * \brief Set the y position
        *
        * \param y Y position
        */
        void SetPositionY( const float &y );

        /**
        * \brief Set the color
        *
        * \param color Color object
        */
        void SetColor( const Color &color );

        /**
        * \brief Get the color
        *
        * \return Output returns the color
        */
        Color GetColor( ) const;

        /**
        * \brief Move the object relative to it's current position in the x and y axis
        *
        * \param x Offset in x axis
        * \param y Offset in y axis
        */
        void Move( const float &x, const float &y );

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
        * \brief Set the sprite texture from a file
        *
		* \param filePath Location of image to be applied
		* \param resetRect Whether or not the texture rect should be reset (default set to false)
        */
		void SetTexture( const std::string &filepath, const bool &resetRect = false );

        /**
        * \brief Set the sprite texture from an existing Texture object
        *
        * \param texture Another texture to be copied onto the local texture
        * \param resetRect Whether or not the texture rect should be reset (default set to false)
        */
		void SetTexture( Texture *texture, const bool &resetRect = false );

        /**
        * \brief Set the sprite rectangle
        *
        * \param rectangle Vector 4 of integers (left, top, width and height)
        */
        void SetTextureRect( const glm::ivec4 &rectangle );

        /**
        * \brief Set the sprite rectangle
        *
		* \param left Top left corner x value
		* \param top Top left corner y value
		* \param width Rectangles width
		* \param height Rectangles height
        */
        void SetTextureRect( const int &left, const int &top, const int &width, const int &height );

        /**
        * \brief Get the Texture object
        *
        * \return Output returns the sprite's texture object
        */
        Texture *GetTexture( ) const;

        /**
        * \brief Get the Textures rectangle
        *
        * \return Output returns the sprite's texture rectangle
        */
		glm::ivec4 GetTextureRect( ) const;

        /**
        * \brief Get the Textures local bounds
        *
        * \return Output returns the sprite's texture local bounds
        */
		glm::vec4 GetLocalBounds( ) const;

        /**
        * \brief Get the Textures global bounds
        *
        * \return Output returns the sprite's texture global bounds
        */
        glm::vec4 GetGlobalBounds( ) const;

    private:
        /**
        * \brief Sprite for the class
        */
        sf::Sprite _sprite;

        /**
        * \brief Texture for loading an image to be assigned to the sprite
        */
        Texture *_texture;

    };
}
