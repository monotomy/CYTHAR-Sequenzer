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

#ifndef DC_OBJECTOBSERVER_H_INCLUDED
#define DC_OBJECTOBSERVER_H_INCLUDED

#include <objectobserver.h>

#include <dc_objectstructure.h>
#include <dc_gui_inits.h>

namespace dc_objects{

    /***********************************************************************/
    /*! \class RelativStepObserver_V2
    */
    /***********************************************************************/
//!\SelectedStepObserver_V2
    typedef SelectedObjectObserver_V2<TemporaryPropertiesIndex::SELECTED_STEP> SelectedStepObserver_V2;

//!\RelativeStepObserver_V2
    struct ChangedRelativeStep_depend_onSELECTED_TAKT_policy
    {
    //NOT_INSTANCEABLE(ChangedRelativeStep_depend_onSELECTED_TAKT_policy)

    template<class THIS>
    static void change(THIS *const this__) noexcept
    {
        this__->detach_at_relative_observedObject();

        auto relative_observedStep(tmpGET_(SELECTED_TAKT)
                                        ->taktsaite(this__->_absolut_parent_id)
                                            ->step(this__->_absolut_id_in_parent));

        this__->attach_at_relative_observedObject(relative_observedStep);
    }};

    typedef RelativObjectObserver_V2
    <
        Step,
        TemporaryPropertiesIndex::SELECTED_STEP,
        TemporaryPropertiesIndex::SELECTED_TAKT,
        ChangedRelativeStep_depend_onSELECTED_TAKT_policy,
        GenElementId_perSaiteId<Step_per_Taktsaite, typename Step::TYPE_UNIQUE_T>
    >
    RelativeStepObserver_V2;

//!\SelecteddetailStepObserver_V2
    typedef RelativObjectObserver_V2
    <
        Step,
        TemporaryPropertiesIndex::SELECTED_STEP,
        TemporaryPropertiesIndex::SELECTED_STEP,
        ChangedRelativeObserver_forSelectedDetailObserver_policy<TemporaryPropertiesIndex::SELECTED_STEP>,
        GenZeroId<TYPE_NOT_UNIQUE>
    >
    SelecteddetailStepObserver_V2;

    /***********************************************************************/
    /*! \class TaktchainObserver_V2
    */
    /***********************************************************************/
//!\SelectedTaktchainObserver_V2
    typedef SelectedObjectObserver_V2<TemporaryPropertiesIndex::SELECTED_TAKTCHAIN> SelectedTaktchainObserver_V2;

//!\RelativeTaktchainObserver_V2
    struct ChangedRelativeTaktchain_depend_onSELECTED_PATTERN_policy{ template<class THIS>
    static void change(THIS *const this__) noexcept
    {
        this__->detach_at_relative_observedObject();

        auto relative_observedTaktchain(tmpGET_(SELECTED_PATTERN)
                                            ->takt(this__->_absolut_id_in_parent)
                                                ->taktchain(tmpGET_(SELECTED_TAKTCHAIN_LEVEL_ID)));
                                            //->GET_PROPERTY_(Temporary,SELECTED_TAKT)
                                              //  ->taktchain(0));
                                                //->taktchain(this__->_absolut_id_in_parent));

        this__->attach_at_relative_observedObject(relative_observedTaktchain);
    }};

//!\RelativeTaktchainObserver_V2
    template
    <
        class UNIQUE_GEN_RELATIVE_ID
    >
    using RelativeTaktchainObserver_V2
    = RelativObjectObserver_V2
    <
        Taktchain,
        TemporaryPropertiesIndex::SELECTED_TAKTCHAIN,
        TemporaryPropertiesIndex::SELECTED_PATTERN,
        ChangedRelativeTaktchain_depend_onSELECTED_PATTERN_policy,
        GenElementId_perSaiteId<Taktchain_per_Takt, UNIQUE_GEN_RELATIVE_ID>
    >;

