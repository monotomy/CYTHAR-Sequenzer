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

#ifndef DC_GUI_DRAG_N_DROP_H_INCLUDED
#define DC_GUI_DRAG_N_DROP_H_INCLUDED

#include <uniques.hpp>

#include <class/properties.hpp>

#include <dc_standard_values.h>
#include <dc_objectstructure.h>

#include <QWidget>
#include <QDrag>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QPixmap>
#include <QString>
#include <QList>
#include <QUrl>

#include <array>

#include <iostream>

namespace extendQt{

    /***********************************************************************/
    /*! \class  DragObject

        Transportiert das Sourcobjekt
        Über die is_copy_compatible_to_source Funktion, wird das target
        auf compatibilität zum sorce untersucht.

        Weitere Daten können in einem Vector transportiert werden.
    */
    /***********************************************************************/
    typedef std::vector<TYPE_offset> TYPE_vector_additional_numeric_drag_data;
    // Enthält 6 Steps in vertikaler Richtung
    typedef std::vector<dc_objects::Step const*> TYPE_vector_additional_steprow_drag_data;

    class DRAGnDROP_QWidget;
    class DragObject : // NOMOVECOPY
        public QMimeData
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(DragObject)

        // Typegleiche Elemente
        UNIQUE_BASE*const _source_object{nullptr};

        // Accorddaten & weitere Nummerics
        TYPE_vector_additional_numeric_drag_data _sorce_data_vector{};
        // Steprow
        TYPE_vector_additional_steprow_drag_data _source_steprow_objects{};

        DRAGnDROP_QWidget const* _drag_source_widget{nullptr};

        friend class DRAGnDROP_QWidget;
        DragObject(UNIQUE_BASE*const source_object__);
        ~DragObject() = default;

    public:
        //! Vergleicht die Liste des Targets mit der Unique Id des Source und
        //! prüft die copy-Kompatibilität.
        template<class Type_target_with_unique_copyCompatibilityList>
        inline bool is_target_copy_compatible_to_source(Type_target_with_unique_copyCompatibilityList*const target__) const noexcept
        {
            enum : bool
            {
                IS_COMPATIBLE = true,
                NOT_COMPATIBLE = false
            };

            for(auto compatible_unique : target__->_unique_list)
                if(_source_object->unique_id() == compatible_unique)
                    return IS_COMPATIBLE;

            return NOT_COMPATIBLE;
        }

        //! Rückgabe der gedragten daten oder objecte
        UNIQUE_BASE* source() const noexcept;
        TYPE_vector_additional_steprow_drag_data const& additional_steprow_objects() const noexcept;
        TYPE_vector_additional_numeric_drag_data const& additional_data_vector() const noexcept;

