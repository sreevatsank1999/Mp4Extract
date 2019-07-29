/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2017 DigiDNA - www.digidna.net
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @header      COLR.hpp
 * @copyright   (c) 2017, DigiDNA - www.digidna.net
 * @author      Jean-David Gadina - www.digidna.net
 */

#ifndef ISOBMFF_COLR_HPP
#define ISOBMFF_COLR_HPP

#include <XS/PIMPL/Object.hpp>
#include <ISOBMFF/Macros.hpp>
#include <ISOBMFF/Box.hpp>
#include <string>
#include <cstdint>
#include <vector>

namespace ISOBMFF
{
    class ISOBMFF_EXPORT COLR: public Box, public XS::PIMPL::Object< COLR >
    {
        public:
            
            using XS::PIMPL::Object< COLR >::impl;
            
            COLR( void );
            
            void                                                 ReadData( Parser & parser, BinaryStream & stream ) override;
            std::vector< std::pair< std::string, std::string > > GetDisplayableProperties( void ) const override;
            
            std::string            GetColourType( void )              const;
            uint16_t               GetColourPrimaries( void )         const;
            uint16_t               GetTransferCharacteristics( void ) const;
            uint16_t               GetMatrixCoefficients( void )      const;
            bool                   GetFullRangeFlag( void )           const;
            std::vector< uint8_t > GetICCProfile( void )              const;
            
            void SetColourType( const std::string & value );
            void SetColourPrimaries( uint16_t value );
            void SetTransferCharacteristics( uint16_t value );
            void SetMatrixCoefficients( uint16_t value );
            void SetFullRangeFlag( bool value );
            void SetICCProfile( const std::vector< uint8_t > & value );
    };
}

#endif /* ISOBMFF_COLR_HPP */