    /***********************************************************************/
    /*! \class TaktsaiteObserver_V2
    */
    /***********************************************************************/
//!\SelectedTaktsaiteObserver_V2
    typedef SelectedObjectObserver_V2<TemporaryPropertiesIndex::SELECTED_TAKTSAITE> SelectedTaktsaiteObserver_V2;

//!\RelativeTaktsaiteObserver_V2
    struct ChangedRelativeTaktsaite_depend_onSELECTED_PATTERN_policy{ template<class THIS>
    static void change(THIS *const this__) noexcept
    {
        this__->detach_at_relative_observedObject();

        auto relative_observedTaktsaite(Temporary::singleton()
                                            ->GET_PROPERTY_(Temporary,SELECTED_PATTERN)
                                                ->takt(this__->_absolut_parent_id)
                                                    ->taktsaite(this__->_absolut_id_in_parent));

        this__->attach_at_relative_observedObject(relative_observedTaktsaite);
    }};

//!\RelativeTaktsaiteObserver_V2
    typedef RelativObjectObserver_V2
    <
        Taktsaite,
        TemporaryPropertiesIndex::SELECTED_TAKTSAITE,
        TemporaryPropertiesIndex::SELECTED_PATTERN,
        ChangedRelativeTaktsaite_depend_onSELECTED_PATTERN_policy,
        Gen_saite_id_over_parents<1, Taktsaiten_per_Patternsaite, typename Taktsaite::TYPE_UNIQUE_T>
    >
    RelativeTaktsaiteObserver_V2;

    /***********************************************************************/
    /*! \class TaktObserver_V2
    */
    /***********************************************************************/
//!\SelectedTaktObserver_V2
    typedef SelectedObjectObserver_V2<TemporaryPropertiesIndex::SELECTED_TAKT> SelectedTaktObserver_V2;

    struct ChangedRelativeTakt_depend_onSELECTED_PATTERN_policy{ template<class THIS>
    static void change(THIS *const this__) noexcept
    {
        this__->detach_at_relative_observedObject();

        auto relative_observedTakt(tmpGET_(SELECTED_PATTERN)
                                            ->takt(this__->_absolut_id_in_parent));

        this__->attach_at_relative_observedObject(relative_observedTakt);
    }};

//!\RelativeTaktObserver_V2
    template
    <
        class UNIQUE_GEN_RELATIVE_ID
    >
    using RelativeTaktObserver_V2
    = RelativObjectObserver_V2
    <
        Takt,
        TemporaryPropertiesIndex::SELECTED_TAKT,
        TemporaryPropertiesIndex::SELECTED_PATTERN,
        ChangedRelativeTakt_depend_onSELECTED_PATTERN_policy,
        GenElementId_perSaiteId<Takt_per_Pattern, UNIQUE_GEN_RELATIVE_ID>
    >;

//!\SelecteddetailTaktObserver_V2
    template
    <
        class UNIQUE_GEN_RELATIVE_ID
    >
    using SelecteddetailTaktObserver_V2
    = RelativObjectObserver_V2
    <
        Takt,
        TemporaryPropertiesIndex::SELECTED_TAKT,
        TemporaryPropertiesIndex::SELECTED_TAKT,
        ChangedRelativeObserver_forSelectedDetailObserver_policy<TemporaryPropertiesIndex::SELECTED_TAKT>,
        GenEndlessLinearId<UNIQUE_GEN_RELATIVE_ID>
    >;

    /***********************************************************************/
    /*! \class PatternsaiteObserver_V2
    */
    /***********************************************************************/
//!\RelativPatternsaiteObserver_V2
    struct ChangedRelativePatternsaite_depend_onSELECTED_PATTERN_policy{ template<class THIS>
    static void change(THIS *const this__) noexcept
    {
        this__->detach_at_relative_observedObject();

        auto relative_observedPatternsaite(tmpGET_(SELECTED_PATTERN)
                                                ->patternsaite(this__->_absolut_id_in_parent));

        this__->attach_at_relative_observedObject(relative_observedPatternsaite);
    }};

    template
    <
        class UNIQUE_GEN_RELATIVE_ID
    >
    using RelativePatternsaiteObserver_V2
    = RelativObjectObserver_V2
    <
        Patternsaite,
        TemporaryPropertiesIndex::SELECTED_PATTERNSAITE,
        TemporaryPropertiesIndex::SELECTED_PATTERN,
        ChangedRelativePatternsaite_depend_onSELECTED_PATTERN_policy,
        GenEndlessLinearId<UNIQUE_GEN_RELATIVE_ID>
    >;

//!\AbsolutPatternObserver_V2
    //! Ändert das observierte Pattern per absoluter Id / child Id
    template<class IS_A_DUMMY = TYPE_NOT_UNIQUE>
    struct ChangedAbsolutObservedPatternsaite_policy{ template<class THIS>
    static void change(THIS *const) noexcept{

    }};

    typedef AbsolutObjectObserver
    <
        Patternsaite,
        TemporaryPropertiesIndex::SELECTED_PROJECT,
        ChangedAbsolutObservedPatternsaite_policy<TYPE_NOT_UNIQUE>
    >
    AbsolutPatternsaiteObserver_V2;

