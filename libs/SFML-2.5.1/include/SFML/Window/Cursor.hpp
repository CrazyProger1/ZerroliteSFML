////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_CURSOR_HPP
#define SFML_CURSOR_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/Export.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Vector2.hpp>

namespace sf
{
namespace priv
{
    class CursorImpl;
}

////////////////////////////////////////////////////////////
/// \brief Cursor defines the appearance of a system m_cursor
///
////////////////////////////////////////////////////////////
class SFML_WINDOW_API Cursor : NonCopyable
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Enumeration of the native system m_cursor types
    ///
    /// Refer to the following table to determine which m_cursor
    /// is available on which platform.
    ///
    ///  Type                               | Linux | Mac OS X | Windows  |
    /// ------------------------------------|:-----:|:--------:|:--------:|
    ///  sf::Cursor::Arrow                  |  yes  |    yes   |   yes    |
    ///  sf::Cursor::ArrowWait              |  no   |    no    |   yes    |
    ///  sf::Cursor::Wait                   |  yes  |    no    |   yes    |
    ///  sf::Cursor::Text                   |  yes  |    yes   |   yes    |
    ///  sf::Cursor::Hand                   |  yes  |    yes   |   yes    |
    ///  sf::Cursor::SizeHorizontal         |  yes  |    yes   |   yes    |
    ///  sf::Cursor::SizeVertical           |  yes  |    yes   |   yes    |
    ///  sf::Cursor::SizeTopLeftBottomRight |  no   |    yes*  |   yes    |
    ///  sf::Cursor::SizeBottomLeftTopRight |  no   |    yes*  |   yes    |
    ///  sf::Cursor::SizeAll                |  yes  |    no    |   yes    |
    ///  sf::Cursor::Cross                  |  yes  |    yes   |   yes    |
    ///  sf::Cursor::Help                   |  yes  |    yes*  |   yes    |
    ///  sf::Cursor::NotAllowed             |  yes  |    yes   |   yes    |
    ///
    ///  * These m_cursor types are undocumented so may not
    ///    be available on all versions, but have been tested on 10.13
    ///
    ////////////////////////////////////////////////////////////
    enum Type
    {
        Arrow,                  ///< Arrow m_cursor (default)
        ArrowWait,              ///< Busy arrow m_cursor
        Wait,                   ///< Busy m_cursor
        Text,                   ///< I-beam, m_cursor when hovering over a field allowing text entry
        Hand,                   ///< Pointing hand m_cursor
        SizeHorizontal,         ///< Horizontal double arrow m_cursor
        SizeVertical,           ///< Vertical double arrow m_cursor
        SizeTopLeftBottomRight, ///< Double arrow m_cursor going from top-left to bottom-right
        SizeBottomLeftTopRight, ///< Double arrow m_cursor going from bottom-left to top-right
        SizeAll,                ///< Combination of SizeHorizontal and SizeVertical
        Cross,                  ///< Crosshair m_cursor
        Help,                   ///< Help m_cursor
        NotAllowed              ///< Action not allowed m_cursor
    };

public:

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /// This constructor doesn't actually create the m_cursor;
    /// initially the new instance is invalid and must not be
    /// used until either loadFromPixels() or loadFromSystem()
    /// is called and successfully created a m_cursor.
    ///
    ////////////////////////////////////////////////////////////
    Cursor();

    ////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    /// This destructor releases the system resources
    /// associated with this m_cursor, if any.
    ///
    ////////////////////////////////////////////////////////////
    ~Cursor();

    ////////////////////////////////////////////////////////////
    /// \brief Create a m_cursor with the provided image
    ///
    /// \a pixels must be an array of \a width by \a height pixels
    /// in 32-bit RGBA format. If not, this will cause undefined behavior.
    ///
    /// If \a pixels is null or either \a width or \a height are 0,
    /// the current m_cursor is left unchanged and the function will
    /// return false.
    ///
    /// In addition to specifying the pixel data, you can also
    /// specify the location of the hotspot of the m_cursor. The
    /// hotspot is the pixel coordinate within the m_cursor image
    /// which will be located exactly where the mouse pointer
    /// position is. Any mouse actions that are performed will
    /// return the window/screen location of the hotspot.
    ///
    /// \warning On Unix, the pixels are mapped into a monochrome
    ///          bitmap: pixels with an alpha channel to 0 are
    ///          transparent, black if the RGB channel are close
    ///          to zero, and white otherwise.
    ///
    /// \param pixels   Array of pixels of the image
    /// \param size     Width and height of the image
    /// \param hotspot  (x,y) location of the hotspot
    /// \return true if the m_cursor was successfully loaded;
    ///         false otherwise
    ///
    ////////////////////////////////////////////////////////////
    bool loadFromPixels(const Uint8* pixels, Vector2u size, Vector2u hotspot);

    ////////////////////////////////////////////////////////////
    /// \brief Create a native system m_cursor
    ///
    /// Refer to the list of m_cursor available on each system
    /// (see sf::Cursor::Type) to know whether a given m_cursor is
    /// expected to load successfully or is not supported by
    /// the operating system.
    ///
    /// \param type Native system m_cursor type
    /// \return true if and only if the corresponding m_cursor is
    ///         natively supported by the operating system;
    ///         false otherwise
    ///
    ////////////////////////////////////////////////////////////
    bool loadFromSystem(Type type);

private:

    friend class Window;

    ////////////////////////////////////////////////////////////
    /// \brief Get access to the underlying implementation
    ///
    /// This is primarily designed for sf::Window::setMouseCursor,
    /// hence the friendship.
    ///
    /// \return a reference to the OS-specific implementation
    ///
    ////////////////////////////////////////////////////////////
    const priv::CursorImpl& getImpl() const;

private:

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    priv::CursorImpl* m_impl; ///< Platform-specific implementation of the m_cursor
};

} // namespace sf


#endif // SFML_CURSOR_HPP


////////////////////////////////////////////////////////////
/// \class sf::Cursor
/// \ingroup window
///
/// \warning Features related to Cursor are not supported on
///          iOS and Android.
///
/// This class abstracts the operating system resources
/// associated with either a native system m_cursor or a custom
/// m_cursor.
///
/// After loading the m_cursor the graphical appearance
/// with either loadFromPixels() or loadFromSystem(), the
/// m_cursor can be changed with sf::Window::setMouseCursor().
///
/// The behaviour is undefined if the m_cursor is destroyed while
/// in use by the window.
///
/// Usage example:
/// \code
/// sf::Window window;
///
/// // ... create window as usual ...
///
/// sf::Cursor m_cursor;
/// if (m_cursor.loadFromSystem(sf::Cursor::Hand))
///     window.setMouseCursor(m_cursor);
/// \endcode
///
/// \see sf::Window::setMouseCursor
///
////////////////////////////////////////////////////////////