        //! Zwischenspeicher der DragNdrop Pixmap
        QPixmap _backup_pixmap{};
        std::string _doc_file_name{};
    };

    /***********************************************************************/
    /*! \class  DRAGnDROP_QWidget

    */
    /***********************************************************************/
    class DRAGnDROP_CLIPBOARD {};
    class DRAGnDROP_QWidget :
        public QWidget
    {
    Q_OBJECT

    protected:
        DRAGnDROP_QWidget();
        ~DRAGnDROP_QWidget() = default;

    private:
        //! Dragauslöser, Dragobject datenzusammenstellung
        virtual void mouseMoveEvent(QMouseEvent *event__)  noexcept override;

        //! Gibt UNIQUE_BASE (EmptyBase) zurück, wenn nicht überladen
        virtual UNIQUE_BASE* unique_source_object2drag() const noexcept;

        //! URL erweiterng
        virtual QUrl additional_drag_url() const noexcept;
        //! Textexport erweiterng
        virtual std::string additional_drag_text() const noexcept;
        //! Doc Transort
        virtual std::string doc_file_name() const noexcept;
        //! Steprow drag&drop erweiterng
        virtual TYPE_vector_additional_steprow_drag_data additional_steprow_drag_data() const noexcept;
        //! Accord Offset drag&drop erweiterng
        virtual TYPE_vector_additional_numeric_drag_data additional_numeric_drag_data() const noexcept;

    public:
        //! Weclches Bild wird dem DragPointer angehangen
        virtual QPixmap drag_pixmap() noexcept;
    private:

        //! Drop Accepter, nur eine Art vo Daten kann gedroppt werden
        bool drop_has_same_type{false};
        bool drop_has_steprow_data{false};
        bool drop_has_additional_numeric_data{false};
        virtual void dragEnterEvent(QDragEnterEvent *event__) noexcept override;

        void clean_accepter() noexcept;

        //! Prüfung ob sich ein Object dropen lässt, wie -> prüft der Erbe ELSE false
        virtual bool compare_is_source_in_target_dropable(DragObject const* drag_source_object__) const noexcept;
        virtual bool compare_is_steprow_data_dropable(DragObject const* drag_source_object__) const noexcept;
        virtual bool compare_is_additional_data_dropable(DragObject const* drag_source_object__) const noexcept;

        //! Do at Drop
        virtual void dropEvent(QDropEvent *event__) noexcept override;

        //! Der Erbe übernimmt die Steuerung was bei einem Drop geschiet.
        virtual void same_type_is_dropped(DragObject const*) noexcept {};
        virtual void additional_steprow_is_dropped(TYPE_vector_additional_steprow_drag_data const&) noexcept {};
        virtual void additional_data_is_dropped(extendQt::TYPE_vector_additional_numeric_drag_data const&) noexcept {};
    };


    //! HELPERMAKROS ***********************************************************************
    //! Virtuelle Drag-Methode für relOBServer - Observertype angeben
    // -> override unique_source_object2drag()
    #define DRAGnDROP___relOBSERVER___DRAG_FROM_THIS_OBSERVER(ARG_relOBSERVER_TYPE) \
    virtual UNIQUE_BASE* unique_source_object2drag() const noexcept override \
    { \
        return relOBS_(ARG_relOBSERVER_TYPE); \
    }

    //! Virtuelle Accepter-Methode für relOBServer - Observertype angeben
    // -> override compare_is_source_in_target_dropable()
    #define DRAGnDROP___relOBSERVER___ACCEPT_DROPS_FROM(ARG_relOBSERVER_TYPE) \
    virtual bool compare_is_source_in_target_dropable(extendQt::DragObject const* drag_source_object__) const noexcept override \
    { \
        return drag_source_object__->is_target_copy_compatible_to_source(relOBS_(ARG_relOBSERVER_TYPE)); \
    }

    //! Virtuelle Drop-Methode für relOBServer - Observertype angeben
    //! Überschreibt das Observierte Objekt mit dem gedroppten SourceObjekt
    //! Kopiert die Daten der Childs und Childs_ofChilds in konfigurierter Tiefe
    #define DRAGnDROP___relOBSERVER___COPY_sourceDROP_2Me(ARG_relOBSERVER_TYPE) \
    virtual void same_type_is_dropped(extendQt::DragObject const* drag_source_object__) noexcept override \
    { \
        auto source(static_cast<typename ARG_relOBSERVER_TYPE::TYPE_Object2Observe_T*>(drag_source_object__->source())); \
        /* Kopiert die eigenen Daten */ \
        relOBS_(ARG_relOBSERVER_TYPE)->copy_from_source(source); \
        /* Kopiert die Daten der Childs Child_copyDEEPNEES */ \
        relOBS_(ARG_relOBSERVER_TYPE)->copy_childdata_from_source(source, \
                                                                  copyDEEPNESS_(ARG_relOBSERVER_TYPE::TYPE_Object2Observe_T::CHILD_COPY_DEEPNESS)); \
    }
}

#endif // DC_GUI_DRAG_N_DROP_H_INCLUDED