    /***********************************************************************/
    /*! \class PatternObserver_V2
    */
    /***********************************************************************/
//!\SelectedPatternObserver_V2
    typedef SelectedObjectObserver_V2<TemporaryPropertiesIndex::SELECTED_PATTERN> SelectedPatternObserver_V2;

//!\RelativPatternObserver_V2
    struct ChangedRelativePattern_depend_onSELECTED_PROJECT_policy{ template<class THIS>
    static void change(THIS *const this__) noexcept
    {
        this__->detach_at_relative_observedObject();

        auto relative_observedPattern(tmpGET_(SELECTED_PROJECT)
                                            ->pattern(this__->_absolut_id_in_parent));

        this__->attach_at_relative_observedObject(relative_observedPattern);
    }};

    template
    <
        class UNIQUE_GEN_RELATIVE_ID
    >
    using RelativePatternObserver_V2
    = RelativObjectObserver_V2
    <
        Pattern,
        TemporaryPropertiesIndex::SELECTED_PATTERN,
        TemporaryPropertiesIndex::SELECTED_PROJECT,
        ChangedRelativePattern_depend_onSELECTED_PROJECT_policy,
        GenEndlessLinearId<UNIQUE_GEN_RELATIVE_ID>
    >;

//!\SelecteddetailPatternObserver_V2
    template
    <
        class UNIQUE_GEN_RELATIVE_ID
    >
    using SelecteddetailPatternObserver_V2
    = RelativObjectObserver_V2
    <
        Pattern,
        TemporaryPropertiesIndex::SELECTED_PATTERN,
        TemporaryPropertiesIndex::SELECTED_PATTERN,
        ChangedRelativeObserver_forSelectedDetailObserver_policy<TemporaryPropertiesIndex::SELECTED_PATTERN>,
        GenEndlessLinearId<UNIQUE_GEN_RELATIVE_ID>
    >;

//!\AbsolutPatternObserver_V2
    //! Ändert das observierte Pattern per absoluter Id / child Id
    template<class IS_A_DUMMY = TYPE_NOT_UNIQUE>
    struct ChangedAbsolutObservedPattern_policy{ template<class THIS>
    static void change(THIS *const this__) noexcept{

        this__->detach_at_absolut_observed_object();

        auto observed_database(this__->selected_observedObject(Loki::Type2Type<typename THIS::TYPE_Database2Observe_T>()));
        auto absolut_observed_object(observed_database
                                     ->pattern(this__->_child_id));

        this__->attach_at_absolut_observed_object(absolut_observed_object);
    }};

    typedef AbsolutObjectObserver
    <
        Pattern,
        TemporaryPropertiesIndex::SELECTED_PROJECT,
        ChangedAbsolutObservedPattern_policy<TYPE_NOT_UNIQUE>
    >
    AbsolutPatternObserver_V2;

    /***********************************************************************/
    /*! \class ProjectObserver_V2
    */
    /***********************************************************************/
//!\SelecteddetailProjectObserver_V2
    typedef RelativObjectObserver_V2
    <
        Project,
        TemporaryPropertiesIndex::SELECTED_PROJECT,
        TemporaryPropertiesIndex::SELECTED_PROJECT,
        ChangedRelativeObserver_forSelectedDetailObserver_policy<TemporaryPropertiesIndex::SELECTED_PROJECT>,
        GenZeroId<TYPE_NOT_UNIQUE>
    >
    SelecteddetailProjectObserver_V2;

//!\SelectedProjectObserver_V2
    typedef SelectedObjectObserver_V2<TemporaryPropertiesIndex::SELECTED_PROJECT> SelectedProjectObserver_V2;

    /***********************************************************************/
    /*! \class SequencerObserver_V2
    */
    /***********************************************************************/
//!\SelecteddetailSequencerObserver_V2
    typedef RelativObjectObserver_V2
    <
        Sequencer,
        TemporaryPropertiesIndex::SEQUENCER,
        TemporaryPropertiesIndex::SEQUENCER,
        ChangedRelativeObserver_forSelectedDetailObserver_policy<TemporaryPropertiesIndex::SEQUENCER>,
        GenZeroId<TYPE_NOT_UNIQUE>
    >
    SelecteddetailSequencerObserver_V2;

//!\SelecteddetailSequencerObserver_V2
    typedef SelectedObjectObserver_V2<TemporaryPropertiesIndex::SEQUENCER> SelectedSequencerObserver_V2;
}

#endif // DC_OBJECTOBSERVER_H_INCLUDED
