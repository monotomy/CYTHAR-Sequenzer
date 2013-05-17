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

#include <extendQt_drag_n_drop.2moc.h>

#include <dc_standard_values.h>

namespace extendQt{

//!\class DragObject
    DragObject
    ::DragObject(UNIQUE_BASE*const source_object__) :
        _source_object{source_object__}
    {}

    UNIQUE_BASE* DragObject
    ::source() const noexcept
    {
        return _source_object;
    }

    TYPE_vector_additional_steprow_drag_data const& DragObject
    ::additional_steprow_objects() const noexcept
    {
        return _source_steprow_objects;
    }

    TYPE_vector_additional_numeric_drag_data const& DragObject
    ::additional_data_vector() const noexcept
    {
        return _sorce_data_vector;
    }

//!\class DRAGnDROP_QWidget
    DRAGnDROP_QWidget
    ::DRAGnDROP_QWidget()
    {
        setAcceptDrops(true);
    }

    void DRAGnDROP_QWidget
    ::mouseMoveEvent(QMouseEvent *event__)  noexcept
    {
        if (!(event__->buttons() & Qt::LeftButton))
            return;

        QDrag *drag = new QDrag(this);
        // Setzen der Cythar Objecte
        DragObject *drag_object = new DragObject(unique_source_object2drag());
        // für spätere this-> drop prüfungen
        drag_object->_drag_source_widget = this;
        // Setzen eines Textexports
        drag_object->setText(QString::fromStdString(additional_drag_text()));
        // Setzen der Info Url
        //drag_object->setUrls(QList<QUrl>{additional_drag_url()});

        // Manual filename setzen
        drag_object->_doc_file_name = doc_file_name();
        // Weitere Daten, welche gedragt werden können
        drag_object->_source_steprow_objects = additional_steprow_drag_data();
        drag_object->_sorce_data_vector = additional_numeric_drag_data();

        // Setzen der Drag Pixmap
        drag_object->_backup_pixmap = drag_pixmap();
        //drag_object->setImageData(drag_object->_backup_pixmap);
        drag->setMimeData(drag_object);

        // Hängt die Pixmap als Dragvisualisierung an
        drag->setPixmap(drag_object->_backup_pixmap);
        drag->exec();
    }

    UNIQUE_BASE* DRAGnDROP_QWidget
    ::unique_source_object2drag() const noexcept
    {
        static EmptyBase* empty_base{new EmptyBase()};
        return empty_base;
    }

    QUrl DRAGnDROP_QWidget
    ::additional_drag_url() const noexcept
    {
        return QUrl(CYTHAR_MAIN_URL.c_str());
    }

    std::string DRAGnDROP_QWidget
    ::additional_drag_text() const noexcept
    {
        return CYTHAR_MAIN_URL;
    }

    std::string DRAGnDROP_QWidget
    ::doc_file_name() const noexcept
    {
        return DOC_MANUAL_COMPLETE;
    }

    TYPE_vector_additional_steprow_drag_data DRAGnDROP_QWidget
    ::additional_steprow_drag_data() const noexcept
    {
        return {};
    }

    TYPE_vector_additional_numeric_drag_data DRAGnDROP_QWidget
    ::additional_numeric_drag_data() const noexcept
    {
        return {};
    }

    QPixmap DRAGnDROP_QWidget
    ::drag_pixmap() noexcept
    {
        return std::move(QPixmap::grabWidget(this));
    }

    void DRAGnDROP_QWidget
    ::clean_accepter() noexcept
    {
        drop_has_same_type = false;
        drop_has_steprow_data = false;
        drop_has_additional_numeric_data = false;
    }

    void DRAGnDROP_QWidget
    ::dragEnterEvent(QDragEnterEvent *event__) noexcept
    {
        clean_accepter();

        // Akzeptiert keine anderen Drops
        if(dynamic_cast<DragObject const*>(event__->mimeData()) == false)
            return;

        auto drag_object(static_cast<DragObject const*>(event__->mimeData()));

        // Prüfen ob nicht in sich selbst gedropt wird
        if(drag_object->_drag_source_widget == this
           or drag_object->_drag_source_widget == nullptr)
            return;

        // Prüfung auf Typegleichhet
        if(this->compare_is_source_in_target_dropable(drag_object))
        {
            drop_has_same_type = true;
            event__->acceptProposedAction();
        }
        // Prüfung auf Steprow Daten
        else if(this->compare_is_steprow_data_dropable(drag_object))
        {
            drop_has_steprow_data = true;
            event__->acceptProposedAction();
        }
        // Prüfung auf erweiterte Daten
        else if(this->compare_is_additional_data_dropable(drag_object))
        {
            drop_has_additional_numeric_data = true;
            event__->acceptProposedAction();
        }
    }

    bool DRAGnDROP_QWidget
    ::compare_is_source_in_target_dropable(DragObject const*) const noexcept
    {
        return false;
    }

    bool DRAGnDROP_QWidget
    ::compare_is_steprow_data_dropable(DragObject const*) const noexcept
    {
        return false;
    }

    bool DRAGnDROP_QWidget
    ::compare_is_additional_data_dropable(DragObject const*) const noexcept
    {
        return false;
    }

    void DRAGnDROP_QWidget
    ::dropEvent(QDropEvent *event__) noexcept
    {
        DragObject const* drag_source_object(static_cast<DragObject const*>(event__->mimeData()));
        if(drop_has_same_type)
            same_type_is_dropped(drag_source_object);

        else if(drop_has_steprow_data)
            additional_steprow_is_dropped(drag_source_object->additional_steprow_objects());

        else if(drop_has_additional_numeric_data)
            additional_data_is_dropped(drag_source_object->additional_data_vector());

        clean_accepter();
    }
}
