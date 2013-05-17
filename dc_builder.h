////////////////////////////////////////////////////////////////////////////////
// Author: Thomas Arndt monotomy@cythar.sequenzer.org
// This file is part of CYTHAR Sequenzer
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////////////

#ifndef DC_BUILDER_H_INCLUDED
#define DC_BUILDER_H_INCLUDED

#include <pattern/singleton.hpp>

class QApplication;

namespace dc{

    /***********************************************************************/
    //! \class Builder
    /***********************************************************************/
    class Builder {
    SINGLETON(Builder)

        QApplication        *_qtApp{nullptr};

    public:
        int  build() noexcept;
        void exec()  noexcept;
        int  end()   noexcept;

    private:
        int  build_dc();
        int  buildQtApp();
        int  buildQtGui()    noexcept;
        int  exec_ticker_eventloop() noexcept;
    };
}       // namespace dc
#endif // DC_BUILDER_H_INCLUDED
