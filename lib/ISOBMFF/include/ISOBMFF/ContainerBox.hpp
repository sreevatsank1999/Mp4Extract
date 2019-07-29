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
 * @header      ContainerBox.hpp
 * @copyright   (c) 2017, DigiDNA - www.digidna.net
 * @author      Jean-David Gadina - www.digidna.net
 */

#ifndef ISOBMFF_CONTAINER_BOX_HPP
#define ISOBMFF_CONTAINER_BOX_HPP

#include <XS/PIMPL/Object.hpp>
#include <ISOBMFF/Macros.hpp>
#include <ISOBMFF/Box.hpp>
#include <ISOBMFF/Container.hpp>
#include <vector>
#include <memory>
#include <ostream>

namespace ISOBMFF
{
    class ISOBMFF_EXPORT ContainerBox: public Box, public Container, public XS::PIMPL::Object< ContainerBox >
    {
        public:
            
            using XS::PIMPL::Object< ContainerBox >::impl;

            ContainerBox( const std::string & name );
            
            void ReadData( Parser & parser, BinaryStream & stream ) override;
            void WriteDescription( std::ostream & os, std::size_t indentLevel ) const override;
            
            void                                  AddBox( std::shared_ptr< Box > box ) override;
            std::vector< std::shared_ptr< Box > > GetBoxes( void ) const override;
    };
}

#endif /* ISOBMFF_CONTAINER_BOX_HPP */
